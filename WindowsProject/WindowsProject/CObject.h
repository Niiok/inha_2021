#pragma once
#include <time.h>
#include <windows.h>
#include <vector>

namespace Geometry {

	class CObject
	{
	public:
		CObject();
		CObject(int x, int y);
		~CObject();

	protected:
		HWND hWnd_;
		HDC hdc_;
		double center_x_;
		double center_y_;
		double vec_x_;
		double vec_y_;
		double cur_vec_x_;
		double cur_vec_y_;
		RECT client_rect_;

	public:
		virtual void Update(std::vector<Geometry::CObject*>&);
		virtual void Collision(std::vector<Geometry::CObject*>&);
		virtual void Draw();
		virtual double WillOverlap(CObject&);
	};


}