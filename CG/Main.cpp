// CG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>
#include <vector>
#include "Constants.h"
#include "Torus.h"
#include "Sphere.h"
#include "Line.h"
#include "geometry.h"
#include "ConsoleRenderer.h"
#include "PinHoleCamera.h"

int main()
{

	float sz = 10.f;


	Line line1(Vec3f(0.f, 0.f, 0.f), Vec3f(sz, 0.f, 0.f));
	Line line2(Vec3f(sz, 0.f, 0.f), Vec3f(sz, sz, 0.f));
	Line line3(Vec3f(sz, sz, 0.f), Vec3f(0.f, sz, 0.f));
	Line line4(Vec3f(0.f, sz, 0.f), Vec3f(0.f, 0.f, 0.f));

	Line line5(Vec3f(0.f, 0.f, 0.f), Vec3f(0.f, 0.f, sz));
	Line line6(Vec3f(sz, 0.f, 0.f), Vec3f(sz, 0.f, sz));
	Line line7(Vec3f(sz, sz, 0.f), Vec3f(sz, sz, sz));
	Line line8(Vec3f(0.f, sz, 0.f), Vec3f(0.f, sz, sz));

	Line line9(Vec3f(0.f, 0.f, sz), Vec3f(sz, 0.f, sz));
	Line line10(Vec3f(sz, 0.f, sz), Vec3f(sz, sz, sz));
	Line line11(Vec3f(sz, sz, sz), Vec3f(0.f, sz, sz));
	Line line12(Vec3f(0.f, sz, sz), Vec3f(0.f, 0.f, sz));

	std::vector<Line*> lines;
	lines.push_back(&line1);
	lines.push_back(&line2);
	lines.push_back(&line3);
	lines.push_back(&line4);
	lines.push_back(&line5);
	lines.push_back(&line6);
	lines.push_back(&line7);
	lines.push_back(&line8);
	lines.push_back(&line9);
	lines.push_back(&line10);
	lines.push_back(&line11);
	lines.push_back(&line12);





	Torus t(10, 2);
	t.transform(Vec3f(30, 30, 0), Vec3f(RADIAN(45), RADIAN(45), RADIAN(0)), Vec3f(sz / 2, sz / 2, sz / 2));
	
	ConsoleRenderer r;

	for (int i = 0; i < lines.size(); i++)
	{
		r.addShapeToScene(lines[i]);
	}

	r.addShapeToScene(&t);

	r.initializeViewPort(60, 60);

	for (int k = 0; k < 360; k += 10)
	{
		system("cls");

		r.clearBuffers();

		for (int i = 0; i < lines.size(); i++)
		{
			lines[i]->transform(Vec3f(10, 10, 0), Vec3f(RADIAN(45), RADIAN(45), RADIAN(k)), Vec3f(sz/2, sz/2, sz/2));
		}

	//	r.setCameraTransform(Vec3f(0, 0, 0), Vec3f(RADIAN(k), 0, 0), Vec3f(0, 0, 0));
		
		r.render();

		r.display();
	}

	return 0;

}