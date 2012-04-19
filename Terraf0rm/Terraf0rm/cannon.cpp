#include "cannon.h"

Cannon::Cannon()
{

}

void Cannon::initCannon()
{
	setID(BULLET);
	setNumParticles(10);
	for (int i = 0; i < getNumParticles(); i++)
	{
		mBullets[i] = false;
		mBulletX[i] = 0;
		mBulletY[i] = 0;
		mBulletDirection[i] = 0;
		mBulletLength[i] = 0;
	}


	setRed(255);
	setGreen(255);
	setBlue(0);

	setSize(3);
	setLength(200);
	setWidth(1);
	setSpeed(10);
	setNumParticles(10);

	
	setCollideable(true);
}
void Cannon::fireCannon(Hero player)
{
	for(int i = 0; i < getNumParticles(); i++)
	{
		if(mBullets[i] == false)
		{
			mBulletX[i] = player.getX();
			mBulletY[i] = player.getY();
			mBullets[i] = true;
			mBulletDirection[i] = player.getDirection();
			switch (mBulletDirection[i])
			{
			case UP: 
					mBulletLength[i] = mBulletY[i] - getLength();
				break;
			case DOWN:
					mBulletLength[i] = mBulletY[i] + getLength();
				break;
			case LEFT:
					mBulletLength[i] = mBulletX[i] - getLength();
				break;
			case RIGHT:
					mBulletLength[i] = mBulletX[i] + getLength();
				break;

			}
			break;
		}
	}
}

void Cannon::Update()
{
	for(int i = 0; i < getNumParticles(); i++)
	{
		if(mBullets[i] == true)
		{
			switch (mBulletDirection[i])
			{
			case UP:mBulletY[i] -= getSpeed();
				if(mBulletY[i] < mBulletLength[i])
					mBullets[i] = false;
				break;
			case DOWN:mBulletY[i] += getSpeed();
				if(mBulletY[i] > mBulletLength[i])
					mBullets[i] = false;
				break;
			case LEFT:mBulletX[i] -= getSpeed();
				if(mBulletX[i] < mBulletLength[i])
					mBullets[i] = false;
				break;
			case RIGHT:mBulletX[i] += getSpeed();
				if(mBulletX[i] > mBulletLength[i])
					mBullets[i] = false;
				break;
			}
		}
	}
}
void Cannon::Render()
{
	for(int i = 0; i < getNumParticles(); i++)
	{
		if(mBullets[i] == true)
			al_draw_filled_circle(mBulletX[i], mBulletY[i], getSize(), al_map_rgb(getRed(),getGreen(),getBlue()));
	}
}
void Cannon::Collided(int objectID)
{

}

Cannon::~Cannon()
{

}