#include "platform.h"
#include"Player.h"
#include<iostream>
void platform::initVariables()
{
	this->platformImage.loadFromFile("C:\\Users\\na\\Desktop\\Extras\\Game_Bachiyo\\images\\ground & platforms\\platform.png");

	this->platforms = new sf::Sprite * [10];
	for (int i = 0;i < 10;i++)
	{
		this->platforms[i] = new sf::Sprite[1000];
	}


}

void platform::initPositions(int WorldMap[][1000])
{
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			if (WorldMap[i][j] == 2)
			{
				this->platforms[i][j].setPosition(60*j , 700 - 50 * (8 - i));
				this->platforms[i][j].setTexture(this->platformImage);
				this->platforms[i][j].scale(1.4f, 1.1f);
			}
		}
	}
	
}



platform::platform(int WorldMap[][1000])
{
	this->initVariables();
	this->initPositions(WorldMap);
}







platform::~platform()
{
}

void platform::PlatformCollision(Player& chara,int xvel, int yvel)
{
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 1000;j++)
		{
			if (chara.character.getPosition().x + 10.f < (this->platforms[i][j].getPosition().x + this->platforms[i][j].getGlobalBounds().width) &&
				(chara.character.getPosition().x + chara.character.getGlobalBounds().width - 5.f) > this->platforms[i][j].getPosition().x &&
				(chara.character.getPosition().y + 5.f) < (this->platforms[i][j].getPosition().y + this->platforms[i][j].getGlobalBounds().height) &&
				(chara.character.getPosition().y + chara.character.getGlobalBounds().height - 22.f) > (this->platforms[i][j].getPosition().y))
			{
				chara.collision = true;
			}
			else
			{
				chara.collision = false;
			}
			if (chara.collision)
			{

				if (xvel > 0 && (chara.character.getPosition().x + chara.character.getGlobalBounds().width - 5.f) > this->platforms[i][j].getPosition().x)
				{
					chara.character.setPosition(this->platforms[i][j].getPosition().x - 70.f, chara.character.getPosition().y);
					chara.velocity.x = 0.0f;




				}
				if (xvel < 0 and chara.character.getPosition().x - 10.f < (this->platforms[i][j].getPosition().x + this->platforms[i][j].getGlobalBounds().width))
				{

					chara.character.setPosition(this->platforms[i][j].getPosition().x + this->platforms[i][j].getGlobalBounds().width, chara.character.getPosition().y);
					chara.velocity.x = 0.f;
				}
				if (yvel > 0 and ((chara.character.getPosition().y) < (this->platforms[i][j].getPosition().y)))
				{
					chara.character.setPosition(chara.character.getPosition().x, this->platforms[i][j].getPosition().y - chara.character.getGlobalBounds().height + 20.f);
					chara.velocity.y = 0.f;
					chara.grounded = true;

				}

				if (yvel < 0 && (chara.character.getPosition().x + 40.f < (this->platforms[i][j].getPosition().x + this->platforms[i][j].getGlobalBounds().width + 10.f)))
				{
					chara.character.setPosition(chara.character.getPosition().x, this->platforms[i][j].getPosition().y + this->platforms[i][j].getGlobalBounds().height - 6.f);
					chara.velocity.y = 0.f;
					chara.jumpCount = -1;



				}

			}
		}
	}
	
}
