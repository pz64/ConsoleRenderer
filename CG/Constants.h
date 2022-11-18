#pragma once
#include <limits>

#define M_PI       3.14159265358979323846f   // pi
#define M_PI_2     1.57079632679489661923f   // pi/2
#define M_PI_4     0.785398163397448309616f  // pi/4

#define PARM_MIN 0.f
#define PARM_MAX 100.f

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MAP(a,I,J,X,Y) (((a) - (I)) * ((Y) - (X)) / ((J) - (I)) + (X))

#define RADIAN(a) (((a) * M_PI) / 180.f)