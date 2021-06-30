#include "GameOver.h"

using namespace Game;


GameOver::GameOver(HWND hWnd) : GameState(hWnd)
{
}
GameOver::~GameOver()
{
	RankOut();
}



int GameOver::Draw(HDC hdc)
{
	GetClientRect(hWnd_, &client_);
	client_.bottom = client_.bottom - client_.top;
	client_.right = client_.right - client_.left;
	client_.top = 0;
	client_.left = 0;

	char str[32];
	wchar_t wstr[32];
	LPWSTR wptr = wstr;

	for (int i = 0; i < 5; ++i)
	{
		TextOut(hdc, client_.right*0.2f, client_.bottom*(0.11f*i + 0.1f), rankers[i].name, _tcslen(rankers[i].name));

		sprintf(str, "  %d", rankers[i].score);
		mbstowcs(wstr, str, strlen(str) + 1);
		TextOut(hdc, client_.right*0.5f, client_.bottom*(0.11f*i + 0.1f), wptr, _tcslen(wstr));

	}

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
		switch (wParam)
		{
		case VK_RETURN:
			Next();
			break;
		}
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

int GameOver::SetScore(int score)
{

	score_ = score; 
	RankIn();
	RankSort();

	return 0;
}

int GameOver::RankIn()
{
	_tcscpy(rankers[5].name, str_);
	rankers[5].score = score_;

	FILE* fin = fopen("../data/ranks", "rb");
	if (fin == NULL)
		return -1;

	for (int i = 0; i < 5; ++i)
	{
		if (fread(rankers[i].name, sizeof(TCHAR), LOGIN_STRMAX, fin) == LOGIN_STRMAX)
			fread(&rankers[i].score, sizeof(int), 1, fin);
		else
		{
			--i;
			break;
		}
	}


	fclose(fin);
	return 0;
}

int GameOver::RankSort()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5 - i; ++j)
		{
			if (rankers[j].score < rankers[j + 1].score)
			{
				Ranker temp = rankers[j];
				rankers[j] = rankers[j + 1];
				rankers[j + 1] = temp;
			}
		}
	}

	return 0;
}

int GameOver::RankOut()
{
	FILE* fout = fopen("../data/ranks", "wb");
	if (fout == NULL)
		return -1;

	for (int i = 0; i < 5; ++i)
	{
		fwrite(rankers[i].name, sizeof(TCHAR), LOGIN_STRMAX, fout);
		fwrite(&rankers[i].score, sizeof(int), 1, fout);
	}

	fclose(fout);
	return 0;
}
