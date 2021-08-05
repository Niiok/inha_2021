#include <stdio.h>
#include "SDL_Game.h"


int main(int argc, char* argv[])
{
	SDL_Game game;

	SDL_State* state = /*GalsPanic*/NULL;

	game.SetState(state);
	game.Run();

	return 0;
}



// todo
/*

- 화면 스크롤
- 애니메이터
- 충돌 (흡수 or 블럭 or 분해)
- ttf 지름 표시
- 타이틀
- 게임오버

*/
