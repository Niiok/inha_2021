#include "SDL.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

int Window_Width = 1000;
int Window_Height = 500;

int main(int argc, char* args[])
{
	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* render;
	SDL_Event e;
	bool quit = false;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
		assert(0);

	window = SDL_CreateWindow("test", 
		1000,
		500,
		Window_Width, Window_Height, 
		SDL_WINDOW_SHOWN /*| SDL_WINDOW_BORDERLESS*/);
	assert(window);

	surface = SDL_GetWindowSurface(window);
	assert(surface);

	//render = SDL_CreateRenderer(window, 1, 0);
	//assert(render);


	////Circle test
	//int circle_x = Window_Width / 2;
	//int circle_y = Window_Height / 2;
	//int circle_radius = 100;
	//SDL_SetRenderDrawColor(render, 100, 100, 255, 255);

	//int point_x;
	//int point_y;

	//while (circle_radius > 0)
	//{
	//	for (int t = 0; t < 360; t++)
	//	{
	//		point_x = circle_x + circle_radius * cos(t);
	//		point_y = circle_y + circle_radius * sin(t);
	//		SDL_RenderDrawPoint(render, point_x, point_y);
	//	}

	//	circle_radius--;
	//}
	//SDL_RenderPresent(render);

	//SDL_Delay(10000);

	while (!quit)
	{
		//while (SDL_PollEvent(&e) != 0)
		{
			SDL_PollEvent(&e);

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

			
			int ran = rand() % 10;
			int x = mouse_x - Window_Width/2 + cos(i/5)*Window_Width/ran;
			
			int y = mouse_y - Window_Height/2 + sin(i/5)*Window_Height/ran;
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