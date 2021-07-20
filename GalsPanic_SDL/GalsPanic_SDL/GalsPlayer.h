#pragma once
#include "GalsObject.h"
#include "GalsMap.h"

class GalsPlayer :
	public GalsObject
{
	friend class GalsMap;

public:
	GalsPlayer() {};
	GalsPlayer(GalsMap& map);
	virtual ~GalsPlayer() override;

protected:
	GalsMap* map_;

	float speed_ = 0.005f;

	int move_mode_ = 1;
	int old_line = -1;
	int in_line = 0;
	intXY old_direction = { 0, 0 };
	int out_move_degree = 0;



public:
	virtual void Draw() override;
	virtual void Update() override;
	inline void SetMap(GalsMap& map) { map_ = &map; }

protected:
	virtual void MoveIn();
	virtual void MoveOut();
	virtual void Died();
	virtual void MoveModeChange(int i);

	void Coll_Line();

};
