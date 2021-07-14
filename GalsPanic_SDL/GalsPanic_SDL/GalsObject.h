#pragma once
#include "SDL_Game.h"

struct intXY
{
	int x;
	int y;
};

struct floatXY
{
	float x;
	float y;
};

floatXY OverlapLine(
	floatXY p1, floatXY p2,
	floatXY p3, floatXY p4);

class GalsObject
{
public:
	GalsObject() {};
	virtual ~GalsObject() {};


public: //protected:
	floatXY location_;

public:
	inline float get_x() { return location_.x; }
	inline float get_y() { return location_.y; }
	virtual void Draw() = 0;
	virtual void Update() = 0;
};
