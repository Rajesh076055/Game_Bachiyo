#include "view.h"
#include"Player.h"

void view::initView()
{
	this->view1 = sf::View(sf::FloatRect(0.f, 0.f, 1920.f, 800.f));
}

view::view()
{
	this->initView();
}

view::~view()
{
}

void view::moveView(Player& chara)
{
	
	if (chara.character.getPosition().x >( this->view1.getCenter().x)  and sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		
		this->view1.move(15.f, 0.f);
		
	}
}
