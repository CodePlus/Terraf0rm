#include "Hero.h"

Hero::Hero()
{

}
void Hero::InitHero(ALLEGRO_BITMAP *image, int Height, int Width)
{
	setHealth(50);
	setMana(100);

	Hero::image = image;

	GameObject::init((Width/2),(Height/2 + 300), 0, 0, 0, 0, 30, 30);

	setID(PLAYER);
	setSuitID(NonSuit);

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
	//Health Bar
	al_draw_filled_rectangle(0, height - 100, getHealth() * 5, height - 95, al_map_rgb(255,0,0));
	//Energy Bar
	if (getMana() > 0)
		al_draw_filled_rectangle(0, height - 90, getMana() * 2, height - 85, al_map_rgb(0,0,255));
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
	setVelY(5);
	dirY = -1;
}
void Hero::moveDown()
{
	animationRow = 3;
	setVelY(5);
	dirY = 1;
}
void Hero::moveLeft()
{
	animationRow = 1;
	setVelX(5);
	dirX = -1;
}
void Hero::moveRight()
{
	animationRow = 2;
	setVelX(5);
	dirX = 1;
}
Hero::~Hero()
{

}