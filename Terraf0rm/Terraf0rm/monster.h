#pragma once
#include "CharacterSprite.h"

class Monster : public CharacterSprite
{
	public:
		Monster();
		~Monster();

		void initMonster(int randMonster, ALLEGRO_FONT *Font, int width, int height);
	
		void setName(string nName);
		void setAttack(int nAttack);
		void setRange(int nRange);

		string getName();
		int getAttack();
		int getRange();

		void Render();

		void move(int frameCount);
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();

		void Collide(int objectID);

		void Update();
		void Destroy();

		void setXOff (int newXOff) {mXOff = newXOff;}
		void setYOff (int newYOff) {mYOff = newYOff;}

	protected:
		string name;

		int attack;
		int range;

		int direction;

	private:
		int mFrameCount;
		ALLEGRO_FONT *mFont;
		int mXOff;
		int mYOff;
		int mTotalHeight;
		int mTotalWidth;
};

void drawHealthBar(int health, ALLEGRO_FONT *font, int pos_x, int pos_y);