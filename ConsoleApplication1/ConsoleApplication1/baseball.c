#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUMS 3
#define CHANCE 10

int check_overlap(int* arr, int size, int num);
int number_setup(int* arr, int size);
int baseball_game(int* arr, int* tryi, int size, int chance);
int check_score(const int* arr, int* tryi, int size);

int main()
{
	

	while (1)
	{
		int arr[NUMS];
		int tryi[NUMS];
		int score[2];
		int tries = 1;

		number_setup(arr, NUMS);
		baseball_game(arr, tryi, NUMS, CHANCE);

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



int number_setup(int* arr, int size)
{
	srand((unsigned int)time(0));

	for (int i = 0; i < size;)
	{
		int num = (rand() % 9) + 1;	// 1~9

		if (check_overlap(arr, i, num))
			continue;

		arr[i] = num;
		i++;
	}

	return 1;
}



int baseball_game(int* arr, int* tryi, int size, int chance)
{
	int tries = 1;

	for (; tries <= chance; tries++)
	{
		printf("\n\t남은 기회 %d번\n\t숫자 1~9를 %d개 입력하세요 : ", chance - tries, size);
		for (int i = 0; i < size; )
		{
			int num;
			scanf_s("%d", &num, 1);
			if (!(num > 0 && num < 10))
			{
				printf("\n조건을 맞추어 입력해주세요. 처음부터 다시 해주세요.\n\n");
				printf("\n\t남은 기회 %d번\n\t숫자 1~9를 %d개 입력하세요 : ", chance - tries, size);
				i = 0;
				fflush(stdin);
				continue;
			}
			if (check_overlap(tryi, i, num))
			{
				printf("\n중복 입력입니다. 처음부터 다시 해주세요.\n\n");
				printf("\n\t남은 기회 %d번\n\t숫자 1~9를 %d개 입력하세요 : ", chance - tries, size);
				i = 0;
				fflush(stdin);
				continue;
			}
			tryi[i] = num;
			i++;
		}

		printf("\n\tTry %d :   ", tries);
		if (check_score(arr, tryi, size))
		{
			printf("\n\t이겼습니다!\n\t%d번만에 알아내셨군요!\n\n", tries);
			return 1;
		}
	}
	if (tries > size)
	{
		printf("\n\t더이상 기회가 없습니다.\n\n");
		return 0;
	}
}



int check_score(const int* arr, int* tryi, int size)
{
	int strike = 0;
	int ball = 0;

	for (int i = 0; i < NUMS; i++)
		if (arr[i] == tryi[i])
			strike++;

	for (int i = 0; i < NUMS; i++)
		if (check_overlap(arr, NUMS, tryi[i]))
			ball++;

	ball -= strike;

	for (int i = 0; i < NUMS; i++)
		printf("  %d", tryi[i]);


	if (strike == 0 && ball == 0)
		printf("\tout\n\n");
	else if (strike == 3)
	{
		printf("\tWIN!\n\n");
		return  1;
	}
	else
		printf("\t%dS  %dB\n\n", strike, ball);


	return 0;
}