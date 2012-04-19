#pragma once
#include"ParticleGenerator.h"
#include "Hero.h"


/*****************************
*     Heroe's main shot      *
*****************************/

class Cannon : public ParticleGenerator
{
public:
		Cannon();
		void initCannon();
		void fireCannon(Hero player);

		void Update();
		void Render();
		void Collided(int objectID);

		~Cannon();

private:
		bool mBullets[10];
		int mBulletX[10];
		int mBulletY[10];
		int mBulletDirection[10];
		int mBulletLength[10];
};