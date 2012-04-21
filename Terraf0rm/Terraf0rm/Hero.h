#pragma once
#include "CharacterSprite.h"

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
			void Render(int heroType);
			void Destroy();
			void Collide(int objectID);
			void moveUp();
			void moveDown();
			void moveLeft();
			void moveRight();

			void setSuitID (int suit) {mSuitID = suit;}
			int getSuitID() {return mSuitID;}
			void setLives (int newLives) {mLives = newLives;}
			int getLives() {return mLives;}

			~Hero();
	private:
		//Tests to see wether the Hero is in their suit or not
		int mSuitID;
		//AMount of lives the player has
		int mLives;
};