#include "CGeometry.h"

Geometry::CGeometry::CGeometry()
{
	hWnd_ = GetActiveWindow();
}
Geometry::CGeometry::CGeometry(int x, int y)
{
	hWnd_ = GetActiveWindow();
	center_x_ = x;
	center_y_ = y;

	float dir = rand();
	vec_x_ = cosf(dir) * ((int)dir % 900 + 100);
	vec_y_ = sinf(dir) * ((int)dir % 900 + 100);
}
Geometry::CGeometry::~CGeometry()
{

}

void Geometry::CGeometry::Update(std::vector<Geometry::CGeometry*>& list)
{
	GetClientRect(hWnd_, &client_rect_);
	Collision(list);

	center_x_ += NextMoveX();
	center_y_ += NextMoveY();
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
double Geometry::CGeometry::WillOverlap(Geometry::CGeometry& another) const 
{
	return false;
}

float Geometry::CGeometry::MaxDistance() const
{
	return 0;
}
