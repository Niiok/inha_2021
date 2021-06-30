#include "Bitmapping.h"

//void DrawBitmap(HWND hWnd, HDC hdc)
//{
//	HDC hMemDC;
//	HBITMAP hOldBitmap;
//	int bx, by;
//
//	{
//		hMemDC = CreateCompatibleDC(hdc);
//		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBackImage);
//		bx = bitBack.bmWidth;
//		by = biBack.bmHeight;
//
//		BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);
//		TransparentBlt(hdc, 200, 200, bx, by, hMemDC, 0, 0, bx, by, RGB(255, 0, 255));
//
//		SelectObject(hMemDC, hOldBitmap);
//		DeleteDC(hMemDC);
//	}
//}
//
//void DeleteBitmap()
//{
//	DeleteObject(hBackImage);
//}