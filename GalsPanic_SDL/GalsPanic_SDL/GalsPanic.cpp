#include "GalsPanic.h"


GalsPanic::GalsPanic()
{
	IMG_Init(IMG_INIT_PNG);
	vertices_static.push_back({player_x, player_y});
	vertices_static.push_back({player_x+0.1, player_y});
	vertices_static.push_back({player_x+0.1, player_y+0.1});
	vertices_static.push_back({player_x, player_y+0.1});
	//vertices.push_back({0.0, 0.0});
	//vertices.push_back({0.0, 1.0});
	//vertices.push_back({1.0, 1.0});
	//vertices.push_back({1.0, 0.0});
}

GalsPanic::~GalsPanic()
{

	IMG_Quit();
}


void GalsPanic::Input()
{

}

void GalsPanic::Process()
{

	switch (player_mode)
	{
	case 0:
		PlayerMoveOut();
		break;

	case 1:
		PlayerMoveIn();
			break;
	}

	if (SDL_Game::keystate[SDL_SCANCODE_SPACE])
	{
		static int count = 0;
		if (count == 0)
		{
			printf("\t change!\n");

			MovementChange();
			
			count = 2;
		}
		else if (count > 0)
			--count;
	}
}

void GalsPanic::Output()
{
	SDL_SetRenderDrawColor(SDL_Game::renderer, 0, 0, 0, 125);
	SDL_RenderFillRect(SDL_Game::renderer, NULL);
	SDL_SetRenderDrawColor(SDL_Game::renderer, 255, 255, 255, 255);

	SDL_Rect player_rect = { (player_x - 0.005)*SDL_Game::window_rect.w,
		(player_y - 0.005)*SDL_Game::window_rect.h,
		0.01*SDL_Game::window_rect.w, 
		0.01*SDL_Game::window_rect.h };
	SDL_RenderDrawRect(SDL_Game::renderer, &player_rect);

	for (int i = 0; i < vertices_static.size()-1; ++i)
	{
		SDL_RenderDrawLine(SDL_Game::renderer, vertices_static[i].first * SDL_Game::window_rect.w,
			vertices_static[i].second * SDL_Game::window_rect.h,
			vertices_static[i + 1].first * SDL_Game::window_rect.w,
			vertices_static[i + 1].second * SDL_Game::window_rect.h);
	}
	SDL_RenderDrawLine(SDL_Game::renderer, vertices_static[0].first * SDL_Game::window_rect.w,
		vertices_static[0].second * SDL_Game::window_rect.h,
		vertices_static[vertices_static.size() - 1].first * SDL_Game::window_rect.w,
		vertices_static[vertices_static.size() - 1].second * SDL_Game::window_rect.h);

	if (vertices_temp.size() > 0)
	{
		for (int i = 0; i < vertices_temp.size() - 1; ++i)
		{
			SDL_RenderDrawLine(SDL_Game::renderer, vertices_temp[i].first * SDL_Game::window_rect.w,
				vertices_temp[i].second * SDL_Game::window_rect.h,
				vertices_temp[i + 1].first * SDL_Game::window_rect.w,
				vertices_temp[i + 1].second * SDL_Game::window_rect.h);
		}
		SDL_RenderDrawLine(SDL_Game::renderer, player_x * SDL_Game::window_rect.w,
			player_y * SDL_Game::window_rect.h,
			vertices_temp[vertices_temp.size() - 1].first * SDL_Game::window_rect.w,
			vertices_temp[vertices_temp.size() - 1].second * SDL_Game::window_rect.h);
	}
}



