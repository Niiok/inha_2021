#include<stdio.h>
#define BALL_NUM 6

int c10hard();
void swap(int* pa, int* pb);
void insert_sort(int* arr, int size);
void input_nums(int *lotto_nums);
void print_nums(int *lotto_nums);
int check_overlap(int*, int, int);

int main()
{
	c10hard();

}


int c10hard()
{
	int lotto_nums[BALL_NUM];
	input_nums(lotto_nums);
	insert_sort(lotto_nums, BALL_NUM);
	print_nums(lotto_nums);

	return 0;
}

void swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void insert_sort(int* arr, int size)
{
	if (size <= 1)
		return;

	for (int i = 0; i < size - 1; i++)
		if (*(arr + i) > *(arr + i + 1))
			swap(arr + i, arr + i + 1);

	insert_sort(arr, size - 1);
}

void input_nums(int *lotto_nums)
{
	int i = 0;
	int num;
	while(i < BALL_NUM)
	{
		printf("번호 입력 : ");
		scanf_s("%d", &num);

		if (check_overlap(lotto_nums, i, num))
		{
			printf("같은 번호가 있습니다!\n");
			continue;
		}

		*(lotto_nums + i) = num;
		i++;
	}
}
void print_nums(int *lotto_nums)
{
	printf("로또 번호 : ");

	for (int i = 0; i < BALL_NUM; i++)
	{
		printf("%d ",*(lotto_nums+i));
	}

}

int check_overlap(int* arr, int size, int num) 
{
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) == num)
		{
			return 1;
		}
	}
	return 0;
}