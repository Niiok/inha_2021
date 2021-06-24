#pragma once
#define _USE_MATH_DEFINES

#include <time.h>
#include <windows.h>
#include <vector>
#include <math.h>

namespace Geometry {

	class CGeometry
	{
	public:
		CGeometry();
		CGeometry(int x, int y);
		~CGeometry();

	protected:
		HWND hWnd_ = NULL;
		HDC hdc_ = NULL;
		float center_x_ = 0;
		float center_y_ = 0;
		float vec_x_ = 0;
		float vec_y_ = 0;
		float spin_ = 0;
		//float cur_vec_x_;
		//float cur_vec_y_;
		RECT client_rect_ = RECT();

	public:
		virtual void Update(std::vector<Geometry::CGeometry*>&);
		virtual void Collision(std::vector<Geometry::CGeometry*>&) = 0;
		virtual void Draw() = 0;
		virtual double WillOverlap(CGeometry&) const = 0;
		virtual float MaxDistance() const = 0;
		virtual float NextMoveX() const = 0;
		virtual float NextMoveY() const = 0;

		// access
		inline float get_vec_x_() const { return vec_x_; }
		inline float get_vec_y_() const { return vec_y_; }
		inline float get_center_x_() const {return center_x_;}
		inline float get_center_y_() const {return center_y_;}
		inline void set_vec_x_(float val) { vec_x_ = val; }
		inline void set_vec_y_(float val) { vec_y_ = val; }
		inline void set_center_x_(float val) {center_x_ = val;}
		inline void set_center_y_(float val) {center_y_ = val;}
	};


}