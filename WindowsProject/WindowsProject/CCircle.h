#pragma once
#include "CObject.h"

namespace Geometry {

	class CCircle : public CObject
	{
	public:
		CCircle();
		CCircle(int x, int y);
		~CCircle();
		
	private:
		double radius_;

	public:
		virtual void Update(std::vector<Geometry::CObject*>&) override;
		virtual void Collision(std::vector<Geometry::CObject*>&) override;
		virtual void Draw() override;
		virtual double WillOverlap(CObject&) override;
	};


}