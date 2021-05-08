#include "i_am_fastest.h"

enum MapTile {		//please write stage txt with this value (%d)
	MapTile_Blank = 0,
	MapTile_Wall = 1,		// bounce with 1/2 speed
	MapTile_Breakable = 2,	// breakable wall
	MapTile_Ice = 3,		// gain x2 sped
	MapTile_Lava = 4,		// immediate game over
	MapTile_Slime = 5,		// bounce with intact speed
	MapTile_TotalMapTile
};

enum MenuButton {
	MenuButton_GameStart = 0, MenuButton_GoToMenu = 0,
	MenuButton_GameEnd = 1,
	MenuButton_TotalMenuButton
};


// global variables
static int b_init_stage = 1;
static int b_quit_stage = 0;


// game variables
		//character variables
static float character_x = 2;
static float character_y = 2;
static float dx = 0, dy = 0;
		//map variables
static FILE* map_file = NULL;
static char* map_memmory_origin = NULL;
static char* map_memmory = NULL;
		//score variables
static int current_speed = 0;
static int max_speed = 0;
static int time_count = 0;
static int broken_breakable = 0;
		//sound variable
static int beep = 0;


// title variables, gameover variables
static int menu_cursor = 0;





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Main Game Logics
//

int GS_IAF()
{
	current_speed = (dx * 10)*(dx * 10) + (dy * 10)*(dy * 10);
	if (current_speed > max_speed)
		max_speed = current_speed;

	if (b_init_stage)		//called on stage init
		if (Stage_Init())
			return -1;

	Stage_Collision();		//called on every frame
	Stage_Draw();
	//IAF_Beep();
	if (b_quit_stage)
		if (Stage_Quit())	//called on stage quit
			return -1;

	if (++time_count == TIME_LIMIT)
		b_quit_stage = 1;

	return 0;
}


int Stage_Init()
{
	int result = 0;

	map_memmory_origin = (char*)malloc(WIDTH*2*HEIGHT*2);
	if (map_memmory_origin == NULL)
		result += -1;

	memset(map_memmory_origin, MapTile_Wall, WIDTH * 2 * HEIGHT * 2);

	map_memmory = map_memmory_origin + (int)(WIDTH*0.5) + (int)(WIDTH*HEIGHT*0.5);

	result += MapRead();

	character_x = 2;
	character_y = 2;
	dx = 0;
	dy = 0;

	_score = 0;
	current_speed = 0;
	max_speed = 0;
	time_count = 0;
	broken_breakable = 0;

	b_init_stage = 0;
	b_quit_stage = 0;

	PlaySound(TEXT("../data/IAF.wav"),NULL,SND_ASYNC | SND_LOOP);

	return result;
}

int Stage_Quit()
{
	free(map_memmory_origin);

	b_init_stage = 1;
	b_quit_stage = 0;		
	_stage++;		//change stage

	return 0;
}


