#pragma once
#include "GameState.h"
#include <tchar.h>
#include "GamePlay.h"

namespace Game {

	class GameLogin : public GameState
	{
	public:
		//GameLogin();
		GameLogin(HWND hWnd);
		~GameLogin();

	private:
		TCHAR str_[LOGIN_STRMAX] {0};
		int strlen_ {0};

	public:
		int Draw(HDC hdc) override;
		int Update() override;
		int Input(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
		int Next() override;
	};

}