#include "Sphere.h"
#include "Constants.h"
#include <iostream>

#include <math.h>

Vec3f Sphere::build(const float& var1, const float& var2)
{
	float theta = MAP(var1, PARM_MIN, PARM_MAX, 0.f, 360.f);
	float phi = MAP(var2, PARM_MIN, PARM_MAX, 0.f, 180.f);

	float x = (radius * sinf(RADIAN(theta)) * cosf(RADIAN(phi)));
	float y = (radius * sinf(RADIAN(theta)) * sinf(RADIAN(phi)));
	float z = (radius * cosf(RADIAN(theta)));

	Vec3f point(x, y, z);

	return applyTransformation(point);
}
