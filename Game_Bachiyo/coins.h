#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"

class coins
{


private:

	sf::Texture coinImage;
	sf::Sprite* coinSprite;
	int coinXimage;



	void initVariables();
	void initPositions(int WorldMap[][1000]);


public:
	coins(int WorldMap[][1000]);
	void coinAnimation();
	void coinCollision(sf::Sprite chara);
	friend void initRender();
	friend void  Updates();
	

};

