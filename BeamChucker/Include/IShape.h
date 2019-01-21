#pragma once

#include "ColorF.h"
#include "Ray.h"
#include "Vector3.h"


struct HitData
{
	float T;
	Vector3f Normal;
	ColorF Color;
};

class IShape
{
public:
	virtual bool Hit(const Ray& ray, float tMin, float tMax, HitData* pData) const = 0;
};
