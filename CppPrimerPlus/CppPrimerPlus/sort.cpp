#include"sort.h"
#include <algorithm>

int compare_sorting()
{
	//int arr[] = { 99, 3, 55, 2, 72, 9, 4, 32, 5, 7, 1 };

	TestArray<int> test1(1000000);
	TestArray<int> test2 = test1;
	TestArray<int> test3 = test1;
	TestArray<int> test4 = test1;
	TestArray<int> test5 = test1;
	TestArray<int> test6 = test1;

	TestArray<int> test0 = test1;
	TestArray<int> test01 = test1;

	StopWatch timer1;
	StopWatch timer2;
	StopWatch timer3;
	StopWatch timer4;
	StopWatch timer5;
	StopWatch timer6;
	
	StopWatch timer0;
	StopWatch timer01;

	printf("\n\n\t STL sort() Sorting\n");
	timer0.Start();
	std::sort(test0.arr(), test0.arr() + test0.size());
	timer0.Stop();
	
	printf("\n\n\t C qsort() Sorting\n");
	timer01.Start();
	qsort(test01.arr(), test01.size(), sizeof(int), comparator);
	timer01.Stop();


	
	printf("\n\n\t Simple Bubble Sorting\n");
	timer1.Start();
	SimpleBubbleSort(test1.size(), test1.arr());
	timer1.Stop();

	printf("\n\n\t Bubble Sorting\n");
	timer2.Start();
	BubbleSort(test2.size(), test2.arr());
	timer2.Stop();

	printf("\n\n\t Cocktail Sorting\n");
	timer3.Start();
	CocktailSort(test3.size(), test3.arr());
	timer3.Stop();

	printf("\n\n\t Simple Selection Sorting\n");
	timer4.Start();
	SimpleSelectionSort(test4.size(), test4.arr());
	timer4.Stop();
	
	printf("\n\n\t Min-Max Selection Sorting\n");
	timer5.Start();
	MinMaxSelectionSort(test4.size(), test4.arr());
	timer5.Stop();

	printf("\n\n\t Insertion Sorting\n");
	timer6.Start();
	InsertionSort(test5.size(), test5.arr());
	timer6.Stop();
	


	return 0;
}

int comparator(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}



int SimpleBubbleSort(int size, int arr[])
{
	int cycle = size - 1;
	//int cycle_num = 0;
	long compare_num = 0;
	long change_num = 0;

	for (; cycle > 0; --cycle)
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

int BubbleSort(int size, int arr[])
{
	int cycle = size - 1;
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

int CocktailSort(int size, int arr[])
{
	int done_right = size, done_left = -1;
	int to_left_or_right = -1;		// -1 : left,   1 : right
	//int cycle_num = 0;
	long compare_num = 0;
	long change_num = 0;

	while (done_left + 1 < done_right)
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

int SimpleSelectionSort(int size, int arr[])
{
	int cycle_num = 0;
	int compare_num = 0;
	int change_num = 0;
	int min;


	for (int i = 0; i < size; ++i)
	{
		//++cycle_num;

		//printf("\n패스%d\n", cycle_num);

		min = i;

		for (int j = i; j < size; ++j)
		{
			//SelectSortShow(size, arr, j, min, -2);

			++compare_num;
			if (arr[j] < arr[min])
				min = j;
		}

		++change_num; 
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	} 

	//printf("\n\n");
	//SelectSortShow(size, arr, -2, -2, -2);
	printf("\n비교를 %d회 했습니다.", compare_num);
	printf("\n교환을 %d회 했습니다.\n", change_num);

	return 0;
}

int MinMaxSelectionSort(int size, int arr[])
{
	int done_right = size, done_left = -1;
	int cycle_num = 0;
	int compare_num = 0;
	int change_num = 0;
	int min;
	int max;


	while (done_left + 1 < done_right)
	{
		//++cycle_num;

		//printf("\n패스%d\n", cycle_num);
		min = done_left + 1;
		max = done_right - 1;


		for (int i = done_left + 1; i < done_right - 1; ++i)
		{
			++compare_num;
			++compare_num;
			//SelectSortShow(size, arr, i, min, max);

			if (arr[i] > arr[max])
				max = i;
			if (arr[i] < arr[min])
				min = i;
		}

		int temp = arr[done_right - 1];
		arr[done_right - 1] = arr[max];
		arr[max] = temp;

		++change_num;

		temp = arr[done_left + 1];
		arr[done_left + 1] = arr[min];
		arr[min] = temp;

		++change_num;


		--done_right;
		++done_left;
	}

	//printf("\n\n");
	//SelectSortShow(size, arr, -2, -2, -2);
	printf("\n비교를 %d회 했습니다.", compare_num);
	printf("\n교환을 %d회 했습니다.\n", change_num);

	return 0;
}

int InsertionSort(int size, int arr[])
{
	int cycle_num = 0;
	int compare_num = 0;
	int change_num = 0;


	for (int i = 1; i < size; ++i)
	{

		//++cycle_num;

		//printf("\n패스%d\n", cycle_num);

		for (int j = i; j > 0; --j)
		{
			//InsertSortShow(size, arr, j);

			++compare_num;
			if (arr[j] < arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;

				++change_num;
			}
			else
				break;
		}
	}

	//printf("\n\n");
	//InsertSortShow(size, arr, -2);
	printf("\n비교를 %d회 했습니다.", compare_num);
	printf("\n교환을 %d회 했습니다.\n", change_num);

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

int SelectSortShow(int size, int arr[], int index, int min, int max)
{
	printf("  ");
	for (int i = 0; i < size; ++i)
	{
		if (i == index)
			printf(" *");
		else if (i == max)
			printf(" +");
		else if (i == min)
			printf(" -");
		else
			printf("  ");
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

int InsertSortShow(int size, int arr[], int index)
{
	printf("  ");
	for (int i = 0; i < size; ++i)
	{
		if (i == index)
		{
			if (arr[i] < arr[i - 1])
				printf("+");
			else
				printf("-");
		}
		else
		{
			printf(" ");
		}
		printf(" %d ", arr[i]);
	}
	printf("\n");

	return 0;
}