#pragma once
#include "SDL_image.h"

#include "GalsObject.h"
#include "GalsPlayer.h"

class GalsMap :
	public GalsObject
{
	friend class GalsPlayer;

public:
	GalsMap();
	virtual ~GalsMap() override;

protected:
	GalsPlayer* player_;

	SDL_Texture* background_ = NULL;

	std::vector<floatXY> vertices_static_;
	std::vector<floatXY> vertices_temp_;

public:
	virtual void Draw() override;
	virtual void Update() override;
	inline void SetPlayer(GalsPlayer& player) { player_ = &player; }

};

