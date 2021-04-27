#include<stdio.h>

char* binary_string(char* arr, int num);

int main()
{
	char arr[128] = {0};
	int num = 131;
	binary_string(arr, num);

	printf("10진수 %d 는 이진수로 %s 입니다. \n", num, arr);

}

char* binary_string(char* arr, int num)
{
	int size = 0;

	for (; num > (1 << size); size++);	//문자열 길이 구하기

	*(arr + size) = 0;	//'\0'으로 문자열 끝
	size--;

	for (int i = size; i >= 0; i--)	//2진수 계산후 문자열에 기록
	{
		if (num / (1 << (i)))
			*(arr + (size - i)) = '1';
		else
			*(arr + (size - i)) = '0';

		num = num % (1 << (i));
	}

	return arr;
}