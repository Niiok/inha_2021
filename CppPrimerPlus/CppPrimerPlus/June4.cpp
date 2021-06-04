#define _CRT_SECURE_NO_WARNINGS
#include"TnT.h"
#include<iostream>
#include<cassert>

int problem1();
int problem2();
int problem3();
int InsertionSort(int size, int arr[]);
int InsertSortShow(int size, int arr[], int index);


int main()
{
	problem3();
}

int problem1()
{
	char num;
	int count_buf = 0;
	int count = 0;
	int dot_loc = -1;
	int is_fraction = -1;
	char buffer[512];
	char number[512];

	std::cout << "입력 : ";
	scanf("%s", buffer);

	int str_len = strlen(buffer);
	printf("출력 1 : ");

	for (int i = 0; i < str_len; ++i)
	{
		if (buffer[i] == '.')
		{
			dot_loc = i;
			printf(" , 소수점 이하 : ");
		}
		else if(i == 0 && dot_loc == -1)
		{
			dot_loc = strlen(buffer);
		}

		if ((buffer[i] <= '9' && buffer[i] >= '0') ||
			buffer[i] == '-' ||
			buffer[i] == '.')
		{
			if (buffer[i] != '.')
				printf("%c ", buffer[i]);
		}
		else
			assert(0);
	}

	while (buffer[count_buf] != 0)
	{
		num = buffer[count_buf];
		++count_buf;


		/*if (is_fraction >= 0)
		{
			if (is_fraction == 3)
			{
				number[count] = ',';
				is_fraction = 0;
				++count;
			}


			++is_fraction;
		}*/
		

		if ((num >= '0' && num <= '9') ||
			num == '.' ||
			num == '-')
		{
			number[count] = num;

			if (num == '.')
				is_fraction = 0;

			++count;
		}


		if ((dot_loc - count_buf) % 3 == 0 &&
			dot_loc != count_buf &&
			dot_loc > count_buf)
		{
			if(!(number[count-1] == '-'))
				number[count] = ',';
				++count;
		}
	}

	number[count] = 0;

	printf("\n출력 2 : %s", number);
	return 0;
}




int problem2()
{
	int integer;
	int decimal;
	int i = 0;
	long numerator;
	int denominator;
	int deno_temp;

	printf("실수 : ");
	
	scanf("%d", &integer);
	getchar();
	scanf("%d", &decimal);

	for (;;++i)
	{
		if (pow(10, i) - decimal > 0)
			break;
	}
	denominator = pow(10, i);
	
	numerator = integer * denominator + decimal;

	deno_temp = denominator;
	for (int temp = denominator; ; )
	{
		if (temp % 2 == 0)
			temp /= 2;
		else
			break;

		if (numerator % (deno_temp/temp) == 0)
			denominator = temp;
	}
	
	deno_temp = denominator;
	for (int temp = denominator; ; )
	{
		if (temp % 5 == 0)
			temp /= 5;
		else
			break;

		if ((int)numerator % (deno_temp/temp) == 0)
			denominator = temp;
	}

	numerator /= (pow(10, i) / denominator);

	printf("분수 : %d/%d", numerator, denominator);

	return 0;
}




	//if (num < 0)
	//	printf("-");

	//printf("%d.", (int)num);

	//num = abs(num - (int)num);
	//
	//while (num != 0.0)
	//{
	//	if (count == 3)
	//	{
	//		printf(",");
	//		count = 0;
	//	}


	//	num *= 10.0;
	//	printf("%d", (int)num);
	//	num -= (int)num;
	//	++count;
	//}




int problem3()
{
	TestArray<int> test(10);
	test.scale(100);
	StopWatch timer;
	timer.Start();

	InsertionSort(test.size(), test.arr());

	timer.Stop();


	return 0;
}

int InsertionSort(int size, int arr[])
{
	int range_right = size, range_left = -1;
	int cycle_num = 0;
	int compare_num = 0;
	int change_num = 0;
	int min;
	int max;

	for(int i = 1; i < size; ++i)
	{

		++cycle_num;

		printf("\n패스%d\n", cycle_num);

		for (int j = i; j > 0 ; --j)
		{
			++compare_num;
			InsertSortShow(size, arr, j);
			
			if (arr[j] < arr[j-1])
			{
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;

				++change_num;
			}
			else
				break;
		}
	}

	printf("\n\n");
	InsertSortShow(size, arr, -2);
	printf("\n비교를 %d회 했습니다.", compare_num);
	printf("\n교환을 %d회 했습니다.\n", change_num);

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