#pragma once
#include <oun_Object.h>
#include <SDL.h>
#include "SDL_Game.h"
#include "SDL_Animator.h"

class RB_Player :
	public oun::Object
{
public:
	RB_Player(oun::Space* space, oun::floatXYZ loc = oun::floatXYZ(1000, 1000, 1000), float vol = 1, float spd = 1) : oun::Object(space, loc, vol,spd) {  }
	~RB_Player() override {}

	void Plan() override;
	void Update() override;
	void Draw() const override;

private:
	SDL_Animator* animator_;



};

