#pragma once
#include "ParticleGenerator.h"
#include "monster.h"

class DragonAttack : public ParticleGenerator
{
public:
	DragonAttack();
	void InitDragon(ALLEGRO_BITMAP *image);
	void Attack (Monster *Boss);
	void Update();
	void Render();
	void Collided(int objectID);
	~DragonAttack();
};