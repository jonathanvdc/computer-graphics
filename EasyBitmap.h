#pragma once
#include "IBitmap.h"
#include "EasyImage.h"
#include "IOutputImage.h"
#include "ZBuffer.h"
#include "ConstantDepthBuffer.h"
#include "Triangle.h"

namespace Engine
{
	class BitmapBase : public virtual IBitmap
	{
	public:
		// Draws a line from one point to another using a brush.
		virtual void DrawLine(int X0, int Y0, int X1, int Y1, std::shared_ptr<IBrush> Brush) override;

		virtual void FillTriangle(Triangle<Vector2> Triangle, std::shared_ptr<IBrush> Brush) override;

		// Sets the color of the pixel at (X, Y).
		virtual void setItem(int X, int Y, std::shared_ptr<IBrush> value);

		// Gets the surface's width.
		virtual double getWidth() const = 0;

		// Gets the surface's height.
		virtual double getHeight() const = 0;

		/// \brief Gets the color of the pixel at (X, Y).
		virtual Vector4 getItem(int X, int Y) const = 0;
		/// \brief Sets the color of the pixel at (X, Y).
		virtual void setItem(int X, int Y, Vector4 value) = 0;

		std::shared_ptr<IRenderContext> getContext() const override;

		std::shared_ptr<IDepthBuffer> getDepthBuffer() const override { return zbuf; }

	protected:
		std::shared_ptr<IDepthBuffer> zbuf;
	};

	class EasyBitmap : public BitmapBase, public virtual IOutputImage
	{
	public:
		EasyBitmap(img::EasyImage Image);
		EasyBitmap(int Width, int Height);
		EasyBitmap(int Width, int Height, Vector4 Color);
		EasyBitmap(int Width, int Height, std::shared_ptr<IDepthBuffer> DepthBuffer);
		EasyBitmap(int Width, int Height, Vector4 Color, std::shared_ptr<IDepthBuffer> DepthBuffer);

		// Gets the surface's width.
		double getWidth() const override;

		// Gets the surface's height.
		double getHeight() const override;

		// Clears the bitmap with the given color.
		void Clear(Vector4 Color);

		// Gets the color of the pixel at (X, Y).
		Vector4 getItem(int X, int Y) const override;

		// Sets the color of the pixel at (X, Y).
		void setItem(int X, int Y, Vector4 value) override;

		static img::Color ToColor(Vector3 Vector);
		static img::Color ToColor(Vector4 Color);
		static Vector4 ToVector(img::Color Color);

		img::EasyImage GetImage() const;

		std::string GetExtension() const override { return "bmp"; }
		void WriteTo(std::ostream& Target) override { Target << image; }
		std::shared_ptr<IDepthBuffer> getDepthBuffer() const override { return zbuf; }

	private:
		img::EasyImage image;
		std::shared_ptr<IDepthBuffer> zbuf;
	};

	class EmptyBitmap : public BitmapBase
	{
	public:
		EmptyBitmap(int Width, int Height, std::shared_ptr<IDepthBuffer> DepthBuffer)
		{
			this->width = Width;
			this->height = Height;
			this->zbuf = DepthBuffer;
		}

		// Gets the surface's width.
		double getWidth() const override { return this->width; }

		// Gets the surface's height.
		double getHeight() const override { return this->height; }

		// Gets the color of the pixel at (X, Y).
		Vector4 getItem(int X, int Y) const override { return Vector4(); }

		// Sets the color of the pixel at (X, Y).
		void setItem(int X, int Y, Vector4 value) override { }

	private:
		int width;
		int height;
	};
}
