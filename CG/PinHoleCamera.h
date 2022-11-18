#pragma once
#include "Constants.h"
#include "geometry.h"

class PinHoleCamera
{
	public:
	float focalLength = 10;
	float filmApertureWidth = 0.825;
	float filmApertureHeight = 0.446;

	const float inchToMm = 25.4;
	
	float nearClippingPlane = 0.1;
	float farClipingPlane = 1000;
	// image resolution in pixels
	
	unsigned imageWidth = 40;
	unsigned imageHeight = 40;

private:

	void computePixelCoordinates(
		const Vec3f& pWorld,
		const Matrix44f& worldToCamera,
		const float& b,
		const float& l,
		const float& t,
		const float& r,
		const float& near,
		const uint32_t& imageWidth,
		const uint32_t& imageHeight,
		Vec3f& pRaster);

	enum FitResolutionGate { kFill = 0, kOverscan };
	FitResolutionGate fitFilm = kOverscan;

public:

	Vec3f getTransformedPoint(Vec3f point);
};

