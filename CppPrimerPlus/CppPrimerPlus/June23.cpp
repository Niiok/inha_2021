#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
//#include <List>

struct Student {
	int number;
	char name[128];
};

int test();
int problem1();
int find_next(Student& a, Student& b);
int find(Student& a, Student& b);
int print(Student& a, Student& b);



int main()
{
	problem1();
}

int test()
{
	List<int> liss;
	List<int> liss2;

	for (int i = 0; i < 10; ++i)
	{
		liss.push_back(i);
		printf("%d ", liss[i]);
	}
	for (int i = 0; i < 10; ++i)
		liss.pop_back();
	printf("\n");
	

	for (int i = 10; i > 0; --i)
	{
		liss.push_back(i);
		printf("%d ", liss.back());
	}
	printf("\n");

	return 0;
}

int problem1()
{
	List<Student> students;
	int menu = 1;

	while (menu)
	{
		rewind(stdin);
		printf("\n    �޴� ����\n");
		printf("\t1.  �л� �߰�\n");
		printf("\t2.  �л� ����\n");
		printf("\t3.  �л� �˻�\n");
		printf("\t4.  ��ü ���\n");

		std::cin >> menu;

		switch (menu)
		{
		case 1:		// add student
		{
			int num;
			char name[128];
			int index;
			Student new_guy;

			
			printf("\n�л� ��ȣ :");
			std::cin >> num;

			rewind(stdin);
			printf("\n�л� �̸� :");
			std::cin.getline(name, 128);

			new_guy.number = num;
			strcpy(new_guy.name, name);

			index = students.foreach(find_next, new_guy);
			if (index != -1)
				students.insert(index, new_guy);
			else
				students.push_back(new_guy);
		}break;

		case 2:		// delete student
		{
			int num;
			char name[128];
			int index;
			Student going_guy;

			
			printf("\n�л� ��ȣ :");
			std::cin >> num;

			going_guy.number = num;

			index = students.foreach(find, going_guy);
			if(index != -1)
			students.erase(index);

		}break;

		case 3:		// search
		{
			int num;
			char name[128];
			int index;
			Student finding_guy;

			printf("\n�л� ��ȣ :");
			std::cin >> num;

			finding_guy.number = num;

			index = students.foreach(find, finding_guy);
			if (index != -1)
				printf("\n%d�� %s�� %d��° �л��̴�.\n\n", num, students[index].name, index);
			else
				printf("\n�׷� �л� �����.\n");

		}break;

		case 4:
			Student ex;
			students.foreach(print, ex);
			printf("\n");
			break;

		default:
			break;
		}
	}

	return 0;
}


int find_next(Student& a, Student& b)
{
	if (a.number > b.number)
		return 1;

	return 0;
}

int find(Student& a, Student& b)
{
	if (a.number == b.number)
		return 1;

	return 0;
}

int print(Student& a, Student& b)
{
	printf("%d�� %s\n", a.number, a.name);
	
	return 0;
}