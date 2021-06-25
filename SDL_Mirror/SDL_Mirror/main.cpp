#include "SDL.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

int Window_Width = 100;
int Window_Height = 100;

int main(int argc, char* args[])
{
	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Event e;
	bool quit = false;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
		assert(0);

	window = SDL_CreateWindow("test", 
		1000,
		500,
		Window_Width, Window_Height, 
		SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
	assert(window);

	surface = SDL_GetWindowSurface(window);
	assert(surface);

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			//SDL_PollEvent(&e);

			switch (e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;

			}

			static double i = 0;
			i += 0.01;

			int mouse_x;
			int mouse_y;
			SDL_GetGlobalMouseState(&mouse_x, &mouse_y);

			
			int x = mouse_x - Window_Width/2 + cos(i/5)*Window_Width/4;
			
			int y = mouse_y - Window_Height/2 + sin(i/5)*Window_Height/4;
			SDL_SetWindowPosition(window, x, y);


			if (SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF * cos(i / 10), 0xFF * sin(i / 10), 0x80)))
				assert(0);
			if (SDL_UpdateWindowSurface(window))
				assert(0);
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}