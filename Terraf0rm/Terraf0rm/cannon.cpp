#include "cannon.h"

Cannon::Cannon()
{

}

void Cannon::initCannon()
{
	GameObject::init(0,0,10,10,0,0,3,3);
	setID(BULLET);
	setAlive(false);
	setCollideable(true);
	setDirection(DOWN);
	
	setRed(50);
	setGreen(255);
	setBlue(10);

	setSize(3);
	setSpeed(10);
}
void Cannon::fireCannon(Hero *player)
{
	setAlive(true);
	setDirection(player->getDirection());
	if(getDirection() == DOWN)
	{
		setX(player->getX() - 7);
		setY(player->getY() + 8);
	}
	else if (getDirection() == RIGHT)
	{
		setX(player->getX());
		setY(player->getY() + 9);
	}
	else if (getDirection() == UP)
	{
		setX(player->getX() + 5);
		setY(player->getY() + 8);
	}
	else
	{
		setX(player->getX());
		setY(player->getY() + 8);
	}
}


void Cannon::Update()
{
	switch(getDirection())
	{
	case UP: y-= getSpeed();
		break;
	case DOWN: y+= getSpeed();
		break;
	case LEFT: x-= getSpeed();
		break;
	case RIGHT: x+= getSpeed();
		break;
	}
	if(y > sHEIGHT)
		Collided(ENEMY);
	else if(y < 15)
		Collided(ENEMY);
	if(x < 15)
		Collided(ENEMY);
	else if(x > sWIDTH)
		Collided(ENEMY);

 }
void Cannon::Render()
{
	al_draw_filled_circle(getX(), getY(), getSize(), al_map_rgb(getRed(),getGreen(),getBlue()));
}
void Cannon::Collided(int objectID)
{
	if (objectID == ENEMY)
		setAlive(false);
}

Cannon::~Cannon()
{

}