#pragma once
#include "CGeometry.h"
#include "CRect.h"

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

		// Collisions
		virtual double OverlapWith(CGeometry*) const override;
		virtual double OverlapWith(const CCircle*) const;
		virtual double CollideWith(CGeometry*) override;
		virtual double CollideWith(CCircle*);

		virtual float MaxDistance() const override;
		virtual float NextMoveX() const override { return vec_.x / radius_; }
		virtual float NextMoveY() const override { return vec_.y / radius_; }

		// access
		inline float get_radius_() const { return radius_; }
	};


}