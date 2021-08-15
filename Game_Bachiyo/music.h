#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>


class Player;
class music
{


public:
	//main game audio
	sf::Music mainAudio;
	sf::Music gameOverAudio;
	bool coinMusic;
	int gameOverPlayed;
	//load the audio files
	sf::SoundBuffer jumpingAudio;
	sf::SoundBuffer coinAudio;

	//functions to play the loaded audio files
	sf::Sound coinSound;
	sf::Sound jumpSound;

	void initAudio();

public:
	music();
	virtual ~music();
	void playingAudio(Player& chara);
	
	
};

