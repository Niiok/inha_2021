#include "RB_Object.h"

void RB_Object::Plan()
{
	auto loc = getLocation();

	//loc.x += sinf(float(rand()%10000)/10000-0.5);
	//loc.y += cosf(float(rand()%10000)/10000-0.5);

	setPlanLocation(loc);
}

void RB_Object::Update()
{
	Locate();
}

void RB_Object::Draw() const
{
	SDL_Rect rect;
	auto bound = getWorld()->getBound();
	auto world_loc = getWorldLocation();
	rect.x = (world_loc.x - bound.x) / bound.w * SDL_Game::window_rect.w;
	rect.y = (world_loc.y - bound.y) / bound.h * SDL_Game::window_rect.h;
	rect.w = (getVolume() / bound.w) * SDL_Game::window_rect.w;
	rect.h = (getVolume() / bound.h) * SDL_Game::window_rect.h;

	//SDL_RenderCopy(SDL_Game::renderer, )
	SDL_SetRenderDrawColor(SDL_Game::renderer, 100, 100, 100, 255);
	SDL_RenderFillRect(SDL_Game::renderer, &rect);
}
