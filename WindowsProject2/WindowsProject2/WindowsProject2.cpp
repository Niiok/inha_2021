// WindowsProject2.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject2.h"
//#pragma comment (lib, "msimg32.lib")

#include <ObjIdl.h>
#include <gdiplus.h>
//#pragma comment (lib, "Gdiplus.lib")
using namespace Gdiplus;

#define MAX_LOADSTRING 100
#define TIMER_1 1

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

HBITMAP hBackImage;
BITMAP bitBack;
HBITMAP hTransparentImage;
BITMAP bitTransparent;
HBITMAP hAniImage;
BITMAP bitAni;

const int SPRITE_SIZE_X = 57;
const int SPRITE_SIZE_Y = 52;
int RUN_FRAME_WIDTH = 0;
int RUN_FRAME_END = 1;
int RUN_FRAME_START = 0;
int frame_add = 1;
int curframe = RUN_FRAME_START;
POINT AniPos = { 0,0 };
int xStart = 0;
int yStart = 0;

RECT rectView;
HBITMAP hDoubleBufferImage;
HBITMAP hReverseImage;

GdiplusStartupInput g_GdiInput;
ULONG_PTR g_GdiToken;



// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void CreateBitmap();
void DrawBitmap(HWND hWnd, HDC hdc);
void DeleteBitmap();
void Update();
void UpdateFrame();
void UpdateFrame(HWND hWnd);

VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);
void DrawBitmapDoubleBuffering(HWND hWnd, HDC hdc);

void GDI_Init();
void GDI_Draw(HDC hdc);
void GDI_End();
void GDI_OnPaint(HDC hdc);


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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT2));

    MSG msg;

	GDI_Init();

    // 기본 메시지 루프입니다:
	while (1)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message != WM_QUIT)
			{
				if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
			else
				break;
		}
		else
		{
			Update();
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT2);
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
		SetTimer(hWnd, TIMER_1, 1000 / 30, NULL);
		CreateBitmap();
		break;


	case WM_SIZE:
		GetClientRect(hWnd, &rectView);
		//rectView.bottom -= rectView.top;
		//rectView.right -= rectView.left;
		//rectView.top = 0;
		//rectView.left = 0;
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

	case WM_TIMER:
		switch (LOWORD(wParam))
		{
		case TIMER_1:
			UpdateFrame(hWnd);
			InvalidateRect(hWnd, NULL, false);
			break;
		}
		break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
			GetClientRect(hWnd, &rectView);

			//DrawBitmap(hWnd, hdc);
			DrawBitmapDoubleBuffering(hWnd, hdc);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		KillTimer(hWnd, TIMER_1);
		GDI_End();
		DeleteBitmap();
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


void CreateBitmap()
{
	hBackImage = (HBITMAP)LoadImage(NULL, TEXT("../image/수지.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hBackImage, sizeof(BITMAP), &bitBack);

	hTransparentImage = (HBITMAP)LoadImage(NULL, TEXT("../image/sigong.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hTransparentImage, sizeof(BITMAP), &bitTransparent);

	hAniImage = (HBITMAP)LoadImage(NULL, TEXT("../image/zero_run.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hAniImage, sizeof(BITMAP), &bitAni);

	RUN_FRAME_WIDTH = bitAni.bmWidth / SPRITE_SIZE_X;
	RUN_FRAME_END = RUN_FRAME_WIDTH;
	RUN_FRAME_START = 2;
	curframe = RUN_FRAME_START;
}

void DrawBitmap(HWND hWnd, HDC hdc)
{
	HDC hMemDC;
	HBITMAP hOldBitmap;
	int bx, by;


	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBackImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;

		BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);

		SelectObject(hMemDC, hOldBitmap);

		DeleteDC(hMemDC);
	}

	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hTransparentImage);
		bx = bitTransparent.bmWidth;
		by = bitTransparent.bmHeight;

		BitBlt(hdc, 100, 200, bx, by, hMemDC, 0, 0, SRCCOPY);
		TransparentBlt(hdc, 200, 200, bx, by, hMemDC, 0, 0, bx, by, RGB(255, 0, 255));

		SelectObject(hMemDC, hOldBitmap);
		DeleteDC(hMemDC);
	}

	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hAniImage);
		bx = bitAni.bmWidth / 16;
		by = bitAni.bmHeight / 2;

		//int xStart = curframe * bx;
		//int yStart = 0;

		TransparentBlt(hdc, 200, 400, bx, by, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255));

		SelectObject(hMemDC, hOldBitmap);
		DeleteDC(hMemDC);
	}

}

