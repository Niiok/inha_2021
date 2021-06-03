#include <iostream>
#include<cassert>
#include <queue>
#include"TnT.h"

//	bit_struct friend_bitfield {
//		bit b_is_following;			// 4<<29
//		bit b_is_checked;			// 2<<29
//		biy b_is_knowing;			// 1<<29
//	};
//
//		=> int can contain 10 user data


int problem1();
int* solution_KevinBacon(int max_user, int* sns_bitfield[], int edge_degree = 1);
int sns_bitfield_writer(int max_user, int* sns_bitfield[]);
int sns_bitfield_reader(int max_user, int* sns_bitfield[]);
int problem2();
int SelectionSort(int size, int arr[]);
int SelectSortShow(int size, int arr[], int index, int min, int max);

int main()
{
	problem2();
}

int problem1()
{
	int num;
	printf("Input Number of Peoples : ");
	std::cin >> num;

	int** relation = (int**)malloc(num * sizeof(int*));
	assert(relation);

	for (int i = 0; i < num; ++i)
	{
		relation[i] = (int*)calloc((num / 10 + 1), sizeof(int));
		assert(relation[i]);
	}

	sns_bitfield_writer(num, relation);

	int* numbers = solution_KevinBacon(num, relation, 1);

	sns_bitfield_reader(num, relation);



	for (int i = 0; i < num; ++i)
	{
		free(relation[i]);
	}
	free(relation);

	return 0;
}

int* solution_KevinBacon(int max_user, int* sns_bitfield[], int edge_degree)
{
	static int number_of_friends[512] = { 0 };

	std::queue<int> que[2];


	for (int user = 0; user < max_user; ++user)		// per user loop
	{
		for (int degree = edge_degree; degree < 0; --degree)		// for edge loop
		{
			int current_que = degree % 2;
			int next_que = (degree + 1) % 2;

			if (degree == edge_degree)
			{
				for (int id = 0; id < max_user; ++id)		// initial queue filling loop
				{
					if ((sns_bitfield[user][id / 10]) & (4 << (29 - (id % 10) * 3)))
						que[current_que].push(id);
				}
			}

			while (!que[current_que].empty())
			{
				int id = que[current_que].front();
				que[current_que].pop();

				if ((sns_bitfield[user][id / 10]) & (2 << (29 - (id % 10) * 3)))
				{
					// already searched
				}
				else
				{
					for (int _id = 0; _id < max_user; ++_id)
					{
						if ((sns_bitfield[id][_id / 10]) & (4 << (29 - (_id % 10) * 3)))
							que[next_que].push(_id);
					}

					sns_bitfield[user][id / 10] += (2 << (29 - (id % 10) * 3));
					sns_bitfield[user][id / 10] += (1 << (29 - (id % 10) * 3));

					++number_of_friends[user];
				}
			}
		}
		while (!que[0].empty())
			que[0].pop();
		while (!que[1].empty())
			que[1].pop();
	}

	return number_of_friends;
}



int sns_bitfield_writer(int max_user, int* sns_bitfield[])
{
	int num;
	for (int user = 0; user < max_user; ++user)
	{
		int num, num2;
		printf("Number of friends #%d Person has : \n", user + 1);
		std::cin >> num;
		for (int i = 0; i < num; ++i)
		{
			printf("%dst/nd/rd/th friend is : ", i + 1);
			std::cin >> num2;
			if (num2 > max_user || num2 < 1)
				exit(0);
			sns_bitfield[user][num2 - 1 / 10] += (4 << (29 - (num2 - 1 % 10) * 3));
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}


int sns_bitfield_reader(int max_user, int* sns_bitfield[])
{
	printf("[DIRECT FRIEND LIST]\n");
	for (int user = 0; user < max_user; ++user)
	{
		printf("Person #%d has ", user + 1);
		for (int id = 0; id < max_user; ++id)
		{
			if ((sns_bitfield[user][id / 10]) & (4 << (29 - (id % 10) * 3)))
				printf("%d ", id);
		}
		printf("as a friend\n");
	}

	printf("\n===============================================\n\n");

	printf("[DIRECT FRIEND LIST]\n");
	for (int user = 0; user < max_user; ++user)
	{
		printf("Person #%d has ", user + 1);
		for (int id = 0; id < max_user; ++id)
		{
			if ((sns_bitfield[user][id / 10]) & (1 << (29 - (id % 10) * 3)))
				printf("%d ", id);
		}
		printf("as a friend\n");
	}

	return 0;
}




int problem2()
{
	//int arr[] = { 99, 3, 55, 2, 72, 9, 4, 32, 5, 7, 1 };

	TestArray<int> test(10);
	test.scale(100);
	StopWatch timer;
	timer.Start();

	SelectionSort(test.size(), test.arr());

	timer.Stop();

	return 0;
}


int SelectionSort(int size, int arr[])
{
	int done_right = size, done_left = -1;
	int cycle_num = 0;
	int compare_num = 0;
	int change_num = 0;
	int min;
	int max;


	while (done_left + 1 < done_right)
	{
		++cycle_num;

		printf("\n패스%d\n", cycle_num);
		min = done_left + 1;
		max = done_right - 1;


		for (int i = done_left + 1; i < done_right - 1; ++i)
		{
			++compare_num;
			++compare_num;
			SelectSortShow(size, arr, i, min, max);

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

	printf("\n\n");
	SelectSortShow(size, arr, -2, -2, -2);
	printf("\n비교를 %d회 했습니다.", compare_num);
	printf("\n교환을 %d회 했습니다.\n", change_num);

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