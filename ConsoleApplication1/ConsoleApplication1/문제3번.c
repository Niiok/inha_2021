#include<stdio.h>

char* binary_string(char* arr, int num);

int main()
{
	char arr[128] = {0};
	int num = 131;
	binary_string(arr, num);

	printf("10���� %d �� �������� %s �Դϴ�. \n", num, arr);

}

char* binary_string(char* arr, int num)
{
	int size = 0;

	for (; num > (1 << size); size++);	//���ڿ� ���� ���ϱ�

	*(arr + size) = 0;	//'\0'���� ���ڿ� ��
	size--;

	for (int i = size; i >= 0; i--)	//2���� ����� ���ڿ��� ���
	{
		if (num / (1 << (i)))
			*(arr + (size - i)) = '1';
		else
			*(arr + (size - i)) = '0';

		num = num % (1 << (i));
	}

	return arr;
}