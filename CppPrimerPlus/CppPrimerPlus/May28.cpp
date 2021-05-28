#include "Circle.h"
#include "Rectangle.h"
#include<iostream>
#include<vector>
#include "stack.h"

int problem1();
int problem2();
int problem3();
int hanoi(int max, int i, int from, int to, Stack<int>* columns[3]);
int hanoi_print(int max, Stack<int>* columns[3]);
int other_column(int from, int to);

int main()
{
	problem3();

}

int problem1()
{
	Circle c1(2, 2, 5.5);
	Circle c2(2, 2, 5.5);
	Circle c3(4, 5, 10.5);

	printf("c1 area : %f\n", c1.Area());
	printf("c1 perimeter : %f\n", c1.Perimeter());
	printf("c1.contains(3,3) : %s\n", c1.Contains(3, 3) ? "true" : "false");
	printf("c1.contains(c2) : %s\n", c1.Contains(c2) ? "true" : "false");
	printf("c1.overlaps(c3) : %s\n", c1.Overlaps(c3) ? "true" : "false");


	return 0;
}

int problem2()
{
	Rectangle r1(2, 2, 5.5, 4.9);
	Rectangle r2(5, 5, 10.5, 3.2);
	Rectangle r3(3, 5, 2.3, 5.4);

	printf("r1 area : %f\n", r1.Area());
	printf("r1 perimeter : %f\n", r1.Perimeter());
	printf("r1.contains(3,3) : %s\n", r1.Contains(3, 3) ? "true" : "false");
	printf("r1.contains(r2) : %s\n", r1.Contained(r2) ? "true" : "false");
	printf("r1.overlaps(r3) : %s\n", r1.Overlaps(r3) ? "true" : "false");

	return 0;
}

int problem3()
{
	while (1)
	{
		int plate_number = 0;

		std::cout << "하노이탑 높이를 입력하시오 : ";
		std::cin >> plate_number;

		Stack<int>column1 = Stack<int>(plate_number);
		Stack<int>column2 = Stack<int>(plate_number);
		Stack<int>column3 = Stack<int>(plate_number);

		Stack<int>* columns[3] = { &column1, &column2, &column3 };

		for (int i = plate_number; i > 0; --i)
			columns[0]->Push(i);

		hanoi_print(plate_number, columns);
		hanoi(plate_number, plate_number, 0, 2, columns);


		std::cout << (1 << plate_number) - 1 << "번 옮기면 된다.\n\n\n";

		// N(k) = N(k-1) * 2 + 1
		// N(1) = 1
		// N(2) = 1 * 2 + 1 = 3
		// N(3) = 3 * 2 + 1 = 7
		// N(4) = 7 * 2 + 1 = 15
		// ...
	}
	return 0;
}

int hanoi(int max, int i, int from, int to, Stack<int>* columns[3])
{
	if (i == 0)
		return 0;

	if (columns[from]->Peek() != i)
			hanoi(max, i - 1, from, other_column(from, to), columns);
	
	{
		int num = 0;
		int* plate = &num;

		columns[from]->Pop(plate);
		columns[to]->Push(*plate);
		hanoi_print(max, columns);
	}

	hanoi(max, i - 1, other_column(from, to), to, columns);

	return 0;
}

int hanoi_print(int max, Stack<int>* columns[3])
{
	static int count = 0;

	printf("\n");
	for (int i = max-1; i >= 0; --i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("\t[");

			int num;
			num = columns[j]->getByIndex(i);
			if (num == 0)
				printf(" ");
			else
				printf("%d", num);

			printf("]");
		}
		printf("\n");
	}

	printf("\t A\t B\t C\n %d -----------------------------\n\n", count);
	count++;

	if (columns[0]->getByIndex(0) == 0 && columns[1]->getByIndex(0) == 0)
		count = 0;

	return 0;
}

int other_column(int from, int to)
{
	if (from == 0)
		return (to == 1 ? 2 : 1);
	else if (from == 1)
		return (to == 2 ? 0 : 2);
	else if (from == 2)
		return (to == 0 ? 1 : 0);
	else
		return -1;
}