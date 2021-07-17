#include "GalsEnemy.h"


GalsEnemy::GalsEnemy(GalsMap& map) : map_{ &map }
{
	location_.x = 0.5f;
	location_.y = 0.5f;
	size_ = 0.1f;

	rect_.x = (location_.x-size_/2) * SDL_Game::window_rect.w;
	rect_.y = (location_.y-size_/2) * SDL_Game::window_rect.h;
	rect_.w = size_ * SDL_Game::window_rect.w;
	rect_.h = size_ * SDL_Game::window_rect.h;

	srand(time(NULL));
}

void GalsEnemy::Update()
{
	static int move_count = 0;
	constexpr float max_short = 32767.0f;

	if (move_count == 0)
	{
		move_count = rand() % (SDL_Game::FPS * 3);

		int ran_val = rand();
		
		old_direction.x = (ran_val % (int)max_short) / max_short;
		old_direction.y = (ran_val / (int)max_short) / max_short;
	}

	//for(int i = map_->vertices_static_.size()-1; )


	--move_count;
}

void GalsEnemy::Draw()
{


	SDL_SetRenderDrawColor(SDL_Game::renderer, 128, 0, 0, 255);
	SDL_RenderFillRect(SDL_Game::renderer, &rect_);
}
