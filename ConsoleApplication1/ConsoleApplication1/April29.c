#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ex18_2();
int ex18_6();
int ex18_7();
int ex18_8();
int c18_hard();
int check_overlap(char* arr, char* arr_b, int word_length, int word_num);
int problem1();
int problem2();

int main()
{
	problem2();
}

int ex18_2()
{
	FILE* fp;
	int ch;

	fp = fopen("../a.txt", "r");
	if (fp == NULL)
	{
		printf("fail\n");
		return 1;
	}

	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF)
		{
			break;
		}
		putchar(ch);
	}
	fclose(fp);

	return 0;
}

int ex18_6()
{
	FILE* fp;
	int ary[10] = { 13, 10, 13, 13, 10, 26, 13, 10, 13, 10 };
	int i, res;

	fp = fopen("a.txt", "wb");
	for (i = 0; i < 10; i++)
	{
		fputc(ary[i], fp);
	}
	fclose(fp);

	fp = fopen("a.txt", "rt");
	while (1)
	{
		res = fgetc(fp);
		if (res == EOF) break;
		printf("%4d", res);
	}
	fclose(fp);


	return 0;
}

int ex18_7()
{
	FILE* fp;
	char str[20];

	fp = fopen("a.txt", "a+");
	if (fp == NULL)
	{
		printf("fail\n");
		return 1;
	}

	while (1)
	{
		printf("fruit name : ");
		scanf("%s", str);
		if (strcmp(str, "end") == 0)
		{
			break;
		}
		else if ((strcmp(str, "list")) == 0)
		{
			fseek(fp, 0, SEEK_SET);
			while (1)
			{
				fgets(str, sizeof(str), fp);
				if (feof(fp))
				{
					break;
				}
				printf("%s", str);
			}
		}
		else
		{
			fprintf(fp, "%s\n", str);
		}
	}
	fclose(fp);

	return 0;
}

int ex18_8()
{
	FILE *ifp, *ofp;
	char str[80];
	char *res;

	ifp = fopen("a.txt", "r");
	if (ifp == NULL)
	{
		printf("fail\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");
	if (ofp == NULL)
	{
		printf("fail\n");
		return 1;
	}

	while (1)
	{
		res = fgets(str, sizeof(str), ifp);
		if (res == NULL)
		{
			break;
		}
		str[strlen(str) - 1] = '\0';
		fputs(str, ofp);
		fputs(" ", ofp);
	}

	fclose(ifp);
	fclose(ofp);

	return 0;
}

int c18_hard()
{
	int word_length = 20;
	int word_num = 10;

	char* a_mem = malloc(word_length * word_num);
	if (a_mem == NULL)
		exit(1);
	char* b_mem = malloc(word_length * word_num);
	if (b_mem == NULL)
		exit(1);
	FILE* fp_a = fopen("../data/a.txt", "r");
	if (fp_a == NULL)
		exit(1);
	FILE* fp_b = fopen("../data/b.txt", "r");
	if (fp_b == NULL)
		exit(1);
	FILE* fp_c = fopen("../data/c.txt", "w");
	if (fp_b == NULL)
		exit(1);

	for (int i = 0, check = 1;; i++)
	{
		check = fscanf(fp_a, "%s", a_mem + i * word_length);
		if (check == EOF)
		{
			*(a_mem + i * word_length) = 0;
			break;
		}
	}
	for (int i = 0, check = 1;; i++)
	{
		check = fscanf(fp_b, "%s", b_mem + i * word_length);
		if (check == EOF)
		{
			*(b_mem + i * word_length) = 0;
			break;
		}
	}

	for (int i = 0; i < word_num && (*(b_mem + i * word_length) != 0); i++)
	{
		if (!check_overlap(b_mem + i * word_length, a_mem, word_length, word_num)) {
			fprintf(fp_c, "%s\n", b_mem + i * word_length);
		}
	}


	fclose(fp_a);
	fclose(fp_b);
	fclose(fp_c);
	free(a_mem);
	free(b_mem);

	return 0;
}

int check_overlap(char* arr, char* strings, int word_length, int word_num)
{
	for (int i = 0; i < word_num; i++)
	{
		if (!strncmp(arr, strings + word_length * i, strlen(arr)))
		{
			return 1;
		}
	}
	return 0;
}

int problem1()
{
	const int GOOGOO = 9;
	int select = 0;

	FILE* fp = fopen("../data/99.txt", "w+");
	if (fp == NULL)
		exit(1);

	for (int i = 2; i <= GOOGOO; i++)
	{
		for (int j = 1; j <= GOOGOO; j++)
		{
			fprintf(fp, "\t%2d x %2d = %3d\n", i, j, i*j);
		}
	}

	printf("출력을 원하는 구구단은 ?  ");
	scanf("%d", &select);
	
	rewind(fp);
	for (int i = 2;;i++)
	{
		if (i == select)
		{
			printf("\t=========\n");
			for (int j = 0; j < GOOGOO; j++)
			{
				fgets(stdin, 99, fp);
				printf("%s", stdin);
			}
			printf("\t=========\n");
			break;
		}
		else
		{
			for (int j = 0; j < GOOGOO; j++)
			{
				fgets(stdin, 99, fp);
			}
			rewind(stdin);
		}
	}

	fclose(fp);
}

int problem2()
{
	int buffer;
	char byte;
	long source_size = 0;
	long start = 0;
	

	FILE* fp_source = fopen("../data/source.gif", "rb");
	if (fp_source == NULL)
		exit(1);
	FILE* fp_destination = fopen("../data/destination.gif", "wb");
	if (fp_destination == NULL)
		exit(1);

	{
		long end = 0;
		fseek(fp_source, 0, SEEK_END);
		end = ftell(fp_source);
		fseek(fp_source, 0, SEEK_SET);
		start = ftell(fp_source);
		source_size = abs(end - start);
	}

	float percent = 50.0;
	int gap = 0;

	for (;;)
	{
		if (source_size - gap < 4)
		{
			fread(&byte, sizeof(char), 1, fp_source);
			fwrite(&byte, sizeof(char), 1, fp_destination);
		}
		else
		{
			fread(&buffer, sizeof(int), 1, fp_source);
			fwrite(&buffer, sizeof(int), 1, fp_destination);
		}
		system("cls");
		gap = abs(start - ftell(fp_source));
		percent = (float)(gap*100) / source_size;
		printf("복사중 : %d %c\n", percent, '%');
		if (percent == 100.0)
		{
			printf("\t복사완료");
			break;
		}
	}

	fclose(fp_source);
	fclose(fp_destination);
}