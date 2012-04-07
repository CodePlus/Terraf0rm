#include "assembly.h"

int main ()
{
	//Display Variable
	ALLEGRO_DISPLAY *display = NULL;
	//Initialize Allegro
	if(!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL, "failed to initialize allegro!", NULL, NULL);
		return -1;
	}
	//Set display
	display = al_create_display(640, 480);
	//Check to make sure the display is running correctly
	if(!display)
	{
		al_show_native_message_box(NULL, NULL, NULL, "failed to initialize display!", NULL, NULL);
		return -1;
	}
	//Kill display
	al_destroy_display(display);

	return 0;
}