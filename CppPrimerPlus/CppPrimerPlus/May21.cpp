#include <iostream>
#include <vector>
#include<time.h>

struct Square {
	double x;
	double y;
	double width;
	double height;
};

struct Circle {
	double x;
	double y;
	double radius;
};

enum Relation {
	Relation_1_Inside_2,
	Relation_2_Inside_1,
	Relation_Contact,
	Relation_Outside
};

int problem1();
int problem2();
int SquareCheck(Square sq1, Square sq2);
int CircleCheck(Circle c1, Circle c2);

int c8q5();
template<typename T> T max5(T arr[]);
template<typename T> T maxn(T arr[], size_t size);
template<> char* maxn<char*>(char* arr[], size_t size);
int c8q6();

int problem3();
int problem4();

int main()
{
	problem3();
}

int problem1()
{
	using namespace std;

	Square sq1;
	Square sq2;

	cout << "첫번째 사각형 x,y,width,height 입력 : ";
	cin >> sq1.x >> sq1.y >> sq1.width >> sq1.height;
	
	cout << "두번째 사각형 x,y,width,height 입력 : ";
	cin >> sq2.x >> sq2.y >> sq2.width >> sq2.height;

	int square_relation = SquareCheck(sq1, sq2);

	switch (square_relation)
	{
	case Relation_Contact:
		cout << "첫번째 사각형과 두번째 사각형은 겹친다.\n";
		break;

	case Relation_1_Inside_2:
		cout << "첫번째 사각형은 두번째 사각형의 내부에 있다.\n";
		break;
	
	case Relation_2_Inside_1:
		cout << "두번째 사각형은 첫번째 사각형의 내부에 있다.\n";
		break;

	case Relation_Outside:
		cout << "첫번째 사각형과 두번째 사각형은 겹치지 않는다.\n";
		break;

	default:
		cout << "unknown case\n";
		break;
	}

	return 0;
}

int SquareCheck(Square sq1, Square sq2)
{
	sq1.height = abs(sq1.height);
	sq1.width = abs(sq1.width);
	sq2.height = abs(sq2.height);
	sq2.width = abs(sq2.width);

	double rel_x = sq2.x - sq1.x;		// positive = sq1 left sq2, 	negative = sq1 right sq2
	double rel_y = sq2.y - sq1.y;		// positive = sq1 under sq2,	negative = sq1 above sq2

	if (abs(rel_x) > sq1.width + sq2.width || abs(rel_y) > sq1.height + sq2.height)
	{
		return Relation_Outside;
	}
	else if (abs(rel_x) + sq1.width < sq2.width && abs(rel_y) + sq1.height < sq2.height)
	{
		return Relation_1_Inside_2;
	}
	else if (abs(rel_x) + sq2.width < sq1.width && abs(rel_y) + sq2.height < sq1.height)
	{
		return Relation_2_Inside_1;
	}
	else if (abs(rel_x) <= sq1.width + sq2.width && abs(rel_y) <= sq1.height + sq2.height)
	{
		return Relation_Contact;
	}

	return -1;
}


int problem2()
{
	using namespace std;

	Circle c1;
	Circle c2;

	cout << "첫번째 원 x,y,radius 입력 : ";
	cin >> c1.x >> c1.y >> c1.radius;
	
	cout << "두번째 원 x,y,radius 입력 : ";
	cin >> c2.x >> c2.y >> c2.radius;

	int circle_relation = CircleCheck(c1, c2);


	switch (circle_relation)
	{
	case Relation_Contact:
		cout << "첫번째 원 두번째 원은 겹친다.\n";
		break;

	case Relation_1_Inside_2:
		cout << "첫번째 원은 두번째 원의 내부에 있다.\n";
		break;

	case Relation_2_Inside_1:
		cout << "두번째 원은 첫번째 원의 내부에 있다.\n";
		break;

	case Relation_Outside:
		cout << "첫번째 원과 두번째 원은 겹치지 않는다.\n";
		break;

	default:
		cout << "unknown case\n";
		break;
	}

	return 0;
}

int CircleCheck(Circle c1, Circle c2)
{
	c1.radius = abs(c1.radius);
	c2.radius = abs(c2.radius);

	double rel_x = c2.x - c1.x;		// positive = sq1 left sq2, 	negative = sq1 right sq2
	double rel_y = c2.y - c1.y;		// positive = sq1 under sq2,	negative = sq1 above sq2

	if (pow(rel_x, 2) + pow(rel_y, 2) > pow(c1.radius + c2.radius, 2) )
	{
		return Relation_Outside;
	}
	else if (pow(rel_x, 2) + pow(rel_y, 2) + pow(c1.radius, 2) < pow(c2.radius, 2))
	{
		return Relation_1_Inside_2;
	}
	else if (pow(rel_x, 2) + pow(rel_y, 2) + pow(c2.radius, 2) < pow(c1.radius, 2))
	{
		return Relation_2_Inside_1;
	}
	else if (pow(rel_x, 2) + pow(rel_y, 2) <= pow(c1.radius + c2.radius, 2))
	{
		return Relation_Contact;
	}

	return -1;
}





int c8q5()
{
	using namespace std;

	int arr_int[5] = { 1, 4, 2, 7, 3 };
	double arr_double[5] = { 1.5, 4.5, 2.5, 7.5, 3.5 };

	cout << max5(arr_int) << endl;
	cout << max5(arr_double) << endl;

	return 0;
}

template<typename T> T max5(T arr[])
{
	T max = arr[0];

	for (size_t i = 1; i < 5; ++i)
	{
		if (max < arr[i])
			max = arr[i];
	}

	return max;
}

int c8q6()
{
	using namespace std;

	int arr_int[6] = { 1, 4, 2, 7, 3, -1 };
	double arr_double[4] = { 1.5, 4.5, 2.5, 7.5 };

	char string0[] = "apple";
	char string1[] = "banana";
	char string2[] = "pineapple";
	char string3[] = "grape";
	char string4[] = "juice";
	char* arr_string[5] = { string0, string1, string2, string3, string4 };

	cout << maxn(arr_int, 6) << endl;
	cout << maxn(arr_double, 4) << endl;
	cout << maxn(arr_string, 5) << endl;

	return 0;
}

template<typename T> T maxn(T arr[], size_t size)
{
	T max = arr[0];

	for (size_t i = 1; i < size; ++i)
	{
		if (max < arr[i])
			max = arr[i];
	}

	return max;
}

template<> char* maxn<char*>(char* arr[], size_t size)
{
	char* max = arr[0];
	size_t max_len = strlen(arr[0]);

	for (size_t i = 1; i < size; ++i)
	{
		if (max_len < strlen(arr[i]))
		{
			max = arr[i];
			max_len = strlen(arr[i]);
		}
	}

	return max;
}