int Stage_Collision()
{
	// input check

	if (GetAsyncKeyState(VK_LEFT) < 0 || GetAsyncKeyState(0x41) < 0) {
		dx -= ECEL_POWER;
	}
	if (GetAsyncKeyState(VK_RIGHT) < 0 || GetAsyncKeyState(0x44) < 0) {
		dx += ECEL_POWER;
	}
	if (GetAsyncKeyState(VK_UP) < 0 || GetAsyncKeyState(0x57) < 0) {
		dy -= ECEL_POWER/2;
	}
	if (GetAsyncKeyState(VK_DOWN) < 0 || GetAsyncKeyState(0x53) < 0) {
		dy += ECEL_POWER/2;
	}

	if (character_x + dx >= 1 && character_x + dx <= WIDTH - 1 && character_y + dy >= 1 && character_y + dy <= HEIGHT - 1)	// collision inside map
	{
		float bigger;

		{		//choose bigger one
			float dx_sample = dx;
			float dy_sample = dy;
			if (dx < 0)
				dx_sample = -dx;
			if (dy < 0)
				dy_sample = -dy;
			if (dx_sample > dy_sample)
				bigger = dx_sample;
			else
				bigger = dy_sample;
		}
		if (bigger < 1)
			bigger = 1;

		bigger *= ACCURACY;

		for (int unit_d = 1; unit_d <= (int)bigger; unit_d++)
		{
			float unit_dx = (dx / (float)bigger) * unit_d;
			float unit_dy = (dy / (float)bigger) * unit_d;

			int character_x_new = (int)(character_x + unit_dx);
			int character_y_new = (int)(character_y + unit_dy);

			if (character_x_new != (int)character_x || character_y_new != (int)character_y)
			{
				switch (map_memmory[(int)character_x_new + WIDTH * (int)character_y_new])			//works to do depend on tile
				{
				case MapTile_Wall:				// Wall case
					if (character_x_new != (int)character_x && map_memmory[(int)character_x_new + WIDTH*(int)character_y] == MapTile_Wall)
					{
						//character_x = character_x_new;
						dx = -(dx-unit_dx) / 2;
						beep = MapTile_Wall;
						unit_d = bigger + 2;	//quit loops
					}
					if (character_y_new != (int)character_y && map_memmory[(int)character_x + WIDTH*(int)character_y_new] == MapTile_Wall)
					{
						//character_y = character_y_new;
						dy = -(dy-unit_dy) / 2;
						beep = MapTile_Wall;
						unit_d = bigger + 1;	//quit loops
					}
					//if (character_x_new != (int)character_x && map_memmory[(int)character_x_new + WIDTH*(int)character_y] == MapTile_Wall && unit_d != bigger +2)
					//{
					//	character_x = character_x_new;
					//	dx = -(dx-unit_dx) / 2;
					//	beep = MapTile_Wall;
					//	unit_d = bigger + 1;	//quit loops
					//}
					break;
				
				case MapTile_Breakable:				// Breakable Wall case
					if (character_x_new != (int)character_x && map_memmory[(int)character_x_new + WIDTH * (int)character_y] == MapTile_Breakable)
					{
						//character_x = character_x_new;
						dx = -(dx-unit_dx) / 2;
						map_memmory[character_x_new + WIDTH * character_y_new] = MapTile_Blank;
						broken_breakable++;
						beep = MapTile_Breakable;
						unit_d = bigger + 2;	//quit loops
					}
					if (character_y_new != (int)character_y && map_memmory[(int)character_x + WIDTH * (int)character_y_new] == MapTile_Breakable)
					{
						//character_y = character_y_new;
						dy = -(dy-unit_dy) / 2;
						map_memmory[character_x_new + WIDTH * character_y_new] = MapTile_Blank;
						broken_breakable++;
						beep = MapTile_Breakable;
						unit_d = bigger + 1;	//quit loops
					}
					//if (character_x_new != (int)character_x && map_memmory[(int)character_x_new + WIDTH * (int)character_y] == MapTile_Breakable && unit_d != bigger+2)
					//{
					//	character_x = character_x_new;
					//	dx = -(dx - unit_dx) / 2;
					//	map_memmory[character_x_new + WIDTH * character_y_new] = MapTile_Blank;
					//	broken_breakable++;
					//	beep = MapTile_Breakable;
					//	unit_d = bigger + 1;	//quit loops
					//}
					break;

				case MapTile_Ice:
					if (current_speed < 50000)
					{
						/*if (GetAsyncKeyState(VK_LEFT) < 0 || GetAsyncKeyState(0x41) < 0) {
							dx -= ECEL_POWER/4;
						}
						if (GetAsyncKeyState(VK_RIGHT) < 0 || GetAsyncKeyState(0x44) < 0) {
							dx += ECEL_POWER/4;
						}
						if (GetAsyncKeyState(VK_UP) < 0 || GetAsyncKeyState(0x57) < 0) {
							dy -= ECEL_POWER / 8;
						}
						if (GetAsyncKeyState(VK_DOWN) < 0 || GetAsyncKeyState(0x53) < 0) {
							dy += ECEL_POWER / 8;
						}*/
						dx *= 1.0001;
						dy *= 1.0001;
					}
					break;

				case MapTile_Lava:
					beep = MapTile_Lava;
					b_quit_stage = 1;
					break;

				case MapTile_Slime:				// Wall case
					if (character_x_new != (int)character_x && map_memmory[(int)character_x_new + WIDTH * (int)character_y] == MapTile_Slime)
					{
						//character_x = character_x_new;
						dx = -(dx);
						beep = MapTile_Slime;
						unit_d = bigger + 2;	//quit loops
					}
					if (character_y_new != (int)character_y && map_memmory[(int)character_x + WIDTH * (int)character_y_new] == MapTile_Slime)
					{
						//character_y = character_y_new;
						dy = -(dy);
						beep = MapTile_Slime;
						unit_d = bigger + 1;	//quit loops
					}
					//if (character_x_new != (int)character_x && map_memmory[(int)character_x_new + WIDTH * (int)character_y] == MapTile_Slime && unit_d != bigger+2)
					//{
					//	character_x = character_x_new;
					//	dx = -(dx);
					//	beep = MapTile_Slime;
					//	unit_d = bigger + 1;	//quit loops
					//}
			
					break;

				}

				if (map_memmory[(int)character_x_new + WIDTH * (int)character_y_new] == MapTile_Wall ||
					map_memmory[(int)character_x_new + WIDTH * (int)character_y_new] == MapTile_Breakable ||
					map_memmory[(int)character_x_new + WIDTH * (int)character_y_new] == MapTile_Slime
					)
				{
					if (character_x > character_x_new)
						character_x++;
					else if (character_x < character_x_new)
						character_x--;

					if (character_y > character_y_new)
						character_y++;
					else if (character_y < character_y_new)
						character_y--;
				}

				/*if (map_memmory[(int)character_x_new + 1 + WIDTH * (int)character_y_new] == MapTile_Wall ||
					map_memmory[(int)character_x_new + 1 + WIDTH * (int)character_y_new] == MapTile_Breakable ||
					map_memmory[(int)character_x_new + 1 + WIDTH * (int)character_y_new] == MapTile_Slime
					)
					character_x--;
				if (map_memmory[(int)character_x_new - 1 + WIDTH * (int)character_y_new] == MapTile_Wall ||
					map_memmory[(int)character_x_new - 1 + WIDTH * (int)character_y_new] == MapTile_Breakable ||
					map_memmory[(int)character_x_new - 1 + WIDTH * (int)character_y_new] == MapTile_Slime
					)
					character_x++;
				if (map_memmory[(int)character_x_new + WIDTH * (int)(character_y_new + 1)] == MapTile_Wall ||
					map_memmory[(int)character_x_new + WIDTH * (int)(character_y_new + 1)] == MapTile_Breakable ||
					map_memmory[(int)character_x_new + WIDTH * (int)(character_y_new + 1)] == MapTile_Slime
					)
					character_y--;
				if (map_memmory[(int)character_x_new + WIDTH * (int)(character_y_new - 1)] == MapTile_Wall ||
					map_memmory[(int)character_x_new + WIDTH * (int)(character_y_new - 1)] == MapTile_Breakable ||
					map_memmory[(int)character_x_new + WIDTH * (int)(character_y_new - 1)] == MapTile_Slime
					)
					character_y++;*/

			}
		}
	}
	else		//map border collision
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
	}


	character_x += dx;
	character_y += dy;

	dx /= DECEL_POWER;
	dy /= DECEL_POWER;


	return 0;
}


