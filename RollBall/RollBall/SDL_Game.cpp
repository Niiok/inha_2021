#include "SDL_Game.h"

int SDL_Game::FPS = INITIAL_FPS;
SDL_Rect SDL_Game::window_rect = { SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, INITIAL_WIDTH, INITIAL_HEIGHT };


SDL_Window* SDL_Game::window = NULL;
SDL_Renderer* SDL_Game::renderer = NULL;
SDL_Event SDL_Game::event;
const Uint8* SDL_Game::keystate = NULL;
TTF_Font* SDL_Game::font = NULL;

SDL_State* SDL_Game::game_state = NULL;


SDL_Game::SDL_Game()
{
	SDL_assert(!SDL_Init(SDL_INIT_VIDEO /*| SDL_INIT_EVENTS*/));

	SDL_assert(IMG_Init(IMG_INIT_PNG));

	SDL_assert(!TTF_Init());

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	window = SDL_CreateWindow("Roll Ball",
		window_rect.x, window_rect.y, window_rect.w, window_rect.h,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE /*| SDL_WINDOW_FULLSCREEN*/ /*| SDL_WINDOW_BORDERLESS*/);
	SDL_assert(window);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_assert(renderer);

	font = TTF_OpenFont("../data/font.ttf", 32);
	SDL_assert(font);

}

SDL_Game::~SDL_Game()
{
	TTF_CloseFont(font);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	if (game_state != NULL)
		delete game_state;
}


void SDL_Game::Run()
{
	int old_tick = SDL_GetTicks();
	int new_tick;

	while (game_state)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				game_state = NULL;
				break;

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
		}

		new_tick = SDL_GetTicks();

		if (new_tick - old_tick >= FPS)
		{
			keystate = SDL_GetKeyboardState(NULL);
			
			if (game_state != NULL)	// Input
				game_state->Input();

			if (game_state != NULL)	// Process
				game_state->Process();
			old_tick += FPS;

			if (new_tick - old_tick >= FPS)	// additional Process
			{
				if (game_state != NULL)
					game_state->Process();
				old_tick += FPS;
			}

			if (game_state != NULL)	// Output
				game_state->Output();

			SDL_RenderPresent(renderer);
		}
	}

}
