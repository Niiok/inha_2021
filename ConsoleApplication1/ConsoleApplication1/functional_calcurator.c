#include<stdio.h>

int first_state();
int second_state(int);
int third_state(int, float, float);

int main()
{
	first_state();
}

int first_state()
{
	int menu;
	while (1)
	{
		printf("�޴��� �������ּ���.\n");
		printf("\t1. ����.\n");
		printf("\t2. ����.\n");
		printf("\t3. ����.\n");
		printf("\t4. ������.\n");
		printf("\t5. ����.\n");
		printf("\t�޴����� > ");

		scanf_s("%d", &menu);
		if (menu < 0 || menu > 5)
		{
			printf("\n�ٽ� �������ּ���.\n\n");
			continue;
		}
		else if (menu == 5)
		{
			printf("\n��� �����մϴ�.\n");
			break;
		}
		else
		{
			second_state(menu);
		}
	}

	return 0;
}

int second_state(int menu)
{
	float val1, val2;
	printf("\n�� ���� �Է����ּ���. > ");
	scanf_s("%f %f", &val1, &val2);

	third_state(menu, val1, val2);

	return 0;
}

int third_state(int menu, float val1, float val2)
{
	double result;

	switch (menu)
	{
	case 1:	//����
		result = (double)val1 + (double)val2;
		break;
	case 2:	//����
		result = (double)val1 - (double)val2;
		break;
	case 3:	//����
		result = (double)val1 * (double)val2;
		break;
	case 4:	//������
		result = (double)val1 / (double)val2;
		break;
	default:
		return -1;
	}

	printf("\n\n����� %f �Դϴ�.\n\n", result);
	printf("- - - - - - - - - - - - - - - - - - - \n\n", result);
	return 0;
}