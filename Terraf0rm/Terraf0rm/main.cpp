#include "assembly.h"

int main (int argc, char **argv)
{
	/*******************************
	*	  GameEngine Variables     *
	*******************************/

	/******************************
	*      Object Variables       *
	******************************/


	/******************************
	*     Allegro Variables       *
	******************************/
	//Initializing the event queue that deals with all the Events taking place in the game
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	/******************************
	*  Initialization Functions   *
	******************************/
	//Initailizes Allegro
	al_init();
	//Initializes the display set up
	displaySet();

	return 0;
}