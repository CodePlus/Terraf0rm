#include "assembly.h"
/***********************************************
*	  The Code For Initializing the display    *
************************************************/
void displaySet ()
{
	//Display Variable
	ALLEGRO_DISPLAY *display = NULL;
	//sets the display
	display = al_create_display(640, 480);
	//Makes sure the display isn't NULL
	if(!display)
	{
	  al_show_native_message_box(NULL, NULL, NULL, "failed to initialize display!", NULL, NULL);
	}
	//Changes the color of the game window
	al_clear_to_color(al_map_rgb(0,0,255));
	//Sends the changes to the screen
	al_flip_display();
	//Pauses the screen for 5 seconds
	al_rest(5.0);
	//Kills Display
	al_destroy_display(display);
}
