#pragma once
#include "CharacterSprite.h"

class Monster : public CharacterSprite
{
	public:
		Monster();
		~Monster();

		void initMonster(ALLEGRO_BITMAP *image);
	
		void setName(string nName);
		void setAttack(int nAttack);
		void setRange(int nRange);

		string getName();
		int getAttack();
		int getRange();

		void Render(ALLEGRO_FONT *font, int xOff, int yOff);

		void move(int frameCount);
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();

		void Collide(int objectID);

		void Update(int frameCount);
		void Destroy();

	protected:
		string name;

		int attack;
		int range;

		int direction;
};

void drawHealthBar(int health, ALLEGRO_FONT *font, int pos_x, int pos_y);