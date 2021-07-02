#include <string>
//#include "BinaryTree.h"
#include "AVLtree.h"

struct Student {
	std::string name;
	int number;
};

int problem1();
int test();
int print(Student& a, Student& b);

int main()
{
	problem1();
}


int problem1()
{
	constexpr int HASH_SCALE = 4;

	AVLtree<Student> hash[HASH_SCALE];
	int menu = 1;
	int num = 0;
	std::string name;

	while (menu)
	{
		printf("\n\tSelect Menu\n");
		printf("\t  1. Insert\n");
		printf("\t  2. Delete\n");
		printf("\t  3. Search\n");
		printf("\t  4. Dump\n");
		printf("\t  5. Show Tree\n");
		std::cin >> menu;
		rewind(stdin);

		switch (menu)
		{
		case 1:		// insert
		{
			printf("\nType to Insert.\n");
			printf("  number : ");
			std::cin >> num;
			rewind(stdin);
			printf("  name : ");
			std::getline(std::cin, name);
			rewind(stdin);
			std::cin.clear();
			Student temp = { name, num };

			hash[num%HASH_SCALE].Add(num, temp);
		}
		break;

		case 2:		// erase
			printf("\nType number to Delete.");
			std::cin >> num;

			rewind(stdin);
			if (hash[num%HASH_SCALE].Search(num))
				hash[num%HASH_SCALE].Remove(num);
			else
				printf("No such a number exists.\n");
			break;

		case 3:		// search
		{
			printf("\nType number to Search.\n");
			std::cin >> num;
			rewind(stdin);

			if (hash[num%HASH_SCALE].Search(num))
				printf("Student %d : %s is in %dth table.\n", num, hash[num%HASH_SCALE][num].name.c_str(), num%HASH_SCALE);
			else
				printf("No such a number exists.\n");
		}
		break;

		case 4:		// show all
		{
			Student no_meaning = { "", 0 };
			for (int i = 0; i < HASH_SCALE; ++i)
			{
				printf("table %d :", i);
				hash[i].foreach(print, no_meaning);
				printf("\n");
			}
		}
		break;

		case 5:		// Show tree

			printf("\n");
			for (int j = 0; j < 64; ++j)
				printf("-");
			printf("\n");

			for (int i = 0; i < HASH_SCALE; ++i)
			{
				hash[i].ShowTree(64);
				printf("\n");
				for (int j = 0; j < 64; ++j)
					printf("-");
				printf("\n");
			}

			break;

		case 6:		// quit
			menu = 0;
			break;
		default:
			break;
		}
	}

	return 0;
}

int print(Student& a, Student& b)
{
	printf("\t%d : %s", a.number, a.name.c_str());

	return 0;
}


int test()
{
	AVLtree<int> tree;

	for (int i = 0; i < 120; ++i)
	{
		tree.Add(rand()%120, 120);

		tree.ShowTree(256);
		
		printf("\n\n");
		for (int i = 0; i < 256; ++i)
			printf("-");
		printf("\n\n");
	}

	return 0;
}