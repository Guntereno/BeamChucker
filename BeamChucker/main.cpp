#include "pch.h"
#include <iostream>
#include "Image.h"

int main()
{
	Image image(128, 256);
	for (size_t y = 0; y < image.GetHeight(); ++y)
	{
		float v = (float)y / image.GetHeight();

		ColorF left = ColorF::Lerp(ColorF::Red(), ColorF::Blue(), v);
		ColorF right = ColorF::Lerp(ColorF::Green(), ColorF::Magenta(), v);

		for (size_t x = 0; x < image.GetWidth(); ++x)
		{
			float u = (float)x / image.GetWidth();

			ColorF pixel = ColorF::Lerp(left, right, u);
			image.SetPixel(x, y, pixel);
		}
	}

	image.SaveBmp("test.bmp");
}
