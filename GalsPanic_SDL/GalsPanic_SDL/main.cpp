#include <stdlib.h>
#include <crtdbg.h>

#include <stdio.h>
#include "SDL_Game.h"
#include "GalsPanic.h"

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	SDL_Game game;

	SDL_State* state = new GalsPanic;

	game.SetState(state);
	game.Run();

	_CrtDumpMemoryLeaks();

	return 0;
}



// todo
/*

- �� �߰�
//- �� �浹
- �ܺ� ���� ����
- ������ ä���
- ���� ����

*/
