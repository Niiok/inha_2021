#include "RollBall.h"


RollBall::RollBall()
{
	RB_Manager::Init((iRollBall*)this);

	background_ = new SDLpp_Texture("../data/background.png");

	player_ = new RB_Player(world_.getCenterSpace(), {1000, 1000, 0}, 5);
	player_->setSpeed(0.1);
	SetPlayerAnim();
	world_.setFocus((oun::iDomain*)player_);

	for (int i = 0; i < 0; ++i)
		objects_.insert(new RB_Object(world_.getCenterSpace(), { RandomValue(),  RandomValue(), 0 }, float(rand()%900 + 100)/100));

	printf("object num : %d\n", objects_.size());

	time_limit_ += SDL_GetTicks();

#ifdef COLLISION_SHOW
	SDL_SetRenderDrawBlendMode(SDLpp_Game::renderer, SDL_BLENDMODE_BLEND);
#endif


}

RollBall::~RollBall()
{
	printf("object num : %d\n", objects_.size());

	for (auto it = objects_.begin(); it != objects_.end();)
	{
		auto value = *(it++);
		delete value;
	}

	delete player_;

	delete background_;

	delete player_anim_;

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

void RollBall::SetPlayerAnim()
{
	//	0	1	2
	//	3	4	5
	//	6	7	8

	player_anim_ = new SDLpp_Animator("../data/prince.png");
	SDL_Rect area = { 0, 0, 64, 64 };

	// idle left
	for (int x = 0; x < 3; ++x)
	{
		area.x = 64 * x;
		player_anim_->AddArea(SDLpp_Animator::State_Idle, SDLpp_Animator::Left, x, &area, SDL_FLIP_NONE);
	}

	// walk down
	area.y = 64;
	for (int x = 0; x < 4; ++x)
	{
		area.x = 64 * x;
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::Down, x, &area, SDL_FLIP_NONE);
	}
	
	// walk down left & down right
	area.y = 128;
	for (int x = 0; x < 4; ++x)
	{
		area.x = 64 * x;
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::DownLeft, x, &area, SDL_FLIP_NONE);
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::DownRight, x, &area, SDL_FLIP_HORIZONTAL);
	}
	
	// walk left & right
	area.y = 192;
	for (int x = 0; x < 4; ++x)
	{
		area.x = 64 * x;
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::Left, x, &area, SDL_FLIP_NONE);
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::Right, x, &area, SDL_FLIP_HORIZONTAL);
	}
	
	// walk up left & up right
	area.y = 256;
	for (int x = 0; x < 4; ++x)
	{
		area.x = 64 * x;
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::UpLeft, x, &area, SDL_FLIP_NONE);
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::UpRight, x, &area, SDL_FLIP_HORIZONTAL);
	}
	
	// walk up
	area.y = 320;
	for (int x = 0; x < 4; ++x)
	{
		area.x = 64 * x;
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::Up, x, &area, SDL_FLIP_NONE);
	}
		
	player_->setAnimator(player_anim_);
}


