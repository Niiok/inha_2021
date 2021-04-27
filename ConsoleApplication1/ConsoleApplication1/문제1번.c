#include<stdio.h>


int main()
{
	char name[128] = {0.};
	int age = 0;

	printf("이름 : ");
	scanf("%s", name);
	
	printf("\n나이 : ");
	scanf("%d", &age);

	printf("\n%s 님의 나이는 %d살 입니다.\n", name, age);

}