#include "CharacterSprite.h"

CharacterSprite::CharacterSprite()
{
		mHealth = 0;
		mMana = 0;
}
void CharacterSprite::Update()
{
	int WIDTH = 0, HEIGHT = 0;
	WIDTH = widthHeight(0);
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

}

void CharacterSprite::Collide(int objectID)
{

}
CharacterSprite::~CharacterSprite()
{

}
