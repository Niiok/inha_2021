#pragma once
#include "RB_Object.h"
#include "RB_Player.h"
#include "RB_Manager.h"
#include <SDLpp_Animator.h>

class RB_ObjectFactory
{
public:
	

	RB_ObjectFactory();
	~RB_ObjectFactory();

	RB_Object* Create(RB_Object::ID id, float x = MAX_SPACE_SCALE/2, float y = MAX_SPACE_SCALE/2);

	private:
	void SetPlayerAnim();
	void SetBoxAnim();


	static int instance_count;
	static std::map<RB_Object::ID, SDLpp_Animator*> animators;
};

