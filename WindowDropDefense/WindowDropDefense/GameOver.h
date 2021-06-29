#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "GameState.h"
#include "GamePlay.h"
#include "GameLogin.h"

namespace Game {

	class GameOver : public GameState
	{
	public:
		GameOver(HWND hWnd);
		~GameOver();

	protected:
		TCHAR str_[LOGIN_STRMAX];
		int score_ = 0;
		friend int GameState::Next();

	public:
		int Draw(HDC hdc) override;
		int Update() override;
		int Input(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
		int Next() override;
		int SetChar(TCHAR* str);
	};

}