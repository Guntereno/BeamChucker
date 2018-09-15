#pragma once

#include "Vector3.h"


struct Matrix3f
{
	union
	{
		struct
		{
			Vector3f Right;
			Vector3f Up;
			Vector3f Forward;
		} Dir;
		float Cell[9];
		Vector3f Vector[3];
	};

	friend bool operator==(const Matrix3f& basisA, const Matrix3f& basisB);
};

static_assert(
	offsetof(Matrix3f, Dir.Up) == offsetof(Matrix3f, Vector[1]),
	"Union layout invalid on this platform!");
static_assert(offsetof(Matrix3f, Dir.Forward) == offsetof(Matrix3f, Cell[6]),
	"Union layout invalid on this platform!");

inline bool operator==(const Matrix3f& matrixA, const Matrix3f& matrixB)
{
	return
		(matrixA.Dir.Right == matrixB.Dir.Right) &&
		(matrixA.Dir.Up == matrixB.Dir.Up) &&
		(matrixA.Dir.Forward == matrixB.Dir.Forward);
}