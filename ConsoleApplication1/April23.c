#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pointpoint_test();
int p15_2();
void swap_ptr(char **ppa, char** ppb);
int p15_3();
void print_str(char** pps, int cnt);
int p15_4();
int p15_5();
int p15_6();
void print_ary(int(*)[4]);
int problem2();
int MaxAndMin(int arr[5], int** maxPtr, int** minPtr);
int c15hard();
void swap(char* swap_type, void* a, void* b);
int p16_1();
int p16_2();
int p16_3();
int problem3();
int input_string(char* arr, int start, int size);
int print_string(char* arr, int size);
int print_inverse(char* arr, int size);

int main()
{
	problem3();
}

int pointpoint_test()
{
	int** pa;
	int** pb = &pa;
	int** pc = &pb;
	pa = &pb;

	for (int i = 0;i <10;i++)
	{
		pc = *pc;
		printf("%p\n", pc);
	}
}

int p15_2()
{
	char* pa = "success";
	char* pb = "failure";

	printf("pa -> %s, pb -> %s\n", pa, pb);
		swap_ptr(&pa, &pb);
	printf("pa -> %s, pb -> %s\n", pa, pb);

	return 0;
}

void swap_ptr(char** ppa, char** ppb)
{
	char* pt;
	pt = *ppa;
	*ppa = *ppb;
	*ppb = pt;
}

int p15_3()
{
	char* ptr_ary[] = { "eagle","tiger","lion","squirrel", };
	int count;

	count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
	print_str(ptr_ary, count);

	return 0;
}

void print_str(char** pps, int cnt)
{
	int i;
	
	for (i = 0; i < cnt; i++)
	{
		printf("%s\n", pps[i]);
	}
}

int p15_4()
{
	int ary[5];

	printf("ary의 값\t : %u\t", ary);
	printf("ary의 주소값\t : %u\n", &ary);
	printf("ary + 1\t\t : %u\t", ary + 1);
	printf("&ary + 1\t : %u\n", &ary + 1);


	return 0;
}

int p15_5()
{
	int ary[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	int(*pa)[4];
	int i, j;

	pa = ary;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%5d", pa[i][j]);
		}
		printf("\n");
		
	}


	return 0;
}

int p15_6()
{
	int ary[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };

	print_ary(ary);

	return 0;
}

void print_ary(int(*pa)[4])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%5d", pa[i][j]);
		}
		printf("\n");

	}
		
		printf("%u\n", pa);
		printf("%u\n", pa+1);
		//printf("%u\n", pa+2+1);
		printf("%u\n", &pa+1);
		printf("%u\n", *(pa+1));
}

int problem2()
{
	int* maxPtr;
	int* minPtr;
	int arr[5] = { 3, -1, 65, 23, 43 };

	MaxAndMin(arr, &maxPtr, &minPtr);

	printf("arr address\t : %u\n", arr);
	printf("maxPtr address\t : %u\n", maxPtr);
	printf("minPtr address\t : %u\n", minPtr);
	printf("\n");
	printf("arr value\t : %d\n", *arr);
	printf("maxPtr value\t : %d\n", *maxPtr);
	printf("minPtr value\t : %d\n", *minPtr);
	return 0;
}

int MaxAndMin(int arr[5], int** maxPtr, int** minPtr)
{
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			*maxPtr = &arr[i];
			*minPtr = &arr[i];
		}
		if (**maxPtr < arr[i])
			*maxPtr = &arr[i];
		if (**minPtr > arr[i])
			*minPtr = &arr[i];
	}


	return 0;
}

int c15hard()
{
	int ia = 1, ib = 2;
	double da = 1.5, db = 2.5;

	printf("A의 나이와 키, B의 나이와 키를 입력해주세요.");
	scanf_s("%d %lf %d %lf", &ia, &da, &ib, &db);

	printf("A - age : %d,\t B - age = %d\n", ia, ib);
	printf("A - height : %lf,\t B - height = %lf\n", da, db);
	
	swap("int", &ia, &ib);
	swap("double", &da, &db);

	printf("A - age : %d,\t B - age = %d\n", ia, ib);
	printf("A - height : %lf,\t B - height = %lf\n", da, db);


	return 0;
}

void swap(char* swap_type, void* a, void* b)
{
	switch (*swap_type)
	{
	case 'i':
	case 'I':
	{
		int* pa = (int*)a;
		int* pb = (int*)b;
		int temp = *pa;
		*pa = *pb;
		*pb = temp;
		return;
	}
		break;

	case 'd':
	case 'D':
	{
		double* pa = (double*)a;
		double* pb = (double*)b;
		double temp = *pa;
		*pa = *pb;
		*pb = temp;
		return;
	}
		break;

	default:
		break;
	}
}

int p16_1()
{
	int *pi;
	double *pd;

	pi = (int*)malloc(sizeof(int) * 1);
	if (pi == NULL)
		exit(0);

	pd = (double*)malloc(sizeof(double) * 1);
	if (pd == NULL)
		exit(0);

	*pi = 10;
	*pd = 1.5;

	printf("%d %lf\n", *pi, *pd);
	printf("%d %d", sizeof(pi), sizeof(pd));

	free(pi);
	free(pd);

	return 0;
}

int p16_2()
{
	int *pi;
	int i, sum = 0;

	pi = (int *)malloc(5 * sizeof(int));
	if (pi == NULL)
		exit(1);

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &pi[i]);
		sum += pi[i];
	}
	printf("%.1lf\n", sum / 5.0);
	free(pi);

	return 0;
}

int p16_3()
{
	int *pi;
	int size = 5;


	return 0;
}

int problem3()
{
	int length;
	char* arr;
	printf("insert length of string. : ");
	scanf_s("%d", &length);
	getchar();

	arr = (char*)calloc(length+1, sizeof(char));
	if (arr == NULL)
		exit(1);

	while (1)
	{
		int i = input_string(arr, 0, length);
		if (!strcmp(arr, "Quit"))
			break;
		print_string(arr, i);
		//print_inverse(arr, i);
	}
	free(arr);
	return 0;
}

int input_string(char* arr, int start, int size)
{
	//puts("input_s");

	int i = start;
	for (; i < size; i++)
	{
		int character = getchar();
		//printf("%d",character);
		if (character == -1)
			break;
		arr[i] = (char)character;

		if (!strcmp(&arr[i - 3], "Quit"))
		{
			i++;
			break;
		}
	}
	arr[i] = '\0';

	if (i == size)
		puts("memmory is full.\n");

	return i;
}
int print_string(char* arr , int size)
{
	puts("p_s\n");

	for (int i = 0; *(arr + i) != '\0' && i < size; i++)
		putchar(*(arr+i));

	return 0;
}
int print_inverse(char* arr, int size)
{
	puts("p_i\n");

	int count = 0;

	for (int i = size - 1; i >= 0; i--)
	{
		if (!((arr[i] >= 'a' && arr[i] <= 'z') || \
			(arr[i] >= 'A' && arr[i] <= 'Z') || \
			(arr[i] >= '0' && arr[i] <= '9')))
		{
			print_string(&arr[i], count);
			putchar(' ');
			count = 0;
		}
		else
		{
			count++;
		}

	}

	return 0;
}
