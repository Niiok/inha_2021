#include "Rectangle.h"


Rectangle::Rectangle() {}

Rectangle::Rectangle(double origin_x, double origin_y, double width, double height)
	:  width_{ width }, height_{ height }
{
	origin_ = { origin_x, origin_y, 0 };
	reset_area_perimeter();
}

void Rectangle::reset_area_perimeter()
{
	area_ = width_ * height_;
	perimeter_ = 2 * (width_ + height_);
}



double Rectangle::get_width() const
{
	return width_;
}
double Rectangle::get_height() const
{
	return height_;
}
int Rectangle::set_width(double val)
{
	width_ = abs(val);
	area_ = width_ * height_;
	perimeter_ = 2 * (width_ + height_);

	return 0;
}
int Rectangle::set_height(double val)
{
	height_ = abs(val);
	area_ = width_ * height_;
	perimeter_ = 2 * (width_ + height_);

	return 0;
}



int Rectangle::Contains(double x, double y) const
{
	double edge_left = origin_.x - width_/2;
	double edge_right = origin_.x + width_/2;
	double edge_bottom = origin_.y - height_/2;
	double edge_top = origin_.y + height_/2;
	
	if (x <= edge_right && x >= edge_left && y <= edge_top && y >= edge_bottom)
		return 1;
	else 
		return 0;
}

int Rectangle::Contains(const Rectangle& rect) const
{
	double diff_x = rect.get_origin_x() - origin_.x;		// positive = sq1 left sq2, 	negative = sq1 right sq2
	double diff_y = rect.get_origin_y() - origin_.y;		// positive = sq1 under sq2,	negative = sq1 above sq2

	if (abs(diff_x) + rect.get_width()/2 < width_/2 &&
		abs(diff_y) + rect.get_height()/2 < height_/2 &&
		origin_.z == rect.get_origin_z())	// depends on how z works
		return 1;
	else 
		return 0;
}

int Rectangle::Contained(const Rectangle& rect) const
{
	double diff_x = rect.get_origin_x() - origin_.x;		// positive = sq1 left sq2, 	negative = sq1 right sq2
	double diff_y = rect.get_origin_y() - origin_.y;		// positive = sq1 under sq2,	negative = sq1 above sq2

	if (abs(diff_x) + width_/2 < rect.get_width()/2 &&
		abs(diff_y) + height_/2 < rect.get_height()/2 &&
		origin_.z == rect.get_origin_z())	// depends on how z works
		return 1;
	else 
		return 0;
}

int Rectangle::Overlaps(const Rectangle& rect) const
{
	double diff_x = rect.get_origin_x() - origin_.x;		// positive = sq1 left sq2, 	negative = sq1 right sq2
	double diff_y = rect.get_origin_y() - origin_.y;		// positive = sq1 under sq2,	negative = sq1 above sq2

	if (abs(diff_x) <= width_/2 + rect.get_width()/2 &&
		abs(diff_y) <= height_/2 + rect.get_height()/2 &&
		origin_.z == rect.get_origin_z())	// depends on how z works
		return 1;
	else
		return 0;
}
