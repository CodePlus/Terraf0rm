#include "assembly.h"
/***********************************************
*	  The Code For Initializing the display    *
************************************************/
void displaySet ()
{
	//Display Variable
	ALLEGRO_DISPLAY *display = NULL;
	//Monitor Info
	ALLEGRO_MONITOR_INFO info;
	//Set width and height Variables
	int w = 0, h = 0;
	//Get Monitor Info
	al_get_monitor_info(0, &info);
	//Gain and set the appropriat x and y valuse
	w = info.x2 - info.x1;
	h = info.y2 - info.y1;
	//Sets the display to fullscreen and the same size as your screen
	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	//Sets the default display
	if (w != 0 && h != 0)
		display = al_create_display(w, h);
	else
		display = al_create_display(800, 600); //sets the back up display
	//Makes sure the display isn't NULL
	if(!display)
	{
	  al_show_native_message_box(NULL, NULL, NULL, "failed to initialize display!", NULL, NULL);
	}
	//Changes the color of the game window
	al_clear_to_color(al_map_rgb(0,255,0));
	//Sends the changes to the screen
	al_flip_display();
	//Pauses the screen for 5 seconds
	al_rest(5.0);
	//Kills Display
	al_destroy_display(display);
}
