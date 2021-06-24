#pragma once
#include "CGeometry.h"
#include "CCircle.h"

namespace Geometry {

	class CRect : public CGeometry
	{
	public:
		CRect();
		CRect(int x, int y);
		~CRect();

	protected:
		float height_ = 0;
		float width_ = 0;

	public:
		virtual void Collision(std::vector<Geometry::CGeometry*>&) override;
		virtual void Draw() override;

		// Collisions
		virtual double OverlapWith(CGeometry*) const override;
		virtual double OverlapWith(const CRect*) const;
		virtual double OverlapWith(const CCircle*) const;
		virtual double CollideWith(CGeometry*) override;
		virtual double CollideWith(CRect*);
		virtual double CollideWith(CCircle*);

		virtual float MaxDistance() const override;
		virtual float NextMoveX() const override { return vec_.x / (width_ + height_); }
		virtual float NextMoveY() const override { return vec_.y / (width_ + height_); }

		// access
		inline float get_width_() const { return width_; }
		inline float get_height_() const { return height_; }

	};

}