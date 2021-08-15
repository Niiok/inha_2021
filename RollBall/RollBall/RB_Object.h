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

private:
	SDLpp_Animator* animator_;
};