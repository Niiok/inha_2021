#include "CCircle.h"

Geometry::CCircle::CCircle()
{
}
Geometry::CCircle::CCircle(int x, int y)
{
	radius_ = (rand() % 90) + 10;
	hWnd_ = GetActiveWindow();
	center_x_ = x;
	center_y_ = y;

	double dir = rand();
	vec_x_ = cos(dir) * ((int)dir%500);
	vec_y_ = sin(dir) * ((int)dir%500);
}
Geometry::CCircle::~CCircle()
{

}

void Geometry::CCircle::Update(std::vector<Geometry::CObject*>& list)
{
	GetClientRect(hWnd_, &client_rect_);
	cur_vec_x_ = vec_x_;
	cur_vec_y_ = vec_y_;
	Collision(list);
	center_x_ += cur_vec_x_;
	center_y_ += cur_vec_y_;
	//Draw();
}
void Geometry::CCircle::Collision(std::vector<Geometry::CObject*>& list)
{
	//boundary
	if ((center_y_ - radius_ + (vec_y_ / radius_) > 0) && (center_y_ + radius_ + (vec_y_ / radius_) < client_rect_.bottom - client_rect_.top));
	else	
	vec_y_ *= -1;

	if ((center_x_ - radius_ + (vec_x_ / radius_) > 0) && (center_x_ + radius_ + (vec_x_ / radius_) < client_rect_.right - client_rect_.left));
	else
		vec_x_ *= -1;

	// other circle
	for (auto i : (std::vector<Geometry::CCircle*>&)list)
	{
		if (i == this)
			continue;

		double over_time = this->WillOverlap(*i);
		if (over_time)
		{
			double temp_x = this->vec_x_;
			double temp_y = this->vec_y_;
			
			center_x_ += vec_x_ * over_time;
			center_y_ += vec_y_ * over_time;

			this->vec_x_ = i->vec_x_;
			this->vec_y_ = i->vec_y_;
			i->vec_x_ = temp_x;
			i->vec_y_ = temp_y;


		}
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
double Geometry::CCircle::WillOverlap(Geometry::CObject& another)
{
	

	return 0;
}