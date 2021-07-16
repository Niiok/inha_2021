#include "GalsPanic.h"


GalsPanic::GalsPanic() : player_{ GalsPlayer(map_) }, enemy_{ GalsEnemy(map_) }
{
	map_.SetPlayer(player_);
	map_.SetEnemy(enemy_);
}

GalsPanic::~GalsPanic()
{
}


void GalsPanic::Input()
{

}

void GalsPanic::Process()
{
	map_.Update();
	player_.Update();
	enemy_.Update();

}

void GalsPanic::Output()
{
	//SDL_SetRenderDrawColor(SDL_Game::renderer, 0, 0, 0, 32);
	//SDL_RenderClear(SDL_Game::renderer);
	

	map_.Draw();
	player_.Draw();
	enemy_.Draw();

}



