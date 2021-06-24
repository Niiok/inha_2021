#pragma once
#include "CCircle.h"

namespace Geometry {

	class CStar : public CCircle
	{
	public:
		CStar();
		CStar(int x, int y);
		~CStar();


	public:
		virtual void Draw() override;
		void DrawStar(HDC hdc, COORD center, INT radius, INT wings);
	};

}

void DrawStar(HDC hdc, COORD center, INT radius, INT wings);