#pragma once

#include <SDL_ttf.h>
#include "SDLpp_Game.h"
#include "SDLpp_Texture.h"
#include "RB_Manager.h"
#include "RB_Player.h"

class RB_Manager;

class RB_UI
{
public:
	RB_UI() {};
	~RB_UI() {};

	void Draw();

private:
	char str[128];
	char str2[128];
	SDLpp_Texture texture_;
	SDL_Rect area_ = { 64, 32, 0, 0 };
	SDL_Point center_ = {0, 0};
};

