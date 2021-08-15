#pragma once
#include<SFML/Graphics.hpp>
class background
{
private:
	sf::Texture BackgroundImage;
	sf::Sprite* Background;

	void initVariables();
	void initPositions();
	
public:
	background();
	virtual ~background();
	void ScrollBackground();

	//a friend function to use its private members
	friend void initRender();
	
};

