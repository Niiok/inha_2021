#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {

	int num;
	char name[60];
	int score;
	struct Student* next;

} Student;

int problem1();
Student* p1_input(int num, char* name, int score, Student* next);
int p1_print(Student* head);
Student* p1_search(Student* head, char* name);
int p1_free(Student* head_student);
Student* find_biggest_in_smaller(Student* head, Student* bigger_one);


int main()
{
	problem1();

	return 0;
}

int problem1()
{
	Student* head_student = NULL;

	for (int i = 0; i < 3; i++)
		head_student = p1_input(0, 0, 0, head_student);
	//puts("stage 1");

	p1_print(head_student);
	//puts("stage 2");

	p1_search(head_student, 0);
	//puts("stage 3");

	p1_free(head_student);

	return 0;
}

Student* p1_input(int num, char* name, int score, Student* next)
{
	char arr[60];

	printf("학생 번호 입력 : ");
	scanf("%d", &num);

	printf("학생 이름 입력 : ");
	scanf("%s", arr);

	printf("학생 점수 입력 : ");
	scanf("%d", &score);
	rewind(stdin);

	Student* new_student = (Student*)malloc(sizeof(Student));
	if (new_student == NULL)
		exit(1);

	new_student->num = num;
	strcpy(new_student->name, arr);
	new_student->score = score;
	new_student->next = next;

	//printf("\n%d %s %d %p\n", new_student->num, new_student->name, new_student->score, new_student->next);

	return new_student;
}

int p1_print(Student* head)
{
	Student* checker = head;
	int student_num = 0;
	Student** student_list = NULL;

	for (; checker != NULL; student_num++)
		checker = checker->next;

	student_list = malloc(sizeof(Student*) * student_num);
	if (student_list == NULL)
		exit(1);

	student_list[0] = find_biggest_in_smaller(head, 0);
	for (int i = 1; i < student_num; i++)
	{
		student_list[i] = find_biggest_in_smaller(head, student_list[i - 1]);
	}

	for (int j = 0; j < student_num; j++)
	{
		p1_search(student_list[j], student_list[j]->name);
		puts("- - - - - - - - - - - - -\n");
	}

	free(student_list);
}


Student* p1_search(Student* head, char* name)
{
	char arr[60] = { 0 };

	if (name == NULL)
	{
		printf("검색할 학생 이름 입력 : ");
		scanf("%s", arr);
		rewind(stdin);
	}
	else
		strcpy(arr, name);


	for (; head != NULL; head = head->next)
	{

		if (!strcmp(head->name, arr))
		{
			printf("%s의 번호 : %d\t", arr, head->num);
			printf("%s의 이름 : %s\t", arr, head->name);
			printf("%s의 성적 : %d\t\n\n  ", arr, head->score);
			break;
		}
	}

	return head;
}


int p1_free(Student* head_student)
{
	Student* next = head_student->next;
	free(head_student);
	if (next != NULL)
		p1_free(next);

	return 0;
}


Student* find_biggest_in_smaller(Student* head, Student* bigger_one)
{
	int bigger_score = 0;
	int next_score = -1;
	Student* next_student = NULL;
	Student* initial_head = head;

	if (bigger_one == NULL)
		bigger_score = 999999;
	else
		bigger_score = bigger_one->score;

	for (; head != NULL; head = head->next)
	{
		int sample_score = head->score;

		if (sample_score < bigger_score)
		{
			if (sample_score > next_score)
			{
				next_score = sample_score;
				next_student = head;
			}
		}
	}

	return next_student;
}