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

- 선 추가
//- 선 충돌
- 외부 내부 구분
- 폴리곤 채우기
- 알파 블랜딩

*/
