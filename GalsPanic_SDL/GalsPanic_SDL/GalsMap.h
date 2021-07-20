#pragma once

#include "GalsObject.h"
#include "GalsPlayer.h"
#include "GalsEnemy.h"
#include <vector>
#include <queue>

class GalsMap :
	public GalsObject
{
	friend class GalsPlayer;
	friend class GalsEnemy;

public:
	GalsMap();
	virtual ~GalsMap() override;

protected:
	GalsPlayer* player_;
	GalsEnemy* enemy_;

	SDL_Texture* background_origin_;
	SDL_Texture* background_;
	SDL_Texture* polygon_;

	std::vector<floatXY> vertices_static_;
	std::vector<floatXY> vertices_temp_;

	int reverse = 1;

public:
	virtual void Draw() override;
	virtual void Update() override;
	inline void SetPlayer(GalsPlayer& player) { player_ = &player; }
	inline void SetEnemy(GalsEnemy& enemy) { enemy_ = &enemy; }
	floatXY CollWithPolygon(floatXY src, floatXY dst, int* coll_line = NULL);
	floatXY CollWithFootprint(floatXY src, floatXY dst, int* coll_line = NULL);

private:
	void RefreshBackground();
	void MergeVertices(int started_line, int ended_line );

	class floatXY_less {
	public:
		inline bool operator() (floatXY a, floatXY b)
		{
			if (a.x < b.x)
				return true;
			else
				return false;
		}
	};
};

