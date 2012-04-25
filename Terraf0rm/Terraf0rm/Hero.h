#pragma once
#include "CharacterSprite.h"
#include "monster.h"

/*******************************************
*				Player Class			   *
*******************************************/

class Hero : public CharacterSprite
{
	#pragma message ("Hero Class is included")
	public:
			Hero();
			void InitHero(ALLEGRO_BITMAP *image);
			void Update();
			void Render();
			void Destroy();
			void Collided(int objectID);
			void moveUp();
			void moveDown();
			void moveLeft();
			void moveRight();

			void setHeroNumber (int number) {mHeroNumber = number;}
			int getHeroNumber() {return mHeroNumber;}

			~Hero();
	private:
		//Tests to see wether the Hero is in their suit or not
		int mHeroNumber;
};