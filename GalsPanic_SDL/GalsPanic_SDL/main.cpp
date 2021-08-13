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

- 선 추가
//- 선 충돌
- 외부 내부 구분
- 폴리곤 채우기
- 알파 블랜딩

*/
