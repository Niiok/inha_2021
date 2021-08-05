#pragma once

#include "SDL_State.h"
#include "oun.h"

class RollBall : public SDL_State
{

public:
	RollBall();
	virtual ~RollBall();

	void Input() override;
	void Process() override;
	void Output() override;

private:
	 oun::iObject* player_;
	
};