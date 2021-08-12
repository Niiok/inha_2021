#pragma once

#include "oun.h"
#include "RB_Manager.h"
#include "SDL_State.h"
#include "SDL_cTexture.h"
#include "RB_Player.h"
#include "RB_Object.h"

inline float RandomValue() { return rand()%int(MAX_SPACE_SCALE - 10) + 10; }

class RB_Player;
class RB_Object;
class RB_UI;
class oun::World;

class RollBall : public SDL_State
{
	friend class SDL_Game;
	friend class RB_Manager;

public:
	static RollBall& Instance();
	static inline void Reset();

	inline void Input() override;
	inline void Process() override;
	inline void Output() override;

private:
	static RollBall* singleton_;
	
	SDL_cTexture* background_;
	oun::World world_;
	//RB_UI ui_;
	RB_Player* player_;
	std::set<RB_Object*> objects_;
	int longer_screen_;

	RollBall();	// singleton
	~RollBall();
};

SDL_Rect ObjectArea(oun::iObject* obj);
