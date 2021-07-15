#pragma once
#include "GalsObject.h"

class GalsEnemy :
	public GalsObject
{

public:
	GalsEnemy();
	~GalsEnemy() {}


private:
	SDL_Rect rect_;
	float size_;

public:
	void Update();
	void Draw();
};

