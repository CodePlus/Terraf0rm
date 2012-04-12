/**********************************************
*  Initializes the keyboard and its commands  *
**********************************************/
#include "assembly.h"
void keyboardUse(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_EVENT ev)
{
	bool key[7] = {false};
	bool done = false;
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
	if(ev.type == ALLEGRO_EVENT_KEY_UP)
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
			break;
		}
	}
}