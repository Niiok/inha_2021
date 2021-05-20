#include <iostream>
#include <vector>
#include <float.h>

int problem1();
int problem2();

int main()
{
	problem2();
}

int problem1()
{
	int x, y, X, Y, R;

	std::cout << "중심 : ";
	std::cin >> X >> Y;
	std::cout << "반지름 : ";
	std::cin >> R;
	std::cout << "점위치 : ";
	std::cin >> x >> y;

	int det = pow(x - X, 2) + pow(y - Y, 2) - pow(R, 2);

	if (det <= 0)
		printf("점 (%d,%d) 는 원 내부에 있다.", x, y);
	else
		printf("점 (%d,%d) 는 원 외부에 있다.", x, y);

	return 0;
}

int problem2()
{
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0, y1 = 0, y2 = 0, y3 = 0, y4 = 0;
	double a1 = 0, a2 = 0, b1 = 0, b2 = 0;
	double cross_x = 0, cross_y = 0;

	std::cout << "점 1의 x, y : ";
	std::cin >> x1 >> y1;
	rewind(stdin);
	std::cout << "점 2의 x, y : ";
	std::cin >> x2 >> y2;
	rewind(stdin);
	std::cout << "점 3의 x, y : ";
	std::cin >> x3 >> y3;
	rewind(stdin);
	std::cout << "점 4의 x, y : ";
	std::cin >> x4 >> y4;

	if (y1 - y2 == 0)
		a1 = DBL_MAX/1.0e+3;
	else
	a1 = (x1 - x2) / (y1 - y2);

	if (y3 - y4 == 0)
		a2 = DBL_MAX/1.0e+3;
	else
	a2 = (x3 - x4) / (y3 - y4);

	b1 = y1 - a1 * x1;
	b2 = y3 - a2 * x3;

	if (a1 == a2 && b1 == b2)
	{
		std::cout << "부정 : 두 직선은 겹친다.";
		return 0;
	}
	else if (a1 == a2)
	{
		std::cout << "불능 : 두 직선은 평행하다.";
		return 0;
	}

	cross_x = (b2 - b1) / (a1 - a2);
	cross_y = a1 * cross_x + b1;

	if ((cross_x > x1 && cross_x > x2) ||	// x 범위 밖
		(cross_x > x3 && cross_x > x4) ||
		(cross_x < x1 && cross_x < x2) ||
		(cross_x < x3 && cross_x < x4) ||
		(cross_y > y1 && cross_y > y2) ||	// y 범위 밖
		(cross_y > y3 && cross_y > y4) ||
		(cross_y < y1 && cross_y < y2) ||
		(cross_y < y3 && cross_y < y4)
		)
		std::cout << "교차점이 선분 밖인 연장선에 있습니다.\n";


	printf("교차점은 ( %f , %f ) 이다.", cross_x, cross_y) ;


	return 0;
}