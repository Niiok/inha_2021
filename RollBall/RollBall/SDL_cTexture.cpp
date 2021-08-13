#include "SDL_cTexture.h"

SDL_cTexture::SDL_cTexture()
{
}

SDL_cTexture::SDL_cTexture(const char * fname)
	:fname_{ fname }
{
	MakeImage(fname);
}

SDL_cTexture::~SDL_cTexture()
{
	FreeTexture();
}

bool SDL_cTexture::MakeImage(const char * fname)
{
	FreeTexture();

	SDL_Surface* surf = IMG_Load(fname);
	if (!surf)
	{
		printf("image load fail : %s\n", fname);
		return false;
	}

	SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 255, 0, 255));

	width_ = surf->w;
	height_ = surf->h;

	texture_ = SDL_CreateTextureFromSurface(SDL_Game::renderer, surf);
	if (!texture_)
		printf("image convert fail : %s\n", fname);

	SDL_FreeSurface(surf);

	return texture_;
}

bool SDL_cTexture::MakeTTF(const char * str, SDL_Color color)
{
	FreeTexture();

	SDL_Surface* surf = TTF_RenderText_Solid(SDL_Game::font, str, color);
	
	if (!surf)
	{
		printf("ttf load fail : %s\n", str);
		return false;
	}

	width_ = surf->w;
	height_ = surf->h;

	texture_ = SDL_CreateTextureFromSurface(SDL_Game::renderer, surf);
	if (!texture_)
		printf("ttf convert fail : %s\n", str);

	SDL_FreeSurface(surf);

	return texture_;
}

void SDL_cTexture::FreeTexture()
{
	fname_ = "";
	width_ = 0;
	height_ = 0;
	SDL_DestroyTexture(texture_);
}
