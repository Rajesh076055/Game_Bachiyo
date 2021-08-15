#pragma once
#include<iostream>

class Player;
class gameover
{
private:
	bool gameOver;


	void initVariables();


public:
	gameover();
	virtual ~gameover();
	friend void Updates();
	void isGameOver(Player& chara);

	
};

