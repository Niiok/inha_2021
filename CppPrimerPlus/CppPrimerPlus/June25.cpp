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
		printf("\n    메뉴 선택\n");
		printf("\t1.  학생 추가\n");
		printf("\t2.  학생 삭제\n");
		printf("\t3.  학생 검색\n");
		printf("\t4.  전체 출력\n");

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


			printf("\n학생 번호 : ");
			std::cin >> num;
			rewind(stdin);

			printf("\n학생 이름 : ");
			std::cin.getline(name, 128);
			rewind(stdin);

			new_guy.number = num;
			strcpy(new_guy.name, name);

			bool check = students.Search(new_guy.number);
			if (check == true)
				printf("해당 학생 번호는 이미 존재합니다.\n");
			else
				students.Add(new_guy.number, new_guy);
		}break;

		case 2:		// delete student
		{
			int num;

			printf("\n학생 번호 : ");
			std::cin >> num;
			rewind(stdin);

			bool check = students.Search(num);
			if (check == true)
				students.Remove(num);
			else
				printf("\n그런 학생 없어요.\n");

		}break;

		case 3:		// search
		{
			int num;

			printf("\n학생 번호 : ");
			std::cin >> num;
			rewind(stdin);

			bool check = students.Search(num);
			if (check == true)
				printf("\n%d번 %s\n", num, students[num].name);
			else
				printf("\n그런 학생 없어요.\n");

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
	printf("%d번 %s\n", a.number, a.name);

	return 0;
}
