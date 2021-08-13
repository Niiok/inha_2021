#ifndef __RB_MANAGER_H__
#define __RB_MANAGER_H__

#include "oun.h"
#include "iRollBall.h"
#include "SDL_Game.h"
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
{
public:
	static void Init(iRollBall* rb) { if (singleton_ == NULL) singleton_ = new RB_Manager(rb); }
	static RB_Manager& Instance() { return *singleton_; }
	static void Quit() { if (singleton_ != NULL) { delete singleton_; singleton_ = NULL; } }

	RollBall* getRollBall() { return (RollBall*)rb_; }
	RB_Player* getPlayer() { return rb_->getPlayer(); }
	int getLonger() { return rb_->getLonger(); }
	const oun::World& getWorld() { return rb_->getWorld(); }
	std::set<RB_Object*>& getObjects() { return rb_->getObjects(); }

private:
	static RB_Manager* singleton_;
	iRollBall* rb_;

	RB_Manager(iRollBall* rb) { rb_ = rb; }
	~RB_Manager() {};
};






#endif