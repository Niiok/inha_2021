#include "windowing.h"



int SetWindowSize(size_t width, size_t height)
{

	HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (output_handle == INVALID_HANDLE_VALUE)
		return 0;

	CheckConsoleBuffer(output_handle);

	printf("pass\n");
	SMALL_RECT rect = {0,};
	rect.Bottom = width;
	rect.Right = height;
	if (SetConsoleWindowInfo(output_handle, FALSE, &rect) == FALSE)
		return 0;

	printf("pass\n");
	COORD coord = {0,};
	coord.X = rect.Bottom + 1;
	coord.Y = rect.Right + 1;

	return (SetConsoleScreenBufferSize(output_handle, coord) != FALSE);
}

int CheckConsoleBuffer(HANDLE buffer_handle)
{
	CONSOLE_SCREEN_BUFFER_INFO cur_screen;
	GetConsoleScreenBufferInfo(buffer_handle, &cur_screen);
	printf("dwSize = %d, %d\n", cur_screen.dwSize.X, cur_screen.dwSize.Y);
	printf("dwCursorPosition = %d, %d\n", cur_screen.dwCursorPosition.X, cur_screen.dwCursorPosition.Y);
	printf("wAttributes = %d\n", cur_screen.wAttributes);
	printf("srWindow = %d, %d, %d, %d\n", cur_screen.srWindow.Right, cur_screen.srWindow.Top, cur_screen.srWindow.Left, cur_screen.srWindow.Bottom);
	printf("dwMaximumWindowSize = %d, %d\n", cur_screen.dwMaximumWindowSize.X, cur_screen.dwMaximumWindowSize.Y);

	return 0;
}

int DoubleBufferSample(void)
{

}