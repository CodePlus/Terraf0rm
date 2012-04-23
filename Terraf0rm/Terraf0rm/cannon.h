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
		void fireCannon(Hero *player);

		void Update();
		void Render();
		void Collided(int objectID);

		~Cannon();
};