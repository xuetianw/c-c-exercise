////////////////////
// MagicHandler.h //
////////////////////

#ifndef MAGICHANDLER_H
#define MAGICHANDLER_H

#include "AccountHandler.h"
#include <sstream>

using model::Player;

namespace model {
    /**
     *  A spell instance containing the Player ID of the spell's caster and target, along
     *  with the remaining duration of the spell (in number of game cycles).
     */
    struct SpellInstance {
        ID casterPlayerId;
        ID targetPlayerId;
        unsigned int cyclesRemaining;
    };

    ID is customized class, which is a good design.

    /**
     * Formatter for boost::find_format. Converts strings into Pig Latin.
     */
    template<typename SeqT>
    struct PigLatinFormatter {
        template<typename ReplaceT>
        SeqT operator()(const ReplaceT& Replace) const {
            std::ostringstream result;
            std::string word(Replace.begin(), Replace.end());

            auto firstVowelIndex = word.find_first_of("aeiouAEIOU");

            Do not know why we want to ge the first Vowel

            if (firstVowelIndex != std::string::npos && firstVowelIndex != 0) {
                // Word starts with consonant(s)
                result << word.substr(firstVowelIndex) << word.substr(0, firstVowelIndex) << "ay";

            } else if (firstVowelIndex != std::string::npos) {
                // Word starts with a vowel
                result << word.substr(firstVowelIndex) << word.substr(0, firstVowelIndex) << "way";

            } else {
                // Word's letters are all consonants
                result << word << "ay";
            }

            return result.str();
        }
    };

    template is a strong technical,  it is used well here,

    /**
     *  @class MagicHandler
     *
     *  @brief A class for defining magic spells and performing the operations involved.
     *
     *  This class defines the available magic spells in the game, their effects on
     *  characters, and tracks the longevity of each spell instance. It uses the
     *  Game class' AccountHandler to associate instances of spells on active players.
     */
    class MagicHandler {
    private:
        AccountHandler* accountHandler;
        std::vector<SpellInstance> bodySwapInstances;
        std::vector<SpellInstance> confuseInstances;

        static constexpr unsigned int BODY_SWAP_DURATION = 50;
        static constexpr unsigned int CONFUSE_DURATION = 50;

        enum class Spell {
            BodySwap,
            Decoy,
            Confuse
        };

        std::map<std::string, Spell> spellMap = {
            {"swap", Spell::BodySwap},
            {"decoy", Spell::Decoy},
            {"confuse", Spell::Confuse},
        };

        std::map<Spell, std::vector<std::string>> spellWordsMap = {
            {Spell::BodySwap, {"swap"}},
            {Spell::Decoy, {"decoy"}},
            {Spell::Confuse, {"confuse"}}
        };

        /**
         *  Switches the bodies of the casting player and the target player.
         */
        std::vector <Message>
        bodySwap(const Connection &client, const std::string &targetName);

        /**
         *  [Not yet implemented] Creates a decoy in combat so the player can flee
         */
        std::vector <Message>
        decoy(const Connection &client);

        /**
         *  Places target player under the effects of the Confuse spell, which causes
         *  the target player's next chat messages to be in Pig Latin.
         */
        std::vector<Message>
        confuse(const Connection &client, const std::string &targetName);

    public:
        /**
         *  Constructs a MagicHandler instance with a pointer to the
         *  AccountHandler instance used by the Game class.
         */
        explicit MagicHandler(AccountHandler &accountHandler);

        /**
         *  Casts a spell if the spell name is valid
         */
        std::vector<Message>
        castSpell(const Connection &client, const std::string &param);

        /**
         *  Returns true if the client's Player is under the effects of the Body Swap spell
         */
        bool
        isBodySwapped(const Connection &client);

        /**
         *  Returns true if the client's Player is under the effects of the Confuse spell
         */
        bool
        isConfused(const Connection &client);

        /**
         *  Converts a string into Pig Latin
         */
        void
        confuseSpeech(std::string &message);

        /**
         *  Handles the active spells affecting the logged out Player.
         */
        void
        handleLogout(const Connection &client);

        /**
         *  Decrements the remaining duration of active spells and removing their
         *  effects on expiration. Creates Messages to notify players when spells
         *  have expired.
         */
        void
        processCycle(std::deque<Message> &messages);
    };
}

#endif //MAGICHANDLER_H

//////////////////////
// MagicHandler.cpp //
//////////////////////

#include "MagicHandler.h"
#include <sstream>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/find_format.hpp>
#include <boost/algorithm/string/formatter.hpp>

using model::MagicHandler;

namespace model {
    MagicHandler::MagicHandler(AccountHandler &accountHandler) :
        accountHandler(&accountHandler){}


    std::vector<Message>
    MagicHandler::castSpell(const Connection &client, const std::string &param) {
        std::vector<std::string> arguments;
        boost::algorithm::split(arguments, param, boost::is_any_of(" "), boost::token_compress_on);

        auto spellName = boost::algorithm::to_lower_copy(arguments.at(0));
        if (spellName.empty()) {
            return {{client, "You need to specify the name of the spell to be cast.\n"}};
        }

        std::string targetName;
        if (arguments.size() > 1) {
            targetName = arguments.at(1);
        }

        std::vector<Message> responses;
        bool isValidSpellName = static_cast<bool>(this->spellMap.count(spellName));

        if (!isValidSpellName) {
            std::ostringstream responseMessage;
            responseMessage << "There are no spells with the name of \"" << arguments.at(0) << "\"\n";

            return {{client, responseMessage.str()}};
        }

        auto spell = this->spellMap.at(spellName);
        switch (spell) {
            case (Spell::BodySwap):
                responses = this->bodySwap(client, targetName);
                break;&


            case (Spell::Decoy):
                responses = this->decoy(client);
                break;

            case (Spell::Confuse):
                responses = this->confuse(client, targetName);
                break;

            default:
                break;
        }

        return responses;
    }


    std::vector<Message>
    MagicHandler::bodySwap(const Connection &client, const std::string &targetName) {
        std::vector<Message> responses;

        if (this->isBodySwapped(client)) {
            return {{client, "You can't cast Swap while already under the effects of the spell!\n"}};
        }

        if (targetName.empty()) {
            return {{client, "You need to specify the name of the person to cast Swap on.\n"}};
        }

        auto casterPlayerId = this->accountHandler->getPlayerIdByClient(client);
        auto casterRoomId = this->accountHandler->getRoomIdByClient(client);
        auto casterUsername = this->accountHandler->getUsernameByClient(client);
        if (casterUsername == targetName) {
            return {{client, "You can't cast Swap on yourself!\n"}};
        }

        std::ostringstream casterMessage;
        std::ostringstream targetMessage;

        auto targetClient = this->accountHandler->getClientByUsername(targetName);
        if (targetClient.id == 0) {
            casterMessage << "There is no one here with the name \"" << targetName << "\"\n";
            return {{client, casterMessage.str()}};
        }

        auto targetRoomId = this->accountHandler->getRoomIdByClient(targetClient);
        if (targetRoomId != casterRoomId) {
            casterMessage << "There is no one here with the name \"" << targetName << "\"\n";
            return {{client, casterMessage.str()}};
        }

        if (this->isBodySwapped(targetClient)) {
            casterMessage << targetName << " is already under the effects of the Swap spell!\n";
            return {{client, casterMessage.str()}};
        }

        auto targetPlayerId = this->accountHandler->getPlayerIdByClient(targetClient);
        this->accountHandler->swapPlayerClientsByPlayerId(casterPlayerId, targetPlayerId);
        this->bodySwapInstances.push_back({casterPlayerId, targetPlayerId, BODY_SWAP_DURATION});

        casterMessage << "You have successfully swapped bodies with " << targetName << "\n";
        targetMessage << casterUsername << " cast swap on you!\n";

        responses.push_back({targetClient, targetMessage.str()});
        responses.push_back({client, casterMessage.str()});

        return responses;
    }


    std::vector<Message>
    MagicHandler::decoy(const Connection &client) {
        std::vector<Message> responses;

        responses.push_back({client, "You do not yet know how to cast the Decoy spell.\n"});

        return responses;
    }


    std::vector<Message>
    MagicHandler::confuse(const Connection &client, const std::string &targetName) {
        std::vector<Message> responses;

        if (targetName.empty()) {
            return {{client, "You need to specify the name of the person to cast Confuse on.\n"}};
        }

        auto casterPlayerId = this->accountHandler->getPlayerIdByClient(client);
        auto casterRoomId = this->accountHandler->getRoomIdByClient(client);
        auto casterUsername = this->accountHandler->getUsernameByClient(client);
        if ((casterUsername == targetName) && (this->isConfused(client))) {
            return {{client, "You are already under the effects of the Confuse spell!\n"}};
        }

        if (casterUsername == targetName) {
            this->confuseInstances.push_back({casterPlayerId, casterPlayerId, CONFUSE_DURATION});
            return {{client, "You cast Confuse on yourself.\n"}};
        }

        std::ostringstream casterMessage;
        std::ostringstream targetMessage;

        auto targetClient = this->accountHandler->getClientByUsername(targetName);
        if (targetClient.id == 0) {
            casterMessage << "There is no player here with the name \"" << targetName << "\"\n";
            return {{client, casterMessage.str()}};
        }

        auto targetPlayerId = this->accountHandler->getPlayerIdByClient(targetClient);
        auto targetRoomId = this->accountHandler->getRoomIdByClient(targetClient);
        if (casterRoomId != targetRoomId) {
            casterMessage << "There is no player here with the name \"" << targetName << "\"\n";
            return {{client, casterMessage.str()}};
        }

        if (isConfused(targetClient)) {
            casterMessage << targetName << " is already under the effects of the Confuse spell!\n";
            return {{client, casterMessage.str()}};
        }

        this->confuseInstances.push_back({casterPlayerId, targetPlayerId, CONFUSE_DURATION});

        casterMessage << "You cast Confuse on " << targetName << "\n";
        targetMessage << casterUsername << " cast Confuse on you!" << "\n";

        responses.push_back({client, casterMessage.str()});
        responses.push_back({targetClient, targetMessage.str()});

        return responses;
    }


    bool
    MagicHandler::isBodySwapped(const Connection &client) {
        auto playerId = this->accountHandler->getPlayerIdByClient(client);

        auto it_swap = std::find_if(
            this->bodySwapInstances.begin(),
            this->bodySwapInstances.end(),
            [&playerId](const SpellInstance &swapInstance) {
                return (playerId == swapInstance.casterPlayerId) || (playerId == swapInstance.targetPlayerId);
            }
        );

        return it_swap != this->bodySwapInstances.end();
    }


    bool
    MagicHandler::isConfused(const Connection &client) {
        auto playerId = this->accountHandler->getPlayerIdByClient(client);

        auto it_confuse = std::find_if(
            this->confuseInstances.begin(),
            this->confuseInstances.end(),
            [&playerId](const SpellInstance &confuseInstance) {
                return playerId == confuseInstance.targetPlayerId;
            }
        );

        return it_confuse != this->confuseInstances.end();
    }


    void
    MagicHandler::confuseSpeech(std::string &message) {
        boost::find_format_all(
            message,
            boost::token_finder((boost::is_alpha() || boost::is_any_of("'")), boost::token_compress_on),
            PigLatinFormatter<std::string>()
        );
    }
}
