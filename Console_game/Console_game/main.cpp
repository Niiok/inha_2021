#include "console_game.h"

int _state = 0;		//FSM based on State class to judge what to do on main loop
CHAR_INFO char_canvas[WIDTH * HEIGHT];		//canvas to share abroad states

float character_x = 0;
float character_y = 0;

float dx = 0, dy = 0;

/**
 * main function manage main loop
 */
int main(int argc, char* argv[])
{
	HANDLE console_buffer_1, console_buffer_2, initial;
	SMALL_RECT draw_region = { 0, 0, WIDTH - 1,HEIGHT - 1 };
	COORD console_buffer_area = {WIDTH, HEIGHT};
	COORD buffer_coord = {0, 0};


	initial = GetStdHandle(STD_OUTPUT_HANDLE);
	if (initial == INVALID_HANDLE_VALUE)
		return 0;
	//SetConsoleScreenBufferSize(initial, console_buffer_area);
	SetConsoleWindowInfo(initial, TRUE, &draw_region);

	console_buffer_1 = CreateConsoleScreenBuffer(		// first buffer create
		GENERIC_WRITE,
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	console_buffer_2 = CreateConsoleScreenBuffer(		// second buffer create
		GENERIC_WRITE,
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL); 

	if (console_buffer_1 == INVALID_HANDLE_VALUE ||
		console_buffer_2 == INVALID_HANDLE_VALUE)		// buffer creattion check
	{
		printf("failed to create consol buffers : %d\n", GetLastError());
		return -1;
	}

	SetConsoleTitle((LPCSTR)L"Console Game Prototype");		// window name
	SetConsoleScreenBufferSize(console_buffer_1, console_buffer_area);
	//SetConsoleWindowInfo(console_buffer_1, TRUE, &draw_region);
	SetConsoleScreenBufferSize(console_buffer_2, console_buffer_area);
	//SetConsoleWindowInfo(console_buffer_2, TRUE, &draw_region);






	while (1) {		//main loop

		//input		//can be skiped thx to GetAsyncKeyState()
		//collison	//check whether character can move or not
		//event		//check input or object tick to trigger events
		//draw		//draw things to show on screen.  1. map	2. obejct	3. character


		// update
		///*
		if (GetAsyncKeyState(VK_LEFT) < 0) {
			dx-=1;
		}

		if (GetAsyncKeyState(VK_RIGHT) < 0) {
			dx+=1;
		}

		if (GetAsyncKeyState(VK_UP) < 0) {
			dy-=0.5;
		}

		if (GetAsyncKeyState(VK_DOWN) < 0) {
			dy+=0.5;
		}
		if (character_x >= 0 && character_x <= WIDTH && character_y >= 0 && character_y <= HEIGHT)
		{
			character_x += dx;
			character_y += dy;
		}
		else
		{
			if (character_x < 0 || character_x > WIDTH)
			{
				dx = -dx;
				if (character_x < 0)
					character_x++;
				if (character_x > WIDTH)
					character_x--;
			}

			if (character_y < 0 || character_y > HEIGHT)
			{
				dy = -dy;
				if (character_y < 0)
					character_y++;
				if (character_y > HEIGHT)
					character_y--;
			}

			character_x += dx;
			character_y += dy;

		}
		dx *= 0.99f;
		dy *= 0.99f;


		// clear

		for (int y = 0; y < HEIGHT; ++y)
		{
			for (int x = 0; x < WIDTH; ++x)
			{
				char_canvas[x + WIDTH * y].Char.UnicodeChar = ' ';
				char_canvas[x + WIDTH * y].Attributes = 0;

				if (x > character_x - 3 && x<character_x + 3 && y>character_y - 2 && y < character_y + 2)
					char_canvas[x + WIDTH * y].Attributes = BACKGROUND_GREEN;
			}
		}

		// draw player
		int playerCoord = (int)(character_x)+WIDTH * (int)(character_y);

		if (0 < playerCoord && playerCoord < WIDTH * HEIGHT) {
			char_canvas[playerCoord].Char.UnicodeChar = '@';
			char_canvas[playerCoord].Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE;
		}
		//*/



		// present

		static int i = 0;
		HANDLE back_console_buffer;

		if (i % 2 == 0) {
			back_console_buffer = console_buffer_1;
		}
		else {
			back_console_buffer = console_buffer_2;
		}

		WriteConsoleOutput(
			back_console_buffer,	// screen buffer to write to 
			char_canvas,			// buffer to copy from 
			console_buffer_area,	// col-row size of char_canvas 
			buffer_coord,			// top left src cell in char_canvas 
			&draw_region);

		if (!SetConsoleActiveScreenBuffer(back_console_buffer)) {
			printf("failed to change buffer : %d\n", GetLastError());
			return 1;
		}

		Sleep(1 / 60.0f * 1000.0f);

		i++;
	}

	return 0;
}