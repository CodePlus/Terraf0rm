#include "assembly.h"
#include "GameObject.h"
#include "CharacterSprite.h"
#include "cannon.h"
#include "Hero.h"
#include "monster.h"

/***********************
*  Obect Declerations  *
***********************/
Hero *player;
Monster *monster[MAX_MONSTERS];
std::list<GameObject *> objects;
std::list<GameObject *>::iterator iter;
std::list<GameObject *>::iterator iter2;

int main (int argc, char **argv)
{
	srand(time(NULL));
	/*********************
	*  Global Variables  *
	*********************/
	bool gameComplete = false;
	int Width = 0, Height = 0, FrameSmoother = 1;
	const int FPS = 60;
	bool redraw = true;
	bool key[7] = {false};
	int Frame = 1;
	int EnergyRegen = 0;
	/******************
	*  Map Variables  *
	******************/
	int xOff = 0;
	int yOff = 0;

	int mapColumns = 25;
	int mapSize = 625;
	int tileSize = 30;

	int map[] = {5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,6,
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
				 8,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,};


	/**********************
	*  Allegro Variables  *
	**********************/
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *mapSprite = NULL;
	ALLEGRO_BITMAP *playerSprite = NULL;
	ALLEGRO_FONT *font10;
	

	/**************************************
	*  Initialize Allegro and components  *
	**************************************/
	if(!al_init())
		return -1;
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0/FPS);

	al_install_keyboard();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	Width = widthHeight(0);
	Height = widthHeight(1);

	displaySet(Width, Height, display);

	/***************************************
	*  Load The Images and Set The Alphas  *
	***************************************/

	mapSprite = al_load_bitmap("art bitmaps/tiles.png");

	playerSprite = al_load_bitmap("art bitmaps/Character bitmaps/Main character/main_character_shooting.bmp");

	al_convert_mask_to_alpha(playerSprite, al_map_rgb(255,0,255));

	font10 = al_load_font("fonts/arial.ttf", 10, 0);

	/**************************
	*  Object Initialization  *
	***************************/
	//First Allocate Memory Space for each object
	player = new Hero();

	for(int i = 0; i < MAX_MONSTERS; i++)
	{
		monster[i] = new Monster();
	}

	//Then Initiate
	player->InitHero(playerSprite, Height, Width);
	objects.push_back(player);
	for(int i = 0; i < MAX_MONSTERS; i++)
	{
		monster[i]->initMonster(rand() % 3, font10);
		objects.push_back(monster[i]);
	}

	/**************************
	*  Allegro Event Sources  *
	**************************/
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	
	/**************
	*  Game Loop  *
	**************/
	al_start_timer(timer);
	while(!gameComplete)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if(ev.type == ALLEGRO_EVENT_TIMER)
		{	
			/********************
			*  Player Movement  *
			********************/
			if(key[W])
			{
				player->setDirection(UP);
				player->moveUp();
				if (FrameSmoother % 10 == 0)
			{
				if (Frame > 3)
					Frame = 1;
				player->setcurFrame(Frame);
				Frame++;
				FrameSmoother = 1;
			}
			else
				FrameSmoother++;
			}
			if(key[S])
			{
			player->setDirection(DOWN);
			player->moveDown();
			if (FrameSmoother % 10 == 0)
			{
				if (Frame > 3)
					Frame = 1;
				player->setcurFrame(Frame);
				Frame++;
				FrameSmoother = 1;
			}
			else
				FrameSmoother++;
			}
			if(key[A])
			{
				player->setDirection(LEFT);
				player->moveLeft();
				if (FrameSmoother % 10 == 0)
				{
					if (Frame > 3)
						Frame = 1;
					player->setcurFrame(Frame);
					Frame++;
					FrameSmoother = 1;
				}
			else
				FrameSmoother++;
			}
			if(key[D])
			{
				player->setDirection(RIGHT);
				player->moveRight();
				if (FrameSmoother % 10 == 0)
				{
					if (Frame > 3)
						Frame = 1;
					player->setcurFrame(Frame);
					Frame++;
					FrameSmoother = 1;
				}
			else
				FrameSmoother++;
			}

			if(key[ENTER])
				gameComplete = true;

			/*******************
			*  Map Offsetting  *
			*******************/
			xOff -= key[D] * 2;
			xOff += key[A] * 2;
			yOff -= key[S] * 2;
			yOff += key[W] * 2;

			/************************
			*  Game Object Updating *
			************************/
			for (int i = 0; i < MAX_MONSTERS; i++)
			{
				monster[i]->setXOff(xOff);
				monster[i]->setYOff(yOff);
			}
			
			if (player->getMana() < 100 && player->getMana() >= 0)
			{
				if (EnergyRegen % 60 == 0)
					player->setMana((player->getMana() + 1));
				EnergyRegen++;
			}
			if (player->getMana() <= 0)
				player->setMana(0);
			for (iter = objects.begin(); iter != objects.end(); ++iter)
				(*iter)->Update();
			redraw = true;

			/***************
			*  Collisions  *
			***************/

			for(iter = objects.begin(); iter != objects.end(); ++iter)
			{
				if(!(*iter)->Collidable()) continue;
				for(iter2 = iter; iter2 != objects.end(); ++iter2)
				{
					if(!(*iter2)->Collidable()) continue;
					if((*iter)->getID() == (*iter2)->getID()) continue;

					if((*iter)->checkCollisions((*iter2)))
					{
						(*iter)->Collided((*iter2)->getID());
						(*iter2)->Collided((*iter)->getID());
					}
				}
			}

			/******************
			*  CULL THE DEAD  *
			******************/
			for(iter = objects.begin(); iter != objects.end();)
			{
				if(! (*iter)->getAlive())
				{
					delete(*iter);
					iter = objects.erase(iter);
				}
				else
					iter++;
			}
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
				if (player->getMana() > 0)
				{
					Cannon *bullet = new Cannon();
					bullet->initCannon();
					bullet->fireCannon(player);
					objects.push_back(bullet);
					player->useMana();
				}
				break;
			}
			player->setcurFrame(0);
		}

		if (redraw && al_is_event_queue_empty(event_queue))
		{
			for(int i = 0; i < mapSize; i++)
			{
				al_draw_bitmap_region(mapSprite, tileSize * map[i], 0, tileSize, tileSize, xOff + tileSize * (i % mapColumns), yOff + tileSize * (i / mapColumns), 0);
			}

			for(iter = objects.begin(); iter != objects.end(); ++iter)
				(*iter)->Render();

			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
			redraw = false;
		}
	}

	for(iter = objects.begin(); iter != objects.end();)
	{
		(*iter)->Destroy();
		delete(*iter);
		iter = objects.erase(iter);
	}
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_bitmap(mapSprite);

	return 0;
}