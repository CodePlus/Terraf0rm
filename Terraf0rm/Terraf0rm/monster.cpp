#pragma once

#include "monster.h"

Monster::Monster()
{
	mXOff = 0;
	mYOff = 0;
	attack = 1;
	range = 1;
	mFrameCount = 0;
	mTotalHeight = 0;
	mTotalWidth = 0;
}

Monster::~Monster()
{
}


void Monster::initMonster(int randMonster, ALLEGRO_FONT *Font, int width, int height)
{
	ALLEGRO_BITMAP *image = NULL; 
	mTotalHeight = height;
	mTotalWidth = width;
	setHealth(100);

	if(randMonster == 0)
	{
		name = "CROCODILE";

		image = al_load_bitmap("art bitmaps/Monster/monster1.bmp");
		
		maxFrame = 4;
		animationColumns = 4;
		animationRow = 0;
	}

	else if(randMonster == 1)
	{
		name = "SKELETON";
			
		image = al_load_bitmap("art bitmaps/Monster/monster2.bmp");
		
		maxFrame = 4;
		animationColumns = 4;
		animationRow = 0;
	}

	else if(randMonster == 2)
	{
		name = "Monster3";
		
		image = al_load_bitmap("art bitmaps/Monster/monster3.bmp");

		maxFrame = 4;
		animationColumns = 4;
		animationRow = 0;
	}

	al_convert_mask_to_alpha(image, al_map_rgb(255, 0, 255));

	Monster::image = image;

	dirX = 1;
	dirY = 1;

	x = (mTotalWidth/4) + rand() % 700;
	if(x < (mTotalWidth / 4) + 15)
		x = (mTotalWidth / 4) + 15;
	if (x > ((mTotalWidth / 4) + sWIDTH) - 15)
		x = ((mTotalWidth / 4) + sWIDTH) - 15;
	y = (mTotalHeight/8) +rand() % 700;
	if(y < (mTotalHeight / 8) - 15)
		x = (mTotalHeight / 8) - 15;
	if (x > ((mTotalHeight / 8) + sHEIGHT) + 15)
		x = ((mTotalHeight / 8) + sHEIGHT) + 15;

	GameObject::init(x,y, 1, 1, 0, 0, 20, 20);
	mFont = Font;
	setID(ENEMY);

	setAlive(true);
	setCollideable(true);

	curFrame = 0;

	frameWidth = spriteSize;
	frameHeight = spriteSize;
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

void Monster::Collided(int objectID)
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

	if(++frameCount >= frameDelay + 10)
	{
		if(++curFrame >= maxFrame)
		{
			curFrame = 0;
		}

		frameCount = 0;
	}
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
			al_draw_textf(mFont, al_map_rgb(0, 0, 0), x + 15, y + 35, ALLEGRO_ALIGN_CENTRE, "%s", name.c_str());

			if(direction == W)
			{
				al_draw_bitmap_region(Monster::image, curFrame * frameWidth, 0, spriteSize, spriteSize, x, y, 0);
			}

			else if(direction == A)
			{
				al_draw_bitmap_region(Monster::image, curFrame * frameWidth, spriteSize * 2, spriteSize, spriteSize, x, y, 0);
			}

			else if(direction == S)
			{
				al_draw_bitmap_region(Monster::image, curFrame * frameWidth, spriteSize * 1, spriteSize, spriteSize, x, y, 0);
			}

			else if(direction == D)
			{
				al_draw_bitmap_region(Monster::image, curFrame * frameWidth, spriteSize * 3, spriteSize, spriteSize, x, y, 0);
			}

			else if(direction == 4)
			{
				al_draw_bitmap_region(Monster::image, curFrame * frameWidth, spriteSize, spriteSize, spriteSize, x, y, 0);
			}

			drawHealthBar(getHealth(), mFont, x, y);
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
	if(y <= 0 + 15  + (mTotalHeight / 8))
	{
	}

	else
	{
		y -= velY;
	}
}

void Monster::moveDown()
{
	if(y >=  (mTotalHeight / 8) + sHEIGHT - spriteSize - 15)
	{
	}
	
	else
	{
		y += velY;
	}
}

void Monster::moveLeft()
{
	if(x <= 0 + 15 + (mTotalWidth / 4))
	{
	}
	
	else
	{
		x -= velX;
	}
}

void Monster::moveRight()
{
	if(x >= (mTotalWidth / 4) + sWIDTH - spriteSize - 15 )
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

