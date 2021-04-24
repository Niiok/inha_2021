#include<stdio.h>
#include<windows.h>

int c8p1();
int problem1();
int c8hard1();
int problem2();
int c9p1();
int problem3();
int c9hard1();
void swap(double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);

int main()
{
	c9hard1();
}

int c8p1()
{
	int A[3] = { 1, 2, 3 };
	int B[10];

	for (int i = 0; i < sizeof(B) / sizeof(B[0]);i++)
	{
		B[i] = A[i % 3];
		printf("%d ",B[i]);
	}

	return 0;
}

int problem1()
{
	int arr[5];
	int max, min, sum;
	
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &arr[i]);

		if (i == 0)
		{
			max = arr[i];
			min = arr[i];
			sum = arr[i];
		}
		else 
		{
			if (max < arr[i])
				max = arr[i];
			if (min > arr[i])
				min = arr[i];
			sum += arr[i];
		}

	}
	printf("max = %d\n", max);
	printf("min = %d\n", min);
	printf("sum = %d\n", sum);

	return 0;
}

int c8hard1()
{
	char string[256];
	int count = 0;

	gets(string);

	for (int i = 0; string[i] != 0; i++)
	{
		if (string[i] >= 'A' && string[i] <= 'Z')
		{
			string[i] += 32;
			count++;
		}
	}
	printf("%s\n", string);
	printf("change words are : %d\n", count);


	return 0;
}

int problem2()
{
	char string[256];
	int length = 0;
	int border = 0;
	gets(string);

	for (int i = 0; ; i++)
	{
		if (string[i] == 0)
		{
			length = i + 4;
			break;
		}
	}
	string[length] = 0;
	string[length - 1] = ' ';
	string[length - 2] = ' ';
	string[length - 3] = ' ';
	
	while(1)
	{
		system("cls");
		
		if (border % length == length - 1)
			border = 0;

		printf("\n\n\t\t");
		for (int i = 0; i < length; i++)
		{
			putchar(string[(i + border) % length]);
		}

		Sleep(100);
		//getchar();
		border++;
	}

	return 0;
}

int c9p1()
{
	int a = 10 , b = 15, total;

 /*
	double avg;
	int* pa;
	int* pb;
	int* pt = &total;
	double* pg = &avg;

	pa = &a;
	pb = &b;

	*pt = *pa + *pb;
	*pg = *pt / 2.0;


	printf("*pa = %d, *pb = %d\n", *pa, *pb);
	printf("*pt = %d\n", *pt);
	printf("*pg = %f\n", *pg);
	*/


	return 0;
}

int problem3()
{
	int num1 = 10, num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int* temp;

	*ptr1 += 10;
	*ptr2 -= 10;

	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;

	printf("*ptr1 : %d, *ptr2 : %d\n", *ptr1, *ptr2);

	return 0;
}

int c9hard1()
{
	double max, mid, min;

	printf("실수값 3개 입력 : ");
	scanf_s("%lf%lf%lf", &max, &mid, &min);
	line_up(&max, &mid, &min);
	printf("정렬된 값 출력 : %.1lf, %.1lf, %.1lf\n", max, mid, min);

	return 0;
}

void swap(double* pa, double* pb)
{
	double temp = *pa;
	*pa = *pb;
	*pb = temp;
}
void line_up(double* maxp, double* midp, double* minp)
{
	if (*minp > *midp)
		swap(minp, midp);
	if (*midp > *maxp)
	{
		swap(midp, maxp);
		if (*minp > *midp)
			swap(minp, midp);
	}
}
