#include "gameover.h"
#include"Player.h"
void gameover::initVariables()
{
	this->gameOver = false;
}

gameover::gameover()
{
	this->initVariables();
}

gameover::~gameover()
{
}

void gameover::isGameOver(Player& chara)
{
	if (chara.character.getPosition().y > 760)
	{
		this->gameOver = true;
	}
	else
	{
		this->gameOver = false;
	}
}
