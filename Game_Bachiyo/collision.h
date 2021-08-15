#pragma once
#include"Player.h"
#include"ground.h"

class collision:public ground,public Player
{
private:
	bool collision;

public:

	void checkCollision();
};

