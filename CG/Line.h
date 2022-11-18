#pragma once
#include "OneParameterParametricShape.h"

class Line : public OneParameterParametricShape
{
	Vec3f start;
	Vec3f end;

public:
	Line(Vec3f start, Vec3f end):start(start), end(end) {}
	
	Vec3f build(const float& var) override;

};

