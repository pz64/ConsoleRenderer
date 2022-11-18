#include <memory>
#include <iostream>
#include "ConsoleRenderer.h"
#include "Constants.h"
#include "TwoParameterParametricShape.h"
#include "OneParameterParametricShape.h"


ConsoleRenderer::~ConsoleRenderer()
{
	delete[] zBuffer;
	delete[] displayBuffer;
}

//void ConsoleRenderer::setCamera(PinHoleCamera* camera)
//{
//	this->camera = camera;
//}

void ConsoleRenderer::clearBuffers()
{
	for (int i = 0; i < width; ++i) 
	{
		for (int j = 0; j < height; ++j)
		{
			int index = i * height + j;
			displayBuffer[index] = ' ';
			zBuffer[index] = INT_MIN;
		}
	}
}

void ConsoleRenderer::initializeViewPort(int width, int height)
{

	this->width = width;
	this->height = height;
	int dimension = width * height;

	delete[] zBuffer;
	zBuffer = new float[dimension];

	delete[] displayBuffer;
	displayBuffer = new char[dimension];


}

void ConsoleRenderer::addShapeToScene(ParametricShape* shape)
{
	shapes.push_back(shape);
}

void ConsoleRenderer::setCameraTransform(const Vec3f& location, const Vec3f& cameraRotation, const Vec3f& cameraRotationPivot)
{
	this->cameraRotation = cameraRotation;
	this->location = location;
	this->cameraRotationPivot = location + cameraRotationPivot;

	rotationMatrix = Matrix44f(
		cos(cameraRotation.y) * cos(cameraRotation.z),
		sin(cameraRotation.x) * sin(cameraRotation.y) * cos(cameraRotation.z) - cos(cameraRotation.x) * sin(cameraRotation.z),
		cos(cameraRotation.x) * sin(cameraRotation.y) * cos(cameraRotation.z) + sin(cameraRotation.x) * sin(cameraRotation.z),
		0.f,

		cos(cameraRotation.y) * sin(cameraRotation.z),
		sin(cameraRotation.x) * sin(cameraRotation.y) * sin(cameraRotation.z) + cos(cameraRotation.x) * cos(cameraRotation.z),
		cos(cameraRotation.x) * sin(cameraRotation.y) * sin(cameraRotation.z) - sin(cameraRotation.x) * cos(cameraRotation.z),
		0.f,

		-sin(cameraRotation.y),
		sin(cameraRotation.x) * cos(cameraRotation.y),
		cos(cameraRotation.x) * cos(cameraRotation.y),
		0.f,

		0.f,
		0.f,
		0.f,
		0.f
	);
}

void ConsoleRenderer::render()
{
	for (float i = PARM_MIN; i < PARM_MAX; i++)
	{
		for (float j = PARM_MIN; j < PARM_MAX; j++)
		{

			for (auto* shape : shapes)
			{
				Vec3f point;
				auto* oneParmPtr = dynamic_cast<OneParameterParametricShape*>(shape);
				if (oneParmPtr != nullptr)
				{
					point = oneParmPtr->build(i);
				}

				auto* twoParmPtr = dynamic_cast<TwoParameterParametricShape*>(shape);
				if (twoParmPtr != nullptr)
				{
					point = twoParmPtr->build(i, j);
				}

				point = point + location;
				Vec3f result;

				rotationMatrix.multDirMatrix(point - cameraRotationPivot, result);

				draw(result);
				//draw(camera->getTransformedPoint(result));
			}
		}
	}
}

void ConsoleRenderer::getDiplayBuffer(char* displayBuffer)
{

}

void ConsoleRenderer::display()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int index = i * height + j;
			std::cout << displayBuffer[index] << displayBuffer[index];
		}
		std::cout << std::endl;
	}
}

void ConsoleRenderer::draw(Vec3f point)
{
	if ((point.x < width && point.x >= 0) && (point.y < height && point.y >= 0))
	{
		int index = (int)point.x * height + (int)point.y;
		float currZNear = zBuffer[index];

		if (point.z > currZNear) {

			zBuffer[index] = point.z;

			displayBuffer[index] = '*';
		}
	}
}