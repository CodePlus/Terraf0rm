#pragma once
#include "GameObject.h"

/***************************
*  Character Sprite Class  *
*                          *
* ~Characters can be NPC~  *
***************************/

class CharacterSprite : public GameObject
{
	#pragma message ("CharacterSprite Class is included")
public:
		CharacterSprite();

		void Update();
		void Render();
		void Destroy();

		int getHealth() {return mHealth;}
		void setHealth(int newHealth) {mHealth = newHealth;}

		void loseHealth() {mHealth -= 10;}
		void useMana() {mMana -= 2;}

		int getMana() {return mMana;}
		void setMana (int newMana) {mMana = newMana;}

		void virtual Collide(int objectID);

		~CharacterSprite();

private:	
		//Health Points
		int mHealth;
		//Energy Points (Mana xP)
		int mMana;
};