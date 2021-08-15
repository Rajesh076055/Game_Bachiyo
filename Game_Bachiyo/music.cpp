#include "music.h"
#include"Player.h"


void music::initAudio()
{
	this->coinMusic = false;
	this->gameOverPlayed = 10;
	this->mainAudio.openFromFile("C:\\Users\\na\\Desktop\\Extras\\mario_from_github\\supermariohd\\res\\Music\\overworld.ogg");
	this->gameOverAudio.openFromFile("C:\\Users\\na\\Desktop\\Extras\\mario_from_github\\supermariohd\\res\\Sounds\\mario_die.wav");
	if (!this->jumpingAudio.loadFromFile("C:\\Users\\na\\Desktop\\Extras\\mario_from_github\\supermariohd\\res\\Sounds\\jump_super.wav"))
	{
		std::cout << "failed to load audio";
	}
	this->jumpSound.setBuffer(this->jumpingAudio);
	if (!this->coinAudio.loadFromFile("C:\\Users\\na\\Desktop\\Extras\\mario_from_github\\supermariohd\\res\\Sounds\\coin.wav"))
	{
		std::cout << "failed to load audio";
	}
	this->coinSound.setBuffer(this->coinAudio);
	this->mainAudio.play();
}

music::music()
{
	this->initAudio();
}

music::~music()
{
}

void music::playingAudio(Player& chara)
{
	
	if (chara.isJump == true && chara.jumpCount == 9)
	{
		this->jumpSound.play();
	}

	if (this->coinMusic)
	{
		this->coinSound.play();
	}
	
	if (chara.character.getPosition().y > 800)
	{
		this->mainAudio.stop();
		this->gameOverAudio.play();
		chara.character.setPosition(0, -5000);
	}
	
	

	

}