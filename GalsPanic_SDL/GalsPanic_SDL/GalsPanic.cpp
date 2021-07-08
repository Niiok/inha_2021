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
	if (SDL_Game::keystate[SDL_SCANCODE_SPACE])
	{
		player_mode = 1 - player_mode;
		SDL_Delay(10);
	}

	switch (player_mode)
	{
	case 0: // in
		PlayerMoveIn();
		break;

	case 1:
		PlayerMoveOut();
			break;
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
	if (vertices_static.size() > 2)
		SDL_RenderDrawLine(SDL_Game::renderer, vertices_static[0].first * SDL_Game::window_rect.w,
			vertices_static[0].second * SDL_Game::window_rect.h,
			vertices_static[vertices_static.size() - 1].first * SDL_Game::window_rect.w,
			vertices_static[vertices_static.size() - 1].second * SDL_Game::window_rect.h);

}



void GalsPanic::PlayerMoveIn()
{
	static int next_line;
	static int prev_line;

	static float src_vertex_x;
	static float src_vertex_y;
	static float dst_vertex_x;
	static float dst_vertex_y;

	static float src_minus_dst_x;
	static float src_minus_dst_y;

	static float gradient;


	// walkway setting
	if (old_line != in_line)
	{

		next_line = (in_line + 1 == vertices_static.size() ? 0 : in_line + 1);
		prev_line = (in_line - 1 == -1 ? vertices_static.size() - 1 : in_line - 1);
		
		printf("\t%d", in_line);
		printf("\t%d", prev_line);
		printf("\t%d\n", next_line);

		src_vertex_x = vertices_static[in_line].first;
		src_vertex_y = vertices_static[in_line].second;
		dst_vertex_x = vertices_static[next_line].first;
		dst_vertex_y = vertices_static[next_line].second;

		src_minus_dst_x = src_vertex_x - dst_vertex_x;
		src_minus_dst_y = src_vertex_y - dst_vertex_y;

		gradient = src_minus_dst_y / src_minus_dst_x;

		printf("\tdx : %f\tdy : %f\tgradient : %f\n",src_minus_dst_x, src_minus_dst_y, gradient);

		old_line = in_line;
	}


	// move
	if (abs(gradient) == 1)
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
	if (src_minus_dst_x > 0)
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
	else if (src_minus_dst_x < 0)
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
	if (src_minus_dst_y > 0)
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
	else if (src_minus_dst_y < 0)
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

	if (SDL_Game::keystate[SDL_SCANCODE_UP])
		new_direction -= 2;

	if (SDL_Game::keystate[SDL_SCANCODE_DOWN])
		new_direction += 2;

	if (SDL_Game::keystate[SDL_SCANCODE_LEFT])
		new_direction -= 16;

	if (SDL_Game::keystate[SDL_SCANCODE_RIGHT] )
		new_direction += 16;


	if (new_direction != old_direction && new_direction != 0)
	{
		vertices_static.push_back({ player_x, player_y });
		old_direction = new_direction;
	}


	if (SDL_Game::keystate[SDL_SCANCODE_UP])
		if (player_y > 0.0)
			player_y -= player_speed;

	if (SDL_Game::keystate[SDL_SCANCODE_DOWN])
		if (player_y < 1.0)
			player_y += player_speed;

	if (SDL_Game::keystate[SDL_SCANCODE_LEFT])
		if (player_x > 0.0)
			player_x -= player_speed;

	if (SDL_Game::keystate[SDL_SCANCODE_RIGHT])
		if (player_x < 1.0)
			player_x += player_speed;
}