#include "CharacterSprite.h"

CharacterSprite::CharacterSprite()
{

}
void CharacterSprite::Update()
{
	int WIDTH = 0, HEIGHT = 0;
	Width = widthHeight(0);
	HEIGHT = widthHeight(1);
	GameObject::Update();
	if(x < 0)
		x = 0;
	else if (x > WIDTH)
		x = WIDTH;
	if (y < 0)
		y = 0;
	else if (y > HEIGHT)
		y = HEIGHT;
}
void CharacterSprite::Render()
{
	GameObject::Render();
}

void CharacterSprite::Destroy()
{
	GameObject::Destroy();

	int fx = (curFrame % animationColumns * frameWidth;
	int fy = animationRow * frameHeight;

	al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - frameWidth / 2, y - frameHeight / 2);
}

void CharacterSprite::resetAnimation(int position)
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

void CharacterSprite::Collide(int objectID)
{

}
CharacterSprite::~CharacterSprite()
{

}
