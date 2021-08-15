#pragma once
#include<SFML/Graphics.hpp>

class ground;
class Player;
class platform;
class enemy;
class FireBall
{

private:
	//variables
	int positionX, positionY;
	bool fired;
	bool CollidedAnything;
	int finalX, finalY;
	sf::Vector2f velocityFire;
	sf::IntRect animationPart;
	//textures and sprites

	sf::Texture FireballImage;
	sf::Sprite fireball;

	//privates functions
	void initVariables();
	


public:
	FireBall();
	virtual ~FireBall();
	void isFired(Player& chara);
	friend void initRender();
	friend void Updates();
	void FireballUpdates(Player& chara);
	void animateFireBall();
	void CollisionWithEnemyorSurfaces(ground& grd,platform& plat,enemy& enem);
};

