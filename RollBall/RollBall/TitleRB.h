#pragma once
#include <SDLpp_Game.h>

class TitleRB :
	public SDLpp_GameState
{
public:
	TitleRB();
	~TitleRB();

	void Input() override;
	void Process() override;
	void Output() override;

private:
	void DrawTexture_Menu();
	void DrawTexture_HowToPlay();

private:
	SDL_Texture* menu_;
	SDL_Texture* how_to_play_;
	int pointed_ = 0;
	bool popup_how = false;
};

