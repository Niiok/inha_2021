#include "SDL_cTexture.h"

SDL_cTexture::SDL_cTexture(const char * fname)
	:fname_{ fname }
{
	SDL_Surface* surf = IMG_Load(fname);
	if (!surf)
	{
		printf("image load fail : %s\n", fname);
		return;
	}

	width_ = surf->w;
	height_ = surf->h;

	texture_ = SDL_CreateTextureFromSurface(SDL_Game::renderer, surf);
	if (!texture_)
		printf("image convert fail : %s\n", fname);

	SDL_FreeSurface(surf);
}

SDL_cTexture::~SDL_cTexture()
{
	SDL_DestroyTexture(texture_);
}
