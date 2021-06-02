#include"Circle.h"
#include "Rectangle.h"
#include<iostream>


class MyPoint {

public:
	MyPoint();
	MyPoint(double, double);

private:
	double x_ = 0;
	double y_ = 0;

public:
	double getX() const;
	double getY() const;
	int setX(double value);
	int setY(double value);
	double Distance() const;
	double Distance(const MyPoint&) const;
	static double Distance(const MyPoint&, const MyPoint&);
	int IsIn(const Circle&) const;
	int IsIn(const Rectangle&) const;

	MyPoint operator-(const MyPoint&) const;

};

int problem1(); 
int Algorithm_5_4();
int EightQueens(int queens, int x, int y, int* checks[]);
int PrintEightQueens(int* checks[]);

int main()
{

	Algorithm_5_4();
}

int problem1()
{
	MyPoint point1;
	MyPoint point2(10, 30.5);
	int mode = 0; // 0 = default, 1 = circle, 2 = rectangle

	if (mode == 0)
	{
			std::cout << "distance between two points is : " << MyPoint::Distance(point1, point2);
	}
	else if (mode == 1)
	{
		while (1)
		{
			double x, y, radius;
			std::cin >> x >> y >> radius;
			Circle circle(x, y, radius);
			std::cout << "whether point1 in circle is " << (point1.IsIn(circle) ? "true" : "false") << ".\n";
			std::cout << "whether point2 in circle is " << (point2.IsIn(circle) ? "true" : "false") << ".\n";
		}
	}
	else if (mode == 2)
	{
		while (1)
		{
			double x, y, width, height;
			std::cin >> x >> y >> width >> height;
			Rectangle rect(x, y, width, height);
			std::cout << "whether point1 in rect is " << (point1.IsIn(rect) ? "true" : "false") << ".\n";
			std::cout << "whether point2 in rect is " << (point2.IsIn(rect) ? "true" : "false") << ".\n";
		}
	}
	else
		return -1;

	return 0;
}

MyPoint::MyPoint(){}

MyPoint::MyPoint(double x_val, double y_val) : x_{ x_val }, y_{ y_val } {};

double MyPoint::getX() const
{
	return x_;
}

double MyPoint::getY() const
{
	return y_;
}
int MyPoint::setX(double value)
{
	x_ = value;
	return 0;
}

int MyPoint::setY(double value)
{
	y_ = value;
	return 0;
}

double MyPoint::Distance() const
{
	return sqrt((x_ * x_) + (y_ * y_));
}

double MyPoint::Distance(const MyPoint& ob) const
{
	return (*this - ob).Distance();
}

double MyPoint::Distance(const MyPoint& ob1, const MyPoint& ob2)
{
	return (ob1 - ob2).Distance();
}

int MyPoint::IsIn(const Circle& circle) const
{
	return circle.Contains(x_, y_);
}

int MyPoint::IsIn(const Rectangle& rect) const
{
	return rect.Contains(x_, y_);
}

MyPoint MyPoint::operator-(const MyPoint& ob) const
{
	return MyPoint(this->x_ - ob.getX(), this->y_ - ob.getY());
}




int Algorithm_5_4()
{
	int queen_x[8] = {-9, };
	int queen_y[8] = {-9, };
	int queen_diag1[8] = {-9, };
	int queen_diag2[8] = {-9, };
	int* locations[4] = { queen_x, queen_y, queen_diag1, queen_diag2 };

	memset(queen_x, -9, 8 * sizeof(int));
	memset(queen_y, -9, 8 * sizeof(int));
	memset(queen_diag1, -9, 8 * sizeof(int));
	memset(queen_diag2, -9, 8 * sizeof(int));

	int queens = 8;


	for (int i = 0; i < 8; ++i)
	{
		locations[0][0] = i;
		locations[1][0] = 0;
		locations[2][0] = locations[0][0] - locations[1][0];
		locations[3][0] = locations[0][0] + locations[1][0];

		EightQueens(7, 0, 0, locations);
	}

	return 0;
}


int EightQueens(int queens, int x_start, int y_start, int* locations[])
{
	if (queens == 0)
		PrintEightQueens(locations);
	else
	{
		for (int y = y_start; y < 8; ++y)
		{
			for (int x = 0; x < 8; ++x)
			{
				for (int i = 0; i < 8 - queens; ++i)
				{
					if (locations[0][i] == x)
						break;
					if (locations[1][i] == y)
					{
						++y;
						x = -1;
						break;
					}
					if (locations[2][i] == x - y)
						break;
					if (locations[3][i] == x + y)
						break;
	

					if(i == 7 - queens)
					{
						if (y != i + 1)
							break;

					//PrintEightQueens(locations);
						locations[0][i+1] = x;
						locations[1][i+1] = y;
						locations[2][i+1] = x - y;
						locations[3][i+1] = x + y;

						EightQueens(queens - 1, x, y+1, locations);

						for (int j = 0; j < 4; ++j)
							locations[j][8 - queens] = -9;
					}

				}
			}
		}

		
		
	}

	return 0;
}

int PrintEightQueens(int* locations[])
{
	static int count = 1;

	for (int y = 0; y < 8; ++y)
	{
		printf("   ");
		for (int x = 0; x < 8; ++x)
		{
			for (int i = 0; i < 8; ++i)
			{
				if (locations[1][i] == y && locations[0][i] == x)
				{
					printf("бс");
					break;
				}
				else if(i == 7)
					printf("бр");
			}
		}
		printf("\n");
	}

	printf("%d --------------------------\n\n", count);
	++count;

	if (locations[0][0] == -9)
		count = 0;

	return 0;
}