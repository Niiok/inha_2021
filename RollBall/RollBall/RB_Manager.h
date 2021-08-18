#ifndef __RB_MANAGER_H__
#define __RB_MANAGER_H__

#define COLLISION_SHOW

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
	static void Init(iRollBall* rb) { singleton_.push(new RB_Manager(rb)); }
	static RB_Manager& Instance() { return *singleton_.top(); }
	static void Quit() { if (!singleton_.empty()) { delete singleton_.top(); singleton_.pop() ; } }

	RollBall* getRollBall() { return (RollBall*)rb_; }
	RB_Player* getPlayer() { return rb_->getPlayer(); }
	int getLonger() { return rb_->getLonger(); }
	int64_t getTimeLimit() { return rb_->getTimeLimit(); }
	const oun::World& getWorld() { return rb_->getWorld(); }
	std::set<RB_Object*>& getObjects() { return rb_->getObjects(); }

private:
	static std::stack<RB_Manager*> singleton_;
	iRollBall* rb_;

	RB_Manager(iRollBall* rb) { rb_ = rb; }
	~RB_Manager() {};
};






#endif