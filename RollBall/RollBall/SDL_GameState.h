#pragma once

class SDL_GameState
{
public:
	virtual void Input() = 0;
	virtual void Process() = 0;
	virtual void Output() = 0;
};