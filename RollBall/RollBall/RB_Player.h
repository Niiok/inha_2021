#pragma once

#include <oun_Object.h>
#include <SDL.h>
#include "SDL_Game.h"
#include "SDL_Animator.h"
#include "RB_Object.h"
#include <queue>

class RB_Player :
	public oun::Object
{
public:
	RB_Player(oun::Space* space, oun::floatXYZ loc = oun::floatXYZ(1000, 1000, 1000), float vol = 1) : oun::Object(space, loc, vol) {  }
	~RB_Player() override {}

	void Plan() override;
	void Update() override;
	void Draw() const override;

	inline float getSpeed() const { return speed_; }
	inline void setSpeed(float spd) { speed_ = spd; }

	bool AttachObjectToBall(RB_Object* obj);

private:
	SDL_Animator* animator_;
	float speed_ = 1;
	std::queue<RB_Object*> attached_;

};

