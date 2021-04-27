#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int p16_5();
void print_str(char **ps);
int c16p1();
int c16hard();
int prime_check(int num);

int main()
{
	c16hard();

	return 0;
}

int p16_5()
{
	char temp[80];
	char* str[21] = { 0 };
	int i = 0;

	while (i < 20)
	{
		printf("문자열을 입력하시오 : ");
		gets(temp);
		if (strcmp(temp, "end") == 0) break;
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
		i++;
	}
	print_str(str);

	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}


	return 0;
}

void print_str(char **ps)
{
	while (*ps != NULL)
	{
		printf("%s\n", *ps);
		ps++;
	}
}

int c16p1()
{
	int col = 5;
	int row = 4;

	int** matrix = malloc(row * sizeof(int*));	//이중포인터 (행) 할당
	if (matrix == NULL)
		exit(1);

	for (int i = 0; i < row;i++)  //포인터 (열) 할당
	{
		int*  prow = malloc(col * sizeof(int));
		if (prow == NULL)
			exit(1);
		
		*(matrix + i) = prow;

	}

	for (int i = 0; i < row; i++)  //  값 입력
	{
		for (int j = 0; j < col; j++)
		{
		*(*(matrix + i)+j) = i*col+j;
		}
	}

	for (int i = 0; i < row; i++)  // 값 출력
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", *(*(matrix + i) + j));
		}
		printf("\n");
	}

	for (int i = 0; i < row; i++)  // 포인터 free
	{
		free(*(matrix + i));
	}
	free(matrix);  // 이중포인터 free

	return 0;
}

int c16hard()
{
	int num;
	int* arr;
	printf("양수 입력 : ");
	scanf("%d", &num);

	arr = malloc((num-2) * sizeof(int));
	if (arr == NULL)
		exit(1);

	for (int i = 2; i < num; i++)
	{
		if (prime_check(i))
			arr[i - 2] = -1;
		else
			arr[i - 2] = 1;


		if (arr[i - 2] == -1)
			printf("   X ");
		else
			printf("%4d ", arr[i-2]);


		if (i % 5 == 1)
			printf("\n");
	}

	free(arr);

	return 0;
}

int prime_check(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num%i == 0)
			return -1;
	}

	return 0;
}