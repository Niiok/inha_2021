#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct Point
{
	int x;
	int y;
} Point;

int input_key(int* map, Point size);
int move_character(int* map, Point size, int command);
void gotoxy(int x, int y);
int show_window(int* map, Point size);
int draw_value(int value);
int set_map(int* map, Point size, Point cursor, int value );
int refresh_window(int* map, Point size, Point cursor);

int main()
{
	Point map_size = {100, 20};

	int* map = calloc(map_size.x * map_size.y, sizeof(int));
	if (map == NULL)
		exit(99);

	int frame = 0;

	show_window(map, map_size);

	while (1)
	{
		printf("frame : %d", frame++);
		if (frame % 100 == 99)
		{
			system("cls");
			show_window(map, map_size);
		}
		input_key(map, map_size);

	}

	free(map);

	return 0;
}



int input_key(int* map, Point size)
{
	int character = 0;
	character = getch();

	switch (character)
	{
	case 224:
		character = getch();
		switch (character)
		{
		case 75:
			//puts("<");
			if (move_character(map, size, character))
				puts("error");
			else
				printf("     ");
			break;
		case 72:
			//puts("^");
			if(move_character(map, size, character))
				puts("error");
			else
				printf("     ");
			break;
		case 80:
			//puts("v");
			if(move_character(map, size, character))
				puts("error");
			else
				printf("     ");
			break;
		case 77:
			//puts(">");
			if(move_character(map, size, character))
				puts("error");
			else
				printf("     ");
			break;
		}
		break;

	default:
		//printf("%d ", character);
		break;
	}
	
	return 0;
}


int move_character(int* map, Point size, int command)
{
	static Point cursor = {0, 0};

	switch (command)
	{
	case 75:
		if (cursor.x > 0)
		{
			set_map(map, size, cursor, 0);
			cursor.x--;
			set_map(map, size, cursor, 1);
		}
		else
			return -1;
		break;
	case 72:
		if (cursor.y > 0)
		{
			set_map(map, size, cursor, 0);
			cursor.y--;
			set_map(map, size, cursor, 1);
		}
		else
			return -1;
		break;
	case 80:
		if (cursor.y < size.y-1)
		{
			set_map(map, size, cursor, 0);
			cursor.y++;
			set_map(map, size, cursor, 1);
		}
		else
			return -1;
		break;
	case 77:
		if (cursor.x < size.x-1)
		{
			set_map(map, size, cursor, 0);
			cursor.x++;
			set_map(map, size, cursor, 1);
		}
		else
			return -1;
		break;
	}
	
	return 0;
}


void gotoxy(int x, int y)
{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}


int show_window(int* map, Point size)
{
	system("cls");

	for (int i = 0; i < size.y; i++)
	{
		for (int j = 0; j < size.x; j++)
		{
			draw_value(*(map + (i*size.x) + j));
		}
			putchar('\n');
	}

	/*
	for (int i = 0; i < x*y; i++)
	{
		printf("%d", *(map + i));
	}
	*/

	return 0;
}


int draw_value(int value)
{
	switch (value)
	{
	case 0:
		putchar(' ');
		break;

	case 1:
		putchar('X');
		break;

	default:
		printf("%d ", value);
		break;
	}

	return 0;
}


int set_map(int* map, Point size, Point cursor, int value)
{
	*(map + (cursor.y*size.x) + cursor.x) = value;
	refresh_window(map, size, cursor);
}


int refresh_window(int* map, Point size, Point cursor)
{
	gotoxy(cursor.x, cursor.y);
	draw_value(*(map + (cursor.y*size.x) + cursor.x));
	gotoxy(0, size.y);

	return 0;
}