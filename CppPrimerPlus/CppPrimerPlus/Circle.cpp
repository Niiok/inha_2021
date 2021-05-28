#include "Circle.h"


Circle::Circle() {}

Circle::Circle(double origin_x, double origin_y, double radius)
	: origin_{ origin_x, origin_y, 0 }, radius_{ radius }
{
	area_ = radius * radius * M_PI;
	perimeter_ = radius * 2 * M_PI;
}

double Circle::get_origin_x() const
{
	return origin_.x;
}
double Circle::get_origin_y() const
{
	return origin_.y;
}



double Circle::get_radius() const
{
	return radius_;
}



double Circle::Area() const
{
	return area_;
}
double Circle::Perimeter() const
{
	return perimeter_;
}



int Circle::Contains(double x, double y) const
{
	double det = pow(x - origin_.x, 2) + pow(y - origin_.y, 2);
	double rad = radius_ * radius_;

	if (det <= rad)
		return 1;
	else
		return 0;
}

int Circle::Contains(const Circle& circle) const
{
	double diff_x = pow(origin_.x - circle.get_origin_x(), 2);
	double diff_y = pow(origin_.y - circle.get_origin_y(), 2);
	double det = diff_x + diff_y + pow(circle.get_radius(), 2);
	double rad = radius_ * radius_;

	if (det <= rad)
		return 1;
	else
		return 0;

}

int Circle::Overlaps(const Circle& circle) const
{
	double diff_x = pow(origin_.x - circle.get_origin_x(), 2);
	double diff_y = pow(origin_.y - circle.get_origin_y(), 2);
	double det = diff_x + diff_y;
	double rad2 = radius_ * radius_ + pow(circle.get_radius(), 2);

	if (det <= rad2)
		return 1;
	else
		return 0;
}
