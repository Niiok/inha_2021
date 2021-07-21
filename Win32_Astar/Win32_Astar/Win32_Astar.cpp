// Win32_Astar.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32_Astar.h"

#define MAX_LOADSTRING 100

class Tile;

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
extern int _tile[MAP_SIZE][MAP_SIZE];
Astar _map;
std::vector<vector<Tile>> _tiles;
RECT client_rect;
intXY _src = {-1, -1};
intXY _dst = {-1, -1};

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void Draw(HDC hdc);

class Tile {

public:
	Tile(Astar& map, int x, int y) : map_{map}
	{
		idea_x_ = x ;
		idea_y_ = y ;
	}

	int idea_x_;
	int idea_y_;
	Astar& map_;

	int left_ = 0;
	int top_ = 0;
	int right_ = 0;
	int bottom_ = 0;

	int flag_ = 2;

	void WindowFit(RECT client) noexcept
	{
		left_ = idea_x_ * client.right / MAP_SIZE;
		top_ = idea_y_ * client.bottom / MAP_SIZE;
		right_ = (idea_x_ + 1) * client.right / MAP_SIZE;
		bottom_ = (idea_y_ + 1) * client.bottom / MAP_SIZE;
	}

	void Draw(HDC hdc)
	{
		COLORREF color;

		WindowFit(client_rect);

		if (map_.dist_src[idea_y_][idea_x_] == INT_MAX/2)
		{
			switch (_tile[idea_y_][idea_x_])
			{
			case 0: // empty
				color = RGB(255, 255, 255);
				break;
			case 1:	// blocked
				color = RGB(0, 0, 0);
				break;
			}
		}
		else
		{
			switch (flag_)
			{
			case 0:	// src
				color = RGB(128, 128, 255);
				break;
			case 1:	// intermediate
				color = RGB(255, 128, 126);
				break;
			default:
				color = RGB(128, 255, 128);
				break;
			}
		}

		HBRUSH old = (HBRUSH)SelectObject(hdc, CreateSolidBrush(color));

		Rectangle(hdc, left_, top_, right_, bottom_);

		HBRUSH todel = (HBRUSH)SelectObject(hdc, old);
		DeleteObject(todel);

		flag_ = 2;
	}
};

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
	for (int i = 0; i < MAP_SIZE; ++i)
		for (int j = 0; j < MAP_SIZE; ++j)
			_tile[i][j] = 0;

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32ASTAR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32ASTAR));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}




ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32ASTAR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32ASTAR);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		astar({ 0,0 }, {0,0}, _map);

		for (int y = 0; y < MAP_SIZE; ++y)
		{
			_tiles.push_back(std::vector<Tile>());
			for (int x = 0; x < MAP_SIZE; ++x)
				_tiles[y].push_back(Tile(_map, x, y));
		}
		break;

	case WM_SIZE:
		GetClientRect(hWnd, &client_rect);

		for (int y = 0; y < MAP_SIZE; ++y)
			for (int x = 0; x < MAP_SIZE; ++x)
				_tiles[y][x].WindowFit(client_rect);

		InvalidateRect(hWnd, NULL, true);
		break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
			Draw(hdc);

            EndPaint(hWnd, &ps);
        }
        break;

	case WM_RBUTTONDOWN:
	{
		static int clicked = 0;
		int clicked_x = (float)LOWORD(lParam) / client_rect.right * MAP_SIZE;
		int clicked_y = (float)HIWORD(lParam) / client_rect.bottom * MAP_SIZE;

		if (_tile[clicked_y][clicked_x] != 1)
		{
			switch (clicked)
			{
			case 0:
				_src.x = clicked_x;
				_src.y = clicked_y;
				_dst.x = clicked_x;
				_dst.y = clicked_y;

				astar(_src, _dst, _map);

				clicked = 1;

				break;
			case 1:

				_src.x = _dst.x;
				_src.y = _dst.y;
				_dst.x = clicked_x;
				_dst.y = clicked_y;

				astar(_src, _dst, _map);

				clicked = 0;

				break;
			}
			InvalidateRect(hWnd, NULL, true);
		}
	}
	break;

	case WM_MOUSEMOVE:
	{
		int clicked_x = (float)LOWORD(lParam) / client_rect.right * MAP_SIZE;
		int clicked_y = (float)HIWORD(lParam) / client_rect.bottom * MAP_SIZE;

		if((wParam & MK_LBUTTON) == MK_LBUTTON)
		{
			if ((wParam & MK_SHIFT) == MK_SHIFT)
			{
				_tile[clicked_y][clicked_x] = 0;
			}
			else
			{
				_tile[clicked_y][clicked_x] = 1;
			}
		}
	}
	break;

	case WM_LBUTTONDOWN:
	{
		int clicked_x = (float)LOWORD(lParam) / client_rect.right * MAP_SIZE;
		int clicked_y = (float)HIWORD(lParam) / client_rect.bottom * MAP_SIZE;

		if((wParam & MK_LBUTTON) == MK_LBUTTON)
		{
			if ((wParam & MK_SHIFT) == MK_SHIFT)
			{
				_tile[clicked_y][clicked_x] = 0;
			}
			else
			{
				_tile[clicked_y][clicked_x] = 1;
			}
		}

		InvalidateRect(hWnd, NULL, true);
	}
	case WM_LBUTTONUP:
		astar({ 0,0 }, { 0,0 }, _map);
		InvalidateRect(hWnd, NULL, true);
		break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


void Draw(HDC hdc)
{
	if (_src.x >= 0 && _dst.x >= 0)
	{
		_tiles[_src.y][_src.x].flag_ = 0;

		for (intXY i = _map.prior[_dst.y][_dst.x]; i != _src;)
		{
			if (i.x == -1)
				break;

			_tiles[i.y][i.x].flag_ = 1;

			i = _map.prior[i.y][i.x];
		}

		_tiles[_dst.y][_dst.x].flag_ = 0;
	}

		for (int y = 0; y < MAP_SIZE; ++y)
			for (int x = 0; x < MAP_SIZE; ++x)
				_tiles[y][x].Draw(hdc);
}