#ifndef ___GEOMETRIC_H___
#define ___GEOMETRIC_H___

#include<cmath>

#ifndef ___XYZ___
#define ___XYZ___
struct XYZ {
	double x = 0;
	double y = 0;
	double z = 0;
};
#endif


class Geometric {

protected:
	XYZ origin_ = { 0,0,0 };
	double area_ = 0;
	double perimeter_ = 0;

public:
	Geometric() {}
	virtual ~Geometric() = 0 {}

	inline double get_origin_x() const	{ return origin_.x; }
	inline double get_origin_y() const	{ return origin_.y; }
	inline double get_origin_z() const	{ return origin_.z; }
	virtual inline int set_origin_x(double val)	{ origin_.x = val;	return 0; }
	virtual inline int set_origin_y(double val)	{ origin_.y = val;	return 0; }
	virtual inline int set_origin_z(double val) { origin_.z = val;	return 0; }

	inline double Area() const { return area_; }
	inline double Perimeter() const {return perimeter_; }

protected:
	virtual void reset_area_perimeter() = 0;
};

#endif
