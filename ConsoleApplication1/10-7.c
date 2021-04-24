#include<stdio.h>

void input_arr(double *pa, int size);
void output_arr(double *pa, int size);
double find_max(double *pa, int size);


int main()
{
	double arr[5];
	double max;
	int size = sizeof(arr) / sizeof(arr[0]);

	input_arr(arr, size);
	output_arr(arr, size);
	printf("�迭�� �ִ밪 : %.1lf\n", find_max(arr, size));

	return 0;
}

void input_arr(double *pa, int size)
{
	int i;

	printf("%d���� �Ǽ��� �Է� : ", size);
	for (i = 0; i < size; i++)
	{
		scanf_s("%lf", pa + i);
	}
}
void output_arr(double *pa, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%2lf ", *(pa+i));
	}
		printf("\n");
}
double find_max(double *pa, int size)
{
	double max;
	int i;

	max = pa[0];
	for (i = 1; i < size; i++)
	{
		if (pa[i] > max)max = pa[i];
	}
	return max;
}