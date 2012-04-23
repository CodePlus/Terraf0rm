#pragma once

#include "monster.h"

Monster::Monster()
{
	name = "MONSTER";
	mXOff = 0;
	mYOff = 0;
	attack = 1;
	range = 1;
	mFrameCount = 0;
}

Monster::~Monster()
{
}


void Monster::initMonster(ALLEGRO_BITMAP *image, ALLEGRO_FONT *Font)
{
	setHealth(50);

	Monster::image = image;

	dirX = 1;
	dirY = 1;

	GameObject::init(sWIDTH / 2, sHEIGHT / 2, 1, 1, 0, 0, 30, 30);
	mFont = Font;
	setID(ENEMY);

	setAlive(true);
	setCollideable(true);
	//setDirection(rand() % 4);

	maxFrame = 0;
	curFrame = 0;
	frameWidth = spriteSize;
	frameHeight = spriteSize;
	animationColumns = 0;
	animationRow = 0;

	if(image != NULL)
	{
		Monster::image = image;
	}
}

void Monster::setName(string nName)
{
	name = nName;
}

void Monster::setAttack(int nAttack)
{
	attack = nAttack;
}

void Monster::setRange(int nRange)
{
	range = nRange;
}


string Monster::getName()
{
	return name;
}

int Monster::getAttack()
{
	return attack;
}

int Monster::getRange()
{
	return range;
}

void Monster::Collide(int objectID)
{
	if(objectID == BULLET)
	{
		loseHealth();
	}
}

void Monster::Update()
{
	move(mFrameCount);
	mFrameCount++;
}

void Monster::Destroy()
{
	GameObject::Destroy();
}

void Monster::Render()
{
	for(int i = 0; i < MAX_MONSTERS; i++)
	{
		if(getAlive())
		{
			al_draw_textf(mFont, al_map_rgb(0, 0, 0), x + mXOff + 15, y + mYOff + 35, ALLEGRO_ALIGN_CENTRE, "%s", name.c_str());

			al_draw_filled_rectangle(x + mXOff, y + mYOff, x + mXOff + spriteSize, y + mYOff + spriteSize, al_map_rgb(255, 0, 0));

			drawHealthBar(getHealth(), mFont, x + mXOff, y + mYOff);
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

	else
	{
	}
}

void Monster::moveUp()
{
	if(y <= 0 + 15)
	{
	}

	else
	{
		y -= velY;
	}
}

void Monster::moveDown()
{
	if(y >= sHEIGHT - spriteSize - 15)
	{
	}
	
	else
	{
		y += velY;
	}
}

void Monster::moveLeft()
{
	if(x <= 0 + 15)
	{
	}
	
	else
	{
		x -= velX;
	}
}

void Monster::moveRight()
{
	if(x >= sWIDTH - spriteSize - 15)
	{
	}
	
	else
	{
		x += velX;
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

