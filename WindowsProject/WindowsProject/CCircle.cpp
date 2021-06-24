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

		double over_time = OverlapWith(i);
		if (over_time > 0.0)
		{
			CollideWith(i);
		}
	}

	//boundary
	if (center_.y - radius_ + NextMoveY() < 0)
	{
		vec_.y *= -1;
		center_.y += 10;
	}
	if (center_.y + radius_ + NextMoveY() > client_rect_.bottom - client_rect_.top)
	{
		vec_.y *= -1;
		center_.y -= 10;
	}


	if (center_.x - radius_ + NextMoveX() < 0)
	{
		vec_.x *= -1;
		center_.x += 10;
	}
	if (center_.x + radius_ + NextMoveX() > client_rect_.right - client_rect_.left)
	{
		vec_.x *= -1;
		center_.x -= 10;
	}

}

void Geometry::CCircle::Draw()
{
	hdc_ = GetDC(hWnd_);

	Ellipse(hdc_,
		center_.x - radius_,
		center_.y - radius_,
		center_.x + radius_,
		center_.y + radius_);

	ReleaseDC(hWnd_, hdc_);
}


double Geometry::CCircle::OverlapWith(Geometry::CGeometry* another) const
{
	CCircle* cp = dynamic_cast<CCircle*>(another);
	if (cp != NULL)
		return OverlapWith(cp);

	// rect here

	return -1;
}
double Geometry::CCircle::OverlapWith(const Geometry::CCircle* another) const
{
	float distance_max = MaxDistance() + another->MaxDistance();
	distance_max *= distance_max;
	float distance_x = center_.x + NextMoveX() - (another->get_center_().x + another->NextMoveX());
	distance_x *= distance_x;
	float distance_y = center_.y + NextMoveY() - (another->get_center_().y + another->NextMoveY());
	distance_y *= distance_y;

	if(distance_max > distance_x + distance_y)
		return 1;

	return 0;
}

double Geometry::CCircle::CollideWith(Geometry::CGeometry* another)
{
	CCircle* cp = dynamic_cast<CCircle*>(another);
	if (cp != NULL)
		return CollideWith(cp);

	// rect here

	return -1;
}
double Geometry::CCircle::CollideWith(Geometry::CCircle* another) 
{
	float temp_x = this->vec_.x;
	float temp_y = this->vec_.y;

	//center_.x += vec_.x * over_time;
	//center_.y += vec_.y * over_time;

	this->vec_.x = another->get_vec_().x;
	this->vec_.y = another->get_vec_().y;

	//another->center_.x += i->vec_.x * over_time;
	//another->center_.y += i->vec_.y * over_time;

	another->set_vec_x_(temp_x);
	another->set_vec_y_(temp_y);

	return 0;
}

float Geometry::CCircle::MaxDistance() const
{
	return radius_;
}