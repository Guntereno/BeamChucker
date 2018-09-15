#pragma once

#include "Matrix3f.h"

namespace OrthonormalBasis
{
	Matrix3f FromU(const Vector3f& u);
	Matrix3f FromV(const Vector3f& v);
	Matrix3f FromW(const Vector3f& w);

	Matrix3f FromUV(const Vector3f& u, const Vector3f& v);
	Matrix3f FromVU(const Vector3f& v, const Vector3f& u);
	Matrix3f FromUW(const Vector3f& u, const Vector3f& w);
	Matrix3f FromWU(const Vector3f& w, const Vector3f& u);
	Matrix3f FromVW(const Vector3f& v, const Vector3f& w);
	Matrix3f FromWV(const Vector3f& w, const Vector3f& v);
};