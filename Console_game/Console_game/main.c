#define MAIN_DECLARE
#include "console_game.h"

/**
 * main function manage main loop
 */
int main(int argc, char* argv[])
{
	HANDLE console_buffer_1, console_buffer_2;
	SMALL_RECT draw_region = { 0, 0, WIDTH_ORIGIN - 1,HEIGHT - 1 };
	COORD console_buffer_area = {WIDTH_ORIGIN, HEIGHT};
	COORD buffer_coord = {0, 0};
	
	Manager_ManagerInit();	// memmory, file manager init

	{
		HANDLE initial = GetStdHandle(STD_OUTPUT_HANDLE);
		if (initial == INVALID_HANDLE_VALUE)
			return 0;
		//SetConsoleScreenBufferSize(initial, console_buffer_area);
		SetConsoleWindowInfo(initial, TRUE, &draw_region);
	}

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



	while (_stage) {		//main loop		//end on Quit

		//input		//can be skiped thx to GetAsyncKeyState()
		//collison	//check whether character can move or not
		//event		//check input or object tick to trigger events
		//draw		//draw things to show on screen.  1. map	2. obejct	3. character

		switch (_stage)
		{
		case GameStage_Title_IAF:
			GS_IAF_Title();
			break;

		case GameStage_IamFastest:
			GS_IAF();
			break;

		case GameStage_GameOver_IAF:
			GS_IAF_GameOver();
			break;

		}


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
			_char_canvas,			// buffer to copy from 
			console_buffer_area,	// col-row size of _char_canvas 
			buffer_coord,			// top left src cell in _char_canvas 
			&draw_region);

		if (!SetConsoleActiveScreenBuffer(back_console_buffer)) {
			printf("failed to change buffer : %d\n", GetLastError());
			return 1;
		}

		Sleep(1000 / _FPS);

		i++;
	}

	Manager_ManagerQuit();		// memmory, file manager quit

	return 0;
}


int DrawStringOnCanvas_Center(int line, char* string, WORD Attributes)
{
	for (int i = 0; i < strlen(string); i++)
	{
		_char_canvas[WIDTH_ORIGIN / 2 - strlen(string) / 2 + i + WIDTH_ORIGIN * line].Char.UnicodeChar = string[i];
		if (Attributes != (WORD)-1)
			_char_canvas[WIDTH_ORIGIN / 2 - strlen(string) / 2 + i + WIDTH_ORIGIN * line].Attributes = Attributes;
	}
}