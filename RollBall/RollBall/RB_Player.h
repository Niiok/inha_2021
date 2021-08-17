#pragma once

#include "oun_Object.h"
#include "SDLpp_Game.h"
#include "SDLpp_Animator.h"
#include "RB_Object.h"
#include <deque>

#include "RB_Manager.h"


constexpr int MAX_ATTACHED_OBJECTS_ON_BALL = 10;

class RollBall;

class RB_Player :
	public RB_Object
{
public:
	RB_Player(oun::Space* space, oun::floatXYZ loc = oun::floatXYZ(1000, 1000, 1000), float vol = 1) : RB_Object(space, loc, vol) {  }
	~RB_Player() override;

	void Plan() override;
	void Update() override;
	void Draw() const override;

	inline float getSpeed() const { return speed_; }
	inline void setSpeed(float spd) { speed_ = spd; }

	bool OverlapRect(SDL_Rect a, SDL_Rect b) const;
	bool CheckCollision(iObject* obj) const;
	bool AttachObjectToBall(RB_Object* obj);

private:
	SDL_Rect collision_;

	float speed_ = 1;
	std::deque<RB_Object*> attached_;


};

