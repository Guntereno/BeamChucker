#pragma once

#include <type_traits>
#include <assert.h>

struct Vector3f
{
	float X;
	float Y;
	float Z;

	void Set(float X, float Y, float Z);
	float Magnitude() const;
	float MagnitudeSquared() const;
	void Normalize();

	Vector3f Normalized() const;

	Vector3f operator+() const;
	Vector3f operator-() const;

	float& operator[](int i);

	Vector3f& operator/=(const Vector3f& rhs);
	Vector3f& operator/=(float rhs);
	Vector3f& operator*=(const Vector3f& rhs);
	Vector3f& operator*=(float rhs);
	Vector3f& operator+=(const Vector3f& rhs);
	Vector3f& operator-=(const Vector3f& rhs);

	friend bool operator==(const Vector3f& vectorA, const Vector3f& vectorB);
	friend bool operator!=(const Vector3f& vectorA, const Vector3f& vectorB);
	friend Vector3f operator/(const Vector3f& vectorA, const Vector3f& vectorB);
	friend Vector3f operator/(const Vector3f& vector, float scalar);
	friend Vector3f operator*(float scalar, const Vector3f& vector);
	friend Vector3f operator*(const Vector3f& vector, float scalar);
	friend Vector3f operator*(const Vector3f& vectorA, const Vector3f& vectorB);
	friend Vector3f operator+(const Vector3f& vectorA, const Vector3f& vectorB);
	friend Vector3f operator-(const Vector3f& vectorA, const Vector3f& vectorB);

	static Vector3f Cross(const Vector3f& vectorA, const Vector3f& vectorB);
	static float Dot(const Vector3f& vectorA, const Vector3f& vectorB);

	static Vector3f Zero();
};

static_assert(std::is_pod<Vector3f>::value, "Vector2 must be a POD type!");


inline void Vector3f::Set(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}

inline float Vector3f::Magnitude() const
{
	return (float)sqrt(MagnitudeSquared());
}

inline float Vector3f::MagnitudeSquared() const
{
	return (X * X) + (Y * Y) + (Z * Z);
}

inline void Vector3f::Normalize()
{
	*this = (*this) / Magnitude();
}

inline Vector3f Vector3f::Normalized() const
{
	Vector3f result = (*this) / Magnitude();
	return result;
}

inline Vector3f Vector3f::operator+() const
{
	return *this;
}

inline Vector3f Vector3f::operator-() const
{
	return Vector3f
	{
		-X,
		-Y,
		-Z
	};
}

inline float& Vector3f::operator[](int i)
{
	switch (i)
	{
	case 0:
		return X;
	case 1:
		return Y;
	case 2:
		return Z;
	default:
		assert(false);
		return (*this)[i % 3];
	}
}


inline Vector3f& Vector3f::operator/=(const Vector3f& rhs)
{
	X /= rhs.X;
	Y /= rhs.Y;
	Z /= rhs.Z;
	return *this;
}

inline Vector3f& Vector3f::operator/=(float rhs)
{
	X /= rhs;
	Y /= rhs;
	Z /= rhs;
	return *this;
}

inline Vector3f& Vector3f::operator*=(const Vector3f& rhs)
{
	X *= rhs.X;
	Y *= rhs.Y;
	Z *= rhs.Z;
	return *this;
}

inline Vector3f& Vector3f::operator*=(float rhs)
{
	X *= rhs;
	Y *= rhs;
	Z *= rhs;
	return *this;
}

inline Vector3f& Vector3f::operator+=(const Vector3f& rhs)
{
	X += rhs.X;
	Y += rhs.Y;
	Z += rhs.Z;
	return *this;
}

inline Vector3f& Vector3f::operator-=(const Vector3f& rhs)
{
	X -= rhs.X;
	Y -= rhs.Y;
	Z -= rhs.Z;
	return *this;
}


inline bool operator==(const Vector3f& vectorA, const Vector3f& vectorB)
{
	return
		(vectorA.X == vectorB.X) &&
		(vectorA.Y == vectorB.Y) &&
		(vectorA.Z == vectorB.Z);
}

inline bool operator!=(const Vector3f& vectorA, const Vector3f& vectorB)
{
	return
		(vectorA.X != vectorB.X) ||
		(vectorA.Y != vectorB.Y) ||
		(vectorA.Z != vectorB.Z);
}

inline Vector3f operator/(const Vector3f& vectorA, const Vector3f& vectorB)
{
	Vector3f result =
	{
		vectorA.X / vectorB.X,
		vectorA.Y / vectorB.Y,
		vectorA.Z / vectorB.Z
	};
	return result;
}

inline Vector3f operator/(const Vector3f& vector, float scalar)
{
	Vector3f result =
	{
		vector.X / scalar,
		vector.Y / scalar,
		vector.Z / scalar
	};
	return result;
}

inline Vector3f operator*(float scalar, const Vector3f& vector)
{
	Vector3f result =
	{
		scalar * vector.X,
		scalar * vector.Y,
		scalar * vector.Z
	};
	return result;
}

inline Vector3f operator*(const Vector3f& vector, float scalar)
{
	Vector3f result =
	{
		scalar * vector.X,
		scalar * vector.Y,
		scalar * vector.Z
	};
	return result;
}

inline Vector3f operator*(const Vector3f& vectorA, const Vector3f& vectorB)
{
	Vector3f result =
	{
		vectorA.X * vectorB.X,
		vectorA.Y * vectorB.Y,
		vectorA.Z * vectorB.Z
	};
	return result;
}

inline Vector3f operator+(const Vector3f& vectorA, const Vector3f& vectorB)
{
	Vector3f result =
	{
		vectorA.X + vectorB.X,
		vectorA.Y + vectorB.Y,
		vectorA.Z + vectorB.Z
	};
	return result;
}

inline Vector3f operator-(const Vector3f& vectorA, const Vector3f& vectorB)
{
	Vector3f result =
	{
		vectorA.X + vectorB.X,
		vectorA.Y + vectorB.Y,
		vectorA.Z + vectorB.Z
	};
	return result;
}

inline Vector3f Vector3f::Cross(const Vector3f& vectorA, const Vector3f& vectorB)
{
	Vector3f result =
	{
		(vectorA.Y * vectorB.Z) - (vectorA.Z * vectorB.Y),
		(vectorA.Z * vectorB.X) - (vectorA.X * vectorB.Z),
		(vectorA.X * vectorB.Y) - (vectorA.Y * vectorB.X)
	};
	return result;
}

inline float Vector3f::Dot(const Vector3f& vectorA, const Vector3f& vectorB)
{
	float result =
		(vectorA.X * vectorB.X) +
		(vectorA.Y * vectorB.Y) +
		(vectorA.Z * vectorB.Z);
	return result;
}

inline Vector3f Vector3f::Zero()
{
	return Vector3f{ 0.0f, 0.0f, 0.0f };
}
