#include "RollBall.h"


RollBall::RollBall()
{
	RB_Manager::Init((iRollBall*)this);

	background_ = new SDL_cTexture("../data/background.png");

	player_ = new RB_Player(world_.getCenterSpace(), {1000, 1000, 0}, 5);
	player_->setSpeed(0.1);
	world_.setFocus((oun::iDomain*)player_);

	for (int i = 0; i < 10000; ++i)
		objects_.insert(new RB_Object(world_.getCenterSpace(), { RandomValue(),  RandomValue(), 0 }, float(rand()%900 + 100)/100));

	time_limit_ += SDL_GetTicks();
}

RollBall::~RollBall()
{
	for (auto it = objects_.begin(); it != objects_.end();)
	{
		auto value = *(it++);
		delete value;
	}

	delete player_;

	delete background_;

	RB_Manager::Quit();
}

inline void RollBall::Input()
{
	SDL_SetRenderDrawColor(SDL_Game::renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(SDL_Game::renderer, NULL);

	//longer_screen_ = (SDL_Game::window_rect.h > SDL_Game::window_rect.w ? SDL_Game::window_rect.h : SDL_Game::window_rect.w);
	world_.Plan();
}

inline void RollBall::Process()
{
	player_->Update();
	world_.Update();

	if (time_limit_ < SDL_GetTicks())
		game_end_ = true;

}

inline void RollBall::Output()
{

	auto bound = world_.getBound();
	SDL_Rect b_rect;
	b_rect.x = bound.x / MAX_SPACE_SCALE * background_->getWidth();
	b_rect.y = bound.y / MAX_SPACE_SCALE * background_->getHeight();
	b_rect.w = bound.w / MAX_SPACE_SCALE * background_->getWidth();
	b_rect.h = bound.h / MAX_SPACE_SCALE * background_->getHeight();

	SDL_Rect s_rect = SDL_Game::window_rect;
	s_rect.x = 0;
	s_rect.y = 0;
	
	if (bound.x < 0)
	{
		s_rect.x = -bound.x / bound.w * s_rect.w;
		s_rect.w -= s_rect.x;
	}
	else if (bound.x + bound.w > MAX_SPACE_SCALE)
	{
		s_rect.w += (MAX_SPACE_SCALE - bound.x - bound.w) / bound.w * s_rect.w;
	}

	
	if (bound.y < 0)
	{
		s_rect.y = -bound.y / bound.h * s_rect.h;
		s_rect.h -= s_rect.y;
	}
	else if (bound.y + bound.h > MAX_SPACE_SCALE)
	{
		s_rect.h += (MAX_SPACE_SCALE - bound.y - bound.h) / bound.h * s_rect.h;
	}

	SDL_RenderCopy(SDL_Game::renderer, *background_, &b_rect, &s_rect);


	world_.Draw();

	ui_.Draw();

	if (game_end_ == true)
	{
		SDL_Game::game_state = NULL;
		delete this;
	}
}


