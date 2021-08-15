#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"FireBall.h"

class ground
{
private:
	 sf::Texture GroundImage;
	 sf::Sprite** GroundSprite;
	
	void initVariables();
	void initPosition(int WorldMap[][1000]);
	
	
	

public:
	ground();
	ground(int WorldMap[][1000]);
	
	virtual ~ground();
	
	//a friend function to use its private members

	friend void initRender();
	friend void Player::collisionHappen(ground& grd,int xvel, int yvel);
	friend void FireBall::CollisionWithEnemyorSurfaces(ground& grd,platform& plat,enemy& enem);
	

};

