
// Win32_Client.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "framework.h"
#include "Win32_Client.h"

#include <list>
#include <vector>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#define WM_ASYNC WM_USER+1
using namespace std;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

WSADATA wsadata;
SOCKET s;
SOCKADDR_IN addr = { 0 };
TCHAR msg[200], str[100];
char buffer[100];
int msgLen;
int msgCount = 0;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int WinClient();	// deprecated

int Init_Client(HWND hWnd);
void Quit_Client();
void ReadMessage(TCHAR* msg, char* buffer);

BOOL CALLBACK CONTROL_DIALOG_Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

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
    LoadStringW(hInstance, IDC_WIN32CLIENT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32CLIENT));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32CLIENT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32CLIENT);
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

   HWND hWnd = CreateDialog(hInst, MAKEINTRESOURCE(IDD_CHATBOX), NULL, CONTROL_DIALOG_Proc);

   //HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
   //   CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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
	/*case WM_CREATE:
		return Init_Client(hWnd);
		break;*/

	/*case WM_ASYNC:
	{
		switch (lParam)
		{
		case FD_READ:
			ReadMessage(msg, buffer);
			InvalidateRgn(hWnd, NULL, TRUE);
			break;
		}
	}
	break;*/

//	case WM_CHAR:
//		if (wParam == VK_RETURN)
//		{
//			if (s == INVALID_SOCKET)
//				return 0;
//
//#ifdef _UNICODE
//			msgLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
//			WideCharToMultiByte(CP_ACP, 0, str, -1, buffer, msgLen, NULL, NULL);
//#else
//			strcpy(buffer, str);
//			msgLen = strlen(buffer);
//#endif
//			send(s, (LPSTR)buffer, msgLen + 1, 0);
//			msgCount = 0;
//			return 0;
//		}
//		str[msgCount++] = wParam;
//		str[msgCount] = NULL;
//		InvalidateRgn(hWnd, NULL, true);
//		break;

    //case WM_COMMAND:
    //    {
    //        int wmId = LOWORD(wParam);
    //        // 메뉴 선택을 구문 분석합니다:
    //        switch (wmId)
    //        {
    //        case IDM_ABOUT:
    //            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
    //            break;
    //        case IDM_EXIT:
    //            DestroyWindow(hWnd);
    //            break;
    //        default:
    //            return DefWindowProc(hWnd, message, wParam, lParam);
    //        }
    //    }
    //    break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
			TextOut(hdc, 0, 0, str, _tcslen(str));
			if (_tcscmp(msg, _T("")))
				TextOut(hdc, 0, 30, msg, (int)_tcslen(msg));

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		Quit_Client();
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

BOOL CALLBACK CONTROL_DIALOG_Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hCombo;
	static int selection;
	static HWND hList;
	static HWND hListName;
	static int list_index = 0;

	switch (iMsg)
	{

	case WM_ASYNC:
	{
		switch (lParam)
		{
		case FD_READ:
			ReadMessage(msg, buffer);
			//InvalidateRgn(hDlg, NULL, TRUE);
			SendMessage(hList, LB_INSERTSTRING, list_index++, (LPARAM)msg);
			break;
		}
	}
	break;

	case WM_INITDIALOG:
		hList = GetDlgItem(hDlg, IDC_LIST_CHAT);
		Init_Client(hDlg);
		return 1;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_EXIT:
			EndDialog(hDlg, 0);
			Quit_Client();
			PostQuitMessage(0);
			return 0;

		case ID_SEND:
		{
			TCHAR name[200];
			GetDlgItemText(hDlg, IDC_EDIT_CHAT, str, 100);
			GetDlgItemText(hDlg, IDC_EDIT_NAME, name, 200);
			if (_tcscmp(str, _T("")) && _tcscmp(name, _T("")))
			{
				if (s == INVALID_SOCKET)
					return 0;

				_tcscat_s(name,200, _T(" : "));
				_tcscat_s(name,200, str);

#ifdef _UNICODE
				msgLen = WideCharToMultiByte(CP_ACP, 0, name, -1, NULL, 0, NULL, NULL);
				WideCharToMultiByte(CP_ACP, 0, name, -1, buffer, msgLen, NULL, NULL);
#else
				strcpy(buffer, name);
				msgLen = strlen(buffer);
#endif
				send(s, (LPSTR)buffer, msgLen + 1, 0);
				msgCount = 0;

				return 0;
			}
			break;

		case IDC_LIST_CHAT:
			if (HIWORD(wParam) == LBN_SELCHANGE)
				selection = SendMessage(hList, LB_GETCURSEL, 0, 0);

		}
		}
		break;


	}

	return 0;
}



int WinClient()
{
	WSADATA wsadata;
	SOCKET s;
	SOCKADDR_IN addr = { 0 };

	WSAStartup(MAKEWORD(2, 2), &wsadata);
	s = socket(AF_INET, SOCK_STREAM, 0);
	addr.sin_family = AF_INET;
	addr.sin_port = 20;
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	connect(s, (LPSOCKADDR)&addr, sizeof(addr));

	send(s, "hello world!", 12, 0);

	closesocket(s);
	WSACleanup();
	return 0;
}

int Init_Client(HWND hWnd)
{
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	s = socket(AF_INET, SOCK_STREAM, 0);
	addr.sin_family = AF_INET;
	addr.sin_port = 20;
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	WSAAsyncSelect(s, hWnd, WM_ASYNC, FD_READ);

	if (connect(s, (LPSOCKADDR)&addr, sizeof(addr)) == -1)
		return 0;

	return 1;
}

void Quit_Client()
{
	closesocket(s);
	WSACleanup();
}

void ReadMessage(TCHAR* msg, char* buffer)
{
	msgLen = recv(s, buffer, 100, 0);
	buffer[msgLen] = NULL;
#ifdef _UNICODE
	msgLen = MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), NULL, NULL);
	MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), msg, msgLen);
	msg[msgLen] = NULL;
#else
	strcpy(msg, buffer);
#endif
}