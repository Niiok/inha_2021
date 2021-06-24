#pragma once
#define _USE_MATH_DEFINES

#include <time.h>
#include <windows.h>
#include <vector>
#include <math.h>

namespace Geometry {

	typedef struct XY {
		float x;
		float y;
	} XY;

	class CGeometry
	{
	public:
		CGeometry();
		CGeometry(int x, int y);
		~CGeometry();

	protected:
		HWND hWnd_ = NULL;
		HDC hdc_ = NULL;
		XY center_ = { 0, 0 };
		XY vec_ = { 0, 0 };
		float spin_ = 0;
		//XY cur_vec_ = {0, 0};
		RECT client_rect_ = RECT();

	public:
		virtual void Update(std::vector<Geometry::CGeometry*>&);

		virtual void Collision(std::vector<Geometry::CGeometry*>&) = 0;
		virtual void Draw() = 0;

		virtual double OverlapWith(CGeometry*) const = 0;
		virtual double CollideWith(CGeometry*) = 0;
		virtual float MaxDistance() const = 0;
		virtual float NextMoveX() const = 0;
		virtual float NextMoveY() const = 0;

		// access
		inline XY get_vec_() const { return vec_; }
		inline XY get_center_() const {return center_;}
		inline void set_vec_x_(float val) { vec_.x = val; }
		inline void set_vec_y_(float val) { vec_.y = val; }
		inline void set_center_x_(float val) {center_.x = val;}
		inline void set_center_y_(float val) {center_.y = val;}
	};


}