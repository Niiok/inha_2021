#include<stdio.h>

int problem1();
int binary_test();
void binary_show(int i);
int c4_p1();
int c4_p2();
int c4_hard1();
int c5_p1();
int problem2();
int problem3();
void calcu();
void problem6();
void problem7();

int main()
{
	problem7();

}

int problem1()
{
	int a = 10;
	double b = 3.4;

	printf("int var size : %d\n", sizeof(a));
	printf("doublle var size : %d\n", sizeof(b));
	printf(" : %d\n", sizeof(10));
	printf(" : %d\n", sizeof(1.5 + 3.4));
	printf(" : %d\n", sizeof(char));
	printf("");

	return 0;
}

int binary_test()
{
	binary_show(4);
	binary_show(4 << 1);
	binary_show(4 << 2);
	binary_show(4 << 3);
	binary_show(4 >> 1);
	binary_show(4 >> 2);
	binary_show(4 >> 3);

	binary_show(243);
	binary_show(84343);
	binary_show(243 | 84343);

	return 0;
}

void binary_show(int i)
{
	int num = i;

	printf("%d in binary is :\t", i);
	for (int j = 31; j >= 0; j--)
	{
		int done = num / (1 << (j));
		num = num % (1 << (j));
		printf("%d", done);
		if (j % 8 == 0)
			printf(" ");
	}
	printf("\n");
}

int c4_p1()
{

	sizeof(short) > sizeof(long) ? printf("short") : printf("long");

	return 0;
}

int c4_p2()
{
	int seats = 70;
	int people = 65;

	printf("%f", (float)65 / (float)75);


	return 0;
}


int c4_hard1()
{
	float kg;
	float cm;
	printf("키와 몸무게를 입력해주세요 : ");
	scanf_s("%f %f", &cm, &kg);

	float BMI = kg / ((cm / 100.0)*(cm / 100.0));

	//printf(" BMI : %f  -> ", BMI);
	((BMI <= 20.0) || (BMI > 25.0)) ? printf("체중관리가 필요합니다.") : printf("표준입니다.");

	return 0;
}

int c5_p1()
{
	int a = 0;

	if (a < 0)
	{
		a = -a;
	}
	else
	{

	}

	if (a % 2 == 0)
	{
		a = 2;
	}
	else
	{
		a = 1;
	}
	return 0;
}

int c5_p2()
{
	int chest = 0;
	char choose;

	if (chest <= 90)
	{
		choose = 'S';
	}
	else if (chest <= 100)
	{
		choose = 'M';
	}
	else
	{
		choose = 'L';
	}
	return 0;
}

int problem2()
{
	int a, b, c;
	printf("정수 두개 입력해줘요 : ");
	scanf_s("%d %d", &a, &b);
	c = a - b;

	//*  case 1
	if (c < 0)
		c = -c;
	else
		NULL;
	//*/

	/*  case 2
	c < 0 ? c = -c : NULL;
	//*/

	printf("두 수의 차는 %d 입니다.", c);

	return 0;
}


int problem3()
{
	int kor, eng, mat;
	float mean;
	char score;

	printf("국어 영어 수학 성적입력 : ");
	scanf_s("%d %d %d", &kor, &eng, &mat);

	mean = (float)(kor + eng + mat) / 3.0;

	if(mean >= 90)
	{
		score = 'A';
	}
	else if (mean >= 80)
	{
		score = 'B';
	}
	else if (mean >= 70)
	{
		score = 'C';
	}
	else if (mean >= 60)
	{
		score = 'D';
	}
	else
	{
		score = 'F';
	}
	printf("score is %c", score);

	return 0;
}

void calcu()
{   //혼합연산 구현 못함
	//괄호 구현 못함
	//유리수계산 구현 못함
	while (1)
	{
		int accum = 0;
		int operand = 0;
		char operate = 0;
		//char old_operate = 0;
		int state = -1;
		/*
		0 : operand1 / accum
		1 : space
		2 : operator
		3 : operand
		4 : space / operand
		5 : calc  / accum XX operand / back to state 1 or 2
		1 : space ...
		*/
		
		char character;
		int end = 0;
		printf("simple calcurator : ");

		while (character = getchar())
		{
			if (state == 5)
			{
				switch (operate)
				{
				case '+':
					accum += operand;
					break;
				case '-':
					accum -= operand;
					break;
				case '*':
					accum *= operand;
					break;
				case '/':
					accum /= operand;
					break;
				case '%':
					accum = accum % operand;
					break;
				case '=':
					break;
				}
				operand = 0;
				state = 2;

				if (end == 1)
				{
					printf("result is : %d.\n\n", accum);
					break;
				}
			}

			printf("state : %d, character : %c, accum : %d, operand : %d\n", state, character, accum, operand);

			switch (character)
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if (state == -1 || state == 0)
				{
					accum *= 10;
					accum += character - 48;
					state = 0;
				}
				else if(state == 2 || state == 3 )
				{
					operand *= 10;
					operand += character - 48;
					state = 3;
				}
				break;

			case ' ':
				if (state == 0) // after first
					state = 1;
				else if (state == 3)  //after operator
					state = 4;
				//else if (state == 3)  //after operand
					//state = 5;
				break;

			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
				if (state == 0 || state == 1) // after first
					state = 2;
				else if (state == 3 || state == 4) // after operand
					state = 5;
				operate = character;
				break;
			case 10:
				if (state == 0 || state == 1) // after first
					state = 2;
				else if (state == 3 || state == 4) // after operand
					state = 5;
				break;

			case '=':
				state = 5;
				end = 1;
				break;
			}

			
		}
	}

}

void problem6()
{
	for (int i = 1; i < 100; i++)
	{
		if (i % 63 == 0)
		{
			printf(" 63x : %d \n", i);
		}
		else if(i % 9 == 0)
		{
			printf(" 9x : %d \n", i);
		}
		else if (i % 7 == 0)
		{
			printf(" 7x : %d \n", i);
		}

	}
}

void problem7()
{
	const int MULTI_NUM = 19;
	const int GAP = 5;

	printf("\t\t %4d 단\n", MULTI_NUM);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - -\n");

	for (int i = 1; i <= MULTI_NUM; i++)
	{
		if (i % GAP == 2)
		{
			for (int k = 1; k <= MULTI_NUM ; k++)
			{
				for (int j = i; j < i + GAP; j++)
				{
					if(j <= MULTI_NUM)
						printf(" %d x %d = %d\t", j, k, j*k);
				}
				printf("\n");
			}
			printf("- - - - - - - - - - - - - - - - - - - - - - - - -\n");
		}
	}

}