#pragma once

#include "Vector3.h"

struct Ray
{
	Vector3f Origin;
	Vector3f Direction;

	Vector3f PointAtT(float t)
	{
		return Origin + (t * Direction);
	}
};