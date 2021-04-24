#include<stdio.h>
#include<windows.h>
#define _CRT_SECURE_NO_WARNINGS


int problem_mod();
int problem1();
void swap(int* pa, int* pb);
void test();
int c11hard();
int f12_13();
char* my_strcpy(char* dest, char* source);
int str_changer(char* arr, char* from, char* to);
void str_change();

int main()
{
	test();

}

int problem_mod()
{
	char string[256];
	int length = 0;
	int border = 0;
	gets(string);

	for (char* i = string; ; i++)
	{
		if (*i == 0)
		{
			length = (int)((i + 4) - (string))/sizeof(char);
			break;
		}
	}

	*(string + length) = 0;
	*(string + (length - 1)) = ' ';
	*(string + (length - 2)) = ' ';
	*(string + (length - 3)) = ' ';

	while (1)
	{
		system("cls");

		if (border % length == length - 1)
			border = 0;

		printf("\n\n\t\t");
		for (int i = 0; i < length; i++)
		{
			putchar(*(string + ((i + border) % length)));
		}

		Sleep(100);
		//getchar();
		border++;
	}

	return 0;
}


int problem1()
{
	int arr[6] = {1, 2, 3, 4, 5, 6};
	int* head = arr;
	int* tail = arr+5;

	/*
	for (int i = 0; i < 6 / 2; i++)
		swap(arr + i, arr + (5 - i));
		*/

	for (; head < tail ; head++, tail--)
		swap(head, tail);

	for (int i = 0; i < 6; i++)
		printf("%d ", *(arr+i));

	return 0;
}

void swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int c11hard()
{
	char character;
	int length = 0, max = 0;
	while (character = getchar())
	{
	//printf("%d\n",character);
		if ((character >= 'a' && character <= 'z') || \
			(character >= 'A' && character <= 'Z') || \
			(character >= '0' && character <= '9'))
			length++;
		else if (character == -1)
			break;
		else
		{
			if (length > max)
				max = length;
			length = 0;
		}
	}
	printf("가장 긴 단어의 길이 : %d", max);

	return 0;
}

void test()
{
	char ch1='0', ch2='0';

	scanf_s("%c%c",&ch1, 1, &ch2, 1);
	printf("[%c%c]", ch1, ch2);
	getchar();

	fflush(stdin);
	fflush(stdout);

	scanf_s(" %c %c",&ch1, 1, &ch2, 1);
	printf("[%c%c]", ch1, ch2);
}

int f12_13()
{
	char str[256] = "strawberry";

	printf("%s\n",str);
	my_strcpy(str, "hamburgger");

	printf("%s\n",str);

	printf("%s\n",my_strcpy(str, "jam"));


	return 0;
}

char* my_strcpy(char* dest, char* source)
{
	/*
	int source_len = strlen(source);

	for (int i = 0; i < source_len; i++)
	{
		dest[i] = source[i];
	}
	dest[source_len] = '\0';
	
	return dest;
	*/

	char* address = dest;

	while (*source != '\0')
		*(dest++) = *(source++);
	*dest = '\0';

	return address;

}

int str_changer(char* arr, char* from, char* to)
{
	char original[256] = {0, };
	strcpy_s(original, sizeof(original), arr);

	char* mod_address = strstr(arr, from);
	int mod_index = (int)(mod_address - arr);

	int from_len = strlen(from);
	int to_len = strlen(to);
	int arr_len = strlen(arr);
	int gap = to_len - from_len;
	int new_end = arr_len + gap;

	for (int i = 0; i < to_len; i++)
	{
		*(arr + mod_index + i) = *(to + i);
	}
	
	for (int i = mod_index + from_len + gap; i < new_end; i++)
	{
		*(arr + i) = *(original + i - gap);
	}
	*(arr + new_end) = '\0';

}

void str_change()
{
	char* arr[256] = { 0, };
	strcpy_s(arr, sizeof(arr), "we are a boy and a girl.");

	printf("%s\n", arr);
	str_changer(arr, "boy", "super man");
	printf("%s\n", arr);
	str_changer(arr, "girl", "man");

}