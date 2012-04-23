#include "GameObject.h"

GameObject::GameObject()
{
	x = 0;
	y = 0;

	velX = 0;
	velY = 0;

	dirX = 0;
	dirY = 0;

	boundX = 0;
	boundY = 0;

	maxFrame = 0;
	curFrame = 0;
	frameCount = 0;
	frameDelay = 0;
	frameWidth = 0;
	frameHeight = 0;
	animationColumns = 0;
	animationRow = 0;

	Direction = RIGHT;

	image = NULL;

	mIsAlive = true;
	mIsCollidable = true;
}

void GameObject::Destroy()
{
	if(image != NULL)
	{
		al_destroy_bitmap(image);
	}
}

void GameObject::init(float x, float y, float velX, float velY, int dirX, int dirY, int boundX, int boundY)
{
	GameObject::x = x;
	GameObject::y = y;

	GameObject::velX = velX;
	GameObject::velY = velY;

	GameObject::dirX = dirX;
	GameObject::dirY = dirY;

	GameObject::boundX = boundX;
	GameObject::boundY = boundY;
}

void GameObject::Update()
{
	x += velX * dirX;
	y += velY * dirY;
}
void GameObject::Render()
{

}
void GameObject::resetAnimation(int position)
{
	if (position == 1)
	{
		animationRow = 1;
		dirY = 0;
	}
	else 
	{
		curFrame = 0;
		dirX = 0;
	}
}

bool GameObject::checkCollisions(GameObject *OtherObject)
{
	float oX = OtherObject->getX();
	float oY = OtherObject->getY();

	int obX = OtherObject->getBoundX();
	int obY = OtherObject->getBoundY();

	if (x + boundX > oX - obX && x - boundX < oX + obX && y + boundY > oY - obY && y - boundY < oY + obY)
		return true;
	else
		return false;
}
void GameObject::Collided(int objectID)
{

}
bool GameObject::Collidable()
{
	return mIsAlive && mIsCollidable;
}