#include "assembly.h"

int main (int argc, char **argv)
{
	/*******************************
	*	  GameEngine Variables     *
	*******************************/
	//Check for when the game engine has completed running
	bool gameComplete = false;
	//Initalize the width and height Variables of the monitor
	int Width = 0, Height = 0;
	//Set The Frames Per Second to smooth out and standardize the gameplay
	const int FPS = 60;
	//Check to see if we should redraw the Display
	bool redraw = true;

	/******************************
	*      Object Variables       *
	******************************/


	/******************************
	*     Allegro Variables       *
	******************************/
	//Initializing the event queue that deals with all the Events taking place in the game
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	//Allegro Timer to set the Frames Per Second
	ALLEGRO_TIMER *timer = NULL;

	/******************************
	*  Initialization Functions   *
	******************************/
	//Initailizes Allegro
	al_init();
	//Gains the Monitors Correct Width and Height
	Width = widthHeight(0);
	Height = widthHeight(1);
	//Initializes the display set up
	displaySet(Width, Height);
	//Creates event the Queue
	event_queue = al_create_event_queue();
	//Creates the timer
	timer = al_create_timer(1.0/FPS);

	/******************************
	*      Allegro Installs       *
	******************************/
	al_install_keyboard();

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
			redraw = true;
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN || ev.type == ALLEGRO_EVENT_KEY_UP)
			keyboardUse(event_queue, ev);
		if (redraw && al_is_event_queue_empty(event_queue))
		{
			//Set redraw it false since we're about to draw to screen
			redraw = false;
			
			//Sends the changes to the screen
			al_flip_display();
			//Changes the color of the game window that's not flipped
			al_clear_to_color(al_map_rgb(255,255,255));
		}
	}
	return 0;
}