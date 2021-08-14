#pragma once
#include "SDL_Game.h"
#include <map>

class SDL_Resource
{
public:
	SDL_Resource();
	~SDL_Resource();

private:
	static std::map<std::string, SDL_Texture*> images_;
	static std::map<std::string, TTF_Font*> fonts_;
	//static std::map<const char*, > fonts_;

};

