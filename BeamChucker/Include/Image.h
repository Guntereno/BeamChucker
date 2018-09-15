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
		mPixels = new ColorF[mWidth * mHeight];
	}

	~Image()
	{
		delete[] mPixels;
	}

	size_t GetSize()
	{
		return mWidth * mHeight;
	}

	ColorF& operator[](size_t index)
	{
		assert(index < GetSize());
		return mPixels[index];
	}

	ColorF& GetPixel(size_t x, size_t y)
	{
		assert(x < mWidth);
		assert(y < mHeight);
		return mPixels[x + (y * mWidth)];
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
	void GammaCorrect(float gamma);

private:
	ColorF* mPixels;
	size_t mWidth;
	size_t mHeight;
};