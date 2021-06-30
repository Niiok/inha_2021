#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "GameState.h"
#include "GamePlay.h"
#include "GameLogin.h"
#include <assert.h>

namespace Game {

	class GameOver : public GameState
	{
		struct Ranker {
			TCHAR name[LOGIN_STRMAX] = {0};
			int score = 0;
		};

	public:
		GameOver(HWND hWnd);
		~GameOver();

	protected:
		TCHAR str_[LOGIN_STRMAX];
		int score_ = 0;
		friend int GameState::Next();

		Ranker rankers[6];

	public:
		int Draw(HDC hdc) override;
		int Update() override;
		int Input(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
		int Next() override;
		int SetChar(TCHAR* str);
		int SetScore(int score);
		int RankIn();
		int RankSort();
		int RankOut();
	};

}