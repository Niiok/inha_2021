#include <stdlib.h>
#include <crtdbg.h>


#include <stdio.h>
#include "SDL_Game.h"
#include "RollBall.h"

class RollBall;

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	SDL_Game game;

	game.SetState(new RollBall);
	game.Run();

	_CrtDumpMemoryLeaks();

	return 0;
}



// todo
/*

v  ȭ�� ��ũ��
v �浹 (��� or ��)
- �ִϸ�����
- ttf ���� ǥ��
- Ÿ��Ʋ
- ���ӿ���

*/
