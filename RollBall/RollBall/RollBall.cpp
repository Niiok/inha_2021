#include "RollBall.h"


RollBall::RollBall()
{
	RB_Manager::Init((iRollBall*)this);

	background_ = new SDLpp_Texture("../data/background.png");

	player_ = (RB_Player*)object_factory_.Create(RB_Object::ID_Player);

	// crab
	for (int i = 0; i < 500; ++i)
	{
		int rand_num = rand();
		float x = MAX_SPACE_SCALE/2 + float(rand_num % 100 - 50)/5;
		float y = MAX_SPACE_SCALE/2 + float(rand_num % 10000 / 100 - 50)/5;
		objects_.insert(object_factory_.Create(RB_Object::ID_Crab, x, y));
	}
	
	// box
	for (int i = 0; i < 200; ++i)
	{
		int rand_num = rand();
		float x = MAX_SPACE_SCALE/2 + float(rand_num % 100 - 50)/2;
		float y = MAX_SPACE_SCALE/2 + float(rand_num % 10000 / 100 - 50)/2;
		if (x != MAX_SPACE_SCALE / 2 && y != MAX_SPACE_SCALE / 2)
			objects_.insert(object_factory_.Create(RB_Object::ID_Box, x, y));
	}
	
	// cow
	for (int i = 0; i < 100; ++i)
	{
		int rand_num = rand();
		float x = MAX_SPACE_SCALE/2 + (rand_num % 100 - 50);
		float y = MAX_SPACE_SCALE/2 + (rand_num % 10000 / 100 - 50);
		if (x != MAX_SPACE_SCALE / 2 && y != MAX_SPACE_SCALE / 2)
			objects_.insert(object_factory_.Create(RB_Object::ID_Cow, x, y));
	}
	
	// house
	for (int i = 0; i < 100; ++i)
	{
		int rand_num = rand();
		float x = MAX_SPACE_SCALE/2 + (rand_num % 100 - 50)*3;
		float y = MAX_SPACE_SCALE/2 + (rand_num % 10000 / 100 - 50)*3;
		if (x != MAX_SPACE_SCALE / 2 && y != MAX_SPACE_SCALE / 2)
			objects_.insert(object_factory_.Create(RB_Object::ID_House, x, y));
	}

	printf("object num : %d\n", objects_.size());

	time_limit_ += SDL_GetTicks();

#ifdef COLLISION_SHOW
	SDL_SetRenderDrawBlendMode(SDLpp_Game::renderer, SDL_BLENDMODE_BLEND);
#endif


}

RollBall::~RollBall()
{
	if (SDLpp_Game::game_state == this)
		SDLpp_Game::game_state = NULL;

	printf("object num : %d\n", objects_.size());

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
	SDL_SetRenderDrawColor(SDLpp_Game::renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(SDLpp_Game::renderer, NULL);

	//longer_screen_ = (SDLpp_Game::window_rect.h > SDLpp_Game::window_rect.w ? SDLpp_Game::window_rect.h : SDLpp_Game::window_rect.w);
	player_->Plan();
	world_.Plan();

	printf("objects around : %d\n", world_.getObjectsAround().size());
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

	SDL_Rect s_rect = SDLpp_Game::window_rect;
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

#ifndef COLLISION_SHOW
	SDL_RenderCopy(SDLpp_Game::renderer, *background_, &b_rect, &s_rect);
#endif 

	world_.Draw();

	ui_.Draw();

	if (game_end_ == true)
	{
		SDLpp_Game::game_state = NULL;
		delete this;
	}
}



