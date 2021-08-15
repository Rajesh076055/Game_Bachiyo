#pragma once
#include<SFML/Graphics.hpp>

class Player;
class view
{
private:
	sf::View view1;


	void initView();

public:
	view();
	virtual ~view();
	void moveView(Player& chara);
	friend int main();
	friend void Updates();
};

