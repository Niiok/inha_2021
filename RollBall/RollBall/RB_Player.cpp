#include "RB_Player.h"

void RB_Player::Plan()
{
	oun::floatXYZ plan = getLocation();
	float plan_vol = getVolume();

	if (SDL_Game::keystate[SDL_SCANCODE_UP])
		plan.y -= getSpeed();
	if (SDL_Game::keystate[SDL_SCANCODE_DOWN])
		plan.y += getSpeed();
	if (SDL_Game::keystate[SDL_SCANCODE_LEFT])
		plan.x -= getSpeed();
	if (SDL_Game::keystate[SDL_SCANCODE_RIGHT])
		plan.x += getSpeed();
	if (SDL_Game::keystate[SDL_SCANCODE_EQUALS])
		plan_vol *= 2;
	if (SDL_Game::keystate[SDL_SCANCODE_MINUS])
		plan_vol /= 2;

	
	setPlanLocation(plan);
	setPlanVolume(plan_vol);
}

void RB_Player::Update()
{
	Locate();
}

void RB_Player::Draw() const
{
	SDL_Rect rect;
	auto bound = getWorld()->getBound();
	auto world_loc = getWorldLocation();
	rect.x = (world_loc.x /*+ getVolume()*/ - bound.x) / bound.w * SDL_Game::window_rect.w;
	rect.y = (world_loc.y /*+ getVolume()*/ - bound.y) / bound.h * SDL_Game::window_rect.h;
	rect.w = getVolume() / bound.w * SDL_Game::window_rect.w;
	rect.h = getVolume() / bound.h * SDL_Game::window_rect.h;

	//SDL_RenderCopy(SDL_Game::renderer, )
	SDL_SetRenderDrawColor(SDL_Game::renderer, 200, 200, 200, 255);
	SDL_RenderDrawRect(SDL_Game::renderer, &rect);

	printf("%f %f\n", getLocation().x, getLocation().y);
	printf("%f %f\n\n", getPlanLocation().x, getPlanLocation().y);

}
