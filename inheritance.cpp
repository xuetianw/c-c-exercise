
#include <iostream>
#include <string>
#include <string_view>


// NOTE: This provides a strongly typed wrapper to prevent argument confusion.
// There are existing libraries and headers that can provide richer strongly
// typed aliases.
template <typename Base, typename Tag>
struct StrongAlias {
  explicit StrongAlias(Base value) : value{std::move(value)} { }
  Base value;
};

using Happiness = StrongAlias<int, struct HappinessTag>;
using Laziness  = StrongAlias<int, struct LazinessTag>;
using Name      = StrongAlias<std::string, struct NameTag>;
using Speech    = StrongAlias<std::string, struct SpeechTag>;


// Vocalization defines a simple interface for speech policie.s
class Vocalization {
public:
  void speak(std::string_view toSay) const noexcept { speakImpl(toSay); }
private:
  virtual void speakImpl(std::string_view toSay) const noexcept = 0;
};


// Movement defines a simple interface for movement policies.
class Movement {
public:
  void move(Laziness laziness) const noexcept { moveImpl(laziness); }
private:
  virtual void moveImpl(Laziness laziness) const noexcept = 0;
};


// Animal provides general functionality for all animals.
// For Vocalization and Movement policies, the Animal is *non-owning* and
// expects the policy lifetime to be determined externally in a stable way.
class Animal {
public:
  Animal(Name name,
         Happiness happiness,
         Laziness laziness,
         Speech speech,
         const Vocalization& vocalization,
         const Movement& movement)
    : name{std::move(name)},
      happiness{happiness},
      laziness{laziness},
      speech{std::move(speech)},
      vocalization{&vocalization},
      movement{&movement}
      { }

  void move() const noexcept { movement->move(laziness); }
  void speak() const noexcept { vocalization->speak(speech.value); }
  Name getName() const noexcept { return name; }

  void setVocalization(const Vocalization& newVocalization) {
    this->vocalization = &newVocalization;
  }

private:
  Name name;
  Happiness happiness;
  Laziness laziness;
  Speech speech;
  const Vocalization* vocalization;
  const Movement* movement;
};


////////////////////////////////////////////////////////////////////////////////
//  Speaking Policies
////////////////////////////////////////////////////////////////////////////////


class DirectSpeaker : public Vocalization {
private:
  void speakImpl(std::string_view toSay) const noexcept override {
    std::cout << toSay << "\n";
  }
};


class CoughSpeaker : public Vocalization {
private:
  void speakImpl(std::string_view toSay) const noexcept override {
    std::cout << "**Cough** " << toSay << " **Cough**\n";
  }
};


class RepeatSpeaker : public Vocalization {
public:
  explicit RepeatSpeaker(int repetitions) : repetitions{repetitions} { }

private:
  void speakImpl(std::string_view toSay) const noexcept override {
    auto prefix = toSay.substr(0, 4);
    for (int count = 0; count < repetitions; ++count) {
      std:: cout << prefix << " ";
    }
    std::cout << toSay << "\n";
  }

  const int repetitions;
};


////////////////////////////////////////////////////////////////////////////////
//  Movement Policies
////////////////////////////////////////////////////////////////////////////////


class Crawler : public Movement {
private:
  void moveImpl(Laziness /*laziness*/) const noexcept override {
    // Imagine that each of these does something to affect the behavior based
    // on the laziness.
    std::cout << "crawl";
  }
};


class Swimmer : public Movement {
private:
  void moveImpl(Laziness /*laziness*/) const noexcept override {
    std::cout << "swim";
  }
};



int
main() {
  DirectSpeaker speaker;
  CoughSpeaker cougher;
  RepeatSpeaker shortStutter{3};
  RepeatSpeaker longStutter{16};

  Crawler crawler;
  Swimmer swimmer;

  Animal animals[] = {
    Animal{
      Name{"Professor"},
      Happiness{10},
      Laziness{1},
      Speech{"Howdy there."},
      shortStutter,
      crawler,
    },

    Animal{
      Name{"House Cat"},
      Happiness{11},
      Laziness{1},
      Speech{"Meow."},
      longStutter,
      crawler,
    },

    Animal{
      Name{"Tiger"},
      Happiness{1},
      Laziness{2},
      Speech{"Roar."},
      speaker,
      swimmer,
    },

    Animal{
      Name{"Sketchy guy in the back of class"},
      Happiness{1},
      Laziness{11},
      Speech{"Did you do the reading?"},
      cougher,
      crawler,
    },
  };


  auto tryAnimal = [] (Animal& animal) {
    std::cout << "The " << animal.getName().value << " says:\n";
    animal.speak();
    std::cout << "\n";
  };

  // We can make them all speak, and there need not be any inheritance in the
  // Animal classes themselves. This allows for greater flexibility and
  // determination of the behavior based on data.
  for (auto& animal : animals) {
    tryAnimal(animal);
  }

  // By isolating the portions that change and not using an Animal hierarchy,
  // we can modify the behaviors dynamically.
  animals[0].setVocalization(speaker);
  tryAnimal(animals[0]);

  animals[0].setVocalization(longStutter);
  tryAnimal(animals[0]);

  return 0;
}


