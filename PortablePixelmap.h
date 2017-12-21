#pragma once
#include <memory>
#include <iostream>
#include "IBitmap.h"
#include "ArraySlice.h"
#include "EasyBitmap.h"
#include "Vector4.h"

namespace Engine
{
	class PortablePixelmap : public BitmapBase, public virtual IOutputImage
	{
	public:
		PortablePixelmap();
		PortablePixelmap(int Width, int Height);
		PortablePixelmap(int Width, int Height, std::shared_ptr<IDepthBuffer> DepthBuffer);
		PortablePixelmap(int Width, int Height, Vector4 Color, std::shared_ptr<IDepthBuffer> DepthBuffer);

		// Gets the surface's width.
		double getWidth() const override;

		// Gets the surface's height.
		double getHeight() const override;

		/// \brief Gets the color of the pixel at (X, Y).
		Vector4 getItem(int X, int Y) const override;
		/// \brief Sets the color of the pixel at (X, Y).
		void setItem(int X, int Y, Vector4 value) override;

		/// \brief Gets the portable pixelmap's pixel array.
		stdx::ArraySlice<Vector4> getPixels() const;

		std::string GetExtension() const override { return "ppm"; }
		void WriteTo(std::ostream& Target) override;
	private:
		int width;
		int height;
		stdx::ArraySlice<Vector4> pixels;
	};

	PortablePixelmap ReadPixelmap(std::istream& Stream);
}

std::istream& operator>>(std::istream& Stream, Engine::PortablePixelmap& Pixelmap);