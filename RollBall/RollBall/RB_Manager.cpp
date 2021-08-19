#include "RB_Manager.h"

RB_Manager* RB_Manager::singleton_ = NULL;


SDL_Rect ObjectArea(oun::iObject * obj)
{
	SDL_Rect area;
	float volume = obj->getVolume();

	//int longer = RB_Manager::getLonger();

	auto bound = RB_Manager::Instance().getWorld().getBound();
	auto world_loc = obj->getPlanWorldLocation();
	area.x = (world_loc.x - volume / 2 - bound.x) / bound.w * SDLpp_Game::window_rect.w;
	area.y = (world_loc.y - volume - bound.y) / bound.h * SDLpp_Game::window_rect.h;
	area.w = (volume / bound.w) * SDLpp_Game::window_rect.w;
	area.h = (volume / bound.h) * SDLpp_Game::window_rect.h;

	return area;
}

void RB_Manager::Init(iRollBall * rb)
{
	if (singleton_ == NULL)
		singleton_ = new RB_Manager;

	singleton_->rb_.push(rb);
}

void RB_Manager::Quit()
{
	if (singleton_ == NULL || singleton_->rb_.empty())
		assert(0);

	singleton_->rb_.pop();

	if (singleton_->rb_.empty())
	{
		delete singleton_;
		singleton_ = NULL;
	}
}
