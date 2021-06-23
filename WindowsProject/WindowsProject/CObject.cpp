#include "CObject.h"

Geometry::CObject::CObject()
{
	hWnd_ = GetActiveWindow();
}
Geometry::CObject::CObject(int x, int y)
{
	hWnd_ = GetActiveWindow();
	center_x_ = x;
	center_y_ = y;

	float dir = rand();
	vec_x_ = cosf(dir);
	vec_y_ = sinf(dir);
}
Geometry::CObject::~CObject()
{

}

void Geometry::CObject::Update(std::vector<Geometry::CObject*>& list)
{
	RECT rect;
	GetClientRect(hWnd_, &rect);
	

}
void Geometry::CObject::Collision(std::vector<Geometry::CObject*>&)
{
	
}
void Geometry::CObject::Draw()
{
	hdc_ = GetDC(hWnd_);



	ReleaseDC(hWnd_, hdc_);
}
double Geometry::CObject::WillOverlap(Geometry::CObject& another)
{
	return false;
}
