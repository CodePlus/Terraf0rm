#pragma once
#include "assembly.h"

class Monster
{
	public:
		Monster();
		~Monster();
	
		void setName(string nName);
		void setHealth(int nHealth);
		void setAttack(int nAttack);
		void setRange(int nRange);
		void setPos_x(int nPos_x);
		void setPos_y(int nPos_y);
		void setBound_x(int nBound_x);
		void setBound_y(int nBound_y);
		void setSpeed(int nSpeed);
		void setAlive(bool nAlive);

		string getName();
		int getHealth();
		int getAttack();
		int getRange();
		int getPos_x();
		int getPos_y();
		int getBound_x();
		int getBound_y();
		int getSpeed();
		bool getAlive();

		void drawMonster(ALLEGRO_FONT *font, int xOff, int yOff);

		void move(int frameCount);
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();

	protected:
		string name;

		int health;
		int attack;
		int range;

		int pos_x;
		int pos_y;
		int direction;

		int bound_x;
		int bound_y;

		int speed;

		bool alive;
};

void drawHealthBar(int health, ALLEGRO_FONT *font, int pos_x, int pos_y);