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
		float center_x_;
		float center_y_;
		float vec_x_;
		float vec_y_;
		float cur_vec_x_;
		float cur_vec_y_;
		RECT client_rect_;

	public:
		virtual void Update(std::vector<Geometry::CObject*>&);
		virtual void Collision(std::vector<Geometry::CObject*>&);
		virtual void Draw();
		virtual double WillOverlap(CObject&);
	};


}