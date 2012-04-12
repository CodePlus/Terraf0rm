#pragma once
#include "assembly.h"
/**********************
*   My Test Player    *
***********************/

typedef struct PLAYER
{
	int ID;
	int x;
	int y;
	int speed;
	int boundx;
	int boundy;
	int direction;
}PlAyEr;

void initPlayer (PlAyEr &player, int Width, int Height);
void drawPlayer (PlAyEr &player);
void MovePlayerLeft(PlAyEr &player);
void MovePlayerUp(PlAyEr &player);
void MovePlayerDown(PlAyEr &player, int Height);
void MovePlayerRight(PlAyEr &player, int Width);

typedef struct BUSTERCANNON
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;
	int direction;
}BusterCannon;

void initShot(BusterCannon shot[], int size);
void drawShot(BusterCannon shot[], int size);
void fireShot(BusterCannon shot[], int size, PlAyEr &player);
void updateShot(BusterCannon shot[], int size, int Height, int Width);