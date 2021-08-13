#include "RB_Manager.h"

RB_Manager* RB_Manager::singleton_ = NULL;


SDL_Rect ObjectArea(oun::iObject * obj)
{
	SDL_Rect area;
	float volume = obj->getVolume();

	//int longer = RB_Manager::getLonger();

	auto bound = RB_Manager::Instance().getWorld().getBound();
	auto world_loc = obj->getPlanWorldLocation();
	area.x = (world_loc.x - volume / 2 - bound.x) / bound.w * SDL_Game::window_rect.w;
	area.y = (world_loc.y - volume - bound.y) / bound.h * SDL_Game::window_rect.h;
	area.w = (volume / bound.w) * SDL_Game::window_rect.w;
	area.h = (volume / bound.h) * SDL_Game::window_rect.h;

	return area;
}