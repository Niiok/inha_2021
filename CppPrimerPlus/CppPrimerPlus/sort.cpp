#include"sort.h"
#include <algorithm>
#include <vector>

int compare_sorting()
{
	TestArray<int> test1(20000);
	//test1.scale(100);
	TestArray<int> test2 = test1;
	TestArray<int> test3 = test1;
	TestArray<int> test4 = test1;
	TestArray<int> test5 = test1;
	TestArray<int> test6 = test1;
	TestArray<int> test7 = test1;
	TestArray<int> test8 = test1;
	TestArray<int> test9 = test1;
	TestArray<int> test10 = test1;
	TestArray<int> test11 = test1;

	TestArray<int> test00 = test1;
	TestArray<int> test01 = test1;

	StopWatch timer1;
	StopWatch timer2;
	StopWatch timer3;
	StopWatch timer4;
	StopWatch timer5;
	StopWatch timer6;
	StopWatch timer7;
	StopWatch timer8;
	StopWatch timer9;
	StopWatch timer10;
	StopWatch timer11;

	StopWatch timer00;
	StopWatch timer01;


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
	MinMaxSelectionSort(test5.size(), test5.arr());
	timer5.Stop();

	printf("\n\n\t Insertion Sorting\n");
	timer6.Start();
	InsertionSort(test6.size(), test6.arr());
	timer6.Stop();

	printf("\n\n\t Shell Sorting\n");
	timer7.Start();
	ShellSort(test7.size(), test7.arr());
	timer7.Stop();
	
	printf("\n\n\t Quick Sorting\n");
	timer8.Start();
	QuickSort(test8.size(), test8.arr());
	timer8.Stop();

	printf("\n\n\t Merge Sorting\n");
	timer9.Start();
	MergeSort(test9.size(), test9.arr());
	timer9.Stop();
	
	//printf("\n\n\t Heap Sorting\n");
	//timer10.Start();
	//HeapSort_Visual(test10.size(), test10.arr());
	//timer10.Stop();

	printf("\n\n\t Count Sorting\n");
	timer11.Start();
	CountSort(test11.size(), test11.arr());
	timer11.Stop();




	printf("\n\n\t STL sort() Sorting\n");
	timer00.Start();
	std::sort(test00.arr(), test00.arr() + test00.size());
	timer00.Stop();

	printf("\n\n\t C qsort() Sorting\n");
	timer01.Start();
	qsort(test01.arr(), test01.size(), sizeof(int), comparator);
	timer01.Stop();

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

int ShellSort(int size, int arr[])
{
	int cycle_num = 0;
	int compare_num = 0;
	int change_num = 0;
	int jump_offset = size / 2 + 1;

	for (; jump_offset > 0; jump_offset /= 2)
	{
		//++cycle_num;

		//printf("\n패스%d\n", cycle_num);

		for (int i = jump_offset; i < size; ++i)
		{
			for (int j = i; j >= jump_offset; j -= jump_offset)
			{
				//ShellSortShow(size, arr, j - jump_offset, j);

				++compare_num;
				if (arr[j] < arr[j - jump_offset])
				{
					int temp = arr[j];
					arr[j] = arr[j - jump_offset];
					arr[j - jump_offset] = temp;

					++change_num;
				}
				else
					break;
			}
		}
	}


	//printf("\n\n");
	//ShellSortShow(size, arr, -2, -2);
	printf("\n비교를 %d회 했습니다.", compare_num);
	printf("\n교환을 %d회 했습니다.\n", change_num);

	return 0;
}

int QuickSort(int size, int arr[])
{
	static int cycle_num = 0;
	static int compare_num = 0;
	static int change_num = 0;

	int result = 0;
	if (cycle_num == 0)
		result = 1;

	++cycle_num;

	int left, right;
	int pivot_value = arr[0];


	for (left = 1, right = size - 1; left != right; )	// does '<' slower than '!=' ?
	{

		++compare_num;
		if (arr[left] > pivot_value)
		{
			++compare_num;
			if (arr[right] < pivot_value)
			{
				int temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;

				++change_num;

				//--right;
				//++left;
			}
			else
				--right;
		}
		else
			++left;
	}

	if (arr[right] < arr[0])
	{
		++change_num;
		int temp = arr[0];
		arr[0] = arr[right];
		arr[right] = temp;
	}
	else
	{
		++change_num;
		int temp = arr[0];
		arr[0] = arr[left - 1];
		arr[left - 1] = temp;
	}

	if(left-1 > 1)
		QuickSort(left-1, arr);
	if(size - left > 1)
		QuickSort(size - left, &arr[left]);


	if (result == 1)
	{
		//printf("\n\n");
		//QuickSortShow(size, arr, -2, -2, 0);

		printf("\n비교를 %d회 했습니다.", compare_num);
		printf("\n교환을 %d회 했습니다.\n", change_num);

		cycle_num = 0;
		compare_num = 0;
		change_num = 0;
	}

	return 0;
}

int QuickSort_Visual(int size, int arr[], int offset)
{
	static int cycle_num = 0;
	static int compare_num = 0;
	static int change_num = 0;

	int result = 0;
	if (cycle_num == 0)
		result = 1;

	int left, right;
	int pivot_value = arr[0];


	++cycle_num;
	printf("\n패스%d\n", cycle_num);

	for (left = 1, right = size - 1; left != right; )
	{
		QuickSortShow(size, arr, left, right, offset);

		++compare_num;
		if (arr[left] > pivot_value)
		{
			++compare_num;
			if (arr[right] < pivot_value)
			{
				int temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;

				++change_num;

				//--right;
				//++left;
			}
			else
				--right;
		}
		else
			++left;
	}

	if (arr[right] < arr[0])
	{
		++change_num;
		int temp = arr[0];
		arr[0] = arr[right];
		arr[right] = temp;
	}
	else
	{
		++change_num;
		int temp = arr[0];
		arr[0] = arr[left - 1];
		arr[left - 1] = temp;
	}

	printf("\n\n");
	QuickSortShow(size, arr, -2, -2, offset);

	if (left-1 > 1)
		QuickSort_Visual(left-1, arr, offset);
	if (size - left > 1)
		QuickSort_Visual(size - left, &arr[left], offset + left);


	if (result == 1)
	{
	printf("\n\n");
	QuickSortShow(size, arr, -2, -2, offset);

		printf("\n비교를 %d회 했습니다.", compare_num);
		printf("\n교환을 %d회 했습니다.\n", change_num);

		cycle_num = 0;
		compare_num = 0;
		change_num = 0;
	}

	return 0;
}

int MergeSort(int size, int arr[])
{
	static int cycle_num = 0;
	static int compare_num = 0;
	static int change_num = 0;

	if(size > 2)
	{
		int recur = cycle_num;

		int left = 0, right = 0;
		int left_size = (size + 1) / 2;
		int right_size = size / 2;
		int* left_arr = (int*)malloc(left_size * sizeof(int));
		int* right_arr = (int*)malloc(right_size * sizeof(int));
		assert(left_arr);
		assert(right_arr);

		memcpy(left_arr, arr, left_size * sizeof(int));
		memcpy(right_arr, &arr[left_size], right_size * sizeof(int));

		++cycle_num;
		//printf("\n패스%d\n", cycle_num);
		//QuickSortShow(size, arr, -2, -2, offset);


		MergeSort(left_size, left_arr);
		MergeSort(right_size, right_arr);

		for (int i = 0; i < size; ++i)
		{
			if (left < left_size && right < right_size)
			{
				++compare_num;

				if (left_arr[left] < right_arr[right])
				{
					arr[i] = left_arr[left];
					++left;
				}
				else
				{
					arr[i] = right_arr[right];
					++right;
				}

				++change_num;
			}
			else
			{
				if (left < left_size)
				{
					arr[i] = left_arr[left];
					++left;

				}
				else if(right < right_size)
				{
					arr[i] = right_arr[right];
					++right;
				}
				else
					assert(0);

				++change_num;
			}

		}

		/*{
			printf("\n  ");
			for (int i = 0; i < offset; ++i)
				printf("     ");
			printf("%d st/nd/rd/th recursion result \n", recur+1);
			QuickSortShow(size, arr, -2, -2, offset);
		}*/

		if (recur == 0)
		{
			printf("\n비교를 %d회 했습니다.", compare_num);
			printf("\n교환을 %d회 했습니다.\n", change_num);

			cycle_num = 0;
			compare_num = 0;
			change_num = 0;
		}

		free(left_arr);
		free(right_arr);

		return 0;

	}
	else if (size == 1)
		return 0;
	else if (size == 2)
	{
		if (arr[0] > arr[1])
		{
			int temp = arr[0];
			arr[0] = arr[1];
			arr[1] = temp;
		}

		return 0;
	}
}

int MergeSort_Visual(int size, int arr[], int offset)
{
	static int cycle_num = 0;
	static int compare_num = 0;
	static int change_num = 0;


	if(size > 2)
	{
		int recur = cycle_num;


		int left = 0, right = 0;
		int left_size = (size + 1) / 2;
		int right_size = size / 2;
		int* left_arr = (int*)malloc(left_size * sizeof(int));
		int* right_arr = (int*)malloc(right_size * sizeof(int));
		assert(left_arr);
		assert(right_arr);

		memcpy(left_arr, arr, left_size * sizeof(int));
		memcpy(right_arr, &arr[left_size], right_size * sizeof(int));

		++cycle_num;
		printf("\n패스%d\n", cycle_num);
		QuickSortShow(size, arr, -2, -2, offset);


		MergeSort_Visual(left_size, left_arr, offset);
		MergeSort_Visual(right_size, right_arr, offset + left_size);

		for (int i = 0; i < size; ++i)
		{
			if (left < left_size && right < right_size)
			{
				++compare_num;

				if (left_arr[left] < right_arr[right])
				{
					arr[i] = left_arr[left];
					++left;
				}
				else
				{
					arr[i] = right_arr[right];
					++right;
				}

				++change_num;
			}
			else
			{
				if (left < left_size)
				{
					arr[i] = left_arr[left];
					++left;

				}
				else if(right < right_size)
				{
					arr[i] = right_arr[right];
					++right;
				}
				else
					assert(0);

				++change_num;
			}

			
		}


		{
			printf("\n  ");
			for (int i = 0; i < offset; ++i)
				printf("     ");
			printf("%d st/nd/rd/th recursion result \n", recur+1);
			QuickSortShow(size, arr, -2, -2, offset);
		}


		if (recur == 0)
		{
			printf("\n비교를 %d회 했습니다.", compare_num);
			printf("\n교환을 %d회 했습니다.\n", change_num);

			cycle_num = 0;
			compare_num = 0;
			change_num = 0;
		}


		free(left_arr);
		free(right_arr);

		return 0;

	}
	else if (size == 1)
		return 0;
	else if (size == 2)
	{
		if (arr[0] > arr[1])
		{
			int temp = arr[0];
			arr[0] = arr[1];
			arr[1] = temp;
		}

		return 0;
	}
}

int HeapSort_Visual(int size, int arr[])
{
	static int cycle_num = 0;
	static int compare_num = 0;
	static int change_num = 0;

	// initial heap making
	HeapSortShow(size, arr, -1);
	MakeHeap_Check(size, arr, 0, &compare_num, &change_num);
	HeapSortShow(size, arr, -1);


	for (int i = size; i > 1; --i)
	{
		++cycle_num;
		printf("\n패스%d\n", cycle_num);


		for (int j = 0; j * 2 + 1 < i; )
		{
			int child_left = j * 2 + 1;
			int child_right = j * 2 + 2;
			int parent = (j - 1) / 2;
			int child_bigger;

			HeapSortShow(i, arr, j);

			if (child_right == i)
				child_bigger = child_left;
			else
			{
				++compare_num;
				child_bigger = (arr[child_left] > arr[child_right] ? child_left : child_right);
			}


			++compare_num;
			if (arr[child_bigger] > arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[child_bigger];
				arr[child_bigger] = temp;
				++change_num;

				j = child_bigger;
			}
			else
				break;
		}

		int temp = arr[i - 1];
		arr[i - 1] = arr[0];
		arr[0] = temp;
		++change_num;
	}

	HeapSortShow(size, arr, -1);

	printf("\n비교를 %d회 했습니다.", compare_num);
	printf("\n교환을 %d회 했습니다.\n", change_num);

	cycle_num = 0;
	compare_num = 0;
	change_num = 0;


	return 0;
}

int CountSort(int size, int arr[])
{
	std::vector<int> a = { 0 };

	for (int i = 0; i < size; ++i)
	{
		int num = arr[i];

		if (num >= a.size())
			a.resize(num + 1, 0);

		++a[num];
	}


	int index = 0;
	for (int i = 0; i < a.size(); ++i)
		for (int j = a[i]; j > 0; --j)
			arr[index++] = i;

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

int ShellSortShow(int size, int arr[], int index1, int index2)
{
	printf("  ");
	for (int i = 0; i < size; ++i)
	{
		if (i == index1 )
		{
			printf(" <");

			if (arr[index2] < arr[index1])
				printf("+");
			else
				printf(" ");
		}
		else if(i != index2+1)
		{
			printf("   ");
		}

		printf("%d", arr[i]);

		if (i == index2)
		{
			if (arr[index2] < arr[index1])
				printf("+");
			else
				printf(" ");

			printf("> ");
		}
	}
	printf("\n");

	return 0;
}

int QuickSortShow(int size, int arr[], int left, int right, int offset)
{
	printf("  ");

	for (int i = 0; i < offset; ++i)
		printf("     ");

	for (int i = 0; i < size; ++i)
	{
		if (i == left )
		{
			printf(" <");

			if (arr[0] < arr[left])
				printf("+");
			else
				printf(" ");
		}
		else if (i == 0 && left > -1)
		{
			printf("  *");
		}
		else if(i != right+1)
		{
			printf("   ");
		}

		printf("%d", arr[i]);

		if (i == right)
		{
			if (arr[right] < arr[0])
				printf("+");
			else
				printf(" ");

			printf("> ");
		}
	}
	printf("\n");

	return 0;
}

int HeapSortShow(int size, int arr[], int index)
{
	printf("  ");

	if (index >= 0)
		for (int i = 0; i < size; ++i)
		{
			if (i == index)
				printf("* %2d ", arr[i]);
			else if(i == (index-1) / 2)
				printf("p %2d ", arr[i]);
			else if (i == index * 2 + 1)
				printf("c %2d ", arr[i]);
			else if (i == index * 2 + 2)
				printf("c %2d ", arr[i]);
			else
				printf("     ");
		}
	else
		for (int i = 0; i < size; ++i)
		{
			printf("  %2d ", arr[i]);
		}

	printf("|\n");

	return 0;
}

int MakeHeap_Check(int size, int* arr, int index, int* compare_num, int* change_num)
{
	int child_left = index * 2 + 1;
	int child_right = index * 2 + 2;
	int parent = (index - 1) / 2;
	int child_bigger;

	if (child_left >= size)
		return 0;
	else
	{
		MakeHeap_Check(size, arr, child_left, compare_num, change_num);
		MakeHeap_Check(size, arr, child_right, compare_num, change_num);
	}

	if (child_right == size)
		child_bigger = child_left;
	else
	{
		++(*compare_num);
		child_bigger = (arr[child_left] > arr[child_right] ? child_left : child_right);
	}

	++(*compare_num);
	if (arr[child_bigger] > arr[index])
	{
		int temp = arr[index];
		arr[index] = arr[child_bigger];
		arr[child_bigger] = temp;

		++(*change_num);

		MakeHeap_Check(size, arr, child_bigger, compare_num, change_num);
	}

	return 0;
}