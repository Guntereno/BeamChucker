#include "pch.h"

#include "Triangle.h"

Triangle::Triangle(const Vector3f& p0, const Vector3f& p1, const Vector3f& p2, const ColorF color):
	mPoints{ p0, p1, p2 },
	mColor(color)
{}

bool Triangle::Hit(const Ray& ray, float tMin, float tMax, HitData* pData) const
{
	float a = mPoints[0].X - mPoints[1].X;
	float b = mPoints[0].Y - mPoints[1].Y;
	float c = mPoints[0].Z - mPoints[1].Z;

	float d = mPoints[0].X - mPoints[2].X;
	float e = mPoints[0].Y - mPoints[2].Y;
	float f = mPoints[0].Z - mPoints[2].Z;

	float g = ray.Direction.X;
	float h = ray.Direction.Y;
	float i = ray.Direction.Z;

	float j = mPoints[0].X - ray.Origin.X;
	float k = mPoints[0].Y - ray.Origin.Y;
	float l = mPoints[0].Z - ray.Origin.Z;

	float eihf = (e*i) - (h*f);
	float gfdi = (g*f) - (d*i);
	float dheg = (d*h) - (e*g);

	float denom = ((a * eihf) + (b * gfdi) + (c * dheg));
	float beta = ((j * eihf) + (k * gfdi) + (l * dheg)) / denom;

	if ((beta <= 0.0f) || (beta >= 1.0f))
	{
		return false;
	}

	float akjb = (a * k) - (j * b);
	float jcal = (j * c) - (a * l);
	float blkc = (b * l) - (k * c);

	float gamma = ((i * akjb) + (h * jcal) + (g * blkc)) / denom;

	if ((gamma <= 0.0f) || (beta + gamma >= 1.0f))
	{
		return false;
	}

	float t = -((f * akjb) + (e * jcal) + (d * blkc)) / denom;

	bool hit = ((t >= tMin) && (t <= tMax));

	if(hit && (pData != nullptr))
	{
		pData->T = t;
		pData->Normal = Vector3f::Cross((mPoints[1] - mPoints[0]), (mPoints[2] - mPoints[0])).Normalized();
		pData->Color = mColor;
	}

	return hit;
}