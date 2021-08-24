#pragma once

#include "oun.h"
#include "SDLpp_GameState.h"
#include "SDLpp_Texture.h"

#include "iRollBall.h"
#include "RB_Manager.h"
#include "RB_Player.h"
#include "RB_Object.h"
#include "RB_UI.h"
#include "RB_ObjectFactory.h"


class RB_Player;
class RB_Object;
class RB_UI;
class oun::World;



class RollBall 
	: public SDLpp_GameState, public iRollBall
{

public:
	RollBall();
	~RollBall();

	// SDLpp_GameState
	inline void Input() override;
	inline void Process() override;
	inline void Output() override;

	//iRollBall
	RB_Player* getPlayer() override { return player_; }
	int getLonger() override { return longer_screen_; }
	int64_t getTimeLimit() override { return time_limit_; }
	oun::World& getWorld() override { return world_; }
	std::set<RB_Object*>& getObjects() override { return objects_; }

	// temporal
	

private:	
	RB_UI ui_;
	RB_ObjectFactory object_factory_;

	SDLpp_Texture* background_;
	oun::World world_;
	RB_Player* player_;
	std::set<RB_Object*> objects_;

	int longer_screen_;
	int64_t time_limit_ = 120000;
	bool game_end_ = false;

};

