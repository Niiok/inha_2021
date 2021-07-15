#include "GalsEnemy.h"

GalsEnemy::GalsEnemy()
{
	location_.x = 0.5;
	location_.y = 0.5;
	size_ = 0.1;

	rect_.x = (location_.x-size_/2) * SDL_Game::window_rect.w;
	rect_.y = (location_.y-size_/2) * SDL_Game::window_rect.h;
	rect_.w = size_ * SDL_Game::window_rect.w;
	rect_.h = size_ * SDL_Game::window_rect.h;
}

void GalsEnemy::Update()
{
}

void GalsEnemy::Draw()
{


	SDL_SetRenderDrawColor(SDL_Game::renderer, 128, 0, 0, 255);
	SDL_RenderFillRect(SDL_Game::renderer, &rect_);
}
