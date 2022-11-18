#include "PinHoleCamera.h"

void PinHoleCamera::computePixelCoordinates(
	const Vec3f& pWorld,
	const Matrix44f& worldToCamera,
	const float& b,
	const float& l,
	const float& t,
	const float& r,
	const float& near,
	const uint32_t& imageWidth,
	const uint32_t& imageHeight,
	Vec3f& pRaster)
{
	Vec3f pCamera;
	worldToCamera.multVecMatrix(pWorld, pCamera);
	Vec2f pScreen;
	pScreen.x = pCamera.x / -pCamera.z * near;
	pScreen.y = pCamera.y / -pCamera.z * near;

	Vec2f pNDC;
	pNDC.x = (pScreen.x + r) / (2 * r);
	pNDC.y = (pScreen.y + t) / (2 * t);
	pRaster.x = (pNDC.x * imageWidth);
	pRaster.y = ((1 - pNDC.y) * imageHeight);
    pRaster.z = pWorld.z;
}

Vec3f PinHoleCamera::getTransformedPoint(Vec3f point)
{

    float filmAspectRatio = filmApertureWidth / filmApertureHeight;
    float deviceAspectRatio = imageWidth / (float)imageHeight;

    float top = ((filmApertureHeight * inchToMm / 2) / focalLength) * nearClippingPlane;
    float right = ((filmApertureWidth * inchToMm / 2) / focalLength) * nearClippingPlane;

    float xscale = 1;
    float yscale = 1;

    switch (fitFilm) {
    default:
    case kFill:
        if (filmAspectRatio > deviceAspectRatio) {
            xscale = deviceAspectRatio / filmAspectRatio;
        }
        else {
            yscale = filmAspectRatio / deviceAspectRatio;
        }
        break;
    case kOverscan:
        if (filmAspectRatio > deviceAspectRatio) {
            yscale = filmAspectRatio / deviceAspectRatio;
        }
        else {
            xscale = deviceAspectRatio / filmAspectRatio;
        }
        break;
    }

    right *= xscale;
    top *= yscale;

    float bottom = -top;
    float left = -right;

    Matrix44f cameraToWorld(
        -0.95424, 0, 0.3, 0, 
        1.0861242, 0.95763, 0.274823, 0 , 
        -0.28637, 0.288002, -0.913809, 0,
        -3.734612, 7.610426, -14.152769, 1.f);
    Matrix44f worldToCamera = cameraToWorld.inverse();

    Vec3f vRaster;

    computePixelCoordinates(point, worldToCamera, bottom, left, top, right, nearClippingPlane, imageWidth, imageHeight, vRaster);
    return vRaster;
}
