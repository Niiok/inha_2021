#include "CCircle.h"

Geometry::CCircle::CCircle() : CGeometry()
{
}
Geometry::CCircle::CCircle(int x, int y) : CGeometry(x, y)
{
	radius_ = (rand() % 90) + 10;
}
Geometry::CCircle::~CCircle()
{

}

void Geometry::CCircle::Collision(std::vector<Geometry::CGeometry*>& list)
{

	// other object
	for (auto i : list)
	{
		if (i == this)
			continue;

		double over_time = WillOverlap(*i);
		if (over_time > 0.0)
		{
			float temp_x = this->vec_x_;
			float temp_y = this->vec_y_;
			
			//center_x_ += vec_x_ * over_time;
			//center_y_ += vec_y_ * over_time;

			this->vec_x_ = i->get_vec_x_();
			this->vec_y_ = i->get_vec_y_();

			//i->center_x_ += i->vec_x_ * over_time;
			//i->center_y_ += i->vec_y_ * over_time;

			i->set_vec_x_(temp_x);
			i->set_vec_y_(temp_y);
		}
	}

	//boundary
	if (center_y_ - radius_ + NextMoveY() < 0)
	{
		vec_y_ *= -1;
		center_y_ += 10;
	}
	if (center_y_ + radius_ + NextMoveY() > client_rect_.bottom - client_rect_.top)
	{
		vec_y_ *= -1;
		center_y_ -= 10;
	}


	if (center_x_ - radius_ + NextMoveX() < 0)
	{
		vec_x_ *= -1;
		center_x_ += 10;
	}
	if (center_x_ + radius_ + NextMoveX() > client_rect_.right - client_rect_.left)
	{
		vec_x_ *= -1;
		center_x_ -= 10;
	}

}
void Geometry::CCircle::Draw()
{
	hdc_ = GetDC(hWnd_);

	Ellipse(hdc_,
		center_x_ - radius_,
		center_y_ - radius_,
		center_x_ + radius_,
		center_y_ + radius_);

	ReleaseDC(hWnd_, hdc_);
}
double Geometry::CCircle::WillOverlap(Geometry::CGeometry& another) const
{
	float distance_max = MaxDistance() + another.MaxDistance();
	distance_max *= distance_max;
	float distance_x = center_x_ + NextMoveX() - (another.get_center_x_() + another.NextMoveX());
	distance_x *= distance_x;
	float distance_y = center_y_ + NextMoveY() - (another.get_center_y_() + another.NextMoveY());
	distance_y *= distance_y;

	if(distance_max > distance_x + distance_y)
		return 1;

	return 0;
}
float Geometry::CCircle::MaxDistance() const
{
	return radius_;
}