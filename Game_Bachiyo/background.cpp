#include "background.h"


background::background()
{
	
	this->initVariables();
	this->initPositions();
}
void background::initVariables()
{
	this->BackgroundImage.loadFromFile("C:\\Users\\na\\Desktop\\Extras\\Game_Bachiyo\\images\\backgrounds\\png\\game_background_2\\game_background_2.png");
	this->Background = new sf::Sprite[20];
	for (int i = 0; i < 20; i++)
	{
		this->Background[i].setTexture(this->BackgroundImage);
	}
}

void background::initPositions()
{
	for (int i = 0;i < 20;i++)
	{
		this->Background[i].setPosition(i * 1920, -200);
	}
}

void background::ScrollBackground()
{

}


background::~background() {};
