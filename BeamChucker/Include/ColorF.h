#pragma once

#include <algorithm>

struct ColorF
{
	float R;
	float G;
	float B;

	ColorF():
		R(0.0f),
		G(0.0f),
		B(0.0f)
	{}

	ColorF(float scalar):
		R(scalar),
		G(scalar),
		B(scalar)
	{}

	ColorF(float r, float g, float b):
		R(r),
		G(g),
		B(b)
	{}

	ColorF& operator=(const ColorF& rhs);
	ColorF& operator/=(const ColorF& rhs);
	ColorF& operator*=(const ColorF& rhs);
	ColorF& operator+=(const ColorF& rhs);
	ColorF& operator-=(const ColorF& rhs);

	ColorF& operator/=(float rhs);
	ColorF& operator*=(float rhs);

	ColorF Clamped() const;

	ColorF operator+() const
	{
		return *this;
	}

	ColorF operator-() const
	{
		return ColorF(-R, -G, -B);
	}

	friend ColorF operator/(const ColorF& colorA, const ColorF& colorB);
	friend ColorF operator*(float scalar, const ColorF& color);
	friend ColorF operator*(const ColorF& color, float scalar);
	friend ColorF operator*(const ColorF& colorA, const ColorF& colorB);
	friend ColorF operator+(const ColorF& colorA, const ColorF& colorB);
	friend ColorF operator-(const ColorF& colorA, const ColorF& colorB);

	static ColorF Lerp(const ColorF& colorA, const ColorF& colorB, float t);

	static ColorF Black();
	static ColorF Red();
	static ColorF Yellow();
	static ColorF Green();
	static ColorF Cyan();
	static ColorF Blue();
	static ColorF Magenta();
	static ColorF White();
};

inline ColorF& ColorF::operator=(const ColorF& rhs)
{
	R = rhs.R;
	G = rhs.G;
	B = rhs.B;
	return *this;
}

inline ColorF& ColorF::operator/=(const ColorF& rhs)
{
	R /= rhs.R;
	G /= rhs.G;
	B /= rhs.B;
	return *this;
}

inline ColorF& ColorF::operator*=(const ColorF& rhs)
{
	R *= rhs.R;
	G *= rhs.G;
	B *= rhs.B;
	return *this;
}

inline ColorF& ColorF::operator+=(const ColorF& rhs)
{
	R += rhs.R;
	G += rhs.G;
	B += rhs.B;
	return *this;
}

inline ColorF& ColorF::operator-=(const ColorF& rhs)
{
	R -= rhs.R;
	G -= rhs.G;
	B -= rhs.B;
	return *this;
}


inline ColorF& ColorF::operator/=(float rhs)
{
	R /= rhs;
	G /= rhs;
	B /= rhs;
	return *this;
}

inline ColorF& ColorF::operator*=(float rhs)
{
	R *= rhs;
	G *= rhs;
	B *= rhs;
	return *this;
}

inline ColorF ColorF::Clamped() const
{
	return ColorF
	{
		(R <= 0.0f) ? 0.0f : ((R >= 1.0f) ? 1.0f : R),
		(G <= 0.0f) ? 0.0f : ((R >= 1.0f) ? 1.0f : G),
		(B <= 0.0f) ? 0.0f : ((R >= 1.0f) ? 1.0f : B)
	};
}


inline ColorF operator/(const ColorF& colorA, const ColorF& colorB)
{
	return ColorF(colorA.R / colorB.R, colorA.G / colorB.G, colorA.B / colorA.B);
}

inline ColorF operator*(float scalar, const ColorF& color)
{
	return ColorF(color.R * scalar, color.G * scalar, color.B * scalar);
}

inline ColorF operator*(const ColorF& color, float scalar)
{
	return ColorF(color.R * scalar, color.G * scalar, color.B * scalar);
}

inline ColorF operator*(const ColorF& colorA, const ColorF& colorB)
{
	return ColorF(colorA.R * colorB.R, colorA.G * colorB.G, colorA.B * colorB.B);
}

inline ColorF operator+(const ColorF& colorA, const ColorF& colorB)
{
	return ColorF(colorA.R + colorB.R, colorA.G + colorB.G, colorA.B + colorB.B);
}

inline ColorF operator-(const ColorF& colorA, const ColorF& colorB)
{
	return ColorF(colorA.R - colorB.R, colorA.G - colorB.G, colorA.B - colorB.B);
}


inline ColorF ColorF::Lerp(const ColorF & colorA, const ColorF & colorB, float t)
{
	ColorF result = ((1.0f - t) * colorA) + (t * colorB);
	return result;
}


inline ColorF ColorF::Black()
{
	return ColorF(1.0f, 1.0f, 1.0f);
}

inline ColorF ColorF::Red()
{
	return ColorF(1.0f, 0.0f, 0.0f);
}

inline ColorF ColorF::Yellow()
{
	return ColorF(1.0f, 1.0f, 0.0f);
}

inline ColorF ColorF::Green()
{
	return ColorF(0.0f, 1.0f, 0.0f);
}

inline ColorF ColorF::Cyan()
{
	return ColorF(0.0f, 1.0f, 1.0f);
}

inline ColorF ColorF::Blue()
{
	return ColorF(0.0f, 0.0f, 1.0f);
}

inline ColorF ColorF::Magenta()
{
	return ColorF(1.0f, 0.0f, 1.0f);
}

inline ColorF ColorF::White()
{
	return ColorF(1.0f, 1.0f, 1.0f);
}
