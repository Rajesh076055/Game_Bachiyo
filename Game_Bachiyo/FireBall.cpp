#include "FireBall.h"
#include"ground.h"
#include"platform.h"
#include"Player.h"
#include"enemy.h"

void FireBall::initVariables()
{
	this->FireballImage.loadFromFile("C:\\Users\\na\\Desktop\\Extras\\Game_Bachiyo\\images\\ground & platforms\\Mario.png");
	this->fireball.setTexture(this->FireballImage);
	this->animationPart = sf::IntRect(0, 0, 16, 33);
	this->fired = false;
	this->fireball.setTextureRect(this->animationPart);
	
}



FireBall::FireBall()
{
	this->initVariables();
	
}

FireBall::~FireBall()
{


}


void FireBall::isFired(Player& chara)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		this->fired = true;
		this->fireball.setPosition(chara.getPositioning().x + 30, chara.getPositioning().y + 60);
		
	}
	
	
	if(this->fired)
	{
	
			this->fireball.move({45,0 });
			this->animateFireBall();
	}
	else
	{
		this->fireball.setPosition(chara.getPositioning().x + 30, chara.getPositioning().y + 60);
	}

}


void FireBall::FireballUpdates(Player& chara)
{

	this->isFired(chara);

}

void FireBall::animateFireBall()
{
	
	if (this->animationPart.left > 16.5) this->animationPart.left = 0;
	this->fireball.setTextureRect(this->animationPart);
	this->animationPart.left += 16.5f;
}


void FireBall::CollisionWithEnemyorSurfaces(ground& grd,platform& plat,enemy& enem)
{
	//collision with the anything 
	for (int i = 0;i < 10; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			if (this->fireball.getGlobalBounds().intersects(grd.GroundSprite[i][j].getGlobalBounds()) || this->fireball.getGlobalBounds().intersects(plat.platforms[i][j].getGlobalBounds()))
			{
				this->fireball.setTextureRect(sf::IntRect(66, 0, 16, 33));
				this->fired = false;
			}
			
		}
	}
	for (int i = 0;i < 1000;i++)
	{
		if (this->fireball.getGlobalBounds().intersects(enem.EnemySprite1[i].getGlobalBounds()))
		{
			enem.EnemySprite1[i].setScale(1.2, -1.2);
			enem.DeadOrNot[i] = 1;
		}
		if (this->fireball.getGlobalBounds().intersects(enem.EnemySprite2[i].getGlobalBounds()))
		{
			enem.EnemySprite2[i].setScale(1.2, -1.2);
			enem.DeadOrNot[i] = 1;
		}


	}
	

}
