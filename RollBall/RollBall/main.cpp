#include <stdio.h>
#include "RollBall.h"
#include "SDL_Game.h"


int main(int argc, char* argv[])
{
	SDL_Game game;

	game.SetState(&RollBall::Instance());
	game.Run();

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
