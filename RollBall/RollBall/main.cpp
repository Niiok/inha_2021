#include <stdio.h>
#include "SDL_Game.h"
#include "RollBall.h"


int main(int argc, char* argv[])
{
	SDL_Game game;

	SDL_State* state = new RollBall;

	game.SetState(state);
	game.Run();

	return 0;
}



// todo
/*

- ȭ�� ��ũ��
- �ִϸ�����
- �浹 (��� or �� or ����)
- ttf ���� ǥ��
- Ÿ��Ʋ
- ���ӿ���

*/
