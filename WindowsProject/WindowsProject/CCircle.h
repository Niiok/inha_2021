#pragma once
#include "CGeometry.h"

namespace Geometry {

	class CCircle : public CGeometry
	{
	public:
		CCircle();
		CCircle(int x, int y);
		~CCircle();
		
	protected:
		double radius_;

	public:
		virtual void Collision(std::vector<Geometry::CGeometry*>&) override;
		virtual void Draw() override;
		virtual double WillOverlap(CGeometry&) const override;
		virtual float MaxDistance() const override;
		virtual float NextMoveX() const override { return vec_x_ / radius_; }
		virtual float NextMoveY() const override { return vec_y_ / radius_; }

		// access
		inline float get_radius_() const { return radius_; }
	};


}