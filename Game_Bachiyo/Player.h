#pragma once
#include<SFML/Graphics.hpp>
#include"platform.h"
#include"music.h"
#include"Fireball.h"
#include"view.h"
#include"gameover.h"
class ground;
class Player
{
protected:
	//variables for players
	int positionX;
	int positionY;
	bool left, right;
	bool isJump;
	bool grounded;
	int accGravity;
	int maxGravity;
	int jumpCount;
	bool collision;
	bool scored;

	//textures and sprites for player
	sf::Texture CharacterText;
	sf::Sprite character;
	sf::IntRect AnimatingPart;


	//initializing functions for positions and variables
	void initVariables();
	void initPositions();


	
	
	

public:
	//public functions and constructors creations

	sf::Vector2i velocity;
	Player();
	virtual ~Player();
	void PlayerUpdates(ground& grd,Player& chara,platform& pl);
	void PlayerMove(ground& grd,Player& chara, platform& pl);
	void PlayerJump(ground& grd,Player& chara, platform& pl);
	void Animate();
	


	//a friend function to use its private members
	sf::Vector2f getPositioning();
	friend void initRender();
	friend void  Updates();
	friend void platform::PlatformCollision(Player& chara,int xvel, int yvel);
	friend void gameover::isGameOver(Player& chara);
	friend void music::playingAudio(Player& chara);
	friend void view::moveView(Player& chara);
	friend void FireBall::CollisionWithEnemyorSurfaces(ground& grd, platform& plat,enemy& enem);
	//checking for ground and player collisions

	void collisionHappen(ground& grd,int xvel, int yvel);

};