void GalsPanic::PlayerMoveIn()
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

		next_line = (in_line + 1 == vertices_static.size() ? 0 : in_line + 1);
		prev_line = (in_line - 1 == -1 ? vertices_static.size() - 1 : in_line - 1);

		src_vertex_x = vertices_static[in_line].first;
		src_vertex_y = vertices_static[in_line].second;
		dst_vertex_x = vertices_static[next_line].first;
		dst_vertex_y = vertices_static[next_line].second;

		dx = dst_vertex_x - src_vertex_x;
		dy = dst_vertex_y - src_vertex_y;

		gradient = dy / dx;
		printf("\tgradient  = %f\n", gradient);
		old_line = in_line;
	}

	// move
	if (abs(gradient) < 1.001 && abs(gradient) > 0.999)
	{
		int key_pressed = 0;

		if (SDL_Game::keystate[SDL_SCANCODE_UP])
			if (player_y > 0.0)
			{
				player_y -= player_speed;
				player_x -= player_speed * gradient;
				key_pressed += 1;
			}

		if (SDL_Game::keystate[SDL_SCANCODE_DOWN])
			if (player_y < 1.0)
			{
				player_y += player_speed;
				player_x += player_speed * gradient;
				key_pressed += -1;
			}

		if (SDL_Game::keystate[SDL_SCANCODE_LEFT] && key_pressed == 0)
			if (player_x > 0.0)
			{
				player_x -= player_speed;
				player_y -= player_speed * gradient;
			}

		if (SDL_Game::keystate[SDL_SCANCODE_RIGHT] && key_pressed == 0)
			if (player_x < 1.0)
			{
				player_x += player_speed;
				player_y += player_speed * gradient;
			}
	}
	else if (abs(gradient) < 1) // gradient < 1
	{
		if (SDL_Game::keystate[SDL_SCANCODE_LEFT])
			if (player_x > 0.0)
			{
				player_x -= player_speed;
				player_y -= player_speed * gradient;
			}

		if (SDL_Game::keystate[SDL_SCANCODE_RIGHT])
			if (player_x < 1.0)
			{
				player_x += player_speed;
				player_y += player_speed * gradient;
			}
	}
	else //if(SDL_abs(gradient) > 1)	// inf
	{
		if (SDL_Game::keystate[SDL_SCANCODE_UP])
			if (player_y > 0.0)
			{
				player_y -= player_speed;
				player_x -= player_speed / gradient;
			}

		if (SDL_Game::keystate[SDL_SCANCODE_DOWN])
			if (player_y < 1.0)
			{
				player_y += player_speed;
				player_x += player_speed / gradient;
			}
	}

	// which line am i standing
		// x compare
	if (dx < 0)	// src x is bigger
	{
		if (player_x > src_vertex_x)
		{
			player_x = vertices_static[in_line].first;
			player_y = vertices_static[in_line].second;
			in_line = prev_line;
			return;
		}
		if (player_x < dst_vertex_x)
		{
			player_x = vertices_static[next_line].first;
			player_y = vertices_static[next_line].second;
			in_line = next_line;
			return;
		}
	}
	else if (dx > 0)	// dst x is bigger
	{
		if (player_x < src_vertex_x)
		{
			player_x = vertices_static[in_line].first;
			player_y = vertices_static[in_line].second;
			in_line = prev_line;
			return;
		}
		if (player_x > dst_vertex_x)
		{
			player_x = vertices_static[next_line].first;
			player_y = vertices_static[next_line].second;
			in_line = next_line;
			return;
		}
	}
		// y compare
	if (dy < 0)	// src y is bigger
	{
		if (player_y > src_vertex_y)
		{
			player_x = vertices_static[in_line].first;
			player_y = vertices_static[in_line].second;
			in_line = prev_line;
			return;
		}
		if (player_y < dst_vertex_y)
		{
			player_x = vertices_static[next_line].first;
			player_y = vertices_static[next_line].second;
			in_line = next_line;
			return;
		}
	}
	else if (dy > 0)	// dst y is bigger
	{
		if (player_y < src_vertex_y)
		{
			player_x = vertices_static[in_line].first;
			player_y = vertices_static[in_line].second;
			in_line = prev_line;
			return;
		}
		if (player_y > dst_vertex_y)
		{
			player_x = vertices_static[next_line].first;
			player_y = vertices_static[next_line].second;
			in_line = next_line;
			return;
		}
	}
}

