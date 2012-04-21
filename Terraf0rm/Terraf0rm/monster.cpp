#pragma once

#include "monster.h"

Monster::Monster()
{
	name = "MONSTER";

	health = 100;
	attack = 1;
	range = 1;

	pos_x = rand() % sWIDTH + 15;
	pos_y = rand() % sHEIGHT + 15;
	direction = rand() % 5;

	bound_x = 30;
	bound_y = 30;

	speed = 1;

	alive = true;
}

Monster::~Monster()
{
}

void Monster::setName(string nName)
{
	name = nName;
}

void Monster::setHealth(int nHealth)
{
	health = nHealth;
}

void Monster::setAttack(int nAttack)
{
	attack = nAttack;
}

void Monster::setRange(int nRange)
{
	range = nRange;
}

void Monster::setPos_x(int nPos_x)
{
	pos_x = nPos_x;
}

void Monster::setPos_y(int nPos_y)
{
	pos_y = nPos_y;
}

void Monster::setBound_x(int nBound_x)
{
	bound_x = nBound_x;
}

void Monster::setBound_y(int nBound_y)
{
	bound_y = nBound_y;
}

void Monster::setSpeed(int nSpeed)
{
	speed = nSpeed;
}

void Monster::setAlive(bool nAlive)
{
	alive = nAlive;
}

string Monster::getName()
{
	return name;
}

int Monster::getHealth()
{
	return health;
}

int Monster::getAttack()
{
	return attack;
}

int Monster::getRange()
{
	return range;
}

int Monster::getPos_x()
{
	return pos_x;
}

int Monster::getPos_y()
{
	return pos_y;
}

int Monster::getBound_x()
{
	return bound_x;
}

int Monster::getBound_y()
{
	return bound_y;
}

int Monster::getSpeed()
{
	return speed;
}

bool Monster::getAlive()
{
	return alive;
}

void Monster::drawMonster(ALLEGRO_FONT *font, int xOff, int yOff)
{
	for(int i = 0; i < MAX_MONSTERS; i++)
	{
		if(alive)
		{
			al_draw_textf(font, al_map_rgb(0, 0, 0), pos_x + xOff + 15, pos_y + yOff + 35, ALLEGRO_ALIGN_CENTRE, "%s", name.c_str());

			al_draw_filled_rectangle(pos_x + xOff, pos_y + yOff, pos_x + xOff + spriteSize, pos_y + yOff + spriteSize, al_map_rgb(255, 0, 0));

			drawHealthBar(health, font, pos_x + xOff, pos_y + yOff);
		}
	}
}

void Monster::move(int frameCount)
{
	if((frameCount % 60) == 0)
	{
		direction = rand() % 5;
	}

	if(direction == W)
	{
		if((frameCount % 60) != 0)
		{
			moveUp();
		}
	}

	else if(direction == A)
	{
		if((frameCount % 60) != 0)
		{
			moveLeft();
		}
	}

	else if(direction == S)
	{
		if((frameCount % 60) != 0)
		{
			moveDown();
		}
	}

	else if(direction == D)
	{
		if((frameCount % 60) != 0)
		{
			moveRight();
		}
	}
}

void Monster::moveUp()
{
	if(pos_y <= 0 + 15)
	{
	}

	else
	{
		pos_y -= speed;
	}
}

void Monster::moveDown()
{
	if(pos_y >= sHEIGHT - spriteSize - 15)
	{
	}
	
	else
	{
		pos_y += speed;
	}
}

void Monster::moveLeft()
{
	if(pos_x <= 0 + 15)
	{
	}
	
	else
	{
		pos_x -= speed;
	}
}

void Monster::moveRight()
{
	if(pos_x >= sWIDTH - spriteSize - 15)
	{
	}
	
	else
	{
		pos_x += speed;
	}
}

void drawHealthBar(int health, ALLEGRO_FONT *font, int pos_x, int pos_y)
{
	//Health bar
	al_draw_rectangle(pos_x - 10, pos_y - 5, pos_x + 41, pos_y - 9, al_map_rgb(0, 0, 0), 1);

	if((health <= 100) && (health > 75))
	{
		al_draw_filled_rectangle(pos_x - 10, pos_y - 6, pos_x - 10 + (health) / 2, pos_y - 9, al_map_rgb(0, 255, 0));
	}

	else if((health <= 75) && (health > 25))
	{
		al_draw_filled_rectangle(pos_x - 10, pos_y - 6, pos_x -10 + (health) / 2, pos_y - 9, al_map_rgb(255, 255, 0));
	}

	else if((health <= 25) && (health >= 0))
	{
		al_draw_filled_rectangle(pos_x - 10 , pos_y - 6, pos_x - 10 + (health) / 2, pos_y - 9, al_map_rgb(255, 0, 0));
	}
}

