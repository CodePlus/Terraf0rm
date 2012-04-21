#pragma once

#include "monster.h"

Monster::Monster()
{
	name = "MONSTER";

	attack = 1;
	range = 1;
}

Monster::~Monster()
{
}


void Monster::initMonster(ALLEGRO_BITMAP *image)
{
	setHealth(50);

	Monster::image = image;

	dirX = 1;
	dirY = 1;

	GameObject::init(sWIDTH / 2, sHEIGHT / 2, 1, 1, 0, 0, 10, 10);

	setID(ENEMY);

	setAlive(true);

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

void Monster::Update(int frameCount)
{
	move(frameCount);
}

void Monster::Destroy()
{
	GameObject::Destroy();
}

void Monster::Render(ALLEGRO_FONT *font, int xOff, int yOff)
{
	for(int i = 0; i < MAX_MONSTERS; i++)
	{
		if(getAlive())
		{
			al_draw_textf(font, al_map_rgb(0, 0, 0), x + xOff + 15, y + yOff + 35, ALLEGRO_ALIGN_CENTRE, "%s", name.c_str());

			al_draw_filled_rectangle(x + xOff, y + yOff, x + xOff + spriteSize, y + yOff + spriteSize, al_map_rgb(255, 0, 0));

			drawHealthBar(getHealth(), font, x + xOff, y + yOff);
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

