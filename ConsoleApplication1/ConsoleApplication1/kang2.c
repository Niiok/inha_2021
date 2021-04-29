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
		printf("��� �� : ");
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

	// 1 - 9�ܱ��� �ݺ�
	// n���� �ۼ��Ͽ� ���Ͽ� ����
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
	while (ch != '\n')        // �� ���� ����� ã�´�.
	{
		ch = fgetc(fp);
		size++;                // ���๮�� ���� ������
	}
	*/

	fseek(fp, size, SEEK_SET);
	printf("\nsize : %d\n", size);
	while (1)
	{
		fgets(str, sizeof(str), fp);        // ���� �� �о���δ�.
		printf("%s", str);
		if (++i == 9)
			break;
	}


	fclose(fp);
}