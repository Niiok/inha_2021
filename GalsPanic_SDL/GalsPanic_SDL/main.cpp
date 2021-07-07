#include <stdio.h>
#include "SDL_Game.h"
#include "GalsPanic.h"

int main(int argc, char* argv[])
{

	SDL_State* state = new GalsPanic;

	SDL_Game this_object_do_everything(state);

	return 0;
}