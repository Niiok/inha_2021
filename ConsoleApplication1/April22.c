#include <stdio.h>
#include<string.h>
#define ARR_LEN 256
#pragma warning( disable : 4996)

int test();
int c12hard();
void insert_sort(char* arr, int size);
int c14p1();
int problem1();
int problem2();
int problem3();
int direction_p3(int num, int x, int y);

int main()
{
	problem3();
}

int test()
{
	int arr[10];

	int* pa = &arr[0];
	int* pb = &arr[4];

	printf("%d", pa - pb);
}

int c12hard()
{
	char arr1[ARR_LEN];
	char arr2[ARR_LEN];
	char arr3[ARR_LEN];
	char* points[3] = { arr1,arr2,arr3 };

	scanf("%s%s%s", arr1, arr2, arr3);

	insert_sort(points, 3);
	 

	for (int i = 0; i < 3; i++)
	{
		printf("%s ", points[i]);
	}
}

void insert_sort(char* arr[], int size)
{
	char temp[ARR_LEN] = {0, };

	if (size <= 1)
		return;

	for (int i = 0; i < size - 1; i++)
		if (strcmp(arr[i], arr[i+1])== 1)
		{
			strcpy(temp, arr[i]);
			strcpy(arr[i], arr[i + 1]);
			strcpy(arr[i + 1], temp);
		}

	insert_sort(arr, size - 1);
}

int c14p1()
{
	char arr[5][5] = { 0 };
	int num = 5;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (i == j || i + j == num - 1)
				arr[i][j] = 'X';
			else
				arr[i][j] = ' ';
		}
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
				printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

int problem1()
{
	int A[2][4] = { {1, 2, 3, 4},{5, 6, 7, 8} };
	int B[4][2] = { 0 };
	int y = 2, x = 4;


	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			B[j][y - i - 1] = A[i][j];
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf(" %d",B[i][j]);
		}
			printf("\n");
		
	}
}

int problem2()
{

	int arr[21][21] = { 0 };
	int num = 21;
	int cell = num * num;
	int direction = 0;
	int cursor_x = 0, cursor_y = 0;

	for (int i = 1; i <= cell; i++)
	{
		arr[cursor_y][cursor_x] = i;

		switch (direction)
		{
		case 0:	//right
			if (cursor_x < num-1 && arr[cursor_y][cursor_x+1] == 0)
				cursor_x++;
			else
			{
				direction = 1;
				cursor_y++;
			}
			break;
		case 1:	//down
			if (cursor_y < num-1 && arr[cursor_y+1][cursor_x] == 0)
				cursor_y++;
			else
			{
				direction = 2;
				cursor_x--;
			}
			break;
		case 2:	//left
			if (cursor_x > 0 && arr[cursor_y][cursor_x -1] == 0)
				cursor_x--;
			else
			{
				direction = 3;
				cursor_y--;
			}
			break;
		case 3:	//up
			if (cursor_y > 0 && arr[cursor_y-1][cursor_x] == 0)
				cursor_y--;
			else
			{
				direction = 0;
				cursor_x++;
			}
			break;
		}
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			printf("%-4d", arr[i][j]);
		printf("\n");
	}

	return 0;
}

int problem3()
{
	int arr[10][10] = { 0, };
	int num = 9;
	int cell = num * num;
	int cursor_x = 0, cursor_y = 0;


	for (int i = 1; i <= cell; i++)
	{
		arr[cursor_y][cursor_x] = i;

		switch (direction_p3(num, cursor_x, cursor_y))
		{
		case 0:
			cursor_x++;
			break;
		case 1:
			cursor_y++;
			cursor_x--;
			break;
		case 2:
			cursor_y++;
			break;
		case 3:
			cursor_y--;
			cursor_x++;
			break;
		}
	}


	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			printf("%-4d", arr[i][j]);
		printf("\n\n");
	}

	return 0;
}



int direction_p3(int num, int x, int y)
{
	/*
	0 : right
	1 : left-down
	2 : down
	3 : right-up
	*/

	if (x + y < num)
	{
		if ((x + y) % 2 == 0)
		{
			if (y == 0)
			{
				if (x + y == num - 1)
					return 2;
				return 0;
			}
			else
				return 3;
		}
		else
		{
			if (x == 0)
			{
				if (x + y == num - 1)
					return 0;
				return 2;
			}
			else
				return 1;
		}
	}
	else
	{
		if ((x + y) % 2 == 0)
		{
			if (x == num - 1)
				return 2;
			else
				return 3;
		}
		else
		{
			if (y == num - 1)
				return 0;
			else
				return 1;
		}
	}
}