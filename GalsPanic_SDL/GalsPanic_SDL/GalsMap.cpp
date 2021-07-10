#include "GalsMap.h"


GalsMap::GalsMap()
{
	SDL_assert(	IMG_Init(IMG_INIT_PNG) );
	vertices_static_.push_back({ 0.5f, 0.5f });
	vertices_static_.push_back({ 0.6f, 0.5f });
	vertices_static_.push_back({ 0.6f, 0.6f });
	vertices_static_.push_back({ 0.5f, 0.6f });
	//vertices.push_back({0.0, 0.0});
	//vertices.push_back({0.0, 1.0});
	//vertices.push_back({1.0, 1.0});
	//vertices.push_back({1.0, 0.0});

	{
		SDL_Surface* image_surface = IMG_Load("../data/background.png");
		printf("%p", image_surface);
		SDL_assert(image_surface != NULL);
		background_ = SDL_CreateTextureFromSurface(SDL_Game::renderer, image_surface);
		printf("%s", SDL_GetError());
		SDL_assert(background_ != NULL);
		SDL_FreeSurface(image_surface);
	}
}

GalsMap::~GalsMap()
{
	SDL_DestroyTexture(background_);
	IMG_Quit();
}

void GalsMap::Draw()
{

	SDL_RenderCopy(SDL_Game::renderer, background_, NULL, NULL);

	SDL_SetRenderDrawColor(SDL_Game::renderer, 255, 255, 255, 255);

	for (int i = 0; i < vertices_static_.size() - 1; ++i)
	{
		SDL_RenderDrawLine(SDL_Game::renderer, vertices_static_[i].x * SDL_Game::window_rect.w,
			vertices_static_[i].y * SDL_Game::window_rect.h,
			vertices_static_[i + 1].x * SDL_Game::window_rect.w,
			vertices_static_[i + 1].y * SDL_Game::window_rect.h);
	}
	SDL_RenderDrawLine(SDL_Game::renderer, vertices_static_[0].x * SDL_Game::window_rect.w,
		vertices_static_[0].y * SDL_Game::window_rect.h,
		vertices_static_[vertices_static_.size() - 1].x * SDL_Game::window_rect.w,
		vertices_static_[vertices_static_.size() - 1].y * SDL_Game::window_rect.h);


	SDL_SetRenderDrawColor(SDL_Game::renderer, 255, 0, 0, 255);

	if (vertices_temp_.size() > 0)
	{
		for (int i = 0; i < vertices_temp_.size() - 1; ++i)
		{
			SDL_RenderDrawLine(SDL_Game::renderer, vertices_temp_[i].x * SDL_Game::window_rect.w,
				vertices_temp_[i].y * SDL_Game::window_rect.h,
				vertices_temp_[i + 1].x * SDL_Game::window_rect.w,
				vertices_temp_[i + 1].y * SDL_Game::window_rect.h);
		}
		SDL_RenderDrawLine(SDL_Game::renderer, player_->location_.x * SDL_Game::window_rect.w,
			player_->location_.y * SDL_Game::window_rect.h,
			vertices_temp_[vertices_temp_.size() - 1].x * SDL_Game::window_rect.w,
			vertices_temp_[vertices_temp_.size() - 1].y * SDL_Game::window_rect.h);
	}
}


void GalsMap::Update()
{

}