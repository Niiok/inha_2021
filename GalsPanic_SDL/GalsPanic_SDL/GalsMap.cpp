#include "GalsMap.h"


GalsMap::GalsMap()
{
	vertices_static_.push_back({ 0.005f, 0.005f });
	vertices_static_.push_back({ 0.995f, 0.005f });
	vertices_static_.push_back({ 0.995f, 0.995f });
	vertices_static_.push_back({ 0.005f, 0.995f });
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

	if (vertices_temp_.size() > 0 && draw_temp_ == 1)
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


floatXY GalsMap::CollWithPolygon(floatXY src, floatXY dst, int* i)
{
	int index;

	int vs_size = vertices_static_.size();
	for (index = 0; index < vs_size; ++(index))
	{
		int next_i = (index != vs_size - 1 ? index + 1 : 0);

		floatXY inter = OverlapLine(
			src, dst,
			vertices_static_[index], vertices_static_[next_i]);

		if (inter.x != -1)
		{
			if (i != nullptr)
				*i = index;

			return inter;
		}
	}
	index = -1;

	if (i != nullptr)
		*i = index;
	return { -1, -1 };
}


floatXY GalsMap::CollWithFootprint(floatXY src, floatXY dst, int* i)
{
	int index;

	int vt_size = vertices_temp_.size();
	for (index = 0; index < vt_size; ++index)
	{
		floatXY inter;

		if (index == vt_size - 1)
			inter = OverlapLine(src, dst,
				vertices_temp_[index],
				{ player_->location_.x, player_->location_.y });
		else
			inter = OverlapLine(src, dst,
				vertices_temp_[index],
				vertices_temp_[index + 1]);

		if (inter.x != -1)
		{
			if (i != nullptr)
				*i = index;

			return inter;
		}
	}
	index = -1;

	if (i != nullptr)
		*i = index;
	return { -1, -1 };
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
	int ij = 0;
	int dj = 1;

	/*if (reverse == -1)
	{
		ij = vs_size - 1;
		vs_size = -1;
		dj = -1;
	}*/

	for (int i = SDL_Game::window_rect.h; i > 0; --i)
	{
		std::priority_queue<floatXY, std::vector<floatXY>, floatXY_less> inters;


		for (int j = ij; j != vs_size; j += dj)
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
			src = inters.top();
			inters.pop();
			dst = inters.top();
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

	PolygonSize();
}


void GalsMap::MergeVertices(int src, int dst)
{
	// vertices_temp_.begin() : first connection
	// vertices_temp_.end()-1 : last connection
	// src : started static line area's index
	// dst : ended static line area's index

	std::vector<floatXY> cw = vertices_temp_;
	std::vector<floatXY> ccw = vertices_temp_;


	int static_size = vertices_static_.size();



	//  cw
	// push_back (dst, src] by increasing
	{
		int from = (dst + 1 == static_size ? 0 : dst + 1);
		int to = src;

		do
		{
			if (from == static_size)
				from = 0;

			cw.push_back(vertices_static_[from]);

			from++;
		} while (from != to + 1);
	}

	//  ccw
	// push_back [dst, src) by decreasing
	{
		int from = dst;
		int to = (src + 1 == static_size ? 0 : src + 1);

		do
		{
			if (from == -1)
				from = static_size - 1;

			ccw.push_back(vertices_static_[from]);

			from--;
		} while (from != to - 1);
	}


	std::queue<floatXY> inters_cw;
	
	for (int j = 0; j < cw.size(); ++j)
	{
		int next_j = (j != cw.size() - 1 ? j + 1 : 0);

		floatXY inter = OverlapLine(
			{ -0.1, enemy_->location_.y }, 
			{ enemy_->location_.x, enemy_->location_.y},
			cw[j], cw[next_j]);

		if (inter.x != -1)
		{
			inters_cw.push(inter);
		}
	}



	if (src == dst)
	{
		if (player_->out_move_degree*reverse > 0)
			vertices_static_.assign(cw.begin(), cw.end());
		else
		{
			vertices_static_.assign(ccw.begin(), ccw.end());
			reverse *= -1;
		}
	}
	else if(inters_cw.size() % 2 == 1)
	{
		vertices_static_.assign(cw.begin(), cw.end());
	}
	else
	{
		vertices_static_.assign(ccw.begin(), ccw.end());
		reverse *= -1;
	}

	player_->in_line = vertices_temp_.size() - 1;
	player_->old_line = -1;
	vertices_temp_[0] = vertices_temp_[vertices_temp_.size() - 1];


	RefreshBackground();
}

void GalsMap::PolygonSize()
{
	float x_mul_y = 0;
	float y_mul_x = 0;

	for (auto i = vertices_static_.begin(); i != vertices_static_.end(); ++i )
	{
		auto next = i + 1;
		if (next == vertices_static_.end())
			next = vertices_static_.begin();

		x_mul_y += i->x * next->y;
		y_mul_x += i->y * next->x;
	}

	polygon_size_ = abs(x_mul_y - y_mul_x) / 2;

	static float origin_size = polygon_size_;

	printf("\t%.2f\%\n", 100.0f - polygon_size_ / origin_size * 100.0f);
	
	if (enemy_ != NULL)
		enemy_->size_ = enemy_->size_rate_*(polygon_size_*0.5 + 0.5);
}