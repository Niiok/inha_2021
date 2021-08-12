#pragma once
#include "oun.h"
#include "RollBall.h"


class RollBall;
class RB_Player;
class RB_Object;
class oun::World;

class RB_Manager
{
public:
	static RB_Player* getPlayer() { return RollBall::Instance().player_; }
	static int getLonger() { return RollBall::Instance().longer_screen_; }
	static const oun::World& getWorld() { return RollBall::Instance().world_; }
	static std::set<RB_Object*>& getObjects() { return RollBall::Instance().objects_; }
};
