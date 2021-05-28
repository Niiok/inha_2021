#ifndef ___CIRCLE_H___
#define ___CIRCLE_H___

#define _USE_MATH_DEFINES

#include<cmath>

#ifndef ___XYZ___
#define ___XYZ___
struct XYZ {
	double x = 0;
	double y = 0;
	double z = 0;
};
#endif

class Circle {
public:
	Circle();
	Circle(double origin_x, double origin_y, double radius);

private:
	XYZ origin_ = { 0,0,0 };
	double radius_ = 1;
	double area_ = M_PI;
	double perimeter_ = M_PI * 2;

public:
	double get_origin_x() const;
	double get_origin_y() const;
	double get_radius() const;
	double Area() const;
	double Perimeter() const;
	int Contains(double x, double y) const;
	int Contains(const Circle& circle) const;
	int Overlaps(const Circle& circle) const;
};

#endif
