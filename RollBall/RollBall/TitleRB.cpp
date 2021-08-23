#include "TitleRB.h"

TitleRB::TitleRB()
{
	DrawTexture_Menu();
	DrawTexture_HowToPlay();
}

TitleRB::~TitleRB()
{
	SDL_DestroyTexture(menu_);
	SDL_DestroyTexture(how_to_play_);
}

void TitleRB::Input()
{
	
}

void TitleRB::Process()
{
	
}

void TitleRB::Output()
{
}

void TitleRB::DrawTexture_Menu()
{
}

void TitleRB::DrawTexture_HowToPlay()
{
}
