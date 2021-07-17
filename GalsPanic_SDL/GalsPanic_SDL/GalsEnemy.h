#pragma once
#include "GalsObject.h"
#include "GalsMap.h"
#include <time.h>

class GalsEnemy :
	public GalsObject
{

	friend class GalsMap;

public:
	GalsEnemy() {}
	GalsEnemy(GalsMap& map);
	~GalsEnemy() {}


private:
	GalsMap* map_;

	float speed_ = 0.002f;

	SDL_Rect rect_;
	float size_;

	floatXY old_direction = { 0, 0 };

public:
	void Update();
	void Draw();
};

