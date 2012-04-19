#include "assembly.h"
#include "GameObject.h"
#include "CharacterSprite.h"
#include "cannon.h"
#include "Hero.h"


int main (int argc, char **argv)
{
	/*******************************
	*	  GameEngine Variables     *
	*******************************/
	//Check for when the game engine has completed running
	bool gameComplete = false;
	//Initalize the width and height Variables of the monitor
	int Width = 0, Height = 0, FrameSmoother = 1;
	//Set The Frames Per Second to smooth out and standardize the gameplay
	const int FPS = 60;
	//Check to see if we should redraw the Display
	bool redraw = true;
	//Keybord Keys to press
	bool key[7] = {false};

	int Frame = 1;

	int xOff = 0;
	int yOff = 0;

	int mapColumns = 25;
	int mapSize = 625;
	int tileSize = 30;

	int map[] = {5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
				 5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,};

	/******************************
	*      Object Variables       *
	******************************/
	//Test Player
	Hero player;
	Cannon buster;

	/******************************
	*     Allegro Variables       *
	******************************/
	//Initializing the event queue that deals with all the Events taking place in the game
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	//Allegro Timer to set the Frames Per Second
	ALLEGRO_TIMER *timer = NULL;
	//Display Variable
	ALLEGRO_DISPLAY *display = NULL;
	//Map Sprite
	ALLEGRO_BITMAP *mapSprite = NULL;
	//Player Bitmap
	ALLEGRO_BITMAP *playerSprite = NULL;

	/******************************
	*  Initialization Functions   *
	******************************/
	//Initailizes Allegro
	if(!al_init())
		return -1;
	//Gains the Monitors Correct Width and Height
	Width = widthHeight(0);
	Height = widthHeight(1);
	//Initializes the display set up
	displaySet(Width, Height, display);
	//Creates event the Queue
	event_queue = al_create_event_queue();
	//Creates the timer
	timer = al_create_timer(1.0/FPS);

	/******************************
	*      Allegro Installs       *
	******************************/
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	/******************************************************
	*     Sprite Loading Area  &  Charactor Initalization *
	******************************************************/

	mapSprite = al_load_bitmap("art bitmaps/tiles.png");
	playerSprite = al_load_bitmap("art bitmaps/Character bitmaps/Main character/main_character.bmp");
	al_convert_mask_to_alpha(playerSprite, al_map_rgb(255,0,255));

		//Initialize Test Player
	player.InitHero(playerSprite, Height, Width);
	buster.initCannon();

	/******************************
	* Allegro EVENT_QUEUE Sources *
	******************************/
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	/****************************
	*     Game Engine Loop      *
	****************************/
	al_start_timer(timer);
	while(!gameComplete)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		//Fires off the computing and draws 60 times every second
		if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			/***********************
			*  Keyboard Detection  *
			***********************/
			
			if(key[W])
			{
				player.setDirection(UP);
				player.moveUp();
				if (FrameSmoother % 10 == 0)
			{
				if (Frame > 3)
					Frame = 1;
				player.setcurFrame(Frame);
				Frame++;
				FrameSmoother = 1;
			}
			else
				FrameSmoother++;
			}
			if(key[S])
			{
			player.setDirection(DOWN);
			player.moveDown();
			if (FrameSmoother % 10 == 0)
			{
				if (Frame > 3)
					Frame = 1;
				player.setcurFrame(Frame);
				Frame++;
				FrameSmoother = 1;
			}
			else
				FrameSmoother++;
			}
			if(key[A])
			{
				player.setDirection(LEFT);
				player.moveLeft();
				if (FrameSmoother % 10 == 0)
				{
					if (Frame > 3)
						Frame = 1;
					player.setcurFrame(Frame);
					Frame++;
					FrameSmoother = 1;
				}
			else
				FrameSmoother++;
			}
			if(key[D])
			{
				player.setDirection(RIGHT);
				player.moveRight();
				if (FrameSmoother % 10 == 0)
				{
					if (Frame > 3)
						Frame = 1;
					player.setcurFrame(Frame);
					Frame++;
					FrameSmoother = 1;
				}
			else
				FrameSmoother++;
			}
			if(key[ENTER])
				gameComplete = true;

				

			/***********************
			*   Update Stuff Here  *
			***********************/
			xOff -= key[D] * 5;
			xOff += key[A] * 5;
			yOff -= key[S] * 5;
			yOff += key[W] * 5;

			redraw = true;
			buster.Update();
		}
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				key[W] = true;
				break;
			case ALLEGRO_KEY_A:
				key[A] = true;
				break;
			case ALLEGRO_KEY_S:
				key[S] = true;
				break;
			case ALLEGRO_KEY_D:
				key[D] = true;
				break;
			case ALLEGRO_KEY_E:
				key[E] = true;
				break;
			case ALLEGRO_KEY_ENTER:
				key[ENTER] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				key[SPACE] = true;
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				key[W] = false;
				break;
			case ALLEGRO_KEY_A:
				key[A] = false;
				break;
			case ALLEGRO_KEY_S:
				key[S] = false;
				break;
			case ALLEGRO_KEY_D:
				key[D] = false;
				break;
			case ALLEGRO_KEY_E:
				key[E] = false;
				break;
			case ALLEGRO_KEY_ENTER:
				key[ENTER] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				key[SPACE] = false;
				buster.fireCannon(player);
				break;
			}
			player.setcurFrame(0);
		}
		if (redraw && al_is_event_queue_empty(event_queue))
		{
			for(int i = 0; i < mapSize; i++)
			{
				al_draw_bitmap_region(mapSprite, tileSize * map[i], 0, tileSize, tileSize, xOff + tileSize * (i % mapColumns), yOff + tileSize * (i / mapColumns), 0);
			}
			//Set redraw it false since we're about to draw to screen
			redraw = false;
			//Draws Player on the preFlipped Display
			player.Render(player.getSuitID());
			//Draw the bullet if its live
			buster.Render();
			//Sends the changes to the screen
			al_flip_display();
			//Changes the color of the game window that's not flipped
			al_clear_to_color(al_map_rgb(0,0,0));
		}
	}

	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_bitmap(mapSprite);

	return 0;
}