#include "CGeometry.h"

Geometry::CGeometry::CGeometry()
{
	hWnd_ = GetActiveWindow();
}
Geometry::CGeometry::CGeometry(int x, int y)
{
	hWnd_ = GetActiveWindow();
	center_.x = x;
	center_.y = y;

	float dir = rand();
	vec_.x = cosf(dir) * ((int)dir % 900 + 100);
	vec_.y = sinf(dir) * ((int)dir % 900 + 100);
}
Geometry::CGeometry::~CGeometry()
{

}

void Geometry::CGeometry::Update(std::vector<Geometry::CGeometry*>& list)
{
	GetClientRect(hWnd_, &client_rect_);
	Collision(list);

	center_.x += NextMoveX();
	center_.y += NextMoveY();
	spin_ = spin_ + (NextMoveX() + NextMoveY()) * M_PI / 360 ;
	while (spin_ > M_PI * 2)
		spin_ -= (M_PI * 2);
}
void Geometry::CGeometry::Collision(std::vector<Geometry::CGeometry*>&)
{

}

void Geometry::CGeometry::Draw() 
{
	hdc_ = GetDC(hWnd_);



	ReleaseDC(hWnd_, hdc_);
}
double Geometry::CGeometry::OverlapWith(Geometry::CGeometry* another) const 
{
	return false;
}
double Geometry::CGeometry::CollideWith(Geometry::CGeometry* another) 
{
	return false;
}


float Geometry::CGeometry::MaxDistance() const
{
	return 0;
}
