#pragma once

#include <map>
#include <SDL.h>
#include <SDL_image.h>

class SDL_Animator
{
public:
	enum State
	{
		State_Idle = 0,
		State_Walk,
		State_Run,
		State_Jump,
		State_Fall,
		State_Swim,
		State_Fly,
		State_Damaged,
		State_Attack,
		State_KnockDown,
		State_Die,

		State_Total
	};

	enum Direction
	{
		Direction_Front = 0,
		Direction_Back,
		Direction_Left,
		Direction_Right,

		Direction_Total
	};

	SDL_Animator();
	~SDL_Animator();




private:
	SDL_Texture* texture_;
	State state_ = State_Idle;
	Direction direct_ = Direction_Front;
	std::map<int, SDL_Rect> area_;
};