#include "pch.h"

#include "Image.h"

#include <assert.h>

#include "FreeImage.h"


static RGBQUAD ConvertColor(const ColorF& color)
{
	ColorF clamped = color.Clamped();

	RGBQUAD result
	{
		BYTE(255 * color.B),
		BYTE(255 * color.G),
		BYTE(255 * color.R),
		0
	};

	return result;
}

void Image::SaveBmp(const char * pFileName)
{
	assert(pFileName != nullptr);

	FreeImage_Initialise();

	const int kBpp = 24;
	FIBITMAP* pBitmap = FreeImage_Allocate((int)mWidth, (int)mHeight, kBpp);

	assert(pBitmap != nullptr);

	for (size_t y = 0; y < mHeight; ++y)
	{
		for (size_t x = 0; x < mWidth; ++x)
		{
			ColorF imageColor = GetPixel(x, y);
			RGBQUAD freeImageColor = ConvertColor(imageColor);
			FreeImage_SetPixelColor(pBitmap, (int)x, (int)y, &freeImageColor);
		}
	}

	FreeImage_Save(FIF_BMP, pBitmap, pFileName, 0);

	FreeImage_DeInitialise();
}

void Image::GammaCorrect(float gamma)
{
	ColorF temp;
	float power = 1.0f / gamma;
	for (int y = 0; y < mHeight; ++y)
	{
		for (int x = 0; x < mWidth; ++x)
		{
			ColorF& pixel = mPixels[x + (y * mWidth)];
			temp = pixel;
			pixel = ColorF
			{
				pow(temp.R, power),
				pow(temp.G, power),
				pow(temp.B, power)
			};
		}
	}
}
