#include "Torus.h"
#include "Constants.h"

#include <math.h>

Vec3f Torus::build(const float& var1, const float& var2)
{
	float theta = MAP(var1, PARM_MIN, PARM_MAX, 0.f, 360.f);
	float phi = MAP(var2, PARM_MIN, PARM_MAX, 0.f, 360.f);

	float x = ((radius + tubeRadius * cosf(RADIAN(theta))) * cosf(RADIAN(phi)));
	float y = ((radius + tubeRadius * cosf(RADIAN(theta))) * sinf(RADIAN(phi)));
	float z = (tubeRadius * sinf(RADIAN(theta)));

	Vec3f point(x , y, z);

	return applyTransformation(point);
}
