#ifndef __RB_MANAGER_H__
#define __RB_MANAGER_H__

//#define COLLISION_SHOW

#include <stack>
#include "oun.h"
#include "iRollBall.h"
#include "SDLpp_Game.h"
//#include "RB_Player.h"
//#include "RB_Object.h"

class iRollBall;
class RollBall;
class RB_Player;
class RB_Object;
class oun::World;


inline float RandomValue() { return rand() % int(MAX_SPACE_SCALE - 10) + 10; }

SDL_Rect ObjectArea(oun::iObject* obj);

class RB_Manager 
	: public iRollBall
{
public:
	static void Init(iRollBall* rb);
	static RB_Manager& Instance() { return *singleton_; }
	static void Quit();

	RollBall* getRollBall() { return (RollBall*)rb_.top(); }
	RB_Player* getPlayer() { return rb_.top()->getPlayer(); }
	int getLonger() { return rb_.top()->getLonger(); }
	int64_t getTimeLimit() { return rb_.top()->getTimeLimit(); }
	const oun::World& getWorld() { return rb_.top()->getWorld(); }
	std::set<RB_Object*>& getObjects() { return rb_.top()->getObjects(); }

private:
	static RB_Manager* singleton_;
	std::stack<iRollBall*> rb_;

	RB_Manager() {}
	~RB_Manager() {}
};






#endif