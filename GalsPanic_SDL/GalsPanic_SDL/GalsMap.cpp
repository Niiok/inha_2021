#include "GalsMap.h"


GalsMap::GalsMap()
{
	vertices_static_.push_back({ 0.001f, 0.001f });
	vertices_static_.push_back({ 0.999f, 0.001f });
	vertices_static_.push_back({ 0.999f, 0.999f });
	vertices_static_.push_back({ 0.001f, 0.999f });
	//vertices.push_back({0.0, 0.0});
	//vertices.push_back({0.0, 1.0});
	//vertices.push_back({1.0, 1.0});
	//vertices.push_back({1.0, 0.0});

	{

		SDL_Surface* image_surface = IMG_Load("../data/background.png");
		SDL_assert(image_surface != NULL);

		background_origin_ = SDL_CreateTextureFromSurface(SDL_Game::renderer, image_surface);
		SDL_assert(background_origin_ != NULL);

		//background_ = SDL_CreateTextureFromSurface(SDL_Game::renderer, image_surface);

		//polygon_ = SDL_CreateTextureFromSurface(SDL_Game::renderer, image_surface);

		background_ = SDL_CreateTexture(
			SDL_Game::renderer, 
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET,
			SDL_Game::window_rect.w , SDL_Game::window_rect.h);
		SDL_assert(background_ != NULL);
		
		polygon_ = SDL_CreateTexture(
			SDL_Game::renderer, 
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET,
			SDL_Game::window_rect.w, SDL_Game::window_rect.h);
		SDL_assert(polygon_ != NULL);

		RefreshBackground();

		SDL_FreeSurface(image_surface);
	}
}

GalsMap::~GalsMap()
{
	SDL_DestroyTexture(background_origin_);
	SDL_DestroyTexture(background_);
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

void GalsMap::RefreshBackground()
{
	// polygon refresh

	SDL_Renderer* game_renderer = SDL_Game::renderer;	// dont delete this renderer!
	SDL_BlendMode origin_blend;
	SDL_GetRenderDrawBlendMode(game_renderer, &origin_blend);


	SDL_SetRenderTarget(game_renderer, polygon_);

	SDL_SetRenderDrawColor(game_renderer, 0, 0, 0, 0);
	SDL_RenderClear(game_renderer);

	SDL_SetRenderDrawBlendMode(game_renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(game_renderer, 1, 1, 1, 220);
	int vs_size = vertices_static_.size();


	for (int i = SDL_Game::window_rect.h; i > 0; --i)
	{
		std::queue<floatXY> inters;

		for (int j = 0; j < vs_size; ++j)
		{
			int next_j = (j != vs_size - 1 ? j + 1 : 0);

			floatXY inter = OverlapLine(
				{ -0.1, (float)i / SDL_Game::window_rect.h }, { 1.1, (float)i / SDL_Game::window_rect.h },
				vertices_static_[j], vertices_static_[next_j]);

			if (inter.x != -1)
			{
				inters.push(inter);
			}
		}

		while (inters.size() >= 2)
		{
			floatXY src, dst;
			src = inters.front();
			inters.pop();
			dst = inters.front();
			inters.pop();

			src.x *= SDL_Game::window_rect.w;
			src.y *= SDL_Game::window_rect.h;
			dst.x *= SDL_Game::window_rect.w;
			dst.y *= SDL_Game::window_rect.h;

			SDL_RenderDrawLine(game_renderer, src.x, src.y, dst.x, dst.y);
		}
	}
	SDL_SetRenderDrawBlendMode(game_renderer, origin_blend);


	// background refresh with polygon & background origin
	SDL_SetRenderTarget(game_renderer, background_);
	SDL_RenderCopy(game_renderer, background_origin_, NULL, NULL);

	SDL_SetTextureBlendMode(polygon_, SDL_BLENDMODE_BLEND);
	SDL_RenderCopy(game_renderer, polygon_, NULL, NULL);


	SDL_SetRenderTarget(game_renderer, NULL);
}


void GalsMap::MergeVertices(int src, int dst)
{
	// vertices_temp_.begin() = first connection
	// vertices_temp_.end()-1 = last connection
	// src = src line area's index
	// dst = dst line area's index

		floatXY till = vertices_static_[dst];
		int index = player_->in_line;
		while (till.x != vertices_static_[index].x
			|| till.y != vertices_static_[index].y)
		{
			vertices_static_.erase(vertices_static_.begin() + index);

			index = (index == vertices_static_.size() - 1 ? 0 : index);
		}



}