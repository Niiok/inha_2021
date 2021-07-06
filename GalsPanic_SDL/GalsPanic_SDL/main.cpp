#include "SDL.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

void Init();
void Quit();
Uint32 TimerCallback(Uint32 interval, void* param);

int Window_Width = 800;
int Window_Height = 500;

SDL_Window* window;
SDL_Surface* surface;
SDL_Renderer* render;
SDL_Event e;
SDL_TimerID timer;


int main(int argc, char* args[])
{

	Init();

	SDL_Point position = { Window_Width / 2, Window_Height / 2 };
	SDL_Point points[5] = { {100, 100 }, {100, 200,}, {200, 200}, {200, 150}, {100, 100} };
	SDL_Point points_mod[5];
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	int speed = 10;

	while (e.type != SDL_QUIT)
	{
		//while (SDL_PollEvent(&e) != 0)
		{
			SDL_Delay(1000 / 30);
			SDL_PollEvent(&e);

			switch (e.type)
			{
			case SDL_QUIT:
				break;

			case SDL_KEYDOWN:
				keystate = SDL_GetKeyboardState(NULL);
				break;
			}

			if (keystate[SDL_SCANCODE_LEFT])
				position.x-=speed;
			if (keystate[SDL_SCANCODE_RIGHT])
				position.x+=speed;
			if (keystate[SDL_SCANCODE_DOWN])
				position.y+=speed;
			if (keystate[SDL_SCANCODE_UP])
				position.y-=speed;
			
			for (int i = 0; i < 5; ++i)
			{
				points_mod[i].x = points[i].x + position.x;
				points_mod[i].y = points[i].y + position.y;
			}

			static double i = 0;
			i += 0.1;

			//if (SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF * cos(i / 10), 0xFF * sin(i / 10), 0x80)))
			//	assert(0);
			//if (SDL_UpdateWindowSurface(window))
			//	assert(0);

			SDL_SetRenderDrawColor(render, 0x40+0x20*sinf(i/5), 0x40 + 0x20 * sinf(i / 5), 0x40 + 0x20 * sinf(i / 5), 0xFF);
			SDL_RenderFillRect(render, NULL);
			SDL_SetRenderDrawColor(render, 0xFF*sinf(i/5), 0xFF*cosf(i/5), 0x80, 0xFF);
			SDL_RenderDrawRect(render, NULL);

			SDL_SetRenderDrawColor(render, 0x80, 0xFF*sin(i), 0xFF*cos(i), 0xFF);
			SDL_RenderDrawLines(render, points_mod, 5);
			SDL_RenderPresent(render);

		}
	}



	return 0;
}

void Init()
{

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER))
		assert(0);

	window = SDL_CreateWindow("test",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		Window_Width, Window_Height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
	assert(window);

	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	assert(render);

	surface = SDL_GetWindowSurface(window);
	assert(surface);

	timer = SDL_AddTimer(1000 / 30, TimerCallback, NULL);

}

void Quit()
{
	SDL_RemoveTimer(timer);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

Uint32 TimerCallback(Uint32 interval, void * param)
{
	return Uint32();
}
