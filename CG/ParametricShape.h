#pragma once

#include "geometry.h"

class ParametricShape
{
protected:
	Vec3f rotation;
	Vec3f rotationPivot;
	Vec3f translation;
	Matrix44f rotationMatrix;
public:

	virtual void transform(const Vec3f& translation, const Vec3f& rotation, const Vec3f& rotationPivot);

protected:
	Vec3f applyTransformation(Vec3f point);

};

