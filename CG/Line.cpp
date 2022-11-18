#include "Line.h"
#include "Constants.h"

Vec3f Line::build(const float& var)
{
	float t = MAP(var, PARM_MIN, PARM_MAX, 0.f, 1.f);

	float x = start.x + t * (end.x - start.x);
	float y = start.y + t * (end.y - start.y);
	float z = start.z + t * (end.z - start.z);

	Vec3f point(x, y, z);

	return applyTransformation(point);
}
