#include "assembly.h"
/***********************************************
*	  The Code For Initializing the display    *
************************************************/
int widthHeight (int variable)
{
	//Monitor Info
	ALLEGRO_MONITOR_INFO info;
	//Get Monitor Info
	al_get_monitor_info(0, &info);
	//Gain and set the appropriat x and y values
	//variable = 0 is the width
	if (variable == 0)
		return(info.x2 - info.x1);
	else
		return(info.y2 - info.y1);
}

void displaySet (int width, int height, ALLEGRO_DISPLAY *display )
{
	//Sets the display to fullscreen and the same size as your screen
	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	//Sets the default display
	if (width != 0 && height != 0)
		display = al_create_display(width, height);
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
}
