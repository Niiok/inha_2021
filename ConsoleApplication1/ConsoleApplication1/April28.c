#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {

	int num;
	char name[60];
	int kor;
	int eng;
	int mat;
	float mean;
	struct Student* next;
	
} Student;

int problem1();
Student* p1_input(Student* next);
int p1_print(Student* head);
Student* p1_search(Student* head, char* name);
int p1_free(Student* head_student);
Student* find_biggest_in_smaller(Student* head, Student* bigger_one);

int problem2();
int best_pic(int* flags, int* worth, int* weight, int max_weight);
int flag_to_worth(int* worth, int item_flag);
int flag_to_weight(int* weight, int item_flag);
void flag_reader(int* worth, int* weight, int item_flag);

int main()
{
	problem2();

	return 0;
}


int problem1()
{
	Student* head_student = NULL;

	for (int i = 0; i < 3; i++)
		head_student = p1_input(head_student);
	//puts("stage 1");

	p1_print(head_student);
	//puts("stage 2");

	p1_search(head_student, 0);
	//puts("stage 3");

	p1_free(head_student);

	return 0;
}

Student* p1_input(Student* next)
{
	int num;
	char arr[60];
	int kor, mat, eng;

	printf("\n  학번 : ");
	scanf("%d", &num);
	rewind(stdin);

	printf("  이름 : ");
	scanf("%s", arr);
	rewind(stdin);

	printf("  국어, 영어, 수학 점수 : ");
	scanf("%d%d%d", &kor, &eng, &mat);
	rewind(stdin);

	Student* new_student = (Student*)malloc(sizeof(Student));
	if (new_student == NULL)
		exit(1);

	new_student->num = num;
	strcpy(new_student->name, arr);
	new_student->kor = kor;
	new_student->eng = eng;
	new_student->mat = mat;
	new_student->mean = ((float)kor + eng + mat) / 3.0;
	new_student->next = next;

	//printf("\n%d %s %d %p\n", new_student->num, new_student->name, new_student->score, new_student->next);

	return new_student;
}

int p1_print(Student* head)
{
	Student* checker = head;
	int student_num = 0;
	Student** student_list = NULL;

	while (checker != NULL)
	{
		student_num++;
		checker = checker->next;
	}

	student_list = (Student**)malloc(sizeof(Student*) * student_num);
	if (student_list == NULL)
		exit(1);


	student_list[0] = find_biggest_in_smaller(head, 0);

	for (int i = 1; i < student_num; i++)
	{
		student_list[i] = find_biggest_in_smaller(head, student_list[i-1]);
	}

	for (int j = 0; j < student_num; j++)
	{
		p1_search(student_list[j], student_list[j]->name);
	}

	free(student_list);
}


