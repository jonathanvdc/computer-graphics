#include "IBitmap.h"
#include "EasyImage.h"
#include "EasyBitmap.h"
#include "BitmapRenderContext.h"
#include <algorithm>

using namespace Engine;

void BitmapBase::setItem(int X, int Y, std::shared_ptr<IBrush> Brush)
{
	auto pos = PixelPosition(X, Y, Vector2(X / getWidth(), Y / getHeight()));
	auto color = Brush->GetColor(pos);
	if (color.W > 0.0)
	{
		this->setItem(X, Y, color);
	}
}

void BitmapBase::DrawLine(int x0, int y0, int x1, int y1, std::shared_ptr<IBrush> Brush)
{
	// Slightly adapted from EasyImage.cc's draw_line
	if (x0 == x1)
	{
		//special case for x0 == x1
		for (int i = std::min(y0, y1); i <= std::max(y0, y1); i++)
		{
			this->setItem(x0, i, Brush);
		}
	}
	else if (y0 == y1)
	{
		//special case for y0 == y1
		for (int i = std::min(x0, x1); i <= std::max(x0, x1); i++)
		{
			this->setItem(i, y0, Brush);
		}
	}
	else
	{
		if (x0 > x1)
		{
			//flip points if x1>x0: we want x0 to have the lowest value
			std::swap(x0, x1);
			std::swap(y0, y1);
		}
		double m = ((double)y1 - (double)y0) / ((double)x1 - (double)x0);
		if (-1.0 <= m && m <= 1.0)
		{
			for (int i = 0; i <= (x1 - x0); i++)
			{
				int xpos = x0 + i;
				int ypos = (int)round(y0 + m * i);
				this->setItem(xpos, ypos, Brush);
			}
		}
		else if (m > 1.0)
		{
			for (int i = 0; i <= (y1 - y0); i++)
			{
				int xpos = (int)round(x0 + (i / m));
				int ypos = y0 + i;
				this->setItem(xpos, ypos, Brush);
			}
		}
		else if (m < -1.0)
		{
			for (int i = 0; i <= (y0 - y1); i++)
			{
				int xpos = (int)round(x0 - (i / m));
				int ypos = y0 - i;
				this->setItem(xpos, ypos, Brush);
			}
		}
	}
}

void BitmapBase::FillTriangle(Triangle<Vector2> Triangle, std::shared_ptr<IBrush> Brush)
{
	double xs[3] = { Triangle.A.X, Triangle.B.X, Triangle.C.X };
	double ys[3] = { Triangle.A.Y, Triangle.B.Y, Triangle.C.Y };

	int ymin = (int)std::ceil(*std::min_element(ys, ys + 3));
	int ymax = (int)std::floor(*std::max_element(ys, ys + 3));

	for (int yi = ymin; yi <= ymax; yi++)
	{
		double xls[3] = {
			std::numeric_limits<double>::infinity(),
			std::numeric_limits<double>::infinity(),
			std::numeric_limits<double>::infinity()
		};
		double xrs[3] = {
			-std::numeric_limits<double>::infinity(),
			-std::numeric_limits<double>::infinity(),
			-std::numeric_limits<double>::infinity()
		};

		for (int i = 0; i < 3; i++)
		{
			double yp = ys[i], yq = ys[(i + 1) % 3];
			if ((yi - yp) * (yi - yq) <= 0.0 && yp != yq)
			{
				double xp = xs[i], xq = xs[(i + 1) % 3];
				double xi = xq + (xp - xq) * (yi - yq) / (yp - yq);
				xls[i] = xrs[i] = xi;
			}
		}

		int xl = (int)std::ceil(*std::min_element(xls, xls + sizeof(xls) / sizeof(double)));
		int xr = (int)std::floor(*std::max_element(xrs, xrs + sizeof(xrs) / sizeof(double)));

		for (int xi = xl; xi <= xr; xi++)
		{
			setItem(xi, yi, Brush);
		}
	}
}

std::shared_ptr<IRenderContext> BitmapBase::getContext() const
{
	return std::make_shared<BitmapRenderContext>(this->getWidth(), this->getHeight());
}

EasyBitmap::EasyBitmap(img::EasyImage Image)
	: image(Image), zbuf(std::make_shared<ZBuffer>(Image.get_width(), Image.get_height()))
{
}

EasyBitmap::EasyBitmap(int Width, int Height)
	: image(Width, Height), zbuf(std::make_shared<ZBuffer>(Width, Height))
{
}

EasyBitmap::EasyBitmap(int Width, int Height, Vector4 Color)
	: image(Width, Height, ToColor(Color)), zbuf(std::make_shared<ZBuffer>(Width, Height))
{
}

EasyBitmap::EasyBitmap(int Width, int Height, std::shared_ptr<IDepthBuffer> DepthBuffer)
	: image(Width, Height), zbuf(DepthBuffer)
{
}

EasyBitmap::EasyBitmap(int Width, int Height, Vector4 Color, std::shared_ptr<IDepthBuffer> DepthBuffer)
	: image(Width, Height, ToColor(Color)), zbuf(DepthBuffer)
{
}

double EasyBitmap::getWidth() const
{
	return this->image.get_width();
}

double EasyBitmap::getHeight() const
{
	return this->image.get_height();
}

void EasyBitmap::Clear(Vector4 Color)
{
	this->image.clear(ToColor(Color));
}

img::Color EasyBitmap::ToColor(Vector3 Vector)
{
	return img::Color((uint8_t)round(Vector.X * 255), (uint8_t)round(Vector.Y * 255), (uint8_t)round(Vector.Z * 255));
}

img::Color EasyBitmap::ToColor(Vector4 Vector)
{
	return img::Color((uint8_t)round(Vector.X * 255), (uint8_t)round(Vector.Y * 255), (uint8_t)round(Vector.Z * 255));
}

Vector4 EasyBitmap::ToVector(img::Color Color)
{
	return Vector4(Color.red / 255.0, Color.green / 255.0, Color.blue / 255.0, 1.0);
}

Vector4 EasyBitmap::getItem(int X, int Y) const
{
	return ToVector(this->image(X, Y));
}

void EasyBitmap::setItem(int X, int Y, Vector4 Value)
{
	this->image(X, Y) = ToColor(Value);
}

img::EasyImage EasyBitmap::GetImage() const
{
	return this->image;
}