#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"FireBall.h"
class enemy:public Player
{

private:
	sf::Texture EnemyTexture;
	sf::Sprite* EnemySprite1;
	sf::Sprite* EnemySprite2;
	int* DeadOrNot;
	sf::Vector2i velocityEnemy;
	sf::Vertex line;
	int enemyMoveCount;
	bool EnemyOnSurface;
	int EnemyPart;
	void initVariables();
	void initPositions(int WorldMap[][1000]);


public:
	enemy(int WorldMap[][1000]);
	virtual ~enemy();

	void EnemyAnimations(int WorldMap[][1000]);
	void EnemyMove(int indexForEnemy);
	//void EnemyWithGround(ground& grd, int yvel);
	friend void FireBall::CollisionWithEnemyorSurfaces(ground& grd, platform& plat, enemy& enem);
	friend void Updates();
	friend void initRender();

};

