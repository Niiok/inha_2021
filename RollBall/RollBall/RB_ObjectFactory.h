#pragma once
#include "RB_Object.h"
#include "RB_Player.h"
#include "RB_Manager.h"
#include <SDLpp_Animator.h>

class RB_ObjectFactory
{
public:
	enum ObjectID
	{
		ID_Player = 0,
		ID_Box,
		ID_Cow,
		ID_House,
		ID_Crab
	};

	RB_ObjectFactory();
	~RB_ObjectFactory();

	RB_Object* Create(ObjectID id);

	private:
	void SetPlayerAnim();


	static int instance_count;
	static std::map<ObjectID, SDLpp_Animator*> animators;
};

