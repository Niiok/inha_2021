#include "RB_UI.h"



void RB_UI::Draw()
{
	sprintf_s(str, "Current Ball size : %.3f M", RB_Manager::Instance().getPlayer()->getVolume());
	sprintf_s(str2, "Time Left : %.1f second", float(RB_Manager::Instance().getTimeLimit() - SDL_GetTicks()) / 1000);

	texture_.MakeTTF(str, { 0,255, 255, 255 });
	area_.y = 32;
	area_.w = texture_.getWidth();
	area_.h = texture_.getHeight();
	SDL_RenderCopy(SDLpp_Game::renderer, texture_, NULL, &area_);
	texture_.MakeTTF(str2, { 255,0,255,255 });
	area_.y = 64;
	area_.w = texture_.getWidth();
	area_.h = texture_.getHeight();
	SDL_RenderCopyEx(SDLpp_Game::renderer, texture_, NULL, &area_, 90, &center_, SDL_FLIP_NONE);
}
