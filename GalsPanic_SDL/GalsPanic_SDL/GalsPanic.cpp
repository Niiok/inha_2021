#include "GalsPanic.h"

GalsPanic::GalsPanic()
{
	IMG_Init(IMG_INIT_PNG);
	vertices.push_back({player_x, player_y});
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
	PlayerMove();


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

	for (int i = 0; i < vertices.size()-1; ++i)
	{
		SDL_RenderDrawLine(SDL_Game::renderer, vertices[i].first * SDL_Game::window_rect.w,
			vertices[i].second * SDL_Game::window_rect.h,
			vertices[i + 1].first * SDL_Game::window_rect.w,
			vertices[i + 1].second * SDL_Game::window_rect.h);
	}
	if (vertices.size() > 2)
		SDL_RenderDrawLine(SDL_Game::renderer, vertices[0].first * SDL_Game::window_rect.w,
			vertices[0].second * SDL_Game::window_rect.h,
			vertices[vertices.size() - 1].first * SDL_Game::window_rect.w,
			vertices[vertices.size() - 1].second * SDL_Game::window_rect.h);

}



void GalsPanic::PlayerMove()
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
		vertices.push_back({ player_x, player_y });
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