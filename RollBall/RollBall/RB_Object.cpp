#include "RB_Object.h"

//void RB_Object::Plan()
//{
//
//}

//void RB_Object::Update()
//{
////	Locate();
//}

void RB_Object::Draw() const
{
	SDL_Rect rect;
	auto bound = getWorld()->getBound();
	auto world_loc = getWorldLocation();
	rect.x = (world_loc.x + getVolume() - bound.x) / bound.w * SDL_Game::window_rect.w;
	rect.y = (world_loc.y + getVolume() - bound.y) / bound.h * SDL_Game::window_rect.h;
	rect.w = getVolume() / bound.w * SDL_Game::window_rect.w;
	rect.h = getVolume() / bound.h * SDL_Game::window_rect.h;

	//SDL_RenderCopy(SDL_Game::renderer, )
	SDL_SetRenderDrawColor(SDL_Game::renderer, 100, 100, 100, 255);
	SDL_RenderFillRect(SDL_Game::renderer, &rect);
}
