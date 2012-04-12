#include "testPlayer.h"

void initPlayer (PlAyEr &player, int Width, int Height)
{
	player.x = Width / 2;
	player.y = Height / 2;
	player.ID = PLAYER;
	player.speed = 5;
	player.boundx = 6;
	player.boundy = 7;
	player.direction = RIGHT;
}

void drawPlayer (PlAyEr &player)
{
	al_draw_line(player.x, player.y, player.x, player.y - 20, al_map_rgb(0,255,0), 5);
}

void MovePlayerLeft(PlAyEr &player)
{
	player.x -= player.speed;
	player.direction = LEFT;
	if (player.x < 0)
		player.x = 0;
}
void MovePlayerUp(PlAyEr &player)
{
	player.y -= player.speed;
	player.direction = UP;
	if (player.y < 0)
		player.y = 0;
}
void MovePlayerDown(PlAyEr &player, int Height)
{
	player.y += player.speed;
	player.direction = DOWN;
	if (player.y > Height)
		player.y = Height;
}
void MovePlayerRight(PlAyEr &player, int Width)
{
	player.x += player.speed;
	player.direction = RIGHT;
	if (player.x > Width)
		player.x = Width;
}

//Shoot

void initShot(BusterCannon shot[], int size)
{
	for(int i = 0; i < size; i++)
	{
		shot[i].ID = BULLET;
		shot[i].speed = 10;
		shot[i].live = false;
	}
}
void drawShot(BusterCannon shot[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(shot[i].live)
			al_draw_filled_circle(shot[i].x, shot[i].y, 2, al_map_rgb(0,0,255));
	}
}
void fireShot(BusterCannon shot[], int size, PlAyEr &player)
{
	for(int i = 0; i < size; i++)
	{
		if(!shot[i].live)
		{
			shot[i].x = player.x;
			shot[i].y = player.y;
			shot[i].live = true;
			shot[i].direction = player.direction;
			break;
		}
	}
}
void updateShot(BusterCannon shot[], int size, int Height, int Width)
{
	for(int i = 0; i < size; i++)
	{
		if(shot[i].live)
		{
			switch (shot[i].direction)
			{
			case UP:shot[i].y -= shot[i].speed;
				if(shot[i].y < 0)
					shot[i].live = false;
				break;
			case DOWN:shot[i].y += shot[i].speed;
				if(shot[i].y > Height)
					shot[i].live = false;
				break;
			case LEFT:shot[i].x -= shot[i].speed;
				if(shot[i].x < 0)
					shot[i].live = false;
				break;
			case RIGHT:shot[i].x += shot[i].speed;
				if(shot[i].x > Width)
					shot[i].live = false;
				break;
			}
		}
	}
}