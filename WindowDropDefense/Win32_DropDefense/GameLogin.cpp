#include "GameLogin.h"

using namespace Game;


GameLogin::GameLogin(HWND hWnd) : GameState(hWnd)
{
	ShowCaret(hWnd);
}
GameLogin::~GameLogin()
{
	HideCaret(hWnd_);
}


int GameLogin::Draw(HDC hdc)
{
	SIZE caret_pos;
	GetClientRect(hWnd_, &client_);
	client_.bottom = client_.bottom - client_.top;
	client_.right = client_.right - client_.left;
	client_.top = 0;
	client_.left = 0;

	Rectangle(hdc, client_.right * 0.3, client_.bottom * 0.7 , client_.right * 0.7, client_.bottom * 0.7 + 19);
	TextOut(hdc, client_.right * 0.3 + 20, client_.bottom * 0.7-20, L"ID를 입력하세요.", 10);
	TextOut(hdc, client_.right * 0.3 + 1, client_.bottom * 0.7+1, str_, strlen_);
	GetTextExtentPoint(hdc, str_, strlen_, &caret_pos);
	SetCaretPos(client_.right * 0.3 + caret_pos.cx + 2, client_.bottom * 0.7 + 2);

	return 0;
}

int GameLogin::Update()
{
	// nothing

	return 0;
}

int GameLogin::Input(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_KEYDOWN:
		break;
	case WM_KEYUP:
		break;
	case WM_CHAR:
		//b_keydown = true;
		switch (wParam)
		{
		case VK_BACK:
			if (strlen_ == 0)
				break;
			str_[--strlen_] = NULL;
			break;
		case VK_RETURN:
			/*if (strlen_ == LOGIN_STRMAX-1)
				break;
			str_[strlen_++] = wParam;
			str_[strlen_] = NULL;*/
			Next();
			break;

		default:
			if (strlen_ == LOGIN_STRMAX-1)
				break;
			str_[strlen_++] = wParam;
			str_[strlen_] = NULL;
			break;
		}
		break;
	case WM_LBUTTONDOWN:
		break;
	case WM_RBUTTONDOWN:
		break;
	}
	
	return 0;
}

int GameLogin::Next()
{
	GamePlay* temp = new GamePlay(hWnd_);
	temp->SetChar(str_);

	next_ = temp;
	b_quit_ = 1;
	return 0;
}