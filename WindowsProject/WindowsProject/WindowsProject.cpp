// WindowsProject.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#define _USE_MATH_DEFINES
#include "framework.h"
#include "WindowsProject.h"
#include <cmath>
#include <ctime>

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void DrawGrid(HDC hdc, RECT rect, INT line_num);
void DrawCircle(HDC hdc, COORD center, INT radius);
void DrawSunflower(HDC hdc, COORD center, INT radius, INT leaves);
void DrawRectangle(HDC hdc, COORD center, INT width, INT height);
void DrawInputText(HDC hdc, RECT area, LPCTSTR str);
void DrawStar(HDC hdc, COORD center, INT radius, INT wings);
void DrawStar_weird(HDC hdc, COORD center, INT radius);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT));

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



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
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

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static bool b_keydown = false;
	static TCHAR str[1024];
	static INT count = 0;
	static SIZE size;

    switch (message)
    {
	case WM_CREATE:
		CreateCaret(hWnd, NULL, 5, 15);
		ShowCaret(hWnd);

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
			RECT win_rect;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
			GetWindowRect(hWnd, &win_rect);
			//DrawGrid(hdc, {0,0,win_rect.right-win_rect.left, win_rect.bottom - win_rect.top}, 100);				
			DrawStar(hdc, { 100, 200 }, 45, 6);
			DrawStar(hdc, { 200, 200 }, 45, 5);
			DrawStar(hdc, { 300, 200 }, 45, 4);
			DrawStar(hdc, { 400, 200 }, 45, 8);
			DrawStar(hdc, { 500, 200 }, 45, 3);
			DrawStar_weird(hdc, { 200, 80 }, 45);
			DrawInputText(hdc, { 10, 10, 400, 400 }, str);
			DrawRectangle(hdc, {400, 100}, 10, 10);

			srand(time(NULL));
		
			HBRUSH brush = CreateSolidBrush(rand());
			HBRUSH old_brush = (HBRUSH)SelectObject(hdc, brush);

			int max = (rand() % 200) + 10;
			for (int i = 0; i < max; ++i)
			{
				brush = CreateSolidBrush(RGB(rand()%256, rand()%256, rand()%256));
				brush = (HBRUSH)SelectObject(hdc, brush);
				DeleteObject(brush);
				SHORT x = rand() % (SHORT)(win_rect.right - win_rect.left);
				SHORT y = rand() % (SHORT)(win_rect.bottom - win_rect.top);
				INT rad = (rand() % 50)+20;
				DrawCircle(hdc, {x ,y }, rad);
			}

			brush = (HBRUSH)SelectObject(hdc, old_brush);
			DeleteObject(brush);

			for (int i = 0; i < 10; ++i)
			{
				SHORT x = rand() % (SHORT)(win_rect.right - win_rect.left);
				SHORT y = rand() % (SHORT)(win_rect.bottom - win_rect.top);
				INT rad = (rand() % 50) + 10;
				INT leaves = (rand() % 50) + 6;
				DrawSunflower(hdc, { x, y }, rad, leaves);
			}

            EndPaint(hWnd, &ps);

			/*{
				HDC hdc = GetDC(hWnd);
				ReleaseDC(hWnd, hdc);
			}*/
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
	case WM_KEYDOWN:
		//b_keydown = true;
		//PostMessage(hWnd, WM_PAINT, 0, 0);
		//InvalidateRect(hWnd, NULL, true);
		break;
	case WM_KEYUP:
		//b_keydown = false;
		//PostMessage(hWnd, WM_PAINT, 0, 0);
		//InvalidateRect(hWnd, NULL, true);
		break;
	case WM_CHAR:
		//b_keydown = true;
		switch (wParam)
		{
		case VK_BACK:
			if (count == 0)
				break;
			str[--count] = NULL;
			break;
		case VK_RETURN:
			//count = 0;
			//str[0] = NULL;
			if (count == 1023)
				break;
			str[count++] = wParam;
			str[count] = NULL;
			break;
		default:
			if (count == 1023)
				break;
			str[count++] = wParam;
			str[count] = NULL;
			break;
		}
		InvalidateRect(hWnd, NULL, true);
		break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
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


void DrawGrid(HDC hdc, RECT rect, INT line_num)
{
	FLOAT x_gap = (FLOAT)(rect.right - rect.left) / (line_num - 1);
	FLOAT y_gap = (FLOAT)(rect.bottom - rect.top) / (line_num - 1);
	for (int i = 0; i < line_num; ++i)
	{
		MoveToEx(hdc, rect.left + (x_gap)*i ,rect.top , NULL);
		LineTo(hdc, rect.left + (x_gap) * i, rect.bottom);
		MoveToEx(hdc, rect.left , rect.top + (y_gap) * i, NULL);
		LineTo(hdc, rect.right, rect.top + (y_gap) * i);
	}
}

void DrawCircle(HDC hdc, COORD center, INT radius)
{
	Ellipse(hdc, center.X-radius, center.Y-radius, center.X + radius, center.Y+radius);
}

void DrawSunflower(HDC hdc, COORD center, INT radius, INT leaves)
{

	if (leaves < 3 || 360 % leaves != 0)
		return;

	float leaf_theta = 2 * M_PI / leaves;
	float leaf_rad = abs(radius * sin(leaf_theta / 2) / (1 - sin(leaf_theta / 2)));

	COORD leaf_center{0 , 0-(radius+leaf_rad)};

	HBRUSH brush = CreateSolidBrush((DWORD)(0x001144));
	HBRUSH old_brush = (HBRUSH)SelectObject(hdc, brush);
	Ellipse(hdc, center.X-radius, center.Y-radius, center.X + radius, center.Y+radius);

	DeleteObject(brush);
	brush = CreateSolidBrush((DWORD)(0x00FFFF));
	SelectObject(hdc, brush);
	for (int i = 0; i < leaves; ++i)
	{
		SHORT x = cos(leaf_theta*i)*leaf_center.X + sin(leaf_theta*i)*leaf_center.Y;
		SHORT y = -sin(leaf_theta*i)*leaf_center.X + cos(leaf_theta*i)*leaf_center.Y;

		Ellipse(hdc, center.X + x - leaf_rad,
			center.Y + y - leaf_rad,
			center.X + x + leaf_rad,
			center.Y + y + leaf_rad);
	}

	DeleteObject(brush);
	SelectObject(hdc, old_brush);
	SelectObject(hdc, brush);
}

void DrawRectangle(HDC hdc, COORD center, INT width, INT height)
{
	Rectangle(hdc, center.X - width / 2, center.Y - height / 2, center.X + width / 2, center.Y + height / 2);
}

void DrawInputText(HDC hdc, RECT area, LPCTSTR str)
{
	INT x_pos = 0;
	INT y_pos = 1;
	INT max_x = 0;
	INT count = _tcslen(str);

	for (int i = 0; i < count; ++i)
	{
		++x_pos;
		if (x_pos > max_x)
			max_x = x_pos;

		if (str[i] == static_cast<TCHAR>('\n'))
		{
			x_pos = 0;
			++y_pos;
		}
	}

	SIZE size;

	//GetTextExtentPoint(hdc, str + (count - x_pos), x_pos, &size);
	GetTextExtentPoint(hdc, str, x_pos, &size);
	Rectangle(hdc, area.left-1, area.top-1, area.left + size.cx +1, area.top + y_pos*16+1);
	//TextOut(hdc, 0, y_pos, str, _tcslen(str));
	DrawText(hdc, str, _tcslen(str), &area, DT_TOP | DT_LEFT);
	SetCaretPos(area.left + size.cx, area.top + (y_pos-1)*16);

}

void DrawStar(HDC hdc, COORD center, INT radius, INT wings)
{
	if (wings < 4 || 360 % wings != 0)
		return;

	const double GOLDEN_RATIO = 1.61803398875;
	const double DTR = M_PI / 180;	// degree to radian
	const INT degree = 360 / wings;

	POINT* points = (POINT*)malloc(sizeof(POINT) * wings*2);

	// outer points
	POINT outer = { 0, -radius };
	for (int i = 0; i < wings; ++i)
	{
		INT x = outer.x*cos(DTR * degree * i) - outer.y*sin(DTR * degree * i);
		INT y = outer.x*sin(DTR * degree * i) + outer.y*cos(DTR * degree * i);
		points[i*2] = {center.X + x ,center.Y + y };
	}

	// inner points
	double star_half = (1 + GOLDEN_RATIO) / 2;
	double pentagon_half = star_half - 1;
	INT first_x = (points[2].x - center.X) * pentagon_half / star_half;
	INT first_y = (points[2].y - center.Y);
	POINT inner = { first_x, first_y };

	for (int i = 0; i < wings; ++i)
	{
		INT x = inner.x*cos(DTR * degree * i) - inner.y*sin(DTR * degree * i);
		INT y = inner.x*sin(DTR * degree * i) + inner.y*cos(DTR * degree * i);
		points[i * 2 +1] = { center.X + x ,center.Y + y };
	}
	
	Polygon(hdc, points, wings*2);
	free (points);
}

void DrawStar_weird(HDC hdc, COORD center, INT radius)
{
	const double GOLDEN_RATIO = 1.61803398875;
	const double DTR = M_PI / 180;	// degree to radian

	POINT points[10];

	// outer points
	POINT outer = { 0.-radius };
	for (int i = 0; i < 5; ++i)
	{
		INT x = outer.x*cos(DTR * 72 * i) - outer.y*sin(DTR * 72 * i);
		INT y = outer.x*sin(DTR * 72 * i) + outer.y*cos(DTR * 72 * i);
		points[i*2] = {center.X + x ,center.Y + y };
	}

	// inner points
	double star_half = (1 + GOLDEN_RATIO) / 2;
	double pentagon_half = star_half - 1;
	INT first_x = (points[2].x - center.X) * star_half / pentagon_half;
	INT first_y = (points[2].y - center.Y);
	POINT inner = { first_x, first_y };

	for (int i = 0; i < 5; ++i)
	{
		INT x = inner.x*cos(DTR * 72 * i) - inner.y*sin(DTR * 72 * i);
		INT y = inner.x*sin(DTR * 72 * i) + inner.y*cos(DTR * 72 * i);
		points[i * 2 +1] = { center.X + x ,center.Y + y };
	}
	
	Polygon(hdc, points, 10);
}

