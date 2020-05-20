// MusicManagerTest.cpp

#include <iostream>
#include <string>

using namespace music;
using namespace testing;
// codes are in different places

// code 1:
// An example of GoogleTest
TEST(songTest, questionableCreationTest){
	std::string title{"CMPT 473"};
	std::string artist{"William Sumner"};
	std::string album{"Spring 2019"};
	std::string location{"here"};

	Song song{artist, album, title, location};

	// assert 
	ASSERT_EQ(title, song.title);
	ASSERT_EQ(artist, song.artist);
	ASSERT_EQ(album, song.album);
	ASSERT_EQ(location, song.location);
}


// .......... we need mocks and stubs ........... //
class FakeMusicLibrary : public MusicLibrary{
public:
	std::deque<Song> songs;
	FakeMusicLibrary(std::deque<Song> songs): songs{songs}{}
	std::deque<Song> getSongs() override{
		return songs;
	}
};

TEST(musicManagerTest, playSongByTest){
	Song song1{"a", "b", "c", "d"};
	Song song2{"e", "f", "g", "h"};

	FakeMusicLibrary fakeLibrary{
		// we have a fake music library with two songs.
		std::deque<Song>(song1, song2)
	};

	FakeMusicPlayer fakePlayer;

	// used for stubbing: they can provide fake behavior
	EXPECT_CALL(fakePlayer, play(Eq(song1)));		// GOOGLEMOCK - better soltuion

	// the only real two lines of code; the rest are infrastructure - prof
	MusicManager manger{fakeLibrary, fakePlayer};
	manager.playSongBy(song1.artist);				// to check if it works, check if right with song1.artist and that song2.artist fails

	ASSERT_EQ(song1.artist, fakePlayer.played);
}



// ............... main points ............... //
// control behavior with stubs : fakeLibrary
// check behavior with mocks : fakePlayer 
// it took a long time to implement, so there
// other features that can help us do things faster
// .............................................//

/
class MusicPlayer{
public:
	virtual void play(const Song& song)= 0;
};

// FakeMusicPlayer doesn't know about the MusicLibrary
class FakeMusicPlayer : public MusicPlayer{
public:
	// song played;
	// void play(const Song& song) override{
	// 	played = song;
	// }

	// this is the type singnatre of play
	MOCK_METHOD1(play, void(const Song&));		// GOOGLEMOCK - better solution
};

// code 2: We are going to use inheritance
// so we need a base class for them

class MusicLibrary{
	public: 
		virtual deque<Song> getSongs() = 0;		// method for an interface; set to 0
};

class MusicManager{
private:
	MusicLibrary& library;
	static FakeMusicPlayer& player;

	public:	
	// we need to be able to change the type of RemoteMusicLibrary in order to isolate the music manager
	MusicManager(FakeMusicLibrary&, FakeMusicPlayer):library{library}, player{player} {}
	void playSongBy(std::string const& artist);
};