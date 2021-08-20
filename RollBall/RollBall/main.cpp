#include <stdlib.h>
#include <crtdbg.h>


#include <stdio.h>
#include "SDLpp_Game.h"
#include "SDLpp_Resource.h"
#include "RollBall.h"

class RollBall;

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(169);

	SDLpp_Game game;

	game.SetState(new RollBall);
	game.Run();

	_CrtDumpMemoryLeaks();

	return 0;
}



// todo
/*

v screen scroll
v Collision (block or absorb)
v ttf print diameter
v Animator
- Object Factory
- Sound
- Title
- Game over

*/
