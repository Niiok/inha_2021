#pragma once
#include "GalsObject.h"
#include "GalsMap.h"

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

	SDL_Rect rect_;
	float size_;

public:
	void Update();
	void Draw();
};

