#pragma once

//#include "oun.h"
//#include "RB_Player.h"
//#include "RB_Object.h"

class oun::World;
class RB_Player;
class RB_Object;

class iRollBall
{
public:
	virtual RB_Player* getPlayer() = 0;
	virtual int getLonger() = 0;
	virtual const oun::World& getWorld() = 0;
	virtual std::set<RB_Object*>& getObjects() = 0;


};