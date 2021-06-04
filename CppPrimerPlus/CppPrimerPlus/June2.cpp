#include <iostream>
#include <assert.h>
#include"TnT.h"

int problem1();
int problem2();
int CocktailSort(int size, int arr[]);
int BubbleSort(int size, int arr[]);
int SimpleBubbleSort(int size, int arr[]);
int BubbleSortShow(int size, int arr[], int index);

int main()
{
	problem2();
}


int problem1()
{

	return 0;
}

int problem2()
{
	//int arr[] = { 99, 3, 55, 2, 72, 9, 4, 32, 5, 7, 1 };

	TestArray<int> test1(50000);
	TestArray<int> test2 = test1;
	TestArray<int> test3 = test1;
	
	StopWatch timer1;
	StopWatch timer2;
	StopWatch timer3;

	timer1.Start();
	CocktailSort(test1.size(), test1.arr());
	timer1.Stop();


	timer2.Start();
	BubbleSort(test2.size(), test2.arr());
	timer2.Stop();


	timer3.Start();
	SimpleBubbleSort(test3.size(), test3.arr());
	timer3.Stop();


	return 0;
}


int CocktailSort(int size, int arr[])
{
	int done_right = size, done_left = -1;
	int to_left_or_right = -1;		// -1 : left,   1 : right
	//int cycle_num = 0;
	long compare_num = 0;
	long change_num = 0;

	while(done_left+1 < done_right)
	{
		//++cycle_num;

		//printf("\n패스%d\n", cycle_num);
		switch (to_left_or_right)
		{

		case -1:	// to left
		{
			int temp_done = size - 1;//done_left+1;
			for (int i = done_right - 1; i > done_left + 1; --i)
			{
				++compare_num;
				//BubbleSortShow(size, arr, i-1);

				if (arr[i] < arr[i - 1])
				{
					int temp = arr[i];
					arr[i] = arr[i - 1];
					arr[i - 1] = temp;
					temp_done = i - 1;

					++change_num;
				}
			}
			done_left = temp_done;
		}
			break;

		case 1:		// to right
		{
			int temp_done = 0;//done_right-1;
			for (int i = done_left + 1; i < done_right - 1; ++i)
			{
				++compare_num;
				//BubbleSortShow(size, arr, i);

				if (arr[i] > arr[i + 1])
				{
					int temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
					temp_done = i + 1;

					++change_num;
				}
			}
			done_right = temp_done;
		}
			break;


		default:
			assert(0);
			break;
		}

		to_left_or_right *= -1;
	}

	//BubbleSortShow(size, arr, -2);
	printf("\n비교를 %ld회 했습니다.", compare_num);
	printf("\n교환을 %ld회 했습니다.\n", change_num);

	return 0;
}

int BubbleSort(int size, int arr[])
{
	int cycle = size-1;
	//int cycle_num = 0;
	long compare_num = 0;
	long change_num = 0;

	while (cycle > 0)
	{
	int temp_cycle = 0;
		//++cycle_num;

		//printf("\n패스%d\n", cycle_num);
		for (int j = 0; j < cycle; ++j)
		{
			++compare_num;
			//BubbleSortShow(size, arr, j);

			if (arr[j] > arr[j + 1])
			{
				int temp_num = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp_num;

				temp_cycle = j;

				++change_num;
			}
		}

		cycle = temp_cycle;
	}

	//BubbleSortShow(size, arr, -2);
	printf("\n비교를 %ld회 했습니다.", compare_num);
	printf("\n교환을 %ld회 했습니다.\n", change_num);

	return 0;
}

int SimpleBubbleSort(int size, int arr[])
{
	int cycle = size-1;
	//int cycle_num = 0;
	long compare_num = 0;
	long change_num = 0;

	for (;cycle > 0; --cycle)
	{
		//++cycle_num;

		//printf("\n패스%d\n", cycle_num);
		for (int j = 0; j < cycle; ++j)
		{
			++compare_num;
			//BubbleSortShow(size, arr, j);

			if (arr[j] > arr[j + 1])
			{
				int temp_num = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp_num;

				++change_num;
			}
		}
	}

	//BubbleSortShow(size, arr, -2);
	printf("\n비교를 %ld회 했습니다.", compare_num);
	printf("\n교환을 %ld회 했습니다.\n", change_num);

	return 0;
}

int BubbleSortShow(int size, int arr[], int index)
{
		printf("  ");
	for (int i = 0; i < size; ++i)
	{
		printf(" %d ", arr[i]);
		if (i == index)
		{
			if (arr[i] > arr[i + 1])
				printf("+");
			else
				printf("-");
		}
		else
		{
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}