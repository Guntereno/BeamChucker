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
	FIBITMAP* pBitmap = FreeImage_Allocate(mWidth, mHeight, kBpp);

	assert(pBitmap != nullptr);

	for (size_t y = 0; y < mHeight; ++y)
	{
		for (size_t x = 0; x < mWidth; ++x)
		{
			ColorF imageColor = GetPixel(x, y);
			RGBQUAD freeImageColor = ConvertColor(imageColor);

			size_t bmpY = (mHeight - 1) - y; // Free Image has 0 at bottom where Image treats 0 as top
			FreeImage_SetPixelColor(pBitmap, x, bmpY, &freeImageColor);
		}
	}

	FreeImage_Save(FIF_BMP, pBitmap, pFileName, 0);

	FreeImage_DeInitialise();
}