void DeleteBitmap()
{
	DeleteObject(hBackImage);
	DeleteObject(hTransparentImage);
	DeleteObject(hAniImage);
}


void Update()
{
	DWORD newTime = GetTickCount();
	static DWORD oldTime = newTime;
	if (newTime - oldTime < 2) 
		return;
	oldTime = newTime;

	UpdateFrame();
}

void UpdateFrame()
{
	constexpr int speed = 5;
	int key_pressed = 0;

	if (GetKeyState(VK_RIGHT) & 0x8000) {
		AniPos.x += speed;
		xStart = 0;
		yStart = 0;
		RUN_FRAME_END = RUN_FRAME_WIDTH;
		RUN_FRAME_START = 2;
		frame_add = 1;
		if (curframe > RUN_FRAME_END)
			curframe = RUN_FRAME_START;
		key_pressed = 1;
	}
	else if (GetKeyState(VK_LEFT) & 0x8000) {
		AniPos.x -= speed;
		xStart = 0;
		yStart = 1;
		RUN_FRAME_END = -1;
		RUN_FRAME_START = RUN_FRAME_WIDTH-3;
		frame_add = -1;
		if (curframe < RUN_FRAME_END)
			curframe = RUN_FRAME_START;
		key_pressed = 1;
	}

	if (GetKeyState(VK_UP) & 0x8000) {
		AniPos.y -= speed;
		key_pressed = 1;
	}
	else if (GetKeyState(VK_DOWN) & 0x8000) {
		AniPos.y += speed;
		key_pressed = 1;
	}

	if (!key_pressed)
		curframe = RUN_FRAME_START - frame_add * 2;

}

void UpdateFrame(HWND hWnd)
{
	curframe+=frame_add;
	if (curframe == RUN_FRAME_END)
		curframe = RUN_FRAME_START;

}

void DrawBitmapDoubleBuffering(HWND hWnd, HDC hdc)
{
	HDC hMemDC;
	HBITMAP hOldBitmap;
	int bx, by;

	HDC hMemDC2;
	HBITMAP hOldBitmap2;

	hMemDC = CreateCompatibleDC(hdc);
	if (!hMemDC)
		MessageBox(hWnd, _T("CreateCompatibleDC failed"), _T("Error"), MB_OK);
	if (hDoubleBufferImage == NULL)
	{
		hDoubleBufferImage = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
	}

	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hDoubleBufferImage);

	//{
	//	//hMemDC2 = CreateCompatibleDC(hMemDC);
	//	hOldBitmap2 = (HBITMAP)SelectObject(hMemDC, hBackImage);
	//	bx = bitBack.bmWidth;
	//	by = bitBack.bmHeight;

	//	//BitBlt(hMemDC, 0, 0, bx, by, hMemDC2, 0, 0, SRCCOPY);
	//	//TransparentBlt(hMemDC, 200, 200, bx, by, hMemDC2, 0, 0, bx, by, RGB(255, 0, 255));

	//	//SelectObject(hMemDC2, hOldBitmap2);
	//	//DeleteDC(hMemDC2);
	//}
	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hBackImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;

		BitBlt(hMemDC, 0, 0, bx, by, hMemDC2, 0, 0, SRCCOPY);
		//TransparentBlt(hMemDC, 200, 200, bx, by, hMemDC2, 0, 0, bx, by, RGB(255, 0, 255));

		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}
	
	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hTransparentImage);
		bx = bitTransparent.bmWidth;
		by = bitTransparent.bmHeight;

		BitBlt(hMemDC, 100, 200, bx, by, hMemDC2, 0, 0, SRCCOPY);
		TransparentBlt(hMemDC, 200, 200, bx, by, hMemDC2, 0, 0, bx, by, RGB(255, 0, 255));

		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}

	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hAniImage);

		//HDC hReverseMemDC;
		//HBITMAP hOldBitmap3;
		//hReverseMemDC = (HDC)CreateCompatibleBitmap(hMemDC, bx, by);
		//if (!hReverseMemDC)
		//{
		//	hReverseImage = CreateCompatibleBitmap(hMemDC2, bx, by);
		//}
		//hOldBitmap3 = (HBITMAP)SelectObject(hReverseMemDC, hReverseImage);

		bx = bitAni.bmWidth / 16;
		by = bitAni.bmHeight / 2;

		//int xStart = curframe * bx;
		//int yStart = 0;
		

		//StretchBlt(hReverseMemDC, bx - 1, 0, -bx, by, hMemDC2, xStart, yStart, bx, by, SRCCOPY);
		//TransparentBlt(hReverseMemDC, 200, 200, bx * 2, by * 2, hMemDC2, xStart, yStart, bx, by, RGB(255, 0, 255));

		TransparentBlt(hMemDC, AniPos.x, AniPos.y, bx * 2, by * 2, hMemDC2, xStart+curframe*bx, yStart*by, bx, by, RGB(255, 0, 255));

		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}

	GDI_Draw(hMemDC);

	BitBlt(hdc, 0, 0, rectView.right, rectView.bottom, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldBitmap);
	DeleteDC(hMemDC);
}

