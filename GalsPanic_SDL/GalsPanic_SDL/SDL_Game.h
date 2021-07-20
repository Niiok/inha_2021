#pragma once

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_State.h"

static constexpr int INITIAL_FPS = 1000 / 60;
static constexpr int INITIAL_WIDTH = 1024;
static constexpr int INITIAL_HEIGHT = 1024;

class SDL_Game
{
public:
	SDL_Game();
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
	inline void SetState(SDL_State* state) { game_state = state; }
	void Run();


};






