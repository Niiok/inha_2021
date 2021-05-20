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

	std::cout << "�߽� : ";
	std::cin >> X >> Y;
	std::cout << "������ : ";
	std::cin >> R;
	std::cout << "����ġ : ";
	std::cin >> x >> y;

	int det = pow(x - X, 2) + pow(y - Y, 2) - pow(R, 2);

	if (det <= 0)
		printf("�� (%d,%d) �� �� ���ο� �ִ�.", x, y);
	else
		printf("�� (%d,%d) �� �� �ܺο� �ִ�.", x, y);

	return 0;
}

int problem2()
{
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0, y1 = 0, y2 = 0, y3 = 0, y4 = 0;
	double a1 = 0, a2 = 0, b1 = 0, b2 = 0;
	double cross_x = 0, cross_y = 0;

	std::cout << "�� 1�� x, y : ";
	std::cin >> x1 >> y1;
	rewind(stdin);
	std::cout << "�� 2�� x, y : ";
	std::cin >> x2 >> y2;
	rewind(stdin);
	std::cout << "�� 3�� x, y : ";
	std::cin >> x3 >> y3;
	rewind(stdin);
	std::cout << "�� 4�� x, y : ";
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
		std::cout << "���� : �� ������ ��ģ��.";
		return 0;
	}
	else if (a1 == a2)
	{
		std::cout << "�Ҵ� : �� ������ �����ϴ�.";
		return 0;
	}

	cross_x = (b2 - b1) / (a1 - a2);
	cross_y = a1 * cross_x + b1;

	if ((cross_x > x1 && cross_x > x2) ||	// x ���� ��
		(cross_x > x3 && cross_x > x4) ||
		(cross_x < x1 && cross_x < x2) ||
		(cross_x < x3 && cross_x < x4) ||
		(cross_y > y1 && cross_y > y2) ||	// y ���� ��
		(cross_y > y3 && cross_y > y4) ||
		(cross_y < y1 && cross_y < y2) ||
		(cross_y < y3 && cross_y < y4)
		)
		std::cout << "�������� ���� ���� ���弱�� �ֽ��ϴ�.\n";


	printf("�������� ( %f , %f ) �̴�.", cross_x, cross_y) ;


	return 0;
}