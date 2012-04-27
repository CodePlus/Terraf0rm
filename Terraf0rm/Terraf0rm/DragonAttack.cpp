#include "DragonAttack.h"

DragonAttack::DragonAttack()
{

}
void DragonAttack::InitDragon(ALLEGRO_BITMAP *image)
{
	GameObject::init(0,0,10,10,0,0,3,3);
	setID(FIREBALL);
	setAlive(false);
	setCollideable(true);
	setDirection(DOWN);
	
	maxFrame = 4;
	curFrame = 1;
	frameWidth = 16;
	frameHeight = 16;
	animationColumns = 4;
	animationRow = 0;
	mFrameSmoother = 1;

	setSize(20);
	setSpeed(15);

	if(image != NULL)
		GameObject::image = image;
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
	GameObject::Render();
	int fx = (curFrame % animationColumns * frameWidth);
	int fy = animationRow * frameHeight;

	al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - frameWidth / 2, y - frameHeight / 2, 0);
	if (mFrameSmoother % 10 == 0)
	{
		if (curFrame > 3)
			curFrame = 1;
		curFrame++;
		mFrameSmoother = 1;
	}
	else
		mFrameSmoother++;
}
void DragonAttack::Collided(int objectID)
{
	if(objectID == PLAYER)
		setAlive(false);
}
DragonAttack::~DragonAttack()
{

}