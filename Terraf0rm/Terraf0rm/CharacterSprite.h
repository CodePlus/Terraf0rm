#pragma once
#include "GameObject.h"

/***************************
*  Character Sprite Class  *
*                          *
* ~Characters can be NPC~  *
***************************/

class CharacterSprite : public GameObject
{
public:
		CharacterSprite();

		void Update();
		void Render();
		void Destroy();

		int getHealth() {return mHealth;}
		void setHealth(int newHealth) {mHealth = newHealth;}

		void loseHealth() {mHealth--;}
		void useMana() {mMana--;}

		int getMana() {return mMana;}
		void setMana (int newMana) {mMana = newMana;}

		int getAnimationRow() {return mAnimationRow;}
		void setAnimationRow(int newAnimationRow) {mAnimationRow = newAnimationRow;}
		void resetAnimation(int position);

		void virtual Collide(int objectID);

		~CharacterSprite();

private:	
		//Health Points
		int mHealth;
		//Energy Points (Mana xP)
		int mMana;
		//The Row to animate on the Bitmap
		int mAnimationRow;
};