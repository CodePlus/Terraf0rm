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
}PlAyEr;

void initPlayer (PlAyEr &player, int Width, int Height);
void drawPlayer (PlAyEr &player);
void MovePlayerLeft(PlAyEr &player);
void MovePlayerUp(PlAyEr &player);
void MovePlayerDown(PlAyEr &player, int Height);
void MovePlayerRight(PlAyEr &player, int Width);