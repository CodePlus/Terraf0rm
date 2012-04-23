#include "cannon.h"

Cannon::Cannon()
{

}

void Cannon::initCannon()
{
	GameObject::init(0,0,0,0,0,0,2,2);
	setID(BULLET);
	setAlive(false);
	setCollideable(true);
	setDirection(DOWN);
	
	setRed(255);
	setGreen(215);
	setBlue(0);

	setSize(3);
	setLength(200);
	setWidth(1);
	setSpeed(10);
	setNumParticles(10);
	setAlive(true);
	setCollideable(true);
}
void Cannon::fireCannon(Hero *player)
{
	if(player->getDirection() == DOWN)
	{
		setX(player->getX() - 7);
		setY(player->getY() + 8);
	}
	else if (player->getDirection() == RIGHT)
	{
		setX(player->getX());
		setY(player->getY() + 9);
	}
	else if (player->getDirection() == UP)
	{
		setX(player->getX() + 5);
		setY(player->getY() + 8);
	}
	else
	{
		setX(player->getX());
		setY(player->getY() + 8);
	}
	setAlive(true);
	setDirection(player->getDirection());
}


void Cannon::Update()
{
	if(getAlive())
	{
		switch (getDirection())
		{
		case UP:y -= getSpeed();
			if(y < sHEIGHT)
				setAlive(false);
			break;
		case DOWN:y += getSpeed();
			if(y > 15)
				setAlive(false);
			break;
		case LEFT:x-= getSpeed();
			if(x < 15)
				setAlive(false);
			break;
		case RIGHT:x += getSpeed();
			if(x > sWIDTH)
				setAlive(false);
			break;
		}
	}
}
void Cannon::Render()
{
	if(getAlive())
		al_draw_filled_circle(getX(), getY(), getSize(), al_map_rgb(getRed(),getGreen(),getBlue()));
}
void Cannon::Collided(int objectID)
{
	if(objectID == ENEMY)
	{

	}
}

Cannon::~Cannon()
{

}