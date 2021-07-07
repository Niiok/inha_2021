#pragma once

#include "SDL_Game.h"
#include "SDL_State.h"
#include "SDL_image.h"
#include <vector>



class GalsPanic :
	public SDL_State
{
public:
	GalsPanic();
	~GalsPanic();

private:
	SDL_Rect rect = { 100, 100, 100, 100 };
	SDL_Texture* background = NULL;
	std::vector<std::pair<float,float>> vertices;
	float player_x = 0.5;
	float player_y = 0.5;
	float player_speed = 0.01;
	int cur_index = 0;
	int old_direction = 0;

public:
	void Input() override;
	void Process() override;
	void Output() override;

private:
	void PlayerMove();
};