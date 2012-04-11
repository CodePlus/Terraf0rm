/************************************************************************
*                     Headers go in this header file!!                  *
*************************************************************************/
#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

enum ID{PLAYER, ENEMY, BULLET};

enum KEYS {W, A, S, D, E, SPACE, ENTER};

//Function to initialize the display
void displaySet ();
//Function to set up the keyBoard
void keyboardSetUp();