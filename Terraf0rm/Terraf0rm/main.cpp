#include "assembly.h"
#include "GameObject.h"
#include "CharacterSprite.h"
#include "cannon.h"
#include "Hero.h"
#include "monster.h"
#include "DragonAttack.h"

/***********************
*  Obect Declerations  *
***********************/
Hero *player;
Hero *player2;
Cannon *bullet;
Cannon *bullet2;
Monster *monster[MAX_MONSTERS];
Monster *Boss;
int Width = 0, Height = 0;
int state = TITLE;
std::list<GameObject *> objects;
std::list<GameObject *>::iterator iter;
std::list<GameObject *>::iterator iter2;
void changeState (int &state, int newState);

int main (int argc, char **argv)
{
	srand(time(NULL));
	/*********************
	*  Global Variables  *
	*********************/
	int select = 1;
	bool gameComplete = false;
	int FrameSmoother = 1, FrameSmoother2 = 1;
	const int FPS = 60;
	bool redraw = true;
	bool key[8] = {false};
	int Frame = 1;
	int EnergyRegen = 0;
	int Frame2 = 1, EnergyRegen2 = 0;
	int MonsterCount = MAX_MONSTERS;
	bool Dragon = true;
	bool DeadDragon = false;
	int Dragonattack = 1;
	bool Alive1 = true, Alive2 = true, Init = true;
	int fireFrame = 1, fireSmoother = 1;
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
	ALLEGRO_BITMAP *player2Sprite = NULL;
	ALLEGRO_BITMAP *ArrowLeft = NULL;
	ALLEGRO_BITMAP *ArrowRight = NULL;
	ALLEGRO_BITMAP *TitleScreen = NULL;
	ALLEGRO_BITMAP *deadScreen = NULL;
	ALLEGRO_BITMAP *Crocodile = NULL;
	ALLEGRO_BITMAP *Skeleton = NULL;
	ALLEGRO_BITMAP *Smile = NULL;
	ALLEGRO_BITMAP *DeathScreen = NULL;
	ALLEGRO_BITMAP *BOSS = NULL;
	ALLEGRO_BITMAP *WIN = NULL;
	ALLEGRO_BITMAP *FireBall = NULL;
	ALLEGRO_JOYSTICK *joystick = NULL;
	ALLEGRO_SAMPLE *sample = NULL;
	ALLEGRO_SAMPLE *Title = NULL;
	ALLEGRO_SAMPLE *Play = NULL;
	ALLEGRO_SAMPLE *BusterShot = NULL;
	ALLEGRO_SAMPLE *Enter = NULL;
	ALLEGRO_SAMPLE *Select = NULL;
	ALLEGRO_SAMPLE *FlameAttack = NULL;

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
	al_install_audio();
	al_init_acodec_addon();
	al_install_joystick();

	//reserves two channels for sound
	al_reserve_samples(2);

	Width = widthHeight(0);
	Height = widthHeight(1);

	displaySet(Width, Height, display);

	/***************************************
	*  Load The Images and Set The Alphas  *
	***************************************/
	mapSprite = al_load_bitmap("art bitmaps/tiles.png");
	playerSprite = al_load_bitmap("art bitmaps/Character bitmaps/Main character/main_character_shooting.bmp");
	al_convert_mask_to_alpha(playerSprite, al_map_rgb(255,0,255));
	player2Sprite = al_load_bitmap("art bitmaps/Character bitmaps/Main character/main character2 Jim.bmp");
	al_convert_mask_to_alpha(player2Sprite, al_map_rgb(255,0,255));
	ArrowLeft = al_load_bitmap("art bitmaps/Arrow_Left.bmp");
	al_convert_mask_to_alpha(ArrowLeft, al_map_rgb(255,0,255));
	ArrowRight = al_load_bitmap("art bitmaps/Arrow_Right.bmp");
	al_convert_mask_to_alpha(ArrowRight, al_map_rgb(255,0,255));
	Crocodile = al_load_bitmap("art bitmaps/Monster/monster1.bmp");
	al_convert_mask_to_alpha(Crocodile, al_map_rgb(255,0,255));
	Skeleton = al_load_bitmap("art bitmaps/Monster/monster2.bmp");
	al_convert_mask_to_alpha(Skeleton, al_map_rgb(255,0,255));
	Smile = al_load_bitmap("art bitmaps/Monster/monster3.bmp");
	al_convert_mask_to_alpha(Smile, al_map_rgb(255,0,255));
	BOSS = al_load_bitmap("art bitmaps/Monster/Boss Monster.bmp");
	al_convert_mask_to_alpha(BOSS, al_map_rgb(255,0,255));
	FireBall = al_load_bitmap("art bitmaps/Monster/dragonfire move.bmp");
	al_convert_mask_to_alpha(FireBall, al_map_rgb(255,0,255));
	TitleScreen = al_load_bitmap("art bitmaps/teraform title screen official.bmp");
	DeathScreen = al_load_bitmap("art bitmaps/dead screen.bmp");
	WIN = al_load_bitmap("art bitmaps/Win screen.bmp");
	font10 = al_load_font("fonts/arial.ttf", 10, 0);
	Title = al_load_sample("music/wasteland.ogg");
	Play = al_load_sample("music/boss.ogg");
	BusterShot = al_load_sample("music/buster.ogg");
	Enter = al_load_sample("music/enter.ogg");
	Select = al_load_sample("music/select.ogg");
	FlameAttack = al_load_sample("music/fire.ogg"); 
	if(Init == true)
	{
		/**************************
		*  Object Initialization  *
		***************************/
		//First Allocate Memory Space for each object
		player = new Hero();
		player2 = new Hero();
		for(int i = 0; i < MAX_MONSTERS; i++)
		{
			monster[i] = new Monster();
		}

		//Then Initiate
		player->InitHero(playerSprite);
		objects.push_back(player);
		player2->InitHero(player2Sprite);
		player2->setHeroNumber(1);
		player2->setID(PLAYER2);
		player2->setX(player->getX()+30);
		objects.push_back(player2);
		for(int i = 0; i < MAX_MONSTERS; i++)
		{
			int randMonster = rand() % 3;
			switch(randMonster)
			{
			case 0: 
				monster[i]->setName("Crocodile");
				monster[i]->initMonster(Crocodile, font10);
				break;
			case 1: 
				monster[i]->setName("Skeleton");
				monster[i]->initMonster(Skeleton, font10);
				break;
			case 2:
				monster[i]->setName("Blob");
				monster[i]->initMonster(Smile ,font10);
				break;
			}
			objects.push_back(monster[i]);
		}
		Init = false;
	}
	al_reconfigure_joysticks();
    joystick=al_get_joystick(0);

	/**************************
	*  Allegro Event Sources  *
	**************************/
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_joystick_event_source());
	changeState(state, TITLE);

	changeState(state, TITLE);
	if(state == TITLE)
	al_play_sample(Title, 0.5, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
	/**************
	*  Game Loop  *
	**************/
	al_start_timer(timer);
	while(!gameComplete)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		
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
			case ALLEGRO_KEY_ESCAPE:
				key[ESCAPE] = true;
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
				if(state == PLAY)
				{
					if (player->getMana() > 0)
					{
						bullet = new Cannon();
						bullet->initCannon();
						objects.push_back(bullet);
						bullet->fireCannon(player);
						player->useMana();
						al_play_sample(BusterShot, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
					}
				}
				break;
			case ALLEGRO_KEY_ESCAPE:
				key[ESCAPE] = false;
				break;
			}
			player->setcurFrame(0);
		}
		if(select == 2)
		{
			if (ev.type == ALLEGRO_EVENT_JOYSTICK_AXIS)
			{
				if(ev.joystick.stick == 0)
				{
					if(ev.joystick.axis == 0)
					{
						if(ev.joystick.pos == -1)
						{
							player2->setDirection(LEFT);
							player2->moveLeft();
							if (FrameSmoother2 % 10 == 0)
							{
								if (Frame2 > 3)
									Frame2 = 1;
								player2->setcurFrame(Frame2);
								Frame2++;
								FrameSmoother2 = 1;
							}
							else
								FrameSmoother2++;
						}
						if(ev.joystick.pos == 1)
						{
							player2->setDirection(RIGHT);
							player2->moveRight();
							if (FrameSmoother2 % 10 == 0)
							{
								if (Frame2 > 3)
									Frame2 = 1;
								player2->setcurFrame(Frame2);
								Frame2++;
								FrameSmoother2 = 1;
							}
							else
								FrameSmoother2++;
						}
						if(ev.joystick.pos == 0)
						{
							player2->setVelX(0);
						}
					}
					if(ev.joystick.axis == 1)
					{
						if(ev.joystick.pos == -1)
						{
							player2->setDirection(UP);
							player2->moveUp();
							if (FrameSmoother2 % 10 == 0)
							{
								if (Frame2 > 3)
									Frame2 = 1;
								player2->setcurFrame(Frame2);
								Frame2++;
								FrameSmoother2 = 1;
							}
							else
								FrameSmoother2++;
						}
						if(ev.joystick.pos == 1)
						{
							player2->setDirection(DOWN);
							player2->moveDown();
							if (FrameSmoother2 % 10 == 0)
							{
								if (Frame2 > 3)
									Frame2 = 1;
								player2->setcurFrame(Frame2);
								Frame2++;
								FrameSmoother2 = 1;
							}
							else
								FrameSmoother2++;
						}
						if(ev.joystick.pos == 0)
						{
							player2->setVelY(0);
						}
					}
				}
			}
			if(ev.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_UP)
			{
				if(ev.joystick.button == 0)
				{	
					if (player2->getMana() > 0)
					{
						bullet2 = new Cannon();
						bullet2->initCannon();
						bullet2->setRed(255);
						bullet2->setGreen(140);
						bullet2->fireCannon(player2);
						objects.push_back(bullet2);
						player2->useMana();
						al_play_sample(BusterShot, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
					}
				}
			}
		}

		if(ev.type == ALLEGRO_EVENT_TIMER)
		{	
			/*********************
			*  Game State Title  *
			*********************/

			if(state == TITLE)
			{
				if (FrameSmoother % 7 == 0)
				{
					if(key[W])
					{
						al_play_sample(Select, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						select--;
						if(select < 1)
							select = 3;
					}
					if(key[S])
					{
						al_play_sample(Select, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						select++;
						if(select > 3)
							select = 1;
					}
					if(key[ENTER])
					{
						al_play_sample(Enter, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						if(select == 1)
						{
							changeState(state, PLAY);
							player2->setAlive(false);
						}
						else if (select == 2)
							changeState(state, PLAY);
						else if(select == 3)
							gameComplete = true;
					}
					redraw = true;
					FrameSmoother = 1;
				}
				else
					FrameSmoother++;
			}
			/**********************
			*  GameState PLAYING  *
			**********************/
			if(state == PLAY)
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

				if(key[ESCAPE])
					gameComplete = true;

				/****************
				*  Update Area  *
				****************/
				if (player->getMana() < 100 && player->getMana() >= 0)
				{
					if (EnergyRegen % 60 == 0)
						player->setMana((player->getMana() + 8));
					EnergyRegen++;
				}

				if (player->getMana() <= 0)
					player->setMana(0);
				if(select == 2)
				{
					if (player2->getMana() < 100 && player2->getMana() >= 0)
					{
						if (EnergyRegen2 % 60 == 0)
							player2->setMana((player2->getMana() + 8));
						EnergyRegen2++;
					}

					if (player2->getMana() <= 0)
						player2->setMana(0);
				}
				for (iter = objects.begin(); iter != objects.end(); ++iter)
				{
					if((*iter)->getID() == DRAGON || (*iter)->getID() == FIREBALL || (*iter)->getID() == ENEMY)
					{
						if(select == 1)
						{
							if ((player->getY() - (*iter)->getY()) < 0)
							{
								(*iter)->setDirection(UP);
								if((*iter)->getY() <= 0 + 15  + (widthHeight(1) / 8))
								{
								}
								else
								{
									(*iter)->setY((*iter)->getY() - (*iter)->getVelY());
								}
							}
							if ((player->getY() - (*iter)->getY()) > 0)
							{
								(*iter)->setDirection(DOWN);
								if((*iter)->getY() >=  (widthHeight(1) / 8) + sHEIGHT - 35 - 15)
								{
								}
								else
								{
									(*iter)->setY((*iter)->getY() + (*iter)->getVelY());
								}
							}
							if ((player->getX() - (*iter)->getX()) < 0)
							{
								(*iter)->setDirection(LEFT);
								if((*iter)->getX() <= 0 + 15  + (widthHeight(0) / 4))
								{
								}
								else
								{
									(*iter)->setX((*iter)->getX() - (*iter)->getVelX());
								}
							}
							if ((player->getX() - (*iter)->getX()) > 0)
							{
								(*iter)->setDirection(RIGHT);
								if((*iter)->getX() >=  (widthHeight(0) / 4) + sWIDTH - 35 - 15)
								{
								}
								else
								{
									(*iter)->setX((*iter)->getX() + (*iter)->getVelX());
								}
							}
						}
					}
					else
						(*iter)->Update();
				}
				player->setVelY(0);
				player->setVelX(0);

				
				/*********
				*  BOSS  *
				*********/
				if(MonsterCount == 0 && Dragon == true)
				{
					Boss = new Monster();
					Boss->initMonster(BOSS, font10);
					Boss->setName("Dragon");
					Boss->setID(DRAGON);
					Boss->setHealth(500);
					Boss->setFrameHeight(35);
					Boss->setFramWidth(35);
					Boss->setSpriteSize(35);
					objects.push_back(Boss);
					Dragon = false;
				}
				if (Dragon == false && DeadDragon == false)
				{
					if(Dragonattack % 60 == 0)
					{
						DragonAttack *flame = new DragonAttack();
						flame->InitDragon(FireBall);
						flame->Attack(Boss);
						objects.push_back(flame);
						al_play_sample(FlameAttack, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
					}
					Dragonattack++;
				}

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
				if (select == 1 && Alive1 == false)
				{
					Alive1 = true;
					Init = true;
					changeState(state, DEAD);
				}
				else if (select == 2 && Alive1 == false && Alive2 == false)
				{
					Alive1 = true;
					Alive2 = true;
					Init = true;
					changeState(state, DEAD);
				}
				else if (DeadDragon == true)
				{
					Init = true;
					changeState(state, WON);
				}
				else
				{
					for(iter = objects.begin(); iter != objects.end(); )
					{
						if(! (*iter)->getAlive())
						{
							if((*iter)->getID() == ENEMY)
							{
								MonsterCount--;
							}
							else if((*iter)->getID() == DRAGON)
							{
								DeadDragon = true;
							}
							else if ((*iter)->getID() == PLAYER)
							{
								Alive1 = false;
							}
							else if ((*iter)->getID() == PLAYER2)
							{
								Alive2 = false;
							}
							delete (*iter);
							iter = objects.erase(iter);
						}
						else
							iter++;
					}
				}
				
			}

			/***************
			*  DEAD STATE  *
			***************/
			if( state == DEAD)
			{
				if (FrameSmoother % 7 == 0)
				{
					if(key[W])
					{
						al_play_sample(Select, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						select--;
						if(select < 1)
							select = 2;
					}
					if(key[S])
					{
						al_play_sample(Select, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						select++;
						if(select > 2)
							select = 1;
					}
					if(key[ENTER])
					{
						al_play_sample(Enter, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						if(select == 1)
						{
							changeState(state, TITLE);
						}
						else if(select == 2)
							gameComplete = true;
					}
					redraw = true;
					FrameSmoother = 1;
				}
				else
					FrameSmoother++;
			}
			/**************
			*  Won State  *
			**************/
			if( state == WON)
			{
				if (FrameSmoother % 7 == 0)
				{
					if(key[W])
					{
						al_play_sample(Select, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						select--;
						if(select < 1)
							select = 2;
					}
					if(key[S])
					{
						al_play_sample(Select, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						select++;
						if(select > 2)
							select = 1;
					}
					if(key[ENTER])
					{
						al_play_sample(Enter, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						if(select == 1)
						{
							changeState(state, TITLE);
						}
						else if(select == 2)
							gameComplete = true;
					}
					redraw = true;
					FrameSmoother = 1;
				}
				else
					FrameSmoother++;
			}
		}

	/****************
	*  Render Area  *
	****************/
		if (redraw && al_is_event_queue_empty(event_queue))
		{
			if(state == TITLE)
			{
				al_draw_scaled_bitmap(TitleScreen,0,0,al_get_bitmap_width(TitleScreen),al_get_bitmap_height(TitleScreen),0,0,Width,Height,0);
				if (select == 1)
				{
					al_draw_bitmap(ArrowRight,Width / 3.43, Height / 1.65, 0 );
				}
				else if (select == 2)
				{
					al_draw_bitmap(ArrowRight,Width / 3.43, Height / 1.48, 0 );
				}
				else if (select == 3)
				{
					al_draw_bitmap(ArrowRight,Width / 3.43, Height / 1.36, 0 );
				}
			}
			if(state == PLAY)
			{
				for(int i = 0; i < mapSize; i++)
				{
					al_draw_bitmap_region(mapSprite, tileSize * map[i], 0, tileSize, tileSize, Width/4 + tileSize * (i % mapColumns), Height/8 + tileSize * (i / mapColumns), 0);
				}
				for(iter = objects.begin(); iter != objects.end(); ++iter)
					(*iter)->Render();
			}
			if(state == DEAD)
			{
				al_draw_scaled_bitmap(DeathScreen,0,0,al_get_bitmap_width(DeathScreen),al_get_bitmap_height(DeathScreen),0,0,Width,Height,0);
				if (select == 1)
				{
					al_draw_bitmap(ArrowRight,Width / 3, Height / 1.55, 0 );
				}
				else if (select == 2)
				{
					al_draw_bitmap(ArrowRight,Width / 3, Height / 1.4, 0 );
				}
			}
			if(state == WON)
			{
				al_draw_scaled_bitmap(WIN,0,0,al_get_bitmap_width(WIN),al_get_bitmap_height(WIN),0,0,Width,Height,0);
				if (select == 1)
				{
					al_draw_bitmap(ArrowRight,Width / 3, Height / 1.55, 0 );
				}
				else if (select == 2)
				{
					al_draw_bitmap(ArrowRight,Width / 3, Height / 1.4, 0 );
				}
			}
			redraw = false;
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
	}
	/*******************
	*  Destroy Region  *
	*******************/
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
	al_destroy_bitmap(playerSprite);
	al_destroy_bitmap(player2Sprite);
	al_destroy_bitmap(ArrowLeft);
	al_destroy_bitmap(ArrowRight);
	al_destroy_bitmap(Crocodile);
	al_destroy_bitmap(Skeleton);
	al_destroy_bitmap(Smile);
	al_destroy_bitmap(TitleScreen);
	al_destroy_bitmap(DeathScreen);
	al_destroy_bitmap(BOSS);
	al_destroy_bitmap(WIN);
	al_destroy_bitmap(FireBall);
	al_destroy_sample(sample);
	al_destroy_sample(Title);
	al_destroy_sample(Play);
	al_destroy_sample(BusterShot);
	al_destroy_sample(Enter);
	al_destroy_sample(Select);
	al_destroy_sample(FlameAttack);
	al_destroy_font(font10);

	return 0;
}

void changeState (int &state, int newState)
{
	if(state == TITLE)
	{	
	}
	else if(state == PLAY)
	{
		for(iter = objects.begin(); iter != objects.end(); ++iter)
		{
			(*iter)->Destroy();
			delete(*iter);
			iter = objects.erase(iter);
		}
	}
	else if(state == DEAD)
	{

	}

	state = newState;

	if(state == TITLE)
	{

	}
	else if(state == PLAY)
	{

	}
	else if(state == DEAD)
	{

	}
}