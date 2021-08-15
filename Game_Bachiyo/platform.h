#pragma once
#include<SFML/Graphics.hpp>
#include"FireBall.h"

class Player;
class platform
{
private:
	sf::Texture platformImage;
	sf::Sprite** platforms;

	void initVariables();
	void initPositions(int WorldMap[][1000]);


public:
	platform(int WorldMap[][1000]);
	virtual ~platform();
	void PlatformCollision(Player& chara,int xvel, int yvel);
	friend void initRender();
	friend void FireBall::CollisionWithEnemyorSurfaces(ground& grd, platform& plat,enemy& enem);

};