int Stage_Draw()
{
	char arr[32] = "Max Speed : ";
	sprintf(arr+12, "%d", max_speed);
	arr[31] = 0;

	char arr2[32] = "Current Speed : ";
	sprintf(arr2 + 16, "%d", current_speed);
	arr2[31] = 0;

	char arr3[32] = "Time Left : ";
	sprintf(arr3 + 12, "%.1f", (float)(TIME_LIMIT - time_count)/_FPS);
	arr3[31] = 0;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map_file != NULL)		//draw map first
			{
				char map_value = *(map_memmory + y * WIDTH + x);
				switch (map_value)
				{
				case MapTile_Blank:
					_char_canvas[x + WIDTH * y].Char.UnicodeChar = ' ';
					_char_canvas[x + WIDTH * y].Attributes = BACKGROUND_INTENSITY;
					break;

				case MapTile_Wall:
					_char_canvas[x + WIDTH * y].Char.UnicodeChar = ' ';
					_char_canvas[x + WIDTH * y].Attributes = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
					break;

				case MapTile_Breakable:
					_char_canvas[x + WIDTH * y].Char.UnicodeChar = 'X';
					_char_canvas[x + WIDTH * y].Attributes = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
					break;

				case MapTile_Ice:
					_char_canvas[x + WIDTH * y].Char.UnicodeChar = ' ';
					_char_canvas[x + WIDTH * y].Attributes = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
					break;

				case MapTile_Lava:
					_char_canvas[x + WIDTH * y].Char.UnicodeChar = ' ';
					_char_canvas[x + WIDTH * y].Attributes = BACKGROUND_RED;
					break;

				case MapTile_Slime:
					_char_canvas[x + WIDTH * y].Char.UnicodeChar = ' ';
					_char_canvas[x + WIDTH * y].Attributes = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
					break;

				}
			}
			else		//default map without map file
			{
				_char_canvas[x + WIDTH * y].Char.UnicodeChar = ' ';
				_char_canvas[x + WIDTH * y].Attributes = BACKGROUND_INTENSITY;
			}

			//score draw
			if (y == 1 && x == WIDTH / 2 + strlen(arr)/2)
			{
				for (int i = 0; i < strlen(arr); i++)
				{
					_char_canvas[x - strlen(arr) + i + WIDTH * y].Char.UnicodeChar = arr[i];
				}
			}
			if (y == 2 && x == WIDTH / 2 + strlen(arr2) / 2)
			{
				for (int i = 0; i < strlen(arr2); i++)
				{
					_char_canvas[x - strlen(arr2) + i + WIDTH * y].Char.UnicodeChar = arr2[i];
				}
			}
			if (y == 28 && x == WIDTH / 2 + strlen(arr3) / 2)
			{
				for (int i = 0; i < strlen(arr3); i++)
				{
					_char_canvas[x - strlen(arr3) + i + WIDTH * y].Char.UnicodeChar = arr3[i];
				}
			}

			//character visual decoration
			if (x > character_x - 3 && x <= character_x + 2 && y > character_y - 2 && y <= character_y + 1)
				_char_canvas[x + WIDTH * y].Attributes = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
		}
	}

	// draw character
	int playerCoord = (int)(character_x)+WIDTH * (int)(character_y);

	if (0 < playerCoord && playerCoord < WIDTH * HEIGHT) {
		_char_canvas[playerCoord].Char.UnicodeChar = '@';
		_char_canvas[playerCoord].Attributes = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
	}


	return 0;
}


int MapRead()
{
	int character = 0;

	map_file = fopen("../data/IAF_map.txt", "r");
	if (map_file == NULL)
		return 0;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			fscanf(map_file, "%d", &character);
			*(map_memmory + y * WIDTH + x) = character;
		}
	}

	fclose(map_file);
	return 0;
}

int IAF_Beep()
{
	if(beep != 0)
	for (int i = -1; i <= 1; i++)
		for (int j = -2; j <= 2; j++)
			_char_canvas[(int)(character_x + j) + WIDTH * (int)(character_y + i)].Attributes = BACKGROUND_RED | BACKGROUND_INTENSITY;

	switch (beep)
	{
	case MapTile_Wall:
		Beep(current_speed / 2, 200);
		break;

	case MapTile_Breakable:
		Beep(current_speed / 2, 200);
		break;
	case MapTile_Lava:
		Beep(max_speed / 10, 1000);
		break;

	case MapTile_Slime:
		Beep(current_speed, 200);
		break;
	}

	beep = 0;

	return 0;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Title Logics
//

// max speed
// all break
// time attack
// accuracy test
// fast die

int GS_IAF_Title()
{
	if (b_init_stage)		//called on stage init
		if (Title_Init())
			return -1;

	Title_Select();
	Title_Draw();			//called on every frame

	if (b_quit_stage)
		if (Title_Quit())	//called on stage quit
			return -1;

	return 0;
}


int Title_Init()
{
	int result = 0;

	menu_cursor = 100;

	b_init_stage = 0;
	b_quit_stage = 0;

	PlaySound(TEXT("../data/IAF_Title.wav"),NULL,SND_ASYNC);

	return result;
}

int Title_Quit()
{
	b_init_stage = 1;
	b_quit_stage = 0;
	_stage++;		//change stage

	return 0;
}


int Title_Select()
{
	static int rest = 0;
	/*if (GetAsyncKeyState(VK_LEFT) < 0 || GetAsyncKeyState(0x41) < 0) {
		dx -= ECEL_POWER;
	}*/
	/*if (GetAsyncKeyState(VK_RIGHT) < 0 || GetAsyncKeyState(0x44) < 0) {
		dx += ECEL_POWER;
	}*/
	if (rest == 0)
	{

		if (GetAsyncKeyState(VK_UP) < 0 || GetAsyncKeyState(0x57) < 0) {
			menu_cursor--;
			rest = 10;
			menu_cursor = menu_cursor % MenuButton_TotalMenuButton;
			if (menu_cursor < 0)
				menu_cursor = MenuButton_TotalMenuButton-1;
		}
		if (GetAsyncKeyState(VK_DOWN) < 0 || GetAsyncKeyState(0x53) < 0) {
			menu_cursor++;
			rest = 10;
			menu_cursor = menu_cursor % MenuButton_TotalMenuButton;
			if (menu_cursor < 0)
				menu_cursor = MenuButton_TotalMenuButton-1;
		}

		if (GetAsyncKeyState(VK_RETURN) < 0 || GetAsyncKeyState(VK_SPACE)) {
			if (menu_cursor == MenuButton_GameStart)
				b_quit_stage = 1;
			if (menu_cursor == MenuButton_GameEnd) {
				_stage = -1;
				b_quit_stage = 1;
			}
			rest = 10;
		}

		if (_kbhit() && menu_cursor == 100)
		{
			menu_cursor = 0;
			rest = 10;
		}
	}
	rest--;
	if (rest < 0)
		rest = 0;
	return 0;
}

int Title_Draw()
{
	char arr[32] = "Game Start";
	char arr2[32] = "Exit";
	char arr3[32] = "- Press any key -";

	static int frame = 0;
	frame++;

	for (int y = 0; y < 30; y++)
	{
		for (int x = 0; x < 120; x++)
		{
			_char_canvas[x + WIDTH * y].Char.UnicodeChar = title_image[y][x];
			if (y < 12)
				_char_canvas[x + WIDTH * y].Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
			else if(y < 19)
				_char_canvas[x + WIDTH * y].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE;
			else
				_char_canvas[x + WIDTH * y].Attributes = 0;


			if (menu_cursor < MenuButton_TotalMenuButton && menu_cursor >= MenuButton_GameStart)
			{
				if (y == 24 && x == WIDTH / 2 + strlen(arr) / 2)		// Game Start Button
				{
					for (int i = 0; i < strlen(arr); i++)
					{
						_char_canvas[x - strlen(arr) + i + WIDTH * y].Char.UnicodeChar = arr[i];
						_char_canvas[x - strlen(arr) + i + WIDTH * y].Attributes = FOREGROUND_INTENSITY;
					}
				}

				if (y == 26 && x == WIDTH / 2 + strlen(arr2) / 2)		// Exit Button
				{
					for (int i = 0; i < strlen(arr2); i++)
					{
						_char_canvas[x - strlen(arr2) + i + WIDTH * y].Char.UnicodeChar = arr2[i];
						_char_canvas[x - strlen(arr2) + i + WIDTH * y].Attributes = FOREGROUND_INTENSITY;
					}
				}
			}
			else if (menu_cursor == 100)
			{
				if (y == 23 && x == WIDTH / 2 + strlen(arr3) / 2 && frame % 100 >20)
				{
					for (int i = 0; i < strlen(arr3); i++)
					{
						_char_canvas[x - strlen(arr3) + i + WIDTH * y].Char.UnicodeChar = arr3[i];
						_char_canvas[x - strlen(arr3) + i + WIDTH * y].Attributes = FOREGROUND_INTENSITY;
					}
				}
			}

		}
		if (menu_cursor < MenuButton_TotalMenuButton && menu_cursor >= MenuButton_GameStart)
		{
			_char_canvas[40 + WIDTH * (24 + menu_cursor * 2)].Attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN |BACKGROUND_BLUE;
			_char_canvas[41 + WIDTH * (24 + menu_cursor * 2)].Char.UnicodeChar = '-';
			_char_canvas[41 + WIDTH * (24 + menu_cursor * 2)].Attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
			_char_canvas[42 + WIDTH * (24 + menu_cursor * 2)].Char.UnicodeChar = '>';
			_char_canvas[42 + WIDTH * (24 + menu_cursor * 2)].Attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
			_char_canvas[43 + WIDTH * (24 + menu_cursor * 2)].Attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;

		}
	}

	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Game Over Logics
//

int GS_IAF_GameOver()
{
	if (b_init_stage)		//called on stage init
		if (GameOver_Init())
			return -1;

	GameOver_Draw();			//called on every frame
	GameOver_Select();

	if (b_quit_stage)
		if (GameOver_Quit())	//called on stage quit
			return -1;

	return 0;
}


int GameOver_Init()
{
	int result = 0;

	menu_cursor = 100;

	b_init_stage = 0;
	b_quit_stage = 0;
	return result;
}

int GameOver_Quit()
{
	b_init_stage = 1;
	b_quit_stage = 0;
	_stage--;		//change stage
	_stage--;

	return 0;
}

int GameOver_Select()
{
	static int rest = 10;

	if ((GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) && rest <= 0)
	{
		b_quit_stage = 1;
		rest = 10;
	}

	rest--;
}

int GameOver_Draw()
{
	char arr[32] = " Speed Score : ";
	sprintf(arr + 15, "%d ", max_speed);
	arr[31] = 0;
	
	char arr2[32] = " Time Left : ";
	sprintf(arr2 + 13, "%.1f ", (float)(TIME_LIMIT - time_count)/_FPS);
	arr2[31] = 0;
	
	char arr3[32] = " Break Score : ";
	sprintf(arr3 + 15, "%d ", broken_breakable);
	arr3[31] = 0;

	char arr4[32] = " Press Space to go Title ";

	for (int y = 0; y < 30; y++)
	{
		for (int x = 0; x < 120; x++)
		{
			if (menu_cursor == 100)
			{
				//_char_canvas[x + WIDTH * y].Char.UnicodeChar = title_image[y][x];
				//_char_canvas[x + WIDTH * y].Attributes = -_char_canvas[x + WIDTH * y].Attributes;
				_char_canvas[x + WIDTH * y].Attributes ^= BACKGROUND_INTENSITY;
			}

			if (y == 10 && x == WIDTH / 2 + strlen(arr) / 2)		// Speed Score
			{
				for (int i = 0; i < strlen(arr); i++)
				{
					_char_canvas[x - strlen(arr) + i + WIDTH * y].Char.UnicodeChar = arr[i];
					_char_canvas[x - strlen(arr) + i + WIDTH * y].Attributes = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN;
				}
			}

			if (y == 12 && x == WIDTH / 2 + strlen(arr2) / 2)		// Time Left
			{
				for (int i = 0; i < strlen(arr2); i++)
				{
					_char_canvas[x - strlen(arr2) + i + WIDTH * y].Char.UnicodeChar = arr2[i];
					_char_canvas[x - strlen(arr2) + i + WIDTH * y].Attributes = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN;
				}
			}

			if (y == 14 && x == WIDTH / 2 + strlen(arr3) / 2)		// Time Left
			{
				for (int i = 0; i < strlen(arr3); i++)
				{
					_char_canvas[x - strlen(arr3) + i + WIDTH * y].Char.UnicodeChar = arr3[i];
					_char_canvas[x - strlen(arr3) + i + WIDTH * y].Attributes = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN;
				}
			}
			if (y == 20 && x == WIDTH / 2 + strlen(arr4) / 2)		// Time Left
			{
				for (int i = 0; i < strlen(arr4); i++)
				{
					_char_canvas[x - strlen(arr4) + i + WIDTH * y].Char.UnicodeChar = arr4[i];
					_char_canvas[x - strlen(arr4) + i + WIDTH * y].Attributes = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN;
				}
			}
		}
	}
	menu_cursor = 0;

	return 0;
}