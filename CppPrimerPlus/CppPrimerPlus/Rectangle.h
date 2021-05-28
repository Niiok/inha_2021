#ifndef ___RECTANGLE_H___
#define ___RECTANGLE_H___

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

class Rectangle {
public:
	Rectangle();
	Rectangle(double origin_x, double origin_y, double width, double height);

private:
	XYZ origin_ = { 0,0,0 };
	double width_ = 1;
	double height_ = 1;
	double area_ = width_ * height_;
	double perimeter_ = 2 * (width_ + height_);

public:
	double get_origin_x() const;
	double get_origin_y() const;
	double get_origin_z() const;
	int set_origin_x(double val);
	int set_origin_y(double val);
	int set_origin_z(double val);
	double get_width() const;
	double get_height() const;
	int set_width(double val);
	int set_height(double val);
	double Area() const;
	double Perimeter() const;
	int Contains(double x, double y) const;
	int Contains(const Rectangle& rect) const;
	int Contained(const Rectangle& rect) const;
	int Overlaps(const Rectangle& rect) const;
};

#endif // !___RECTANGLE_H___
