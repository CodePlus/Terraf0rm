#include "CharacterSprite.h"

CharacterSprite::CharacterSprite()
{
		mHealth = 0;
		mMana = 0;
}
void CharacterSprite::Update()
{
	int WIDTH = 0, HEIGHT = 0;
	WIDTH = sWIDTH;
	HEIGHT = sHEIGHT;
	GameObject::Update();
	if(x <= 15)
		x = 15;
	else if (x >= WIDTH - 15)
		x = WIDTH;
	if (y <= 15)
		y = 15;
	else if (y >= HEIGHT - 15)
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
