#include <stdio.h>
#include "SDL_Game.h"
#include "GalsPanic.h"

int main(int argc, char* argv[])
{
	SDL_Game game;

	SDL_State* state = new GalsPanic;

	game.SetState(state);
	game.Run();

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
