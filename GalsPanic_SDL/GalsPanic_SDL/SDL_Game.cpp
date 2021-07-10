#include "SDL_Game.h"

int SDL_Game::FPS = INITIAL_FPS;
SDL_Rect SDL_Game::window_rect = { SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, INITIAL_WIDTH, INITIAL_HEIGHT };


SDL_Window* SDL_Game::window = NULL;
SDL_Renderer* SDL_Game::renderer = NULL;
SDL_Event SDL_Game::event;
const Uint8* SDL_Game::keystate = NULL;

SDL_State* SDL_Game::game_state = NULL;


SDL_Game::SDL_Game(SDL_State* initial_state)
{
	if (SDL_Init(SDL_INIT_VIDEO /*| SDL_INIT_EVENTS*/))
		SDL_assert(0);

	window = SDL_CreateWindow("test",
		window_rect.x, window_rect.y, window_rect.w, window_rect.h,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE /*| SDL_WINDOW_BORDERLESS*/);
	SDL_assert(window);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_assert(renderer);

	game_state = initial_state;

	int old_tick = SDL_GetTicks();
	int new_tick;

	while (event.type != SDL_QUIT)
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_RESIZED:
				window_rect.w = event.window.data1;
				window_rect.h = event.window.data2;
				break;
			}
			break;
		}


		new_tick = SDL_GetTicks();

		if (new_tick - old_tick >= FPS)
		{
			SDL_PollEvent(&event);
			keystate = SDL_GetKeyboardState(NULL);
			game_state->Input();

			for (; new_tick - old_tick >= FPS
				; old_tick += FPS)
			{
				game_state->Process();
			}

			game_state->Output();
			SDL_RenderPresent(renderer);

			old_tick = new_tick;
		}
	}

}

SDL_Game::~SDL_Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	delete game_state;
}