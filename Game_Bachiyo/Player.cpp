#include "Player.h"
#include "ground.h"
#include<iostream>

void Player::initVariables()
{
	this->grounded = true;
	this->positionX = 30;
	this->positionY = 720;
	this->left = false;
	this->right = false;
	this->isJump = false;
	this->jumpCount = 10;
	this->accGravity = 10;
	this->velocity = sf::Vector2i(0, 0);
	this->maxGravity = 40;
	this->AnimatingPart = sf::IntRect(0, 0, 100, 150);
	this->CharacterText.loadFromFile("C:\\Users\\na\\Desktop\\Extras\\Game_Bachiyo\\images\\characters\\characters.png");
	this->character.setTexture(this->CharacterText);
	
}

void Player::initPositions()
{
	this->character.setPosition(this->positionX, this->positionY);
	this->character.setScale(0.7, 0.8);

}

Player::Player()
{
	this->initVariables();
	this->initPositions();
}

Player::~Player()
{
}

void Player::PlayerUpdates(ground& grd,Player& chara,platform& pl)
{
	this->PlayerMove(grd,chara,pl);
	this->PlayerJump(grd,chara,pl);
	this->Animate();

}





void Player::PlayerMove(ground& grd,Player& chara, platform& pl)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //if user presses the key D
	{
		this->right = true;
		this->left = false;
	
		
		this->velocity.x = 15;
		
	
		

	}
	else
	{
		this->velocity.x = 0.f;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //if user presses the key D
	{
		this->right = false;
		this->left = true;
		if (this->character.getPosition().x > 10)
		{
			this->velocity.x = -15;
		}
		else
		{
			this->velocity.x = 0.f;
		}

	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		
		this->velocity.x = 0.f;
		this->right = false;
		this->left = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		this->character.setPosition(this->positionX, this->positionY);
	}
	this->character.move(this->velocity.x, 0);
     
	this->collisionHappen(grd,this->velocity.x, 0);
	pl.PlatformCollision(chara,this->velocity.x, 0);

}





void Player::PlayerJump(ground& grd,Player& chara, platform& pl)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->grounded)
	{
		this->isJump = true;
	}

	if (this->isJump)

		
	{

		this->AnimatingPart.left = 221;
		this->velocity.y = (pow(this->jumpCount, 2) * 0.5 * -1);
		this->jumpCount -= 1;
		if (this->jumpCount < 0)
		{

			this->grounded = false;
			this->jumpCount = 10.f;
			this->isJump = false;
		}
	}



	if (!this->grounded || this->jumpCount == 10.f)
	{

		this->velocity.y = pow(this->accGravity, 2) * 0.5;
		this->accGravity += 1.f;
		if (this->velocity.y > this->maxGravity) { this->velocity.y = this->maxGravity; }

	}
	else
	{
		this->accGravity = 10.f;
	}
	this->character.move(0, this->velocity.y);
	this->collisionHappen(grd,0, this->velocity.y);
	pl.PlatformCollision(chara, 0, this->velocity.y);

	
}




void Player::Animate()
{
	
	if (this->right)
	{
		if (this->AnimatingPart.left >= 720 && !this->isJump)
		{
			this->AnimatingPart.left = 0;
			this->AnimatingPart.top = 0;
		}
		else { this->AnimatingPart.left += 110.5; }
	}

	if (this->left)
	{
		this->AnimatingPart.top = 150;
		if (this->AnimatingPart.left >= 720 && !this->isJump)
		{
			this->AnimatingPart.left = 0;
			this->AnimatingPart.top = 150;
		}
		else { this->AnimatingPart.left += 107; }

	}

	if (!this->right &&  !this->left)
	{
		this->AnimatingPart.left = 0;
		this->AnimatingPart.top = 0;
	}
	
	
	this->character.setTextureRect(this->AnimatingPart);
	
}

sf::Vector2f Player::getPositioning()
{
	return (this->character.getPosition());

}



void Player::collisionHappen(ground& grd, int xvel, int yvel)
{	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0;j < 1000;j++)
		{
			if (this->character.getPosition().x + 20.f < (grd.GroundSprite[i][j].getPosition().x + grd.GroundSprite[i][j].getGlobalBounds().width) &&
				(this->character.getPosition().x + this->character.getGlobalBounds().width - 15.f) > grd.GroundSprite[i][j].getPosition().x &&
				(this->character.getPosition().y) < (grd.GroundSprite[i][j].getPosition().y + grd.GroundSprite[i][j].getGlobalBounds().height) &&
				(this->character.getPosition().y + this->character.getGlobalBounds().height - 30.f) > (grd.GroundSprite[i][j].getPosition().y))
			{
				this->collision = true;

			}
			else
			{
				this->collision = false;
			}
			if (this->collision)
			{
				if (xvel > 0)
				{
					this->character.setPosition(grd.GroundSprite[i][j].getPosition().x - 60.f, this->character.getPosition().y);
					this->velocity.x = 0.0f;


				}

				if (xvel < 0)
				{

					this->character.setPosition(grd.GroundSprite[i][j].getPosition().x + grd.GroundSprite[i][j].getGlobalBounds().width - 15.f, this->character.getPosition().y);
					this->velocity.x = 0.f;
				}


				if (yvel > 0)
				{
					this->character.setPosition(this->character.getPosition().x, grd.GroundSprite[i][j].getPosition().y - this->character.getGlobalBounds().height + 25.f);
					this->velocity.y = 0.f;
					this->grounded = true;

				}

				if (yvel < 0) //&& (this->character.getPosition().x + 40.f < (this->GroundSprite[i][j].getPosition().x + this->GroundSprite[i][j].getGlobalBounds().width + 10.f)))
				{
					this->character.setPosition(this->character.getPosition().x, grd.GroundSprite[i][j].getPosition().y + grd.GroundSprite[i][j].getGlobalBounds().height);
					this->velocity.y = 0.f;
				}

			}

		}
	}

	

	
}
