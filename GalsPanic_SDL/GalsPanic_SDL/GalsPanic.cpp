#include "GalsPanic.h"


GalsPanic::GalsPanic()
{
	map_ = GalsMap();
	player_ = GalsPlayer(map_);
	map_.SetPlayer(player_);


}

GalsPanic::~GalsPanic()
{
}


void GalsPanic::Input()
{

}

void GalsPanic::Process()
{


}

void GalsPanic::Output()
{
	SDL_SetRenderDrawColor(SDL_Game::renderer, 0, 0, 0, 125);
	SDL_RenderFillRect(SDL_Game::renderer, NULL);
	




}



