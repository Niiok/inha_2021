#pragma once

class SDL_State
{
public:
	SDL_State() {};
	virtual ~SDL_State() {};


	virtual void Input() = 0;
	virtual void Process() = 0;
	virtual void Output() = 0;

};