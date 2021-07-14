#include "GalsObject.h"


floatXY OverlapLine(
	floatXY p1, floatXY p2,
	floatXY p3, floatXY p4)
{
	// p1 = line 1's source
	// p2 = line 1's destination
	// p3 = line 2's source
	// p4 = line 2's destination

	float denominator =		// (x1-x2)(y3-y4)-(y1-y2)(x3-x4)
		(p1.x - p2.x) * (p3.y - p4.y)
		- (p1.y - p2.y) * (p3.x - p4.x);

	if (denominator == 0)
		return { -1,-1 };

	float t =
		((p1.x - p3.x)*(p3.y - p4.y)
			- (p1.y - p3.y)*(p3.x - p4.x))
		/ denominator;
	if (t > 1.0 || t <= 0.0)
		return { -1, -1 };

	float u =
		((p2.x - p1.x)*(p1.y - p3.y)
			- (p2.y - p1.y)*(p1.x - p3.x))
		/ denominator;
	if (u >= 1.0 || u < 0.0)
		return { -1, -1 };


	float inter_x = p1.x + t * (p2.x - p1.x);
	float inter_y = p1.y + t * (p2.y - p1.y);

	return { inter_x, inter_y };
}

