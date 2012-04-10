/**********************************************
*  Initializes the keyboard and its commands  *
**********************************************/
#include "assembly.h"
void keyboardSetUp(ALLEGRO_EVENT_QUEUE *event_queue)
{
	bool key[7] = {false};
	bool done = false;
	al_install_keyboard();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	while (!done)
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
			}
		}
	}
}