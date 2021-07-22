#include "GalsPlayer.h"


GalsPlayer::GalsPlayer(GalsMap& map) : map_{ &map }
{
	location_.x = map_->vertices_static_[0].x;
	location_.y = map_->vertices_static_[0].y;
}

GalsPlayer::~GalsPlayer()
{

}


void GalsPlayer::Draw()
{
	SDL_Rect win = SDL_Game::window_rect;

	SDL_SetRenderDrawColor(SDL_Game::renderer,
		128 - sin((float)SDL_GetTicks() / 200) * 127,
		255,
		128 + sin((float)SDL_GetTicks() / 200) * 127,
		255);

	SDL_Rect player_rect = { (location_.x - 0.01)*win.w,
	(location_.y - 0.01)*win.h,
	0.02*win.w,
	0.02*win.h };
	SDL_RenderDrawRect(SDL_Game::renderer, &player_rect);

	for (int i = 0; i < life_; ++i)
	{
		SDL_SetRenderDrawColor(SDL_Game::renderer, 200, 100, 100, 50);

		SDL_Rect heart{ 0.02*(i + 1) * win.w,
		0.02 * win.h,
		0.03 * (i + 1) * win.w,
		0.03 * win.h };
		SDL_RenderFillRect(SDL_Game::renderer, &heart);
	}
}

void GalsPlayer::Update()
{
	switch (move_mode_)
	{
	case 0:
		MoveOut();
		break;

	case 1:
		MoveIn();
		break;

	case 2:
		Died();
		break;
	}

	if (SDL_Game::keystate[SDL_SCANCODE_SPACE])
	{
		static int count = 0;
		if (count == 0)
		{
			printf("\t change!\n");

			MoveModeChange(1 - move_mode_);

			count = SDL_Game::FPS / 2;
		}
		else if (count > 0)
			--count;
	}

}


void GalsPlayer::MoveIn()
{
	static int next_line;
	static int prev_line;

	static float src_vertex_x;
	static float src_vertex_y;
	static float dst_vertex_x;
	static float dst_vertex_y;

	static float dx;
	static float dy;

	static float gradient;

	// walkway setting
	if (old_line != in_line)
	{
		next_line = (in_line + 1 == map_->vertices_static_.size() ? 0 : in_line + 1);
		prev_line = (in_line - 1 == -1 ? map_->vertices_static_.size() - 1 : in_line - 1);

		src_vertex_x = map_->vertices_static_[in_line].x;
		src_vertex_y = map_->vertices_static_[in_line].y;
		dst_vertex_x = map_->vertices_static_[next_line].x;
		dst_vertex_y = map_->vertices_static_[next_line].y;

		dx = dst_vertex_x - src_vertex_x;
		dy = dst_vertex_y - src_vertex_y;

		gradient = dy / dx;
		//printf("\tgradient  = %f\n", gradient);

		if (isnan(gradient))
		{
			if (in_line == 0 && old_line != 1)
			{
				in_line = 1;
				return;
			}
			else if (old_line == 0 && in_line != 1)
			{
				in_line = map_->vertices_static_.size() - 2;
				return;
			}


			in_line += (in_line - old_line) / abs(in_line - old_line);

			if (in_line == map_->vertices_static_.size())
				in_line = 0;
			else if (in_line == -1)
				in_line = map_->vertices_static_.size() - 1;

			return;
		}

		old_line = in_line;
	}

	// move
	if (abs(gradient) < 1.001 && abs(gradient) > 0.999)
	{
		int key_pressed = 0;

		if (SDL_Game::keystate[SDL_SCANCODE_UP])
			if (location_.y > 0.0)
			{
				location_.y -= speed_;
				location_.x -= speed_ * gradient;
				key_pressed += 1;
			}

		if (SDL_Game::keystate[SDL_SCANCODE_DOWN])
			if (location_.y < 1.0)
			{
				location_.y += speed_;
				location_.x += speed_ * gradient;
				key_pressed += -1;
			}

		if (SDL_Game::keystate[SDL_SCANCODE_LEFT] && key_pressed == 0)
			if (location_.x > 0.0)
			{
				location_.x -= speed_;
				location_.y -= speed_ * gradient;
			}

		if (SDL_Game::keystate[SDL_SCANCODE_RIGHT] && key_pressed == 0)
			if (location_.x < 1.0)
			{
				location_.x += speed_;
				location_.y += speed_ * gradient;
			}
	}
	else if (abs(gradient) < 1) // gradient < 1
	{
		if (SDL_Game::keystate[SDL_SCANCODE_LEFT])
			if (location_.x > 0.0)
			{
				location_.x -= speed_;
				location_.y -= speed_ * gradient;
			}

		if (SDL_Game::keystate[SDL_SCANCODE_RIGHT])
			if (location_.x < 1.0)
			{
				location_.x += speed_;
				location_.y += speed_ * gradient;
			}
	}
	else //if(SDL_abs(gradient) > 1)	// inf
	{
		if (SDL_Game::keystate[SDL_SCANCODE_UP])
			if (location_.y > 0.0)
			{
				location_.y -= speed_;
				location_.x -= speed_ / gradient;
			}

		if (SDL_Game::keystate[SDL_SCANCODE_DOWN])
			if (location_.y < 1.0)
			{
				location_.y += speed_;
				location_.x += speed_ / gradient;
			}
	}

	// which line am i standing
		// x compare
	if (dx < 0)	// src x is bigger
	{
		if (location_.x > src_vertex_x)
		{
			location_.x = map_->vertices_static_[in_line].x;
			location_.y = map_->vertices_static_[in_line].y;
			in_line = prev_line;
			return;
		}
		if (location_.x < dst_vertex_x)
		{
			location_.x = map_->vertices_static_[next_line].x;
			location_.y = map_->vertices_static_[next_line].y;
			in_line = next_line;
			return;
		}
	}
	else if (dx > 0)	// dst x is bigger
	{
		if (location_.x < src_vertex_x)
		{
			location_.x = map_->vertices_static_[in_line].x;
			location_.y = map_->vertices_static_[in_line].y;
			in_line = prev_line;
			return;
		}
		if (location_.x > dst_vertex_x)
		{
			location_.x = map_->vertices_static_[next_line].x;
			location_.y = map_->vertices_static_[next_line].y;
			in_line = next_line;
			return;
		}
	}
	// y compare
	if (dy < 0)	// src y is bigger
	{
		if (location_.y > src_vertex_y)
		{
			location_.x = map_->vertices_static_[in_line].x;
			location_.y = map_->vertices_static_[in_line].y;
			in_line = prev_line;
			return;
		}
		if (location_.y < dst_vertex_y)
		{
			location_.x = map_->vertices_static_[next_line].x;
			location_.y = map_->vertices_static_[next_line].y;
			in_line = next_line;
			return;
		}
	}
	else if (dy > 0)	// dst y is bigger
	{
		if (location_.y < src_vertex_y)
		{
			location_.x = map_->vertices_static_[in_line].x;
			location_.y = map_->vertices_static_[in_line].y;
			in_line = prev_line;
			return;
		}
		if (location_.y > dst_vertex_y)
		{
			location_.x = map_->vertices_static_[next_line].x;
			location_.y = map_->vertices_static_[next_line].y;
			in_line = next_line;
			return;
		}
	}
}

