#pragma once

#include "IShape.h"

class Triangle : public IShape
{
public:
	static const int kNumPoints = 3;
	Triangle(const Vector3f& p0, const Vector3f& p1, const Vector3f& p2, const ColorF color);

	bool Hit(const Ray& ray, float tMin, float tMax, HitData* pData) const override;

private:
	Vector3f mPoints[kNumPoints];
	ColorF mColor;
};