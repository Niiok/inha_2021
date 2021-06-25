#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BinaryTree.h"


struct Student {
	int number = 0;
	char name[128];
};


int problem1();
int print(Student& a, Student& b);


int main()
{
	problem1();
}


int problem1()
{
	BinaryTree<Student> students;
	int menu = 1;

	while (menu)
	{
		printf("\n    �޴� ����\n");
		printf("\t1.  �л� �߰�\n");
		printf("\t2.  �л� ����\n");
		printf("\t3.  �л� �˻�\n");
		printf("\t4.  ��ü ���\n");

		std::cin >> menu;
		rewind(stdin);
		std::cin.clear();

		switch (menu)
		{
		case 1:		// add student
		{
			int num;
			char name[128];
			Student new_guy;


			printf("\n�л� ��ȣ : ");
			std::cin >> num;
			rewind(stdin);

			printf("\n�л� �̸� : ");
			std::cin.getline(name, 128);
			rewind(stdin);

			new_guy.number = num;
			strcpy(new_guy.name, name);

			bool check = students.Search(new_guy.number);
			if (check == true)
				printf("�ش� �л� ��ȣ�� �̹� �����մϴ�.\n");
			else
				students.Add(new_guy.number, new_guy);
		}break;

		case 2:		// delete student
		{
			int num;

			printf("\n�л� ��ȣ : ");
			std::cin >> num;
			rewind(stdin);

			bool check = students.Search(num);
			if (check == true)
				students.Remove(num);
			else
				printf("\n�׷� �л� �����.\n");

		}break;

		case 3:		// search
		{
			int num;

			printf("\n�л� ��ȣ : ");
			std::cin >> num;
			rewind(stdin);

			bool check = students.Search(num);
			if (check == true)
				printf("\n%d�� %s\n", num, students[num].name);
			else
				printf("\n�׷� �л� �����.\n");

		}break;

		case 4:
		{
			Student ex;
			students.foreach(print, ex);
			printf("\n");
		}
			break;

		default:
			break;
		}
	}

	return 0;
}


int print(Student& a, Student& b)
{
	printf("%d�� %s\n", a.number, a.name);

	return 0;
}
