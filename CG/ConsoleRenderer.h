#pragma once
#include <vector>
#include <memory>
#include "ParametricShape.h"
#include "geometry.h"
#include "PinHoleCamera.h"

class ConsoleRenderer
{
	std::vector<ParametricShape*> shapes;

	int width, height;
	
	Vec3f location;
	Vec3f cameraRotation;
	Vec3f cameraRotationPivot;
	Matrix44f rotationMatrix;

	PinHoleCamera* camera;

	float* zBuffer;
	char* displayBuffer;

	void draw(Vec3f point);

public:

	~ConsoleRenderer();

	/*void setCamera(PinHoleCamera* camera);*/

	void clearBuffers();

	void initializeViewPort(int width, int height);

	void addShapeToScene(ParametricShape* shape);

	void setCameraTransform(const Vec3f& translation, const Vec3f& cameraRotation, const Vec3f& cameraRotationPivot);

	void render();

	void getDiplayBuffer(char* displayBuffer);

	void display();
};

