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
		plan_vol *= 1.1;
	if (SDL_Game::keystate[SDL_SCANCODE_MINUS])
		plan_vol /= 1.1;

	
	setPlanLocation(plan);
	if (plan_vol * getWorld()->getZoom()*2 < oun::MAX_SPACE_SCALE)
		setPlanVolume(plan_vol);
	setSpeed(plan_vol/SDL_Game::FPS);

}

void RB_Player::Update()
{
	Locate();
}

void RB_Player::Draw() const
{
	SDL_Rect rect;
	int longer = (SDL_Game::window_rect.h > SDL_Game::window_rect.w ? SDL_Game::window_rect.h : SDL_Game::window_rect.w);

	auto bound = getWorld()->getBound();
	auto world_loc = getWorldLocation();
	rect.x = (world_loc.x - bound.x) / bound.w * longer;
	rect.y = (world_loc.y - bound.y) / bound.h * longer;
	rect.w = (getVolume() / bound.w) * longer;
	rect.h = (getVolume() / bound.h) * longer;

	//SDL_RenderCopy(SDL_Game::renderer, )
	SDL_SetRenderDrawColor(SDL_Game::renderer, 200, 200, 200, 255);
	SDL_RenderFillRect(SDL_Game::renderer, &rect);

	//printf("%d : %f %f\n", in_world_, getLocation().x, getLocation().y);
	//printf("%f %f\n\n", getPlanLocation().x, getPlanLocation().y);
}

bool RB_Player::AttachObjectToBall(RB_Object * obj)
{

	return false;
}
