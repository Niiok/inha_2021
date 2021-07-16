// Win32_MultiDot.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32_MultiDot.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

DWORD dwThreadIDs[10];
HANDLE hThreads[10];

int thread_num = 0;
HWND global_hwnd;
RECT client_rect;
int dot_x[10] = {-100, };
int dot_y[10] = {-100, };
HBRUSH colors[10];

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

unsigned __stdcall ThFunc(LPVOID lpParam);
void StopThread(int i);

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
    LoadStringW(hInstance, IDC_WIN32MULTIDOT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32MULTIDOT));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32MULTIDOT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32MULTIDOT);
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
    switch (message)
    {
	case WM_CREATE:
		//InitializeCriticalSection(NULL);

		thread_num = 0;
		global_hwnd = hWnd;
		//client_rect;
		GetClientRect(hWnd, &client_rect);
		client_rect.right -= client_rect.left;
		client_rect.bottom -= client_rect.top;
		client_rect.left = 0;
		client_rect.top = 0;
		for (int i = 0; i < 10; ++i)
		{
			dwThreadIDs[i] = NULL;
			hThreads[i] = NULL;
			dot_x[i] = -100;
			dot_y[i] = -100;
			colors[i] = NULL;
		}
		break;

	case WM_SIZE:
		GetClientRect(hWnd, &client_rect);
		client_rect.right -= client_rect.left;
		client_rect.bottom -= client_rect.top;
		client_rect.left = 0;
		client_rect.top = 0;
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

	case WM_LBUTTONDOWN:
	{
		if (hThreads[thread_num] != NULL)
		{
			CloseHandle(hThreads[thread_num]);
			//hThreads[thread_num] = NULL;
		}
		hThreads[thread_num] = (HANDLE)_beginthreadex(NULL, 0, 
			(unsigned(__stdcall*) (void*)) ThFunc,
			(void*)thread_num, 0, (unsigned*)&dwThreadIDs[thread_num]);
		
		ResumeThread(hThreads[thread_num]);

		thread_num = (thread_num < 9 ? thread_num + 1 : 0);
	}
	break;

	case WM_RBUTTONDOWN:
		for (int i = 0; i < 10; ++i)
		{
			//dwThreadIDs[i] = NULL;

			//hThreads[i]
			StopThread(i);
			//hThreads[i] = NULL;

			//colors[i]
			//DeleteObject(colors[i]);

			thread_num = 0;
		}
		InvalidateRect(hWnd, NULL, true);
		break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
			for (int i = 0; i < 10; ++i)
			{
				SelectObject(hdc, (HBRUSH)colors[i]);
				Ellipse(hdc, dot_x[i] - 30, dot_y[i] - 30,
					dot_x[i] + 30, dot_y[i] + 30);
			}

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		//DeleteCriticalSection(NULL);
		for (int i = 0; i < 10; ++i)
		{
			//dwThreadIDs[i] = NULL;

			//hThreads[i]
			CloseHandle(hThreads[i]);

			//colors[i]
			DeleteObject(colors[i]);
		}
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



unsigned __stdcall ThFunc(LPVOID lpParam)
{
	// lpParam is index of thread
	int index = (int)lpParam;
	srand(GetTickCount());

		DeleteObject(colors[index]);
		colors[index] = CreateSolidBrush(RGB((BYTE)rand(), (BYTE)rand(), (BYTE)rand()));

	while (1)
	{

		dot_x[index] = rand() % client_rect.right;
		dot_y[index] = rand() % client_rect.bottom;

		InvalidateRect(global_hwnd, NULL, true);

		Sleep(1000);
	}

	return 0;
}

void StopThread(int i)
{
	if (hThreads[i] != NULL)
	{
		CloseHandle(hThreads[i]);
	}

	if (dwThreadIDs[i] != NULL)
	{
		DWORD dwExitCode = 0;
		GetExitCodeThread(hThreads[i], &dwExitCode);
		if (dwExitCode == STILL_ACTIVE)
		{
			CloseHandle(hThreads[i]);
			TerminateThread(hThreads[i], dwExitCode);
		}
		dwThreadIDs[i] = NULL;
		hThreads[i] = NULL;
	}

	dot_x[i] = -100;
	dot_y[i] = -100;
	DeleteObject(colors[i]);
}
