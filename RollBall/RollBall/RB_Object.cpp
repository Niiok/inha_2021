#include "RB_Object.h"

void RB_Object::Plan()
{
	auto loc = getLocation();

	//loc.x += (RollBall::Instance().getPlayer()->getLocation().x - getLocation().x)/100;
	//loc.y += (RollBall::Instance().getPlayer()->getLocation().y - getLocation().y)/100;

	setPlanLocation(loc);
}

void RB_Object::Update()
{
	Locate();
}

void RB_Object::Draw() const
{
	SDL_Rect rect = ObjectArea((iObject*)this);

	//SDL_RenderCopy(SDL_Game::renderer, )
	SDL_SetRenderDrawColor(SDL_Game::renderer, 100, 100, 100, 125);
	SDL_RenderFillRect(SDL_Game::renderer, &rect);
}

