#pragma once
#include "GameState.h"

namespace Game {

	class GameOver :
		public GameState
	{
	public:
		int Draw(HDC hdc) override;
		int Update() override;
		int Input(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
		int Next() override;
	};

}