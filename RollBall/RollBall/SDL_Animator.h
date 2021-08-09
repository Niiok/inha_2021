#pragma once

#include <map>
#include "SDL.h"
#include "SDL_image.h"

class SDL_Animator
{
public:
	enum state
	{
		Idle = 0,
		Walk,
		Run,
		Jump,
		Fall,
		Swim,
		Fly,
		Damaged,
		Attack,
		KnockDown,
		Die,

		Total
	};

	enum direction
	{
		Front = 0,
		Back,
		Left,
		Right,

		Total
	};

	SDL_Animator();
	~SDL_Animator();




private:
	SDL_Texture* texture_;
	state state_ = Idle;
	direction direct_ = Front;
	std::map<int, SDL_Rect> area_;
};