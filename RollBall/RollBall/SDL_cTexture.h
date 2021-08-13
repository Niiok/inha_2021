#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "SDL_Game.h"
#include <string>


class SDL_cTexture
{
public:
	SDL_cTexture();
	SDL_cTexture(const char* fname);
	~SDL_cTexture();

	inline operator SDL_Texture*() { return texture_; };
	inline int getWidth() { return width_; }
	inline int getHeight() { return height_; }
	bool MakeImage(const char* fname);
	bool MakeTTF(const char* str, SDL_Color color);
	void FreeTexture();

private:
	SDL_Texture* texture_ = NULL;
	std::string fname_;
	int width_ = 0;
	int height_ = 0;
};

