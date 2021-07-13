#pragma once

//#include "SDL_Game.h"
#include "SDL_State.h"
#include "GalsObject.h"
#include "GalsPlayer.h"
#include "GalsMap.h"


class GalsPlayer;
class GalsMap;



class GalsPanic :
	public SDL_State
{
public:
	GalsPanic();
	~GalsPanic();

private:
	GalsMap map_;
	GalsPlayer player_;

public:
	void Input() override;
	void Process() override;
	void Output() override;

private:
	

};