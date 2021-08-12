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

v  화면 스크롤
v 충돌 (흡수 or 블럭)
- 애니메이터
- ttf 지름 표시
- 타이틀
- 게임오버

*/
