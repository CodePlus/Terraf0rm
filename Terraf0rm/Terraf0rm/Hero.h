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
			void InitHero(ALLEGRO_BITMAP *image, int Height, int Width);
			void Update();
			void Render();
			void Destroy();
			void Collide(int objectID);
			void moveUp();
			void moveDown();
			void moveLeft();
			void moveRight();

			void setSuitID (int suit) {mSuitID = suit;}
			int getSuitID() {return mSuitID;}

			~Hero();
	private:
		//Tests to see wether the Hero is in their suit or not
		int mSuitID;
};