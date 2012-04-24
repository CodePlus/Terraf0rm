/************************************************************************
*                     Headers go in this header file!!                  *
*************************************************************************/
#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <list>

#include <string>

using namespace std;

#define sWIDTH 720
#define sHEIGHT 720
#define spriteSize 30
#define MAX_MONSTERS 10
#define MAX_CANNON_PARTICLES 10

enum ID{PLAYER, ENEMY, BULLET};

enum heroID {NonSuit, Suit, Shooting};

enum KEYS {W, A, S, D, E, SPACE, ENTER};

enum DIRECTION {UP, DOWN, LEFT, RIGHT};

enum GAMESTATE {TITLE, PLAY, DEAD};

//Function that Reads the width and height
int widthHeight (int variable);
//Function to initialize the display
void displaySet (int width, int height, ALLEGRO_DISPLAY *display);
//Function to set up the keyBoard
void keyboardUse(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_EVENT ev);

