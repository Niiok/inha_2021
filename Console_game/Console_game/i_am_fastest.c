#include "i_am_fastest.h"

enum MapTile {		//please write stage txt with this value (%d)
	MapTile_Blank = 0,
	MapTile_Wall = 1,		// bounce with 1/2 speed
	MapTile_Breakable = 2,	// breakable wall
	MapTile_Ice = 3,		// gain x2 speed
	MapTile_Lava = 4,		// immediate game over
	MapTile_Slime = 5,		// bounce with intact speed
	MapTile_TotalMapTile
};

enum MenuButton {
	MenuButton_GameStart = 0,
	MenuButton_GameEnd = 1,
	MenuButton_TotalMenuButton
};


// general variables
		//state_control
static int b_init_stage = 1;
static int b_quit_stage = 0;
		//map variables
static char* map_memmory_origin = NULL;
static char* map_memmory = NULL;
		//score variables
static int current_speed = 0;
static int max_speed = 0;
static int time_count = 0;
static int broken_breakable = 0;
static int b_gameover_speed_score = 1;
static int b_gameover_time_score = 1;
static int b_gameover_break_score = 1;


// game variables
		//character variables
static float character_x = 3;
static float character_y = 2;
static float dx = 0, dy = 0;
		//setting variables
static float ecel_power = (float)ECEL_POWER;
static float decel_power = (float)DECEL_POWER;
static float time_limit = TIME_LIMIT;
static int collision_accuracy = COLLISION_ACCURACY;
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
		//called on stage init

	if (b_init_stage)
		if (Stage_Init())
			return -1;


		//called on every frame

	Stage_Collision();

	current_speed = (int)(  (dx * 10)*(dx * 10) + (dy * 10)*(dy * 10)  );
	if (current_speed > max_speed)
		max_speed = current_speed;

	Stage_Draw();

	//IAF_Beep();

	if (++time_count >= time_limit)
	{
		b_quit_stage = 1;
		time_count = (int)time_limit;
	}


		//called on stage quit

	if (b_quit_stage)
		if (Stage_Quit())
			return -1;

	return 0;
}


int Stage_Init()
{
	int result = 0;	// return value

	_score = 0;

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
	_stage = GameStage_GameOver_IAF;		// transition to game over

	return 0;
}


int Stage_Collision()
{
	// input check

	if (GetAsyncKeyState(VK_LEFT) < 0 || GetAsyncKeyState(0x41) < 0) {
		dx -= ecel_power;
	}
	if (GetAsyncKeyState(VK_RIGHT) < 0 || GetAsyncKeyState(0x44) < 0) {
		dx += ecel_power;
	}
	if (GetAsyncKeyState(VK_UP) < 0 || GetAsyncKeyState(0x57) < 0) {
		dy -= ecel_power/2;
	}
	if (GetAsyncKeyState(VK_DOWN) < 0 || GetAsyncKeyState(0x53) < 0) {
		dy += ecel_power/2;
	}

	if (character_x + dx > WIDTH_ORIGIN * -1/5 && character_x + dx < WIDTH_ORIGIN * 6/5 && character_y + dy > HEIGHT * -1/5 && character_y + dy < HEIGHT * 6/5)	// collision inside map
	{
		int bigger_d;

		{		//choose bigger one
			float dx_sample = dx;
			float dy_sample = dy;
			if (dx < 0)
				dx_sample = -dx;
			if (dy < 0)
				dy_sample = -dy;
			if (dx_sample > dy_sample)
				bigger_d = (int)dx_sample;
			else
				bigger_d = (int)dy_sample;

			bigger_d += 1;
		}

		bigger_d *= collision_accuracy;

		int ice_once = 0;

		for (int unit_d = 1; unit_d <= bigger_d; unit_d++)
		{
			float unit_dx = (dx / bigger_d) * unit_d;
			float unit_dy = (dy / bigger_d) * unit_d;

			float character_x_new = (character_x + unit_dx);
			float character_y_new = (character_y + unit_dy);

			if ((int)character_x_new != (int)character_x || (int)character_y_new != (int)character_y)
			{
				switch (map_memmory[(int)character_x_new + WIDTH_EXTEND * (int)character_y_new])			//works to do depend on tile
				{
				case MapTile_Wall:				// Wall case
				case MapTile_Slime:				// Slime case
				case MapTile_Breakable:			// Breakable Wall case

					if ((int)character_x_new != (int)character_x && map_memmory[(int)character_x_new + WIDTH_EXTEND * (int)character_y] == MapTile_Breakable)
					{						// Breakable X act
						dx = -(dx) / 2;
						map_memmory[(int)character_x_new + WIDTH_EXTEND * (int)character_y] = MapTile_Blank;
						broken_breakable++;
						beep = MapTile_Breakable;
						unit_d = bigger_d+ 2;	//quit loops
					}
					if ((int)character_y_new != (int)character_y && map_memmory[(int)character_x + WIDTH_EXTEND * (int)character_y_new] == MapTile_Breakable)
					{						// Breakable Y act
						dy = -(dy) / 2;
						map_memmory[(int)character_x + WIDTH_EXTEND * (int)character_y_new] = MapTile_Blank;
						broken_breakable++;
						beep = MapTile_Breakable;
						unit_d = bigger_d + 1;	//quit loops
					}

					if ((int)character_x_new != (int)character_x && map_memmory[(int)character_x_new + WIDTH_EXTEND * (int)character_y] == MapTile_Slime)
					{						// Slime X act
						dx = -(dx);
						beep = MapTile_Slime;
						unit_d = bigger_d+ 2;	//quit loops
					}
					if ((int)character_y_new != (int)character_y && map_memmory[(int)character_x + WIDTH_EXTEND * (int)character_y_new] == MapTile_Slime)
					{						// Slime Y act
						dy = -(dy);
						beep = MapTile_Slime;
						unit_d = bigger_d+ 1;	//quit loops
					}
					if ((int)character_x_new != (int)character_x && map_memmory[(int)character_x_new + WIDTH_EXTEND *(int)character_y] == MapTile_Wall)
					{							// Wall X act
						dx = -(dx) / 2;
						beep = MapTile_Wall;
						unit_d = bigger_d + 2;	//quit loops
					}
					if ((int)character_y_new != (int)character_y && map_memmory[(int)character_x + WIDTH_EXTEND *(int)character_y_new] == MapTile_Wall)
					{							// Wall Y act
						dy = -(dy) / 2;
						beep = MapTile_Wall;
						unit_d = bigger_d + 1;	//quit loops
					}


					/*if (map_memmory[(int)character_x_new + WIDTH_EXTEND * (int)character_y_new] == MapTile_Wall ||
						map_memmory[(int)character_x_new + WIDTH_EXTEND * (int)character_y_new] == MapTile_Breakable ||
						map_memmory[(int)character_x_new + WIDTH_EXTEND * (int)character_y_new] == MapTile_Slime
						)*/
					{		// force move
						if (character_x > character_x_new)
							character_x++;
						else if (character_x < character_x_new)
							character_x--;

						if (character_y > character_y_new)
							character_y++;
						else if (character_y < character_y_new)
							character_y--;
					}
			
					break;
				

				case MapTile_Ice:
					if (current_speed < 50000 && ice_once == 0)
					{
						/*if (GetAsyncKeyState(VK_LEFT) < 0 || GetAsyncKeyState(0x41) < 0) {		// deprecated because of over power
							dx -= ecel_power/4;
						}
						if (GetAsynckeystate(VK_RIGHT) < 0 || GetAsyncKeyState(0x44) < 0) {
							dx += ecel_power/4;
						}
						if (GetAsynckeystate(VK_UP) < 0 || GetAsyncKeyState(0x57) < 0) {
							dy -= ecel_power / 8;
						}
						if (GetAsynckeystate(VK_DOWN) < 0 || GetAsyncKeyState(0x53) < 0) {
							dy += ecel_power / 8;
						}*/
						dx *= (float)1.0001;
						dy *= (float)1.0001;
						ice_once = 1;
					}
					break;

				case MapTile_Lava:
					beep = MapTile_Lava;
					b_quit_stage = 1;
					unit_d = bigger_d + 1;	//quit loops
					break;


				}

			}
		}
	}
	else		//map border collision
	{	
		/*if (character_x < 0 || character_x > WIDTH_ORIGIN)
		{
			dx = -dx;
			if (character_x < 0)
				character_x++;
			if (character_x > WIDTH_ORIGIN)
				character_x--;
		}

		if (character_y < 0 || character_y > HEIGHT)
		{
			dy = -dy;
			if (character_y < 0)
				character_y++;
			if (character_y > HEIGHT)
				character_y--;
		}*/
		dx = 0;
		dy = 0;
		character_x = WIDTH_ORIGIN / 2;
		character_y = HEIGHT / 2;
	}


	character_x += dx;
	character_y += dy;

	dx /= decel_power;
	dy /= decel_power;


	return 0;
}


int Stage_Draw()
{
	char arr[32] = " Max Speed : ";
	sprintf(arr + strlen(arr), "%d ", max_speed);
	arr[31] = 0;

	char arr2[32] = " Current Speed : ";
	sprintf(arr2 + strlen(arr2), "%d ", current_speed);
	arr2[31] = 0;

	char arr3[32] = " Time Left : ";
	sprintf(arr3 + strlen(arr3), "%.1f ", (float)(time_limit - time_count)/_FPS);
	arr3[31] = 0;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH_ORIGIN; x++)
		{
			char map_value = *(map_memmory + y * WIDTH_EXTEND + x);
			switch (map_value)
			{
			case MapTile_Blank:
				_char_canvas[x + WIDTH_ORIGIN * y].Char.UnicodeChar = ' ';
				_char_canvas[x + WIDTH_ORIGIN * y].Attributes = BACKGROUND_INTENSITY;
				break;

			case MapTile_Wall:
				_char_canvas[x + WIDTH_ORIGIN * y].Char.UnicodeChar = ' ';
				_char_canvas[x + WIDTH_ORIGIN * y].Attributes = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
				break;

			case MapTile_Breakable:
				_char_canvas[x + WIDTH_ORIGIN * y].Char.UnicodeChar = 'X';
				_char_canvas[x + WIDTH_ORIGIN * y].Attributes = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
				break;

			case MapTile_Ice:
				_char_canvas[x + WIDTH_ORIGIN * y].Char.UnicodeChar = ' ';
				_char_canvas[x + WIDTH_ORIGIN * y].Attributes = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
				break;

			case MapTile_Lava:
				_char_canvas[x + WIDTH_ORIGIN * y].Char.UnicodeChar = ' ';
				_char_canvas[x + WIDTH_ORIGIN * y].Attributes = BACKGROUND_RED;
				break;

			case MapTile_Slime:
				_char_canvas[x + WIDTH_ORIGIN * y].Char.UnicodeChar = ' ';
				_char_canvas[x + WIDTH_ORIGIN * y].Attributes = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
				break;
			}

			//character visual highlight
			if (x > character_x - 3 && x <= character_x + 2 && y > character_y - 2 && y <= character_y + 1)
				_char_canvas[x + WIDTH_ORIGIN * y].Attributes ^= BACKGROUND_INTENSITY;
		}
	}

	//score draw
	DrawStringOnCanvas_Center(1, arr, -1);
	DrawStringOnCanvas_Center(2, arr2, -1);		
	DrawStringOnCanvas_Center(28, arr3, -1);


	// draw character
	{
		int character_xy = (int)(character_x)+WIDTH_ORIGIN * (int)(character_y);

		if (0 < character_xy && character_xy < WIDTH_ORIGIN * HEIGHT) {
			_char_canvas[character_xy].Char.UnicodeChar = '@';
			_char_canvas[character_xy].Attributes |= FOREGROUND_RED;
		}
	}

	return 0;
}


int IAF_Beep()
{
	if(beep != 0)
	for (int i = -1; i <= 1; i++)
		for (int j = -2; j <= 2; j++)
			_char_canvas[(int)(character_x + j) + WIDTH_ORIGIN * (int)(character_y + i)].Attributes = BACKGROUND_RED | BACKGROUND_INTENSITY;

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

	///////////////////////////////////////// reset values into default

	character_x = 3;
	character_y = 2;
	dx = 0, dy = 0;

	ecel_power = (float)ECEL_POWER;
	decel_power = (float)DECEL_POWER;
	time_limit = (float)TIME_LIMIT;
	collision_accuracy = COLLISION_ACCURACY;

	map_memmory_origin = NULL;
	map_memmory = NULL;

	current_speed = 0;
	max_speed = 0;
	time_count = 0;
	broken_breakable = 0;

	b_gameover_speed_score = 1;
	b_gameover_time_score = 1;
	b_gameover_break_score = 1;

	beep = 0;

	//////////////////////////////////////////////// map memmory call

	map_memmory_origin = (char*)malloc(WIDTH_ORIGIN * 2 * HEIGHT * 2);
	if (map_memmory_origin == NULL)
		result += -1;

	memset(map_memmory_origin, MapTile_Wall, WIDTH_ORIGIN * 2 * HEIGHT * 2);

	map_memmory = map_memmory_origin + (int)(WIDTH_ORIGIN / 2) + (int)(WIDTH_EXTEND*HEIGHT / 2);

	///////////////////////////////////////////////// map read

	result += MapRead(NULL);		// IMPORTANT : read rules, properties, map data.


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
	if(_stage == GameStage_Title_IAF)
	_stage = GameStage_IamFastest;		// transition to game play

	return 0;
}


int Title_Select()
{
	static int key_rest = 0;
	char map_path[256] = {0};
	
	if (key_rest == 0)
	{
		switch (menu_cursor)
		{
		case MenuButton_GameStart: case MenuButton_GameEnd:
		{
			if (GetAsyncKeyState(VK_UP) < 0 || GetAsyncKeyState(0x57) < 0) {
				menu_cursor--;
				key_rest = _FPS / 10;
				menu_cursor = menu_cursor % MenuButton_TotalMenuButton;
				if (menu_cursor < 0)
					menu_cursor = MenuButton_TotalMenuButton - 1;
			}
			if (GetAsyncKeyState(VK_DOWN) < 0 || GetAsyncKeyState(0x53) < 0) {
				menu_cursor++;
				key_rest = _FPS / 10;
				menu_cursor = menu_cursor % MenuButton_TotalMenuButton;
				if (menu_cursor < 0)
					menu_cursor = MenuButton_TotalMenuButton - 1;
			}

			if (GetAsyncKeyState(VK_RETURN) < 0 || GetAsyncKeyState(VK_SPACE)) {
				if (menu_cursor == MenuButton_GameStart)
					b_quit_stage = 1;
				if (menu_cursor == MenuButton_GameEnd) {
					_stage = GameStage_Quit;
					b_quit_stage = 1;
				}
				key_rest = _FPS / 10;
			}
		}break;

		case 100:
		{
			if (_kbhit())
			{
				menu_cursor = 0;
				key_rest = _FPS / 10;
			}
		} break;

		}
	}
	key_rest--;
	if (key_rest < 0)
		key_rest = 0;
	return 0;
}

int Title_Draw()
{
	char arr[32] = "Game Start";
	char arr2[32] = "Exit";
	char arr3[32] = "- Press any key -";

	static int frame = 0;
	frame++;

	for (int y = 0; y < HEIGHT; y++)		// TItle Screen
	{
		for (int x = 0; x < WIDTH_ORIGIN; x++)
		{
			_char_canvas[x + WIDTH_ORIGIN * y].Char.UnicodeChar = title_image[y][x];
			if (y >= 4 && y <= 10)
				_char_canvas[x + WIDTH_ORIGIN * y].Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
			else if (y >= 14 && y <= 16)
				_char_canvas[x + WIDTH_ORIGIN * y].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE;
			else
				_char_canvas[x + WIDTH_ORIGIN * y].Attributes = 0;

		}
	}

	switch (menu_cursor)		// Buttons
	{
	case MenuButton_GameStart:
	case MenuButton_GameEnd:
	{
		DrawStringOnCanvas_Center(24, arr, FOREGROUND_INTENSITY);
		DrawStringOnCanvas_Center(26, arr2, FOREGROUND_INTENSITY);
	} break;

	case 50:
	{

	} break;

	case 100:
	{
		if (frame % 100 > 20)
		{
			DrawStringOnCanvas_Center(23, arr3, FOREGROUND_INTENSITY);
		}
	} break;

	}
	if (menu_cursor < MenuButton_TotalMenuButton && menu_cursor >= MenuButton_GameStart)
	{
		_char_canvas[40 + WIDTH_ORIGIN * (24 + menu_cursor * 2)].Attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
		_char_canvas[41 + WIDTH_ORIGIN * (24 + menu_cursor * 2)].Char.UnicodeChar = '=';
		_char_canvas[41 + WIDTH_ORIGIN * (24 + menu_cursor * 2)].Attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
		_char_canvas[42 + WIDTH_ORIGIN * (24 + menu_cursor * 2)].Char.UnicodeChar = '>';
		_char_canvas[42 + WIDTH_ORIGIN * (24 + menu_cursor * 2)].Attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
		_char_canvas[43 + WIDTH_ORIGIN * (24 + menu_cursor * 2)].Attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;

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
	_stage = GameStage_Title_IAF;		// transition to title

	return 0;
}

int GameOver_Select()
{
	static int key_rest = 30;

	if ((GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) && key_rest <= 0)
	{
		b_quit_stage = 1;
		key_rest = _FPS/10;
	}

	key_rest--;
}

int GameOver_Draw()
{
	char arr[32] = " Speed Score : ";
	sprintf(arr + strlen(arr), "%d ", max_speed);
	arr[31] = 0;
	
	char arr2[32] = " Time Left : ";
	sprintf(arr2 + strlen(arr2), "%.1f ", (float)(time_limit - time_count)/_FPS);
	arr2[31] = 0;
	
	char arr3[32] = " Break Score : ";
	sprintf(arr3 + strlen(arr3), "%d ", broken_breakable);
	arr3[31] = 0;

	char arr4[32] = " Press Space to go Title ";

	int result_align = 10;
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH_ORIGIN; x++)
		{
			if (menu_cursor == 100)
			{
				//_char_canvas[x + WIDTH_ORIGIN * y].Char.UnicodeChar = title_image[y][x];
				//_char_canvas[x + WIDTH_ORIGIN * y].Attributes = -_char_canvas[x + WIDTH_ORIGIN * y].Attributes;
				_char_canvas[x + WIDTH_ORIGIN * y].Attributes ^= BACKGROUND_INTENSITY;
			}
		}
	}

	DrawStringOnCanvas_Center(20, arr4, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);		// Prompt

	if (b_gameover_speed_score)								// Speed Score
	{
		DrawStringOnCanvas_Center(result_align, arr, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		b_gameover_speed_score = 0;
		result_align += 2;
	}
	if (b_gameover_time_score)								// Time Score
	{
		DrawStringOnCanvas_Center(result_align, arr2, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		b_gameover_time_score = 0;
		result_align += 2;
	}
	if (b_gameover_break_score)								// Break Score
	{
		DrawStringOnCanvas_Center(result_align, arr3, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		b_gameover_break_score = 0;
		result_align += 2;
	}

	menu_cursor = 0;

	return 0;
}



int MapRead(const char* map_path)
{
	FILE* map_file = NULL;
	int character = 0;

	if (map_path == NULL)		// default map
	{
		map_file = fopen("../data/IAF_map.txt", "r");
		if (map_file == NULL)		// error map
		{
			for (int y = 0; y < HEIGHT; y++)
				for (int x = 0; x < WIDTH_ORIGIN; x++)
					*(map_memmory + y * WIDTH_EXTEND + x) = 0;

			return -3;
		}
	}
	else		// custom map
	{
		map_file = fopen(map_path, "r");
		if (map_file == NULL)		// error map
		{
			for (int y = 0; y < HEIGHT; y++)
				for (int x = 0; x < WIDTH_ORIGIN; x++)
					*(map_memmory + y * WIDTH_EXTEND + x) = 0;

			return -1;
		}
	}

	/////////////////////////////////////////////////// rule tag parse
	for (char arr[64] = { 1 }; !(arr[0] == 'm' || arr[0] == 'M'); )		// simple rule parser
	{
		fscanf(map_file, "%s", arr);

		switch (arr[0])
		{
		case 'c': case 'C':
			fscanf(map_file, "%d", &collision_accuracy);
			if (collision_accuracy < 1)
				collision_accuracy = 1;
			break;
		case 'd': case 'D':
			fscanf(map_file, "%f", &decel_power);
			decel_power /= 100000;
			decel_power += 1;
			break;
		case 'e': case 'E':
			fscanf(map_file, "%f", &ecel_power);
			ecel_power /= 1000;
			break;
		case 't': case 'T':
			fscanf(map_file, "%f", &time_limit);
			time_limit *= _FPS;
			break;

		case 'r': case 'R':
		{
			int count = 0;
			fscanf(map_file, "%d", &count);
			for (; count > 0; count--)
			{
				fscanf(map_file, "%s", arr);
				switch (arr[0])
				{
				case 's': case 'S':
					fscanf(map_file, "%s", arr);
					if (arr[0] == '0' || arr[0] == 'f' || arr[0] == 'F')
						b_gameover_speed_score = 0;
					else if (arr[0] == '1' || arr[0] == 't' || arr[0] == 'T')
						b_gameover_speed_score = 1;
					break;
					
				case 't': case 'T':
					fscanf(map_file, "%s", arr);
					if (arr[0] == '0' || arr[0] == 'f' || arr[0] == 'F')
						b_gameover_time_score = 0;
					else if (arr[0] == '1' || arr[0] == 't' || arr[0] == 'T')
						b_gameover_time_score = 1;
					break;

				case 'b': case 'B':
					fscanf(map_file, "%s", arr);
					if (arr[0] == '0' || arr[0] == 'f' || arr[0] == 'F')
						b_gameover_break_score = 0;
					else if (arr[0] == '1' || arr[0] == 't' || arr[0] == 'T')
						b_gameover_break_score = 1;
					break;

				default:
					MapReadError(arr[0]);
					break;
				}
			}
			break; 
		}

		case 'm': case 'M':
			break;

		default:
			MapReadError(arr[0]);
			break;
		}
	}

	/////////////////////////////////////////////////////  map tile read
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH_ORIGIN; x++)
		{
			fscanf(map_file, "%d", &character);
			*(map_memmory + y * WIDTH_EXTEND + x) = (char)character;
		}
	}

	fclose(map_file);
	return 0;
}

int MapReadError(char i)
{
	exit(i);
	return 0;
}
