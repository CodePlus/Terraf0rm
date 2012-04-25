#include "DragonAttack.h"

DragonAttack::DragonAttack()
{

}
void DragonAttack::InitDragon()
{
	GameObject::init(0,0,10,10,0,0,3,3);
	setID(ENEMY);
	setAlive(false);
	setCollideable(true);
	setDirection(DOWN);
	
	setRed(178);
	setGreen(34);
	setBlue(34);

	setSize(20);
	setSpeed(15);
}
void DragonAttack::Attack (Monster *Boss)
{
	setAlive(true);
	setX(Boss->getX());
	setY(Boss->getY());
	setDirection(Boss->getDirection());
}
void DragonAttack::Update()
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
		Collided(PLAYER);
	else if(y <= 0 + 15  + (mTotalHeight / 8))
		Collided(PLAYER);
	if(x <= 0 + 15 + (mTotalWidth / 4))
		Collided(PLAYER);
	else if(x >= (mTotalWidth / 4) + sWIDTH - 15 )
		Collided(PLAYER);
}
void DragonAttack::Render()
{
	al_draw_filled_rectangle(x, y, x + getSize(), y + getSize(), al_map_rgb(getRed(), getGreen(), getBlue()));
}
void DragonAttack::Collided(int objectID)
{
	if(objectID == PLAYER)
		setAlive(false);
}
DragonAttack::~DragonAttack()
{

}