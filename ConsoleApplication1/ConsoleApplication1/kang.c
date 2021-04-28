#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
typedef struct student SS;

struct student {
	int num;
	char name[20];
	double grade;
	struct list *next;
};

int check_num(SS *current, int num) {
	while (current != NULL && current->next != NULL) {
		if (current->num == num) return 0;
		current = current->next;
	}
	return 1;
}

void sort_data(SS *head, SS *current) {
	SS *left;
	left = head;
	while (current != NULL) {
		if (left->grade > current->grade) {
			left = left->next;
		}
		else {
			current->next = left->next;
			left->next = current;
			break;
		}
	}
}

int input_data(SS *head) {
	int num; char name[20]; double grade;
	int check = 1, sort;
	SS *current;
	current = head;

	while (1) {
		current = (SS*)malloc(sizeof(SS));
		if (current == NULL) {
			printf("동적할당 실패\n");
			exit(1);
		}
		memset(current, 0, sizeof(SS));

		printf("학생 데이터 입력 (학번:0 입력하면 종료)\n");
		while (check = 1) {
			check = 1;
			printf("학번 : ");
			scanf("%d", &num);
			check = check_num(head, num);
			if (num == 0) return 0;
			else if (check == 0) printf("학번 중복 불가능합니다\n");
			else {
				current->num = num;
				break;
			}
		}
		printf("이름 : ");
		scanf("%s", &(current->name));
		printf("학점 : ");
		scanf("%lf", &(current->grade));
		sort_data(head, current);
	}
}

void print_data(SS *current) {
	printf("  학번   이름   성적\n");
	while (current != NULL) {
		printf("%5d%7s%7.1lf\n", current->num, current->name, current->grade);
		current = current->next;
	}
}

void search_data(SS *current) {
	char name[20];
	int num = 1;
	printf("검색할 학생 이름 : ");
	scanf("%s", name);
	printf("   학번   이름   성적\n");
	while (current != NULL && current->next != NULL) {
		if (strcmp(current->name, name) == 0) {
			printf("%d%5d%7s%7.1lf\n", num, current->num, current->name, current->grade);
			num++;
		}
		current = current->next;
	}
	if (num == 1) printf("학생을 찾을 수 없습니다.\n");
}

int main() {
	int state = 1;
	int i = 1, menu;
	SS* student = (SS*)malloc(sizeof(SS));
	if (student == NULL) {
		printf("동적할당 실패\n");
		exit(1);
	}
	memset(student, 0, sizeof(SS));

	while (1) {
		printf("menu 선택 (1입력 2성적순출력 3검색 4종료)\n");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			input_data(student);
			break;
		case 2:
			print_data(student);
			break;
		case 3:
			search_data(student);
			break;
		case 4:
			return 0;
		}
	}
	free(student);
	return 0;
}