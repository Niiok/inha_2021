#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>

void make99();
void print_n(int n);

void main()
{
	int n;
	make99();

	while (1)
	{
		printf("출력 단 : ");
		scanf("%d", &n);
		getchar();

		print_n(n);
	}
	return;
}


void make99()
{
	FILE *fp = fopen("multipication_table.txt", "w+");
	if (fp == NULL)
		exit(1);

	// 1 - 9단까지 반복
	// n단을 작성하여 파일에 대입
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			fprintf(fp, "%3d x %3d = %3d\n", i, j, i*j);
		}
	}

	fclose(fp);
}

void print_n(int n)
{
	int i = 0, size = 0;
	char str[40], ch = 0;
	FILE *fp = fopen("multipication_table.txt", "r");

	fscanf(fp, "%s", str);
	size = strlen(str);

	/*
	while (ch != '\n')        // 한 줄의 사이즈를 찾는다.
	{
		ch = fgetc(fp);
		size++;                // 개행문자 포함 사이즈
	}
	*/

	fseek(fp, size, SEEK_SET);
	printf("\nsize : %d\n", size);
	while (1)
	{
		fgets(str, sizeof(str), fp);        // 한줄 씩 읽어들인다.
		printf("%s", str);
		if (++i == 9)
			break;
	}


	fclose(fp);
}