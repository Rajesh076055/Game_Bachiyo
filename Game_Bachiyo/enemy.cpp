#include "enemy.h"


void enemy::initVariables()
{
	
	this->EnemyPart = 0;
	this->enemyMoveCount = 20;
	this->DeadOrNot = new int[1000];
	this->EnemySprite1 = new sf::Sprite  [1000];
	this->EnemySprite2 = new sf::Sprite[1000];
	this->EnemyTexture.loadFromFile("C:\\Users\\na\\Desktop\\Extras\\sfmlproject\\HelloSFML\\images\\enemies&chains\\Enemies.png");

}

void enemy::initPositions(int WorldMap[][1000])
{
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			
			if (WorldMap[i][j] == 7)
			{
					
					this->EnemySprite1[j].setPosition(j * 60, 715 - 50 * (8 - i));
					this->EnemySprite1[j].setTexture(this->EnemyTexture);
					this->EnemySprite1[j].setTextureRect(sf::IntRect(this->EnemyPart, 0, 32, 30));
					this->EnemySprite1[j].setScale((float)1.2, (float)1.2);
				
				
			}

			if (WorldMap[i][j] == 8)
			{
				this->EnemySprite2[j].setPosition(j * 60, 700 - 50 * (8 - i));
				this->EnemySprite2[j].setTexture(this->EnemyTexture);
				this->EnemySprite2[j].setTextureRect(sf::IntRect(this->EnemyPart, 35, 32, 40));
				this->EnemySprite2[j].setScale((float)1.2, (float)1.2);
			}

			
		}
	}
	for (int i = 0;i < 1000;i++)
	{
		this->DeadOrNot[i] = 0;
	}
}

enemy::enemy(int WorldMap[][1000])
{
	this->initVariables();
	this->initPositions(WorldMap);
}

enemy::~enemy()
{
	
}

void enemy::EnemyAnimations(int WorldMap[][1000])
{
	if (this->EnemyPart >= 32)
	{
		this->EnemyPart = 0;
	}

	else
	{
		this->EnemyPart += 32;
	}

	for (int i = 0;i < 1000;i++)
	{
		if (!this->DeadOrNot[i])
		{
			this->EnemySprite1[i].setTextureRect(sf::IntRect(this->EnemyPart, 0, 32, 30));
			this->EnemySprite2[i].setTextureRect(sf::IntRect(this->EnemyPart, 35, 32, 40));

		}
		
	}


}

	


void enemy::EnemyMove(int indexForEnemy)
{
	if (this->enemyMoveCount > 0)
	{
		this->velocityEnemy.x = 8;
		this->enemyMoveCount -= 1;
		for (int i = 0;i < 1000;i++)
		{
			this->EnemySprite2[i].setScale(-1.2f, 1.2f);
		}
	}
	else
	{
		for (int i = 0;i < 1000;i++)
		{
			this->EnemySprite2[i].setScale(1.2f, 1.2f);
		}
		this->velocityEnemy.x = -8;
		this->enemyMoveCount -= 1;
		if (this->enemyMoveCount < -20)
		{
			this->enemyMoveCount = 20;
		}
	}



	for (int j = 0; j < 1000;j++)
	{
		if (!this->DeadOrNot[j])
		{
			this->EnemySprite1[j].move(this->velocityEnemy.x, 0);
			this->EnemySprite2[j].move(this->velocityEnemy.x * 0.5, 0);

		}
		if (this->DeadOrNot[j])
		{
			this->EnemySprite1[j].move(0, 18);
			this->EnemySprite2[j].move(0, 18);
		}
	
		
		
	}

}





