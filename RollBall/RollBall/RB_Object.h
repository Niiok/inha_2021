#pragma once


#include "oun_Object.h"
#include <SDL.h>
#include "SDLpp_Game.h"
#include "SDLpp_Animator.h"
#include <math.h>
#include <time.h>

#include "RB_Manager.h"

class RB_Manager;

class RB_Object 
	: public oun::Object
{
public:
	RB_Object(oun::Space* space, oun::floatXYZ loc, float vol) : oun::Object(space, loc, vol) {}
	~RB_Object() override { RB_Manager::Instance().getObjects().erase(this); }

	void Plan() override;
	void Update() override;
	void Draw() const override;

	inline void setAnimator(SDLpp_Animator* anim) { animator_ = anim; }
	inline bool setState(SDLpp_Animator::State state) { state_ = state; }
	inline bool setDirection(SDLpp_Animator::Direction direct) { direct_ = direct; }

protected:
	SDLpp_Animator* animator_;
	SDLpp_Animator::State state_;
	SDLpp_Animator::Direction direct_;
};