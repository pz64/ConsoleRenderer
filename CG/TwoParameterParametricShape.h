#pragma once

#include "ParametricShape.h"

class TwoParameterParametricShape: public ParametricShape
{
public:
	virtual Vec3f build(const float &var1, const float &var2) = 0;
};

