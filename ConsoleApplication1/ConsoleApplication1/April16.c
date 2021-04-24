#include<stdio.h>

void c6hard1();
void problem1();
void problem2();
void problem3();
void problem_abs();
void c7hard1();
int facto_sum(int i);
void problem4();
int snail_maker(int month, int start_baby);

int main(int argc, char* agrv[])
{
	problem4();

}

void c6hard1()
{
	int num;
	int gap = 0;
	scanf_s("%d",  &num);

	for (int i = 2; i <= num; i++)
	{
		int yes = 1;
		for (int j = i - 1; j >= 2; j--)
		{
			if (i%j == 0)
			{
				yes = 0;
				break;

			}
		}
		if (yes == 1)
		{
			printf("%d\t", i);
			gap++;

			if (gap % 5 == 0)
				printf("\n");
		}
	}

}

void problem1()
{
	int num;
	printf("�ڿ��� �Է� : ");
	scanf_s("%d",&num);


	/*
	for (; i <=  num; i++)
	{
		for (int j = i; j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}
	i-=2;
	for (; i >= 0; i--)
	{
		for (int j = i; j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}
	//*/

	/*
	for (; i <=  num; i++)
	{
		for (int j = num; j > 0; j--)
		{
			if (j > i)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
	i-=2;
	for (; i >= 0; i--)
	{
		for (int j = num; j > 0; j--)
		{
			if (j > i)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
	//*/

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (i == j || i + j == num-1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}

void problem2()
{
	int num;
	printf("���ڸ� ������ �ֽÿ� : ");
	scanf_s("%d",&num);

	for (int i=0;i<=9;i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if ((i * 10 + j) + (j * 10 + i) == num)
			{
				printf("A = %d  Z = %d\n", i, j);
				printf("Z = %d  A = %d\n", j, i);
				printf("- - - - - - - - \n");
				printf("    %d      %d\n", i+j, i+j);
				printf("\n\n");
			}
		}
	}
}

void problem3()
{
	problem_abs();
}

void problem_abs()
{
	while (1)
	{
		int num = 1;
	printf("���� �Է� : ");
	scanf_s("%d", &num);

	if (num == 0)
		break;
	else if (num < 0)
		num = -num;

	printf("���밪�� : %d �Դϴ�.\n", num);
	printf("�����Ϸ��� 0�� �Է��ϼ���\n");
	}
}

void c7hard1()
{
	printf("%d", facto_sum(100));
}

int facto_sum(int i)
{
	if (i > 1)
		i += facto_sum(i - 1);

	return i;
}

void problem4()
{
	int snail_kid = 1;
	int snail_adult = 0;
	int month = 0;

	/*
	while(month <12)
	{
		month++;

		int temp = snail_adult;  //�̹� ��� ������ ����
		snail_adult += snail_kid;  //���ο� � ������ �߰�
		snail_kid = 0;  //�ֱ�� ���� ����
		snail_kid += temp;  //�̹� ��� ������ ����

		printf("month : %d...\n", month);
		printf("baby snail : %d\n", snail_kid);
		printf("adult snail : %d\n\n", snail_adult);
	}
	//*/

	//*
	printf("�ֱ� ������ : %d\n", snail_maker(11, 1));
	printf("� ������ : %d\n", snail_maker(12, 1));
	printf("�� ������ : %d\n",snail_maker(12,1) + snail_maker(11,1));
	//*/
}

int snail_maker(int month, int start_baby)
{
	if (month == 1)
	{
		return start_baby;
	}
	else if (month < 1)
	{
		return 0;
	}
	return snail_maker(month - 1, start_baby) + snail_maker(month - 2, start_baby);
}