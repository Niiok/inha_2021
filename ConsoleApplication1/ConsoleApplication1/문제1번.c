#include<stdio.h>


int main()
{
	char name[128] = {0.};
	int age = 0;

	printf("�̸� : ");
	scanf("%s", name);
	
	printf("\n���� : ");
	scanf("%d", &age);

	printf("\n%s ���� ���̴� %d�� �Դϴ�.\n", name, age);

}