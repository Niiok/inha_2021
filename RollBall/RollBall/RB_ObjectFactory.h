#pragma once
#include "RB_Object.h"
#include "RB_Player.h"

class RB_ObjectFactory
{
public:
	enum Type
	{
		Player = 0,
		House,
		SoccerBall
	};

	RB_ObjectFactory() {};
	~RB_ObjectFactory() {};

	RB_Object* newObject(Type id);

};

