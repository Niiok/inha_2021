#include "CStar.h"


Geometry::CStar::CStar() : CCircle()
{
}
Geometry::CStar::CStar(int x, int y) : CCircle(x, y)
{
	
}
Geometry::CStar::~CStar()
{

}

void Geometry::CStar::Draw()
{
	hdc_ = GetDC(hWnd_);

	DrawStar(hdc_, { (SHORT)center_.x, (SHORT)center_.y }, radius_, 5);

	ReleaseDC(hWnd_, hdc_);
}

void Geometry::CStar::DrawStar(HDC hdc, COORD center, INT radius, INT wings)
{
	if (wings < 4 || 360 % wings != 0)
		return;

	const double GOLDEN_RATIO = 1.61803398875;
	const double DTR = M_PI / 180;	// degree to radian
	const INT degree = 360 / wings;

	POINT* points = (POINT*)malloc(sizeof(POINT) * wings * 2);

	// outer points
	POINT outer = { 0, -radius};
	for (int i = 0; i < wings; ++i)
	{
		INT x = outer.x*cos(DTR * degree * i) - outer.y*sin(DTR * degree * i);
		INT y = outer.x*sin(DTR * degree * i) + outer.y*cos(DTR * degree * i);
		points[i * 2] = { x , y };
	}

	// inner points
	double star_half = (1 + GOLDEN_RATIO) / 2;
	double pentagon_half = star_half - 1;
	INT first_x = (points[2].x) * pentagon_half / star_half;
	INT first_y = (points[2].y);
	POINT inner = { first_x, first_y };

	for (int i = 0; i < wings; ++i)
	{
		INT x = inner.x*cos(DTR * degree * i) - inner.y*sin(DTR * degree * i);
		INT y = inner.x*sin(DTR * degree * i) + inner.y*cos(DTR * degree * i);
		points[i * 2 + 1] = { x , y };
	}


	for (int i = 0; i < wings * 2; ++i)
	{
		INT x = points[i].x * cosf(spin_) - points[i].y * sinf(spin_);
		INT y = points[i].y * cosf(spin_) + points[i].x * sinf(spin_);

		points[i] = { x + center.X, y + center.Y };
	}


	Polygon(hdc, points, wings * 2);
	free(points);
}