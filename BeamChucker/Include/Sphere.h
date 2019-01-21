#pragma once

#include "IShape.h"

class Sphere : public IShape
{
public:
	Sphere(const Vector3f& center, float radius, const ColorF& color);

	bool Hit(const Ray& ray, float tMin, float tMax, HitData* pData) const override;

private:
	Vector3f mCenter;
	float mRadius;
	ColorF mColor;
};