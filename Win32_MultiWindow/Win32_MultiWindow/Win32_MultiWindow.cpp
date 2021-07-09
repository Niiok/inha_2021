// Win32_MultiWindow.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32_MultiWindow.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

HWND ChildWnd[3];
int draw_mode = -1;


// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

LRESULT CALLBACK    ChildWnd1Proc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ChildWnd2Proc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ChildWnd3Proc(HWND, UINT, WPARAM, LPARAM);

void DrawRectangle(HDC hdc, COORD center, INT width, INT height);
void DrawCircle(HDC hdc, COORD center, INT radius);
void DrawStar(HDC hdc, COORD center, INT radius, INT wings);


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
    LoadStringW(hInstance, IDC_WIN32MULTIWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32MULTIWINDOW));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32MULTIWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32MULTIWINDOW);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	RegisterClassExW(&wcex);
	
    wcex.lpfnWndProc    = ChildWnd1Proc;
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = _T("Child Window Class 1");
	RegisterClassExW(&wcex);
	
	wcex.lpfnWndProc    = ChildWnd2Proc;
    wcex.lpszClassName  = _T("Child Window Class 2");
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc    = ChildWnd3Proc;
    wcex.lpszClassName  = _T("Child Window Class 3");
	RegisterClassExW(&wcex);

	return NULL;
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
    switch (message)
    {
	case WM_CREATE:
	{
		RECT rectView;
		GetClientRect(hWnd, &rectView);
		//rectView.right -= rectView.left;
		ChildWnd[0] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child WIndow Class 1"),
			NULL, WS_CHILD | WS_VISIBLE, 0, 0, 
			rectView.right/2-1, rectView.bottom / 2 - 1, hWnd, NULL, hInst, NULL);
		ChildWnd[1] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child WIndow Class 2"),
			NULL, WS_CHILD | WS_VISIBLE, 0,	rectView.bottom/2+1, 
			rectView.right/2-1, rectView.bottom / 2 - 1, hWnd, NULL, hInst, NULL);
		ChildWnd[2] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child WIndow Class 3"),
			NULL, WS_CHILD | WS_VISIBLE, rectView.right/2-1, 0, 
			rectView.right/2 -1, rectView.bottom, hWnd, NULL, hInst, NULL);
	}
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
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
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

LRESULT CALLBACK ChildWnd1Proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static SHORT x = 0;
	static SHORT y = 0;

	switch (message)
	{
	case WM_CREATE:
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		switch (draw_mode)
		{
		case 0:	// rect
			DrawRectangle(hdc, {x, y}, 100, 100);
			break;

		case 1:	// circle
			DrawCircle(hdc, { x, y }, 50);
			break;

		case 2:	// star
			DrawStar(hdc, { x, y }, 50, 5);
			break;
		}
		EndPaint(hWnd, &ps);
	}
	break;

	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		InvalidateRect(hWnd, NULL, false);
		break;

	case WM_DESTROY:
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

LRESULT CALLBACK ChildWnd2Proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static RECT client_rect;
	static int old_mode = -1;


	switch (message)
	{
	case WM_CREATE:
		GetClientRect(hWnd, &client_rect);
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		switch (draw_mode)
		{
		case 0:	// rect
			DrawRectangle(hdc, { (SHORT)client_rect.right/2,
				(SHORT)client_rect.bottom/2 }, 100, 100);
			break;

		case 1:	// circle
			DrawCircle(hdc, { (SHORT)client_rect.right / 2,
				(SHORT)client_rect.bottom / 2 }, 50);
			break;

		case 2:	// star
			DrawStar(hdc, { (SHORT)client_rect.right / 2,
				(SHORT)client_rect.bottom / 2 }, 50, 5);
			break;
		}
		EndPaint(hWnd, &ps);
	}
	break;

	case WM_COMMAND:
	if (old_mode != draw_mode)
	{
		old_mode = draw_mode;
		InvalidateRect(hWnd, NULL, true);
	}
	break;

	case WM_DESTROY:
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

LRESULT CALLBACK ChildWnd3Proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	constexpr int BUTTON_RECT = 110;
	constexpr int BUTTON_CIRCLE = 220;
	constexpr int BUTTON_STAR = 330;

	 HWND hBtn_rect;
	 HWND hBtn_circle;
	 HWND hBtn_star;
	static RECT client_rect;

	switch (message)
	{
	case WM_CREATE:
		GetClientRect(hWnd, &client_rect);

		hBtn_rect = CreateWindow(_T("button"), _T("Rectangle"),
	WS_CHILD | WS_VISIBLE | DFCS_BUTTONPUSH, 
			client_rect.right*0.4, client_rect.bottom*0.1,
			client_rect.right*0.2, client_rect.bottom*0.1, hWnd,
	(HMENU)BUTTON_RECT, hInst, NULL);

		hBtn_rect = CreateWindow(_T("button"), _T("Circle"),
	WS_CHILD | WS_VISIBLE | DFCS_BUTTONPUSH, 
			client_rect.right*0.4, client_rect.bottom*0.3,
			client_rect.right*0.2, client_rect.bottom*0.1, hWnd,
	(HMENU)BUTTON_CIRCLE, hInst, NULL);

		hBtn_rect = CreateWindow(_T("button"), _T("Star"),
	WS_CHILD | WS_VISIBLE | DFCS_BUTTONPUSH, 
			client_rect.right*0.4, client_rect.bottom*0.5,
			client_rect.right*0.2, client_rect.bottom*0.1, hWnd,
	(HMENU)BUTTON_STAR, hInst, NULL);
		break;

	case WM_SIZE:
		GetClientRect(hWnd, &client_rect);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case BUTTON_RECT:
		{
			HDC hdc = GetDC(hWnd);
			TextOut(hdc, client_rect.right * 0.41,
				client_rect.bottom*0.8, _T("Rectangle selected"), 18);
			ReleaseDC(hWnd, hdc);
			draw_mode = 0;
			SendMessage(ChildWnd[1], WM_COMMAND, NULL, NULL);
			return 0;
		}
		case BUTTON_CIRCLE:
		{
			HDC hdc = GetDC(hWnd);
			TextOut(hdc, client_rect.right * 0.41,
				client_rect.bottom*0.8, _T("   Circle selected    "), 22);
			ReleaseDC(hWnd, hdc);
			draw_mode = 1;
			SendMessage(ChildWnd[1], WM_COMMAND, NULL, NULL);
			return 0;
		}
		case BUTTON_STAR:
		{
			HDC hdc = GetDC(hWnd);
			TextOut(hdc, client_rect.right * 0.41,
				client_rect.bottom*0.8, _T("     Star selected     "), 23);
			ReleaseDC(hWnd, hdc);
			draw_mode = 2;
			SendMessage(ChildWnd[1], WM_COMMAND, NULL, NULL);
			return 0;
		}
		}
		break;

	case WM_DESTROY:
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}



void DrawCircle(HDC hdc, COORD center, INT radius)
{
	Ellipse(hdc, center.X - radius, center.Y - radius, center.X + radius, center.Y + radius);
}

void DrawRectangle(HDC hdc, COORD center, INT width, INT height)
{
	Rectangle(hdc, center.X - width / 2, center.Y - height / 2, center.X + width / 2, center.Y + height / 2);
}

void DrawStar(HDC hdc, COORD center, INT radius, INT wings)
{
	if (wings < 4 || 360 % wings != 0)
		return;

	const double GOLDEN_RATIO = 1.61803398875;
	const double DTR = M_PI / 180;	// degree to radian
	const INT degree = 360 / wings;

	POINT* points = (POINT*)malloc(sizeof(POINT) * wings * 2);

	// outer points
	POINT outer = { 0, -radius };
	for (int i = 0; i < wings; ++i)
	{
		INT x = outer.x*cos(DTR * degree * i) - outer.y*sin(DTR * degree * i);
		INT y = outer.x*sin(DTR * degree * i) + outer.y*cos(DTR * degree * i);
		points[i * 2] = { center.X + x ,center.Y + y };
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
		points[i * 2 + 1] = { center.X + x ,center.Y + y };
	}

	Polygon(hdc, points, wings * 2);
	free(points);
}