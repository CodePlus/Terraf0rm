#include "CharacterSprite.h"

CharacterSprite::CharacterSprite()
{
		mHealth = 0;
		mMana = 0;
}
void CharacterSprite::Update()
{
	GameObject::Update();
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
