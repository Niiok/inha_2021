//*#include <iostream>//*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int problem1();
int problem2();
int problem3();
int problem4();
int problem5();
int problem6();


int main()
{
	problem8();

	return 0;
}



int problem1()
{
	int i = 1;
	while (1)
	{
		float f;

		printf("실수 입력 %d (e표기법 ) : ", i);

		scanf_s("%e", &f);

		printf("입력된 실수 %.6f\n", f);

		i++;
	}

	return 0;
}

int problem2()
{
	while (1)
	{
		int time;

		printf("입력 : ");
		scanf_s("%d", &time);
		printf("출력 : %d초는 %02d시간 %02d분 %02d초 입니다.\n", time, time / 3600, (time % 3600) / 60, time % 60);
	}

	return 0;
}

int problem3()
{
	double a = 4.0, b = 1.2;

	printf("%.1lf + %.1lf = %.1lf\n", a, b, a + b);
	printf("%.1lf - %.1lf = %.1lf\n", a, b, a - b);
	printf("%.1lf * %.1lf = %.1lf\n", a, b, a * b);
	printf("%.1lf / %.1lf = %.1lf\n", a, b, a / b);

	return 0;
}

int problem4()
{
	int nInput, nTotal=0;
	printf("세 과목의 점수 : ");
	for (int i = 3; i > 0; i--)
	{
		scanf_s("%d", &nInput);
		nTotal += nInput;
	}

	printf("평균 : %.2f\n", (double)nTotal/3.0);

	return 0;
}

int problem5()
{
	int kor = 3, eng = 5, mat = 4, credits, res;
	double kscore=3.8, escore=4.4, mscroe=3.9, grade;

	credits = kor + eng + mat;
	grade = (kscore + escore + mscroe) / 3.0;

	res = (credits >= 10) && (grade > 4.0);
	printf("%d",res);

	return 0;
}

int problem6()
{
	while (1)
	{
		int a, b, c;
		//int ao, bo, co;
		printf("please input a, b, c : ");
		scanf_s("%d %d %d", &a, &b, &c);

		//printf("biggiest one is %d.\n", (a > b ? a : b) > c ? (a > b ? a : b) : c);
		
		a = a * ((a > b) && (a > c));
		b = b * ((b > a) && (b > c));
		c = c * ((c > a) && (c > b));
		a = a + b + c;
		printf("biggest one is %d.\n", a);


	}
	return 0;
}
