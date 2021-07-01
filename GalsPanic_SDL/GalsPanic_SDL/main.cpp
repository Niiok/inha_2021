#include "SDL.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

void Init();
void Quit();
Uint32 TimerCallback(Uint32 interval, void* param);

int Window_Width = 1000;
int Window_Height = 500;

SDL_Window* window;
SDL_Surface* surface;
SDL_Renderer* render;
SDL_Event e;
SDL_TimerID timer;


int main(int argc, char* args[])
{

	Init();

	while (e.type != SDL_QUIT)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			//SDL_PollEvent(&e);

			switch (e.type)
			{
			case SDL_QUIT:
				break;

			}

			static double i = 0;
			i += 0.01;

			int mouse_x;
			int mouse_y;
			SDL_GetGlobalMouseState(&mouse_x, &mouse_y);


			int ran = rand() % 10;
			int x = mouse_x - Window_Width / 2 + cos(i / 5)*Window_Width / ran;

			int y = mouse_y - Window_Height / 2 + sin(i / 5)*Window_Height / ran;
			SDL_SetWindowPosition(window, x, y);


			if (SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF * cos(i / 10), 0xFF * sin(i / 10), 0x80)))
				assert(0);
			if (SDL_UpdateWindowSurface(window))
				assert(0);
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
		SDL_WINDOW_SHOWN /*| SDL_WINDOW_BORDERLESS*/);
	assert(window);

	surface = SDL_GetWindowSurface(window);
	assert(surface);

	render = SDL_CreateRenderer(window, 1, 0);
	assert(render);

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
