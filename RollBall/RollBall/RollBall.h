#pragma once

#include "oun.h"
#include "SDLpp_GameState.h"
#include "SDLpp_Texture.h"

#include "iRollBall.h"
#include "RB_Manager.h"
#include "RB_Player.h"
#include "RB_Object.h"
#include "RB_UI.h"


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
	const oun::World& getWorld() override { return world_; }
	std::set<RB_Object*>& getObjects() override { return objects_; }

private:	
	SDLpp_Texture* background_;
	oun::World world_;
	RB_UI ui_;
	RB_Player* player_;
	std::set<RB_Object*> objects_;
	int longer_screen_;

	int64_t time_limit_ = 50000;
	bool game_end_ = false;

};

