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
	
	setRed(0);
	setGreen(200);
	setBlue(0);

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
	if(y >=  (mTotalHeight / 8) + sHEIGHT- 15)
		Collided(ENEMY);
	else if(y <= 0 + 15  + (mTotalHeight / 8))
		Collided(ENEMY);
	if(x <= 0 + 15 + (mTotalWidth / 4))
		Collided(ENEMY);
	else if(x >= (mTotalWidth / 4) + sWIDTH - 15 )
		Collided(ENEMY);

 }
void Cannon::Render()
{
	al_draw_filled_circle(getX(), getY(), getSize(), al_map_rgb(getRed(),getGreen(),getBlue()));
}
void Cannon::Collided(int objectID)
{
	if (objectID == ENEMY || objectID == DRAGON)
		setAlive(false);
}

Cannon::~Cannon()
{

}