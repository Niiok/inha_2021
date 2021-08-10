#include "RollBall.h"

RollBall::RollBall()
{
	player_ = new RB_Player(world_.getCenterSpace(), {500, 500,500}, 1, 0.1);
	world_.setFocus(player_);

	for (int i = 0; i < 10; ++i)
		objects_.insert(new RB_Object(world_.getCenterSpace(), { 500 + RandomValue(), 500 + RandomValue(), 500 + RandomValue() }, 1));
}

RollBall::~RollBall()
{
	delete player_;

	for (auto it = objects_.begin(); it != objects_.end(); ++it)
		delete *it;
}

void RollBall::Input()
{
	world_.Plan();
}

void RollBall::Process()
{
	world_.Update();
}

void RollBall::Output()
{
	SDL_SetRenderDrawColor(SDL_Game::renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(SDL_Game::renderer, NULL);
	world_.Draw();
}
