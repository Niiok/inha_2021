#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<time.h>


#define ITEM_NUMBER 11

struct GachaItem
{
	long win_count = 0;		// win_count
	int win_chance = 0;	// percentage
};

struct GachaTable
{
	GachaItem item[ITEM_NUMBER];
	int total_chance[ITEM_NUMBER];
	long total_count = 0;
};

int problem3();
int problem4();
int GachaHistory_read(FILE*, GachaTable*);
int GachaHistory_write(FILE*, GachaTable*);
int UnluckCheck(GachaTable*);
int ShowGachaStatus(GachaTable* table);

int main()
{
	problem4();
}

int problem3()
{
	long front = 0, back = 0;
	long loop = 0;
	long check = 1;

	srand(time(NULL));

	while (1)
	{
		++loop;


		if (rand() % 2 == 0)
			++front;
		else
			++back;


		if (loop % check == 0)
		{
			srand(time(NULL));
			check *= 2;
			printf("%dtry\n", loop);
			printf("front: %d, back : %d\n", front, back);
			printf("%f %c\n\n", (double)front / (front + back)*100.0, '%');
		}
	}

	return 0;
}


int problem4()
{
	GachaTable table;
	table.item[0].win_chance = 1;
	table.item[1].win_chance = 3;
	table.item[2].win_chance = 3;
	table.item[3].win_chance = 5;
	table.item[4].win_chance = 5;
	table.item[5].win_chance = 5;
	table.item[6].win_chance = 10;
	table.item[7].win_chance = 10;
	table.item[8].win_chance = 10;
	table.item[9].win_chance = 10;
	table.item[10].win_chance = 38;

	table.total_chance[0] = table.item[0].win_chance;

	for (int i = 1; i < ITEM_NUMBER; ++i)
		table.total_chance[i] = table.total_chance[i - 1] + table.item[i].win_chance;


	FILE* history = fopen("../gacha_history.txt", "r");
	if (history == NULL)
	{
		history = fopen("../gacha_history.txt", "w");
		if (history == NULL)
			return -1;
		fclose(history);
	}
	else
	{
		GachaHistory_read(history, &table);
		fclose(history);
	}



	int gacha = 100;
	while (gacha != 0)
	{
		srand(time(NULL));

		std::cin >> gacha;

		for (int i = 1; i <= gacha; ++i)
		{
			int under_chance = UnluckCheck(&table);
			if (under_chance != -1)
			{
				printf("%d try\n", i);
				printf("You were unlucky but we gave you item.\n", i);
				printf("item %c\n\n", under_chance + 'A');

				table.item[under_chance].win_count++;
				table.total_count++;
			}
			else
			{
				int value = rand() % table.total_chance[ITEM_NUMBER - 1];

				for (int j = 0; j < ITEM_NUMBER; ++j)
				{
					if (value < table.total_chance[j])
					{
						printf("%d try\n", i);
						printf("item %c\n\n", j + 'A');

						table.item[j].win_count++;
						table.total_count++;
						break;
					}
				}
			}
		}

		history = fopen("../gacha_history.txt", "w");
		if (history == NULL)
			return -1;
		GachaHistory_write(history, &table);
		fclose(history);
		
		ShowGachaStatus(&table);
	}

	return 0;
}


int GachaHistory_write(FILE* file, GachaTable* table)
{	
	if (file == NULL)
		return -1;

	char item_name = 'A';

	for (int i = 0; i < ITEM_NUMBER; ++i)
		fprintf(file, "%c %d\n", item_name + i, table->item[i].win_count);

	return 0;
}


int GachaHistory_read(FILE* file, GachaTable* table)
{
	if (file == NULL)
		return -1;

	for (int i = 0; i < ITEM_NUMBER; ++i)
	{
		char item_name[128];
		long history_count = 0;

		fscanf(file, "%s", &item_name);
		fscanf(file, "%d", &history_count);


		switch(item_name[0])
		{

		case 'A':
		{
			table->item[0].win_count = history_count;
		} break;
		
		case 'B':
		{
			table->item[1].win_count = history_count;
		} break;
		
		case 'C':
		{
			table->item[2].win_count = history_count;
		} break;
		
		case 'D':
		{
			table->item[3].win_count = history_count;
		} break;
		
		case 'E':
		{
			table->item[4].win_count = history_count;
		} break;
		
		case 'F':
		{
			table->item[5].win_count = history_count;
		} break
		
		;case 'G':
		{
			table->item[6].win_count = history_count;
		} break;
		
		case 'H':
		{
			table->item[7].win_count = history_count;
		} break;
		
		case 'I':
		{
			table->item[8].win_count = history_count;
		} break;
		
		case 'J':
		{
			table->item[9].win_count = history_count;
		} break;
		
		case 'K':
		{
			table->item[10].win_count = history_count;
		} break;

		default:
			break;
		}

		table->total_count += history_count;
	}

	return 0;
}

int UnluckCheck(GachaTable* table)
{
	for (int i = ITEM_NUMBER-2; i >= 0; --i)
	{
		double wanted_chance = (double)table->item[i].win_chance / table->total_chance[ITEM_NUMBER-1];
		double counted_chance = (double)table->item[i].win_count / table->total_count;

		if (wanted_chance > counted_chance)
			return i;
	}

	return -1;
}

int ShowGachaStatus(GachaTable* table)
{
	for (int i = 0; i < ITEM_NUMBER; ++i)
	{
		int wanted_chance = table->item[i].win_chance*100 / table->total_chance[ITEM_NUMBER - 1];
		int counted_chance = table->item[i].win_count*100 / table->total_count;

		printf("item %c:\n", 'A' + i);
		printf("aimed chance : %d %c\n", wanted_chance, '%');
		printf("counted chance : %d %c\n", counted_chance, '%');
		printf("\n");
	}

	return 0;
}