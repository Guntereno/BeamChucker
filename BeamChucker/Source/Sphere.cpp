#include "pch.h"

#include "Sphere.h"

#include <cmath>

Sphere::Sphere(const Vector3f& center, float radius, const ColorF& color):
	mCenter(center),
	mRadius(radius),
	mColor(color)
{}

bool Sphere::Hit(const Ray& ray, float tMin, float tMax, HitData* pData) const
{
	Vector3f offset = ray.Origin - mCenter;

	float a = Vector3f::Dot(ray.Direction, ray.Direction);
	float b = 2.0f * Vector3f::Dot(ray.Direction, offset);
	float c = Vector3f::Dot(offset, offset) - (mRadius * mRadius);

	float discriminant = (b * b) - (4.0f * a * c);
	if (discriminant > 0.0f)
	{
		// Ray intersects sphere
		discriminant = (float)sqrt(discriminant);
		float t = (-b - discriminant) / (2.0f * a);

		if (t < tMin)
		{
			t = (-b + discriminant) / (2.0f * a);
		}
		if ((t < tMin) || (t > tMax))
		{
			return false;
		}

		if (pData != nullptr)
		{
			pData->T = t;
			pData->Normal = (ray.Origin + (t * ray.Direction) - mCenter).Normalized();
			pData->Color = mColor;
		}

		return true;
	}

	return false;
}