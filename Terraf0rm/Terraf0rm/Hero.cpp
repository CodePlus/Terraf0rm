#include "Hero.h"

Hero::Hero()
{

}
void Hero::InitHero(ALLEGRO_BITMAP *image)
{
	setHealth(50);
	setMana(100);

	GameObject::init((mTotalWidth/2),(mTotalHeight/2 + 300), 0, 0, 0, 0, 10, 10);

	setID(PLAYER);
	setHeroNumber(0);

	setAlive(true);
	setCollideable(true);
	setDirection(DOWN);

	maxFrame = 5;
	curFrame = 1;
	frameWidth = 30;
	frameHeight = 30;
	animationColumns = 3;
	animationRow = 4;

	if (image != NULL)
		Hero::image = image;

}
void Hero::Update()
{
	CharacterSprite::Update();
}
void Hero::Render()
{
	int height = 0, width = 0, count = 0;
	width = widthHeight(0);
	height = widthHeight(1);

	CharacterSprite::Render();
	int fx = (curFrame % animationColumns * frameWidth);
	int fy = animationRow * frameHeight;

	al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - frameWidth / 2, y - frameHeight / 2, 0);
	//HUD
	if(mHeroNumber == 0)
	{
		//Health Bar
		al_draw_filled_rectangle(0, height - 100, getHealth() * 5, height - 95, al_map_rgb(255,0,0));
		//Energy Bar
		if (getMana() > 0)
			al_draw_filled_rectangle(0, height - 90, getMana() * 2, height - 85, al_map_rgb(0,0,255));
	}
	else if (mHeroNumber == 1)
	{
		//Health Bar
		al_draw_filled_rectangle(width, height - 100, width - (getHealth() * 5), height - 95, al_map_rgb(255,0,0));
		//Energy Bar
		if (getMana() > 0)
			al_draw_filled_rectangle(width, height - 90, width - (getMana() * 2), height - 85, al_map_rgb(0,0,255));
	}
}
void Hero::Destroy()
{
	GameObject::Destroy();
}
void Hero::Collided(int objectID)
{
	/*if(objectID == BULLET)
		loseHealth();*/
	if (objectID == ENEMY || objectID == DRAGON)
	{
		loseHealth();
		if(getHealth() <= 0)
			setAlive(false);
	}
}
void Hero::moveUp()
{
	if(y <= 0 + 15  + (mTotalHeight / 8))
	{
	}

	else
	{
		animationRow = 0;
		setVelY(5);
		dirY = -1;
	}
}
void Hero::moveDown()
{
	if(y >=  (mTotalHeight / 8) + sHEIGHT)
	{
	}
	
	else
	{
		animationRow = 3;
		setVelY(5);
		dirY = 1;
	}
}
void Hero::moveLeft()
{
	if(x <= 0 + 15 + (mTotalWidth / 4))
	{
	}
	
	else
	{
		animationRow = 1;
		setVelX(5);
		dirX = -1;
	}
}
void Hero::moveRight()
{
	if(x >= (mTotalWidth / 4) + sWIDTH)
	{
	}
	
	else
	{
		animationRow = 2;
		setVelX(5);
		dirX = 1;
	}
	
}
Hero::~Hero()
{

}