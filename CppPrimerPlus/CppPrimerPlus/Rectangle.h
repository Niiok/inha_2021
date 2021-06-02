#ifndef ___RECTANGLE_H___
#define ___RECTANGLE_H___

#define _USE_MATH_DEFINES

#include"Geometric.h"

class Rectangle  : public Geometric {
public:
	Rectangle();
	Rectangle(double origin_x, double origin_y, double width, double height);

protected:
	double width_ = 1;
	double height_ = 1;

public:
	double get_width() const;
	double get_height() const;
	int set_width(double val);
	int set_height(double val);
	int Contains(double x, double y) const;
	int Contains(const Rectangle& rect) const;
	int Contained(const Rectangle& rect) const;
	int Overlaps(const Rectangle& rect) const;

protected:
	virtual void reset_area_perimeter();
};

#endif // !___RECTANGLE_H___
