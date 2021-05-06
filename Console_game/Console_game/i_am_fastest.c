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
static float character_x = 2;
static float character_y = 2;

static float dx = 0, dy = 0;

static FILE* map_file = NULL;
static char* map_memmory = NULL;

static int current_speed = 0;
static int max_speed = 0;
static int time_limit = 0;


// title variables, gameover variables
static int menu__cursor = 0;





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Main Game Logics
//

int GS_IAF()
{
	current_speed = sqrt(((dx * 1000)*(dx * 1000)) + (dy * 1000)*(dy * 1000));
	if (current_speed > max_speed)
		max_speed = current_speed;

	if (b_init_stage)		//called on stage init
		if (Stage_Init())
			return -1;

	Stage_Collision();		//called on every frame
	Stage_Draw();

	if (b_quit_stage)
		if (Stage_Quit())	//called on stage quit
			return -1;

	if (time_limit-- == -1)
		b_quit_stage = 1;

	return 0;
}


int Stage_Init()
{
	int result = 0;

	map_memmory = (char*)malloc(WIDTH*HEIGHT);
	if (map_memmory == NULL)
		result += -1;

	result += MapRead();

	character_x = 2;
	character_y = 2;

	_score = 0;
	current_speed = 0;
	max_speed = 0;
	time_limit = TIME_LIMIT;

	b_init_stage = 0;
	b_quit_stage = 0;
	return result;
}

int Stage_Quit()
{
	free(map_memmory);

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

		bigger *= 10;

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
						dx = -dx / 2;
						unit_d = bigger + 1;	//quit loops
					}
					if (character_y_new != (int)character_y && map_memmory[(int)character_x + WIDTH*(int)character_y_new] == MapTile_Wall)
					{
						dy = -dy / 2;
						unit_d = bigger + 1;	//quit loops
					}
					break;
				
				case MapTile_Breakable:				// Breakable Wall case
					if (character_x_new != (int)character_x && map_memmory[(int)character_x_new + WIDTH * (int)character_y] == MapTile_Breakable)
					{
						dx = -dx / 2;
						map_memmory[character_x_new + WIDTH * character_y_new] = MapTile_Blank;
						unit_d = bigger + 1;	//quit loops
					}
					if (character_y_new != (int)character_y && map_memmory[(int)character_x + WIDTH * (int)character_y_new] == MapTile_Breakable)
					{
						dy = -dy / 2;
						map_memmory[character_x_new + WIDTH * character_y_new] = MapTile_Blank;
						unit_d = bigger + 1;	//quit loops
					}
					break;

				case MapTile_Ice:
					if (GetAsyncKeyState(VK_LEFT) < 0 || GetAsyncKeyState(0x41) < 0) {
						dx -= ECEL_POWER;
					}
					if (GetAsyncKeyState(VK_RIGHT) < 0 || GetAsyncKeyState(0x44) < 0) {
						dx += ECEL_POWER;
					}
					if (GetAsyncKeyState(VK_UP) < 0 || GetAsyncKeyState(0x57) < 0) {
						dy -= ECEL_POWER / 2;
					}
					if (GetAsyncKeyState(VK_DOWN) < 0 || GetAsyncKeyState(0x53) < 0) {
						dy += ECEL_POWER / 2;
					}
					break;

				case MapTile_Lava:
					b_quit_stage = 1;
					break;

				case MapTile_Slime:				// Wall case
					if (character_x_new != (int)character_x && map_memmory[(int)character_x_new + WIDTH * (int)character_y] == MapTile_Wall)
					{
						dx = -dx;
						unit_d = bigger + 1;	//quit loops
					}
					if (character_y_new != (int)character_y && map_memmory[(int)character_x + WIDTH * (int)character_y_new] == MapTile_Wall)
					{
						dy = -dy;
						unit_d = bigger + 1;	//quit loops
					}
					break;

				}
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

			//character visual decoration
			if (x > character_x - 3 && x <= character_x + 2 && y > character_y - 2 && y <= character_y + 1)
				_char_canvas[x + WIDTH * y].Attributes = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		}
	}

	// draw character
	int playerCoord = (int)(character_x)+WIDTH * (int)(character_y);

	if (0 < playerCoord && playerCoord < WIDTH * HEIGHT) {
		_char_canvas[playerCoord].Char.UnicodeChar = '@';
		_char_canvas[playerCoord].Attributes = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
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

	menu__cursor = 100;

	b_init_stage = 0;
	b_quit_stage = 0;
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
			menu__cursor--;
			rest = 10;
		}
		if (GetAsyncKeyState(VK_DOWN) < 0 || GetAsyncKeyState(0x53) < 0) {
			menu__cursor++;
			rest = 10;
		}
		menu__cursor = menu__cursor % MenuButton_TotalMenuButton;
		if (menu__cursor < 0)
			menu__cursor = MenuButton_TotalMenuButton-1;

		if (GetAsyncKeyState(VK_RETURN) < 0 || GetAsyncKeyState(VK_SPACE)) {
			if (menu__cursor == MenuButton_GameStart)
				b_quit_stage = 1;
			if (menu__cursor == MenuButton_GameEnd) {
				_stage = -1;
				b_quit_stage = 1;
			}
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
	arr[31] = 0;

	char arr2[32] = "Exit";
	arr[31] = 0;

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
		if (menu__cursor < MenuButton_TotalMenuButton && menu__cursor >= MenuButton_GameStart)
		{
			_char_canvas[40 + WIDTH * (24 + menu__cursor * 2)].Attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN |BACKGROUND_BLUE;
			_char_canvas[41 + WIDTH * (24 + menu__cursor * 2)].Char.UnicodeChar = '-';
			_char_canvas[41 + WIDTH * (24 + menu__cursor * 2)].Attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
			_char_canvas[42 + WIDTH * (24 + menu__cursor * 2)].Char.UnicodeChar = '>';
			_char_canvas[42 + WIDTH * (24 + menu__cursor * 2)].Attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
			_char_canvas[43 + WIDTH * (24 + menu__cursor * 2)].Attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;

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

	if (b_quit_stage)
		if (GameOver_Quit())	//called on stage quit
			return -1;

	return 0;
}


int GameOver_Init()
{
	int result = 0;

	menu__cursor = 0;

	b_init_stage = 0;
	b_quit_stage = 0;
	return result;
}

int GameOver_Quit()
{
	b_init_stage = 1;
	b_quit_stage = 0;
	_stage -= 2;		//change stage

	return 0;
}

int GameOver_Draw()
{

	return 0;
}