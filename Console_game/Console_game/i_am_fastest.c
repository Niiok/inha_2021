#include "i_am_fastest.h"

enum MapTile {		//please write stage txt with this value (%d)
	MapTile_Blank = 0,
	MapTile_Wall = 1,
	MapTile_Breakable = 2,
	MapTile_3,
	MapTile_Lava = 4,
	MapTile_TotalMapTile
};

static int b_init_stage = 1;
static int b_quit_stage = 0;

	static float character_x = WIDTH/2;
	static float character_y = HEIGHT/2;

	static float dx = 0, dy = 0;

	static FILE* map_file = NULL;
	static char* map_memmory = NULL;

int GS_IAF()
{
	int current_speed = sqrt(((dx * 1000)*(dx * 1000)) + (dy * 1000)*(dy * 1000));
	if (current_speed > _score)
		_score = current_speed;

	if (b_init_stage)		//called on stage init
		if (Stage_Init())
			return -1;

	Stage_Collision();		//called on every frame
	Stage_Draw();

	if (b_quit_stage)
		if (Stage_Quit())	//called on stage quit
			return -1;

	return 0;
}

int Stage_Init()
{
	int result = 0;

	map_memmory = (char*)malloc(WIDTH*HEIGHT);
	if (map_memmory == NULL)
		result += -1;

	result += MapRead();

	_score = 0;

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

	if (GetAsyncKeyState(VK_LEFT) < 0) {
		dx -= 0.2f;
	}
	if (GetAsyncKeyState(VK_RIGHT) < 0) {
		dx += 0.2f;
	}
	if (GetAsyncKeyState(VK_UP) < 0) {
		dy -= 0.1f;
	}
	if (GetAsyncKeyState(VK_DOWN) < 0) {
		dy += 0.1f;
	}


	if (character_x + dx >= 1 && character_x + dx <= WIDTH - 1 && character_y + dy >= 1 && character_y + dy <= HEIGHT - 1)	// collision inside map
	{

		int bigger = abs(dx) > abs(dy) ? abs(dx)+1 : abs(dy)+1;

		int unit_d = 0;
		for (int unit_d = 0; unit_d < bigger; unit_d++) 
		{
				float unit_dx = (dx / bigger) * unit_d;
				float unit_dy = (dy / bigger) * unit_d;

			char map_values[4] = { *(map_memmory + ((int)(character_y + unit_dy)) * WIDTH + ((int)(character_x + unit_dx) + 1)),
							*(map_memmory + ((int)(character_y + unit_dy) - 1) * WIDTH + ((int)(character_x + unit_dx))),
							*(map_memmory + ((int)(character_y + unit_dy)) * WIDTH + ((int)(character_x + unit_dx) - 1)),
							*(map_memmory + ((int)(character_y + unit_dy) + 1) * WIDTH + ((int)(character_x + unit_dx))) };

			for (int i = 0; i < 4; i++)
			{
				switch (map_values[i])		//works to do depend on tile
				{
				case MapTile_Wall:
					switch (i)
					{
					case 0:	//right
						if (character_x + unit_dx + (dx / bigger) >= (int)(character_x + unit_dx)+1)
						{
							dx = -dx / 2;
						}
						break;
					case 1:	//up
						if ((int)character_y + unit_dy - (dy / bigger) <= (int)(character_y + unit_dy))
						{
							dy = -dy / 2;
						}
						break;
					case 2:	//left
						if ((int)character_x + unit_dx - (dx / bigger) <= (int)(character_x + unit_dx))
						{
							dx = -dx / 2;
						}
						break;
					case 3:	//down
						if (character_y + unit_dy + (dy / bigger) >= (int)(character_y + unit_dy)+1)
						{
							dy = -dy / 2;
						}
						break;
					}
					break;

				case MapTile_Breakable:
					switch (i)
					{
					case 0:	//right
						if (character_x + dx >= (int)character_x + 1)
						{
							dx = -dx / 2;
							*(map_memmory + ((int)character_y) * WIDTH + ((int)character_x + 1)) = MapTile_Blank;
						}
						break;
					case 1:	//up
						if (character_y + dy <= (int)character_y - 1)
						{
							dy = -dy / 2;
							*(map_memmory + ((int)character_y - 1) * WIDTH + ((int)character_x)) = MapTile_Blank;
						}
						break;
					case 2:	//left
						if (character_x + dx <= (int)character_x - 1)
						{
							dx = -dx / 2;
							*(map_memmory + ((int)character_y) * WIDTH + ((int)character_x - 1)) = MapTile_Blank;
						}
						break;
					case 3:	//down
						if (character_y + dy >= (int)character_y + 1)
						{
							dy = -dy / 2;
							*(map_memmory + ((int)character_y + 1) * WIDTH + ((int)character_x)) = MapTile_Blank;
						}
						break;
					}
					break;

				case MapTile_Lava:
					switch (i)
					{
					case 0:	//right
						if (character_x + dx >= (int)character_x + 1)
							b_quit_stage = 1;
						break;
					case 1:	//up
						if (character_y + dy <= (int)character_y - 1)
							b_quit_stage = 1;
						break;
					case 2:	//left
						if (character_x + dx <= (int)character_x - 1)
							b_quit_stage = 1;
						break;
					case 3:	//down
						if (character_y + dy >= (int)character_y + 1)
							b_quit_stage = 1;
						break;
					}
					break;

				default:
					//do nothing
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

	dx *= 0.99f;
	dy *= 0.99f;


	return 0;
}

int Stage_Draw()
{

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

				case MapTile_Lava:
					_char_canvas[x + WIDTH * y].Char.UnicodeChar = ' ';
					_char_canvas[x + WIDTH * y].Attributes = BACKGROUND_RED;
					break;
				}
			}
			else		//default map without map file
			{
				_char_canvas[x + WIDTH * y].Char.UnicodeChar = ' ';
				_char_canvas[x + WIDTH * y].Attributes = BACKGROUND_INTENSITY;
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
		rewind(stdin);
	}

	fclose(map_file);
	return 0;
}