#include "testPlayer.h"

void initPlayer (PlAyEr &player, int Width, int Height)
{
	player.x = Width / 2;
	player.y = Height / 2;
	player.ID = PLAYER;
	player.speed = 5;
	player.boundx = 6;
	player.boundy = 7;
}

void drawPlayer (PlAyEr &player)
{
	al_draw_line(player.x, player.y, player.x, player.y - 20, al_map_rgb(0,255,0), 5);
}

void MovePlayerLeft(PlAyEr &player)
{
	player.x -= player.speed;
	if (player.x < 0)
		player.x = 0;
}
void MovePlayerUp(PlAyEr &player)
{
	player.y -= player.speed;
	if (player.y < 0)
		player.y = 0;
}
void MovePlayerDown(PlAyEr &player, int Height)
{
	player.y += player.speed;
	if (player.y > Height)
		player.y = Height;
}
void MovePlayerRight(PlAyEr &player, int Width)
{
	player.x += player.speed;
	if (player.x > Width)
		player.x = Width;
}