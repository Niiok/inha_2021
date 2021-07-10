#include <stdio.h>
#include "SDL_Game.h"
#include "GalsPanic.h"

int main(int argc, char* argv[])
{

	SDL_State* state = new GalsPanic;

	SDL_Game this_object_do_everything(state);

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