void GDI_Init()
{
	GdiplusStartup(&g_GdiToken, &g_GdiInput, NULL);
}

void GDI_Draw(HDC hdc)
{
	GDI_OnPaint(hdc);
}

void GDI_End()
{
	GdiplusShutdown(g_GdiToken);
}

void GDI_OnPaint(HDC hdc)
{
	Gdiplus::Graphics graphics(hdc);

	SolidBrush brush(Color(255, 255, 0, 0));
	FontFamily fontFamily(L"Times New Roman");
	Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
	PointF pointF(10.0f, 20.0f);
	graphics.DrawString(L"Hello GDI+", -1, &font, pointF, &brush);

	Pen pen(Color(255, 0, 255, 255));
	graphics.DrawLine(&pen, 0, 0, 200, 100);

	Image img((WCHAR*)L"../image/sigong.png");
	int w = img.GetWidth();
	int h = img.GetHeight();
	graphics.DrawImage(&img, 100, 100, w, h);

	Image* pimg = Image::FromFile((WCHAR*)L"../image/sigong.png");

	Gdiplus::Matrix mat;
	Gdiplus::Matrix mat_spin;
	static int rot = 0;
	int xPos = 200;
	int yPos = 100;
	mat_spin.RotateAt(rot % 360, Gdiplus::PointF(200 + (float)w/2, 100 + (float)h / 2));
	rot += 2;
	graphics.SetTransform(&mat_spin);
	graphics.DrawImage(pimg, xPos, yPos, w, h);

	ImageAttributes imgAttr;
	imgAttr.SetColorKey(Color(240, 0, 240), Color(255, 10, 255));
	xPos = 300;
	//mat.RotateAt(rot % 360, Gdiplus::PointF(200 + (float)w/2, 100 + (float)h / 2));
	//graphics.SetTransform(&mat);
	graphics.DrawImage(pimg, Rect(xPos - (float)w / 2, yPos - (float)h / 2, w, h),
		0, 0, w, h, UnitPixel, &imgAttr);

	graphics.SetTransform(&mat);

	brush.SetColor(Color(128, 255, 0, 0));
	graphics.FillRectangle(&brush, 100, 100, 200, 300);

	REAL transparency = 0.5f;
	ColorMatrix colorMatrix = {
		1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, transparency, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f, 1.0f
	};
	imgAttr.SetColorMatrix(&colorMatrix);
	xPos = 400;
	graphics.DrawImage(pimg, Rect(xPos, yPos, w, h),
		0, 0, w, h, UnitPixel, &imgAttr);
	

	if (pimg)
		delete pimg;
}