void GalsPanic::PlayerMoveOut()
{
	int new_direction = 0;


	if (SDL_Game::keystate[SDL_SCANCODE_UP] && player_y > 0.0)
		new_direction -= 2;

	if (SDL_Game::keystate[SDL_SCANCODE_DOWN] && player_y < 1.0)
		new_direction += 2;

	if (SDL_Game::keystate[SDL_SCANCODE_LEFT] && player_x > 0.0)
		new_direction -= 16;

	if (SDL_Game::keystate[SDL_SCANCODE_RIGHT] && player_x < 1.0)
		new_direction += 16;


	if (abs(new_direction) != abs(old_direction) && new_direction != 0)
	{
		vertices_temp.push_back({ player_x, player_y });

		out_move_degree += (DirToDegree(new_direction) - DirToDegree(old_direction));

		old_direction = new_direction;
	}
		printf("\ttotoal degree = %d\n", out_move_degree);


	if (SDL_Game::keystate[SDL_SCANCODE_UP] && player_y > 0.0)
			player_y -= player_speed;

	if (SDL_Game::keystate[SDL_SCANCODE_DOWN] && player_y < 1.0)
			player_y += player_speed;

	if (SDL_Game::keystate[SDL_SCANCODE_LEFT] && player_x > 0.0)
			player_x -= player_speed;

	if (SDL_Game::keystate[SDL_SCANCODE_RIGHT] && player_x < 1.0)
			player_x += player_speed;


	int vt_size = vertices_temp.size();
	for (int i = vt_size - 1; i > 0; --i)
	{
		std::pair<float, float> inter = OverlapLine(
			{ player_x, player_y }, vertices_temp[vt_size - 1],
			vertices_temp[i], vertices_temp[i - 1]);
		if (inter.first != -1)
		{
			MovementChange();
			return;
		}
	}
}

std::pair<float,float> GalsPanic::OverlapLine(
	std::pair<float, float> p1, std::pair<float, float> p2,
	std::pair<float, float> p3, std::pair<float, float> p4)
{
	// p1 = line 1's source
	// p2 = line 1's destination
	// p3 = line 2's source
	// p4 = line 2's destination

	float denominator =		// (x1-x2)(y3-y4)-(y1-y2)(x3-x4)
		(p1.first - p2.first) * (p3.second - p4.second)
		- (p1.second - p2.second) * (p3.first - p4.first);

	if (denominator == 0)
		return { -1,-1 };

	float t = 
		((p1.first - p3.first)*(p3.second - p4.second)
		- (p1.second - p3.second)*(p3.first - p4.first))
		/ denominator;
	if (t >= 1.0 || t <= 0.0)
		return { -1, -1 };

	float u =
		((p2.first - p1.first)*(p1.second - p3.second)
			- (p2.second - p1.second)*(p1.first - p3.first))
		/ denominator;
	if (u >= 1.0 || u <= 0.0)
		return { -1, -1 };
	

	float inter_x = p1.first + t * (p2.first - p1.first);
	float inter_y = p1.second + t * (p2.second - p1.second);

	return { inter_x, inter_y };
}



void GalsPanic::MovementChange()
{
	switch (player_mode)
	{
	case 0:		// out to in  ==  inmove initial
	{
		player_x = vertices_temp[0].first;
		player_y = vertices_temp[0].second;
	}
		break;
	case 1:		// in to out  ==  outmove initial
	{
		out_move_degree = 0;
		vertices_temp.clear();
		vertices_temp.push_back({ player_x, player_y });
	}
		break;
	}

	player_mode = 1 - player_mode;
}

int GalsPanic::DirToDegree(int keydir)
{
	/*if (SDL_Game::keystate[SDL_SCANCODE_UP] && player_y > 0.0)
		new_direction -= 2;

	if (SDL_Game::keystate[SDL_SCANCODE_DOWN] && player_y < 1.0)
		new_direction += 2;

	if (SDL_Game::keystate[SDL_SCANCODE_LEFT] && player_x > 0.0)
		new_direction -= 16;

	if (SDL_Game::keystate[SDL_SCANCODE_RIGHT] && player_x < 1.0)
		new_direction += 16;*/

	switch (keydir)
	{
	case 16:	// right
		return 0;
	case 14:	// right-up
		return 45;
	case -2:	// up
		return 90;
	case -18:	// left-up
		return 135;
	case -16:	// left
		return 180;
	case -14:	// left-down
		return 225;
	case 2:	// down
		return 270;
	case 18:	// right-down
		return 315;
	}

	return -1;

	// new_move - old_move = changed_degree
}