void GalsPlayer::MoveOut()
{
	intXY new_direction = { 0, 0 };

	if (SDL_Game::keystate[SDL_SCANCODE_UP] && location_.y > 0.0)
		new_direction.y -= 2;

	if (SDL_Game::keystate[SDL_SCANCODE_DOWN] && location_.y < 1.0)
		new_direction.y += 2;

	if (SDL_Game::keystate[SDL_SCANCODE_LEFT] && location_.x > 0.0)
		new_direction.x -= 2;

	if (SDL_Game::keystate[SDL_SCANCODE_RIGHT] && location_.x < 1.0)
		new_direction.x += 2;


	if (abs(new_direction.x * 4 + new_direction.y) != abs(old_direction.x * 4 + old_direction.y)
		&& (new_direction.x * 4 + new_direction.y) != 0)
	{

		map_->vertices_temp_.push_back({ location_.x, location_.y });

		int diff = new_direction.x*old_direction.y - new_direction.y*old_direction.x;
		out_move_degree += diff;

		old_direction = new_direction;
	}


	if (SDL_Game::keystate[SDL_SCANCODE_UP] && location_.y - speed_ > 0.0)
		location_.y -= speed_;

	if (SDL_Game::keystate[SDL_SCANCODE_DOWN] && location_.y + speed_ < 1.0)
		location_.y += speed_;

	if (SDL_Game::keystate[SDL_SCANCODE_LEFT] && location_.x - speed_ > 0.0)
		location_.x -= speed_;

	if (SDL_Game::keystate[SDL_SCANCODE_RIGHT] && location_.x + speed_ < 1.0)
		location_.x += speed_;



	Coll_Line();
	Coll_Enemy();
}

void GalsPlayer::Died()
{
	location_.x += (respawn_count_ % 4  > 1 ? -1 : 1)* 0.005;

	respawn_count_--;

	if (respawn_count_ == 0)
		MoveModeChange(1);
}


void GalsPlayer::MoveModeChange(int i)
{
	static floatXY backup;

	switch (move_mode_)	// quit
	{
	case 0:		// out to in  ==  inmove initial
		break;

	case 1:		// in to out  ==  outmove initial
		backup = location_;
		break;

	case 2:
		map_->draw_temp_ = 1;
		break;
	}


	switch (i)	// init
	{
	case 0:
		old_direction = { 0, 0 };
		out_move_degree = 0;
		//map_->vertices_temp_.push_back({ location_.x, location_.y });
		break;

	case 1:
		if (map_->vertices_temp_.size() > 0)
		{
			location_.x = map_->vertices_temp_[0].x;
			location_.y = map_->vertices_temp_[0].y;
		}
		else
			location_ = backup;
		map_->vertices_temp_.clear();
		break;

	case 2:
		respawn_count_ = SDL_Game::FPS * 3;
		map_->draw_temp_ = 0;
		--life_;
		break;
	}


	move_mode_ = i;
}







void GalsPlayer::Coll_Line()
{
	if (map_->vertices_temp_.size() > 0)
	{
		int i;

		floatXY inter = map_->CollWithPolygon(
			map_->vertices_temp_[map_->vertices_temp_.size() - 1],
			{ location_.x, location_.y }, &i);

		if (inter.x != -1)
		{
			map_->vertices_temp_.push_back(inter);
			map_->MergeVertices(in_line, i);

			MoveModeChange(1);
			return;
		}


		// temp lines
		//int vt_size = map_->vertices_temp_.size();
		//for (int i = 0; i < vt_size; ++i)
		//{
		//	int next_i = (i != vt_size - 1 ? i + 1 : 0);

		//	floatXY inter = OverlapLine(
		//		map_->vertices_temp_[vt_size - 1], { location_.x, location_.y },
		//		map_->vertices_temp_[i], map_->vertices_temp_[next_i]);

			inter = map_->CollWithFootprint(
				map_->vertices_temp_[map_->vertices_temp_.size() - 1],
				{ location_.x, location_.y });

			if (inter.x != -1)
			{
				MoveModeChange(1);
				return;
			}
		
	}
}


void GalsPlayer::Coll_Enemy()
{
	floatXY enemy_loc = map_->enemy_->location_;
	float enemy_size = map_->enemy_->size_/2;

	float enemy_left = enemy_loc.x - enemy_size;
	float enemy_top = enemy_loc.y - enemy_size;
	float enemy_right = enemy_loc.x + enemy_size;
	float enemy_bottom = enemy_loc.y + enemy_size;

	if (location_.x >= enemy_left &&
		location_.y >= enemy_top &&
		location_.x <= enemy_right &&
		location_.y <= enemy_bottom )
		MoveModeChange(2);

}