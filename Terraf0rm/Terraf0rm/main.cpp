#include "assembly.h"
#include "GameObject.h"
#include "CharacterSprite.h"
#include "cannon.h"
#include "Hero.h"
#include "monster.h"

int main (int argc, char **argv)
{
	bool gameComplete = false;

	int Width = 0, Height = 0, FrameSmoother = 1;

	const int FPS = 60;

	bool redraw = true;
	bool key[7] = {false};

	int Frame = 1;
	int heroID = Suit;
	int ShootingSmoother = 1;

	int frameCount = 0;

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

	Hero player;
	Cannon buster;

	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *mapSprite = NULL;
	ALLEGRO_BITMAP *playerSprite = NULL;
	ALLEGRO_FONT *font10 = NULL;

	if(!al_init())
		return -1;

	Width = widthHeight(0);
	Height = widthHeight(1);

	displaySet(Width, Height, display);

	event_queue = al_create_event_queue();

	timer = al_create_timer(1.0/FPS);

	al_install_keyboard();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	mapSprite = al_load_bitmap("art bitmaps/tiles.png");
	playerSprite = al_load_bitmap("art bitmaps/Character bitmaps/Main character/main_character.bmp");
	al_convert_mask_to_alpha(playerSprite, al_map_rgb(255,0,255));

	font10 = al_load_font("fonts/arial.ttf", 10, 0);

	player.InitHero(playerSprite, Height, Width);
	buster.initCannon();

	Monster monster[MAX_MONSTERS];
	
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);
	while(!gameComplete)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if(ev.type == ALLEGRO_EVENT_TIMER)
		{	
			frameCount++;

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

			xOff -= key[D] * 5;
			xOff += key[A] * 5;
			yOff -= key[S] * 5;
			yOff += key[W] * 5;

			for(int i = 0; i < MAX_MONSTERS; i++)
			{
				monster[i].move(frameCount);
			}

			if (heroID == Shooting)
			{
				if (ShootingSmoother % 60 == 0)
					heroID = Suit;
				else
					ShootingSmoother++;
			}

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
				heroID = Shooting;
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

			redraw = false;

			buster.Render();

			player.Render(heroID);

			for(int i = 0; i < MAX_MONSTERS; i++)
			{
				monster[i].drawMonster(font10, xOff, yOff);
			}

			al_flip_display();

			al_clear_to_color(al_map_rgb(0,0,0));
		}
	}

	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_bitmap(mapSprite);

	return 0;
}