#pragma once

#include "SDL_State.h"
#include "oun.h"
#include "oun_World.h"
//#include "oun_Space.h"
#include "RB_Object.h"
#include "RB_Player.h"

inline float RandomValue() { return rand()%int(oun::MAX_SPACE_SCALE - 10) + 10; }

class RollBall : public SDL_State
{
	friend class SDL_Game;

public:
	inline RollBall* Instance();
	inline void Reset();

	void Input() override;
	void Process() override;
	void Output() override;

private:
	static RollBall* singleton_;

	oun::World world_;
	RB_Player* player_;
	std::set<RB_Object*> objects_;

	RollBall();	// singleton
	~RollBall();
};

RollBall* RollBall::singleton_ = NULL;