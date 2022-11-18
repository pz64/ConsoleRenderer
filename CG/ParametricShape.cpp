#include "ParametricShape.h"
#include "Constants.h"

void ParametricShape::transform(const Vec3f &translation, const Vec3f &rotation, const Vec3f &rotationPivot)
{
	this->translation = translation;
	this->rotation = rotation; 
	this->rotationPivot = translation + rotationPivot;

	rotationMatrix = Matrix44f(
		cos(rotation.y) * cos(rotation.z),
		sin(rotation.x) * sin(rotation.y) * cos(rotation.z) - cos(rotation.x) * sin(rotation.z),
		cos(rotation.x) * sin(rotation.y) * cos(rotation.z) + sin(rotation.x) * sin(rotation.z),
		0.f,

		cos(rotation.y) * sin(rotation.z),
		sin(rotation.x) * sin(rotation.y) * sin(rotation.z) + cos(rotation.x) * cos(rotation.z),
		cos(rotation.x) * sin(rotation.y) * sin(rotation.z) - sin(rotation.x) * cos(rotation.z),
		0.f,

		-sin(rotation.y),
		sin(rotation.x) * cos(rotation.y),
		cos(rotation.x) * cos(rotation.y),
		0.f,

		0.f,
		0.f,
		0.f,
		0.f
	);
}

Vec3f ParametricShape::applyTransformation(Vec3f point)
{
	Vec3f result;

	rotationMatrix.multDirMatrix(point + translation - rotationPivot, result);

	return result + rotationPivot;
}
