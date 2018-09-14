#pragma once

#include <array>
#include <assert.h>

#include "ColorF.h"

class Image
{
public:
	Image(size_t width, size_t height):
		mWidth(width),
		mHeight(height)
	{
		Pixels = new ColorF[mWidth * mHeight];
	}

	~Image()
	{
		delete[] Pixels;
	}

	size_t GetSize()
	{
		return mWidth * mHeight;
	}

	ColorF& operator[](size_t index)
	{
		assert(index < GetSize());
		return Pixels[index];
	}

	ColorF& GetPixel(size_t x, size_t y)
	{
		assert(x < mWidth);
		assert(y < mHeight);
		return Pixels[x + (y * mWidth)];
	}

	void SetPixel(size_t x, size_t y, ColorF color)
	{
		GetPixel(x, y) = color;
	}

	size_t GetHeight()
	{
		return mHeight;
	}

	size_t GetWidth()
	{
		return mWidth;
	}

	void SaveBmp(const char* pFileName);
	
private:
	ColorF* Pixels;
	size_t mWidth;
	size_t mHeight;
};