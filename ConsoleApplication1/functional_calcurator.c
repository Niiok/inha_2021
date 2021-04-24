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
		printf("¸Þ´º¸¦ ¼±ÅÃÇØÁÖ¼¼¿ä.\n");
		printf("\t1. µ¡¼À.\n");
		printf("\t2. »¬¼À.\n");
		printf("\t3. °ö¼À.\n");
		printf("\t4. ³ª´°¼À.\n");
		printf("\t5. Á¾·á.\n");
		printf("\t¸Þ´º¼±ÅÃ > ");

		scanf_s("%d", &menu);
		if (menu < 0 || menu > 5)
		{
			printf("\n´Ù½Ã ¼±ÅÃÇØÁÖ¼¼¿ä.\n\n");
			continue;
		}
		else if (menu == 5)
		{
			printf("\nÀåºñ¸¦ Á¤ÁöÇÕ´Ï´Ù.\n");
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
	printf("\nµÎ °ªÀ» ÀÔ·ÂÇØÁÖ¼¼¿ä. > ");
	scanf_s("%f %f", &val1, &val2);

	third_state(menu, val1, val2);

	return 0;
}

int third_state(int menu, float val1, float val2)
{
	double result;

	switch (menu)
	{
	case 1:	//µ¡¼À
		result = (double)val1 + (double)val2;
		break;
	case 2:	//»¬¼À
		result = (double)val1 - (double)val2;
		break;
	case 3:	//°ö¼À
		result = (double)val1 * (double)val2;
		break;
	case 4:	//³ª´°¼À
		result = (double)val1 / (double)val2;
		break;
	default:
		return -1;
	}

	printf("\n\n°á°ú´Â %f ÀÔ´Ï´Ù.\n\n", result);
	printf("- - - - - - - - - - - - - - - - - - - \n\n", result);
	return 0;
}