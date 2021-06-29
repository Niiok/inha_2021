#pragma once
#include <Windows.h>

#define LOGIN_STRMAX 30

namespace Game {

	class GameState
	{
	public:
		GameState();
		GameState(HWND hWnd);
		virtual ~GameState();

	protected:
		int b_quit_ = 0;
		HWND hWnd_ = 0;
		GameState* next_ = NULL;

	public:
		virtual int Draw(HDC hdc) = 0;
		virtual int Update() = 0;
		virtual int Input(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;
		virtual int Next() = 0;
		inline GameState* NextState() { return next_; }
	};

}
