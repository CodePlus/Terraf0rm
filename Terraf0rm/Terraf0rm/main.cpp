#include "assembly.h"

int main (int argc, char **argv)
{
	/*******************************
	*	  GameEngine Variables     *
	*******************************/
	//Check for when the game engine has completed running
	bool gameComplete = false;

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


	/****************************
	*     Game Engine Loop      *
	****************************/

	while(!gameComplete)
	{

	}
	return 0;
}