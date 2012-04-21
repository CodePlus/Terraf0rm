#include "Hero.h"

Hero::Hero()
{

}
void Hero::InitHero(ALLEGRO_BITMAP *image, int Height, int Width)
{
	setHealth(50);
	setMana(100);

	Hero::image = image;

	GameObject::init((Width/2),(Height/2), 5, 5, 0, 0, 10, 10);

	setID(PLAYER);
	setSuitID(NonSuit);

	setAlive(true);

	setDirection(DOWN);

	mLives = 3;
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
void Hero::Render(int heroType)
{
	int height = 0, width = 0, count = 0;
	width = widthHeight(0);
	height = widthHeight(1);
	if (heroType == Shooting)
	{
		switch (curFrame)
		{
		case 1: curFrame = 4;
			break;
		case 2: curFrame = 5;
			break;
		case 3: curFrame = 6;
			break;
		}
	}
	else if (heroType == Suit)
	{
		switch (curFrame)
		{
		case 4: curFrame = 1;
			break;
		case 5: curFrame = 2;
			break;
		case 6: curFrame = 3;
			break;
		}
	}

	CharacterSprite::Render();
	int fx = (curFrame % animationColumns * frameWidth);
	int fy = animationRow * frameHeight;

	al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - frameWidth / 2, y - frameHeight / 2, 0);
	//HUD
	//Health Bar
	al_draw_filled_rectangle(10, height - 100, getHealth() * 5, height - 95, al_map_rgb(255,0,0));
	//Energy Bar
	al_draw_filled_rectangle(10, height - 90, getMana() * 2, height - 85, al_map_rgb(0,0,255));
	//Amount of lives left
	while(count < getLives())
	{
		al_draw_filled_circle(((width - 20) - (count * 30)), 15, 5, al_map_rgb(255,0,0));
		count++;
	}
}
void Hero::Destroy()
{
	GameObject::Destroy();
}
void Hero::Collide(int objectID)
{
	if(objectID == BULLET)
		loseHealth();
	else if (objectID == ENEMY)
		loseHealth();
}
void Hero::moveUp()
{
	animationRow = 0;
	dirY = -1;
}
void Hero::moveDown()
{
	animationRow = 3;
	dirY = 1;
}
void Hero::moveLeft()
{
	animationRow = 1;
	dirX = -1;
}
void Hero::moveRight()
{
	animationRow = 2;
	dirX = 1;
}
Hero::~Hero()
{

}