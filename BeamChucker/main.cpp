#include "pch.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

#include "Image.h"
#include "OrthonormalBasis.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Vector3.h"

void TestImage();
void TestOrthonormalBasis();
void TestRayTracer();

int main()
{
	TestImage();
	TestOrthonormalBasis();
	TestRayTracer();
}

void TestImage()
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

	image.GammaCorrect(2.2f);

	image.SaveBmp("test.bmp");
}

void TestOrthonormalBasis()
{
	Matrix3f onbA = OrthonormalBasis::FromU(Vector3f{ 0.0f, 0.0f, -1.0f });
	Matrix3f onbB = OrthonormalBasis::FromUV(Vector3f{ 0.0f, 0.0f, -1.0f }, Vector3f{ 0.0f, -1.0f, 0.0f });
	assert(onbA == onbB);
}

void TestRayTracer()
{
	std::vector<std::unique_ptr<IShape>> shapes;
	shapes.push_back(std::unique_ptr<IShape>(new Sphere({ 250, 250, -1000 }, 150, ColorF::Blue())));
	//shapes.push_back(std::unique_ptr<IShape>(new Triangle(
	//	{ 300, 600, -800 },
	//	{ 0, 100, -1000 },
	//	{ 450, 20, -1000 },
	//	ColorF::Red())));

	Image renderTarget(500, 500);

	const Vector3f dir{ 0.0f, 0.0f, -1.0f };
	HitData hitData;

	for (size_t y = 0; y < renderTarget.GetHeight(); ++y)
	{
		for (size_t x = 0; x < renderTarget.GetWidth(); ++x)
		{
			Vector3f origin{ (float)x, (float)y, 0.0f };
			Ray ray{ origin, dir };

			float maxT = 100000.0f;
			ColorF color = ColorF::Black();
			for(auto it = shapes.begin(); it != shapes.end(); ++it)
			{
				IShape* pShape = it->get();

				bool hit = pShape->Hit(ray, 0.0f, maxT, &hitData);
				if (hit && (hitData.T < maxT))
				{
					color = hitData.Color;
					maxT = hitData.T;
				}
			}

			renderTarget.SetPixel(x, y, color);
		}
	}

	renderTarget.SaveBmp("raytracer.bmp");
}
