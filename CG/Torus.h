#pragma once

#include "TwoParameterParametricShape.h"

class Torus: public TwoParameterParametricShape
{
	float radius;
	float tubeRadius;
public:
	Torus(float radius, float tubeRadius) :radius(radius), tubeRadius(tubeRadius){}

	Vec3f build(const float& var1, const float& var2) override;


};

