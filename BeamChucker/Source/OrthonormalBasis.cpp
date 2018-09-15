#include "pch.h"

#include "OrthonormalBasis.h"

#include <cfloat>

namespace OrthonormalBasis
{
	static const Vector3f kUp = { 0.0f, 1.0f, 0.0f };
	static const Vector3f kRight = { 1.0f, 0.0f, 0.0f };

	Matrix3f FromU(const Vector3f& u)
	{
		Matrix3f result;

		result.Dir.Right = u.Normalized();
		result.Dir.Up = Vector3f::Cross(result.Dir.Right, kRight);
		if (result.Dir.Up.MagnitudeSquared() < FLT_EPSILON)
		{
			result.Dir.Up = Vector3f::Cross(result.Dir.Right, kUp);
		}
		result.Dir.Forward = Vector3f::Cross(result.Dir.Right, result.Dir.Up);

		return result;
	}

	Matrix3f FromV(const Vector3f& v)
	{
		Matrix3f result;

		result.Dir.Up = v.Normalized();
		result.Dir.Right = Vector3f::Cross(result.Dir.Up, kRight);
		if (result.Dir.Right.MagnitudeSquared() < FLT_EPSILON)
		{
			result.Dir.Right = Vector3f::Cross(result.Dir.Right, kRight);
		}
		result.Dir.Forward = Vector3f::Cross(result.Dir.Right, result.Dir.Up);

		return result;
	}

	Matrix3f FromW(const Vector3f& w)
	{
		Matrix3f result;
		
		result.Dir.Forward = w.Normalized();
		result.Dir.Right = Vector3f::Cross(result.Dir.Forward, kRight);
		if (result.Dir.Right.MagnitudeSquared() < FLT_EPSILON)
		{
			result.Dir.Right = Vector3f::Cross(result.Dir.Forward, kUp);
		}
		result.Dir.Up = Vector3f::Cross(result.Dir.Forward, result.Dir.Right);
		
		return result;
	}

	Matrix3f FromUV(const Vector3f& u, const Vector3f& v)
	{
		Matrix3f result;
		
		result.Dir.Right = u.Normalized();
		result.Dir.Forward = Vector3f::Cross(u, v).Normalized();
		result.Dir.Up = Vector3f::Cross(result.Dir.Forward, result.Dir.Right);

		return result;
	}

	Matrix3f FromVU(const Vector3f& v, const Vector3f& u)
	{
		Matrix3f result;

		result.Dir.Up = v.Normalized();
		result.Dir.Forward = Vector3f::Cross(u, v).Normalized();
		result.Dir.Right = Vector3f::Cross(result.Dir.Up, result.Dir.Forward);

		return result;
	}

	Matrix3f FromUW(const Vector3f& u, const Vector3f& w)
	{
		Matrix3f result;

		result.Dir.Right = u.Normalized();
		result.Dir.Up = Vector3f::Cross(w, u).Normalized();
		result.Dir.Forward = Vector3f::Cross(result.Dir.Right, result.Dir.Up);

		return result;
	}

	Matrix3f FromWU(const Vector3f& w, const Vector3f& u)
	{
		Matrix3f result;

		result.Dir.Forward = w.Normalized();
		result.Dir.Up = Vector3f::Cross(w,u).Normalized();
		result.Dir.Forward = Vector3f::Cross(result.Dir.Up, result.Dir.Forward);

		return result;
	}

	Matrix3f FromVW(const Vector3f& v, const Vector3f& w)
	{
		Matrix3f result;

		result.Dir.Up = v.Normalized();
		result.Dir.Right = Vector3f::Cross(v, w).Normalized();
		result.Dir.Forward = Vector3f::Cross(result.Dir.Right, result.Dir.Up);

		return result;
	}

	Matrix3f FromWV(const Vector3f& w, const Vector3f& v)
	{
		Matrix3f result;

		result.Dir.Forward = w.Normalized();
		result.Dir.Right = Vector3f::Cross(v, w).Normalized();
		result.Dir.Up = Vector3f::Cross(result.Dir.Up, result.Dir.Right);

		return result;
	}
}
