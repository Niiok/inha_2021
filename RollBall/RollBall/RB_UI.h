#pragma once

#include <SDL_ttf.h>
#include "SDL_Game.h"
#include "SDL_cTexture.h"
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
	SDL_cTexture texture_;
	SDL_Rect area_ = { 64, 32, 0, 0 };
	SDL_Point center_ = {0, 0};
};

