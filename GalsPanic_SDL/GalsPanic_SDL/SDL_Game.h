#pragma once

#include<stdio.h>
#include "SDL.h"
#include "SDL_State.h"


class SDL_Game
{
public:
	SDL_Game(SDL_State* initial_state);
	~SDL_Game();

public:
	static int FPS;
	static SDL_Rect window_rect;

	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static const Uint8* keystate;

	static SDL_State* game_state;


public:



};






