#pragma once

#include "SDL_State.h"
#include "oun.h"
#include "oun_World.h"
//#include "oun_Space.h"
#include "RB_Object.h"
#include "RB_Player.h"

inline float RandomValue() { return rand()%int(10) - 5; }

class RollBall : public SDL_State
{

public:
	RollBall();
	~RollBall();

	void Input() override;
	void Process() override;
	void Output() override;

private:
	oun::World world_;
	RB_Player* player_;
	std::set<RB_Object*> objects_;
};