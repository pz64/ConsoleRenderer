#pragma once

#include "ParametricShape.h"

class OneParameterParametricShape : public ParametricShape
{
public:
	virtual Vec3f build(const float& var) = 0;
};
