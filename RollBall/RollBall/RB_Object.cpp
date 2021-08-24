#include "RB_Object.h"

void RB_Object::Plan()
{
	//auto loc = getLocation();
	//
	//RB_Object* player = (RB_Object*)RB_Manager::Instance().getPlayer();
	//auto p_loc = player->getLocation();
	//
	//loc.x += (p_loc.x - getLocation().x)/100;
	//loc.y += (p_loc.y - getLocation().y)/100;
	//
	//setPlanLocation(loc);
}

void RB_Object::Update()
{
	Locate();
}

void RB_Object::Draw() const
{
	SDL_Rect rect = ObjectArea((iObject*)this);

	//SDL_RenderCopy(SDLpp_Game::renderer, )
	if (animator_ == NULL)
	{
		SDL_SetRenderDrawColor(SDLpp_Game::renderer, 100, 100, 100, 100);
		SDL_RenderFillRect(SDLpp_Game::renderer, &rect);
	}
	else
	{
		animator_->DrawSprite(state_, direct_, SDL_GetTicks() / 10, &rect);
	}
}

