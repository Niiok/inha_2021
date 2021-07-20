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

	float size_;

private:
	GalsMap* map_;

	float speed_ = 0.02f;

	SDL_Rect rect_;
	float size_rate_;

	floatXY old_direction = { 0, 0 };

public:
	void Update();
	void Draw();
};

