#pragma once

#include "TwoParameterParametricShape.h"

class Sphere: public TwoParameterParametricShape
{
	float radius;
public:
	Sphere(float radius):radius(radius){}

	Vec3f build(const float& var1, const float& var2) override;
};

