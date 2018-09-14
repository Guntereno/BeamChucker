#pragma once

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

	ColorF operator+() const
	{
		return ColorF(+R, +G, +B);
	}

	ColorF operator-() const
	{
		return ColorF(-R, -G, -B);
	}

	ColorF operator*(float scalar) const
	{
		return ColorF(R * scalar, G * scalar, B * scalar);
	}

	ColorF operator/(float scalar) const
	{
		return ColorF(R / scalar, G / scalar, B / scalar);
	}

	ColorF
};

ColorF operator*(float scalar, const ColorF& color)
{
	return ColorF(color.R * scalar, color.G * scalar, color.B * scalar);
}

ColorF operator*(const ColorF& color, float scalar)
{
	return ColorF(color.R * scalar, color.G * scalar, color.B * scalar);
}

ColorF operator+(const ColorF& colorA, const ColorF& colorB)
{
	return ColorF(colorA.R + colorB.R, colorA.G + colorB.G, colorA.B + colorA.B);
}

ColorF operator-(const ColorF& colorA, const ColorF& colorB)
{
	return ColorF(colorA.R - colorB.R, colorA.G - colorB.G, colorA.B - colorA.B);
}

ColorF operator*(const ColorF& colorA, const ColorF& colorB)
{
	return ColorF(colorA.R * colorB.R, colorA.G * colorB.G, colorA.B * colorA.B);
}

ColorF operator/(const ColorF& colorA, const ColorF& colorB)
{
	return ColorF(colorA.R / colorB.R, colorA.G / colorB.G, colorA.B / colorA.B);
}

ColorF& operator+=(ColorF& colorA, const ColorF& colorB)
{
	colorA.R += colorB.R;
	colorA.G += colorB.G;
	colorA.B += colorB.B;
	return colorA;
}

ColorF& operator-=(ColorF& colorA, const ColorF& colorB)
{
	colorA.R -= colorB.R;
	colorA.G -= colorB.G;
	colorA.B -= colorB.B;
	return colorA;
}

ColorF& operator*=(ColorF& colorA, const ColorF& colorB)
{
	colorA.R *= colorB.R;
	colorA.G *= colorB.G;
	colorA.B *= colorB.B;
	return colorA;
}

ColorF& operator/=(ColorF& colorA, const ColorF& colorB)
{
	colorA.R /= colorB.R;
	colorA.G /= colorB.G;
	colorA.B /= colorB.B;
	return colorA;
}