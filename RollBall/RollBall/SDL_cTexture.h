#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "SDL_Game.h"

class SDL_cTexture
{
public:
	SDL_cTexture(const char* fname);
	~SDL_cTexture();

	inline operator SDL_Texture*() { return texture_; };
	inline int getWidth() { return width_; }
	inline int getHeight() { return height_; }

private:
	SDL_Texture* texture_ = NULL;
	std::string fname_;
	int width_ = 0;
	int height_ = 0;
};