Student* p1_search(Student* head, char* name)
{
	char arr[60] = {0};

	if (name == NULL)
	{
		printf("\n\n검색할 학생 이름 입력 : ");
		scanf("%s", arr);
		rewind(stdin);
	}
	else
		strcpy(arr, name);


	for (; head != NULL ; head = head->next)
	{

		if (!strcmp(head->name, arr))
		{
			printf("\n\n%s의 번호 : %-6d\t", arr, head->num);
			printf("%s의 이름 : %-6s\t", arr, head->name);
			printf("%s의 성적 : %-6.2f\t\n  ", arr, head->mean);
			puts("- - - - - - - - - - - - - - - - - - - - - - - - - - -");
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
		bigger_score = bigger_one->mean;

	for (; head != NULL; head = head->next)
	{
		int sample_score = head->mean;

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



	enum Items {
		KAR,		//7, 4
		FRYPAN,		//10, 2
		SCOPE,		//7, 4
		DDOOK,		//6, 6
		SHOTGUN,	//2,10
		MAP,		//3, 5
		TOTAL_ITEMS
	};

int problem2()
{

	int max_weight = 10;

	int worth[TOTAL_ITEMS] = {7, 10, 7, 6, 2, 3};
	int weight[TOTAL_ITEMS] = {4, 2, 4, 6, 10, 5};
	int flags[100] = {-10, };

	memset(flags, -1, 100);

	best_pic(flags, worth, weight, max_weight);

	//printf("%d\n",flag_to_worth(worth, flags[max_weight]));
	flag_reader(worth, weight, flags[max_weight]);

	return 0;
}

int best_pic(int* flags, int* worth, int* weight, int max_weight)
{
	if (flags[max_weight] >= 0 )
		return flags[max_weight];
	else if (max_weight <= 0)
	{
		flags[0] = 0;
		return 0;
	}
	else
	{
		int best_worth = 0;
		int best_flag = 0;

		for (int i = KAR; i < TOTAL_ITEMS; i++)
		{
			int current_worth = worth[i];
			int item_weight = weight[i];
			int extra_weight = max_weight - item_weight;
			int extra_flag = 0;

			//printf("extra : %d\n", extra_weight);
			if (extra_weight < 0)		//아이템 무게 확인
				continue;


			if (flags[extra_weight] < 0)		//여유분 케이스 불러오기
			{
				//printf("call %d\n", extra_weight);
				extra_flag = best_pic(flags, worth, weight, extra_weight);
			}
			else
			{
				extra_flag = flags[extra_weight];
			}

			if (flag_to_worth(worth, extra_flag) > best_worth)
			{
				best_worth = flag_to_worth(worth, extra_flag);
				best_flag = extra_flag;
			}

			if ((extra_flag & (1 << i)) == (1 << i))		//아이템 중복 여부 확인
			{
				continue;
			}

			if (extra_weight - flag_to_weight(weight, extra_flag) < 0)		//여분과 아이템 무게 확인
				continue;


			current_worth += flag_to_worth(worth, flags[extra_weight]);

			if (best_worth < current_worth)
			{
				best_worth = current_worth;
				best_flag = extra_flag | (1 << i);
			}
		}

		//printf("case %d's best worth is %d\n", max_weight, best_worth);
		flags[max_weight] = best_flag;
		return best_flag;
	}
}


int flag_to_worth(int* worth, int item_flag)
{
	int total_worth = 0;

	for (int i = KAR; i < TOTAL_ITEMS; i++)
	{
		if (item_flag % 2 == 1)
			total_worth += worth[i];
		item_flag = item_flag / 2;
	}

	return total_worth;
}


int flag_to_weight(int* weight, int item_flag)
{
	int total_weight = 0;

	for (int i = KAR; i < TOTAL_ITEMS; i++)
	{
		if (item_flag % 2 == 1)
			total_weight += weight[i];
		item_flag = item_flag / 2;
	}

	return total_weight;
}


void flag_reader(int* worth, int* weight, int item_flag)
{
	printf("  이름\t\t중요도\t\t무게\n");

	for (int i = KAR; i < TOTAL_ITEMS; i++)
	{
		if ((item_flag % 2) == 1)
		{
			switch (i)
			{
			case KAR:
				printf("  %8s\t%d\t\t%d\n", "kar98k", worth[KAR], weight[KAR]);
				break;

			case FRYPAN:
				printf("  %8s\t%d\t\t%d\n", "후라이팬", worth[FRYPAN], weight[FRYPAN]);
				break;

			case SCOPE:
				printf("  %8s\t%d\t\t%d\n", "스코프", worth[SCOPE], weight[SCOPE]);
				break;

			case DDOOK:
				printf("  %8s\t%d\t\t%d\n", "뚝배기", worth[DDOOK], weight[DDOOK]);
				break;

			case SHOTGUN:
				printf("  %8s\t%d\t\t%d\n", "샷건", worth[SHOTGUN], weight[SHOTGUN]);
				break;

			case MAP:
				printf("  %8s\t%d\t\t%d\n", "지도", worth[MAP], weight[MAP]);
				break;

			default:
				break;
			}
		}
		item_flag = item_flag / 2;
	}
}

