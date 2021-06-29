#include "GameOver.h"

using namespace Game;


GameOver::GameOver(HWND hWnd) : GameState(hWnd)
{
}
GameOver::~GameOver()
{
}



int GameOver::Draw(HDC hdc)
{
	GetClientRect(hWnd_, &client_);
	client_.bottom = client_.bottom - client_.top;
	client_.right = client_.right - client_.left;
	client_.top = 0;
	client_.left = 0;

	return 0;
}

int GameOver::Update()
{
	// nothing

	return 0;
}

int GameOver::Input(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_KEYDOWN:
		Next();
		break;
	case WM_KEYUP:
		break;
	case WM_CHAR:
		break;
	case WM_LBUTTONDOWN:
		break;
	case WM_RBUTTONDOWN:
		break;
	}

	return 0;
}

int GameOver::Next()
{
	GameLogin* temp = new GameLogin(hWnd_);

	next_ = temp;
	b_quit_ = 1;
	return 0;
}

int GameOver::SetChar(TCHAR* str)
{
	_tcscpy(str_, str);

	return 0;
}