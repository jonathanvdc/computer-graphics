#include "PortablePixelmap.h"

#include <memory>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include "IBitmap.h"
#include "ArraySlice.h"
#include "EasyBitmap.h"
#include "Vector4.h"
#include "ConstantDepthBuffer.h"

using namespace Engine;

PortablePixelmap::PortablePixelmap()
	: width(1), height(1), pixels(1)
{
	this->zbuf = std::make_shared<Engine::ConstantDepthBuffer>(1, 1);
}
PortablePixelmap::PortablePixelmap(int Width, int Height)
	: width(Width), height(Height), pixels(Width * Height)
{
	this->zbuf = std::make_shared<Engine::ConstantDepthBuffer>(width, height);
}
PortablePixelmap::PortablePixelmap(int Width, int Height, std::shared_ptr<IDepthBuffer> DepthBuffer)
	: width(Width), height(Height), pixels(Width * Height)
{
	this->zbuf = DepthBuffer;
}
PortablePixelmap::PortablePixelmap(int Width, int Height, Vector4 Color, std::shared_ptr<IDepthBuffer> DepthBuffer)
	: width(Width), height(Height), pixels(Width * Height)
{
	this->zbuf = DepthBuffer;
	for (auto& item : pixels)
	{
		item = Color;
	}
}

// Gets the surface's width.
double PortablePixelmap::getWidth() const
{
	return width;
}

// Gets the surface's height.
double PortablePixelmap::getHeight() const
{
	return height;
}

/// \brief Gets the color of the pixel at (X, Y).
Vector4 PortablePixelmap::getItem(int X, int Y) const
{
	return pixels[Y * width + X];
}
/// \brief Sets the color of the pixel at (X, Y).
void PortablePixelmap::setItem(int X, int Y, Vector4 value)
{
	pixels[Y * width + X] = value;
}

/// \brief Gets the portable pixelmap's pixel array.
stdx::ArraySlice<Vector4> PortablePixelmap::getPixels() const
{
	return pixels;
}

/// \brief "Trims" a word in a string, removing all whitespace around it.
void trimStringMut(std::string& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		std::not1(std::ptr_fun<int, int>(std::isspace))));
	s.erase(std::find_if(s.rbegin(), s.rend(),
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

std::string ReadPpmString(std::istream& Stream)
{
	std::string line;
	Stream >> line;
	trimStringMut(line);
	while ((line.size() == 0 || line[0] == '#') && Stream)
	{
		std::getline(Stream, line);
		Stream >> line;
		trimStringMut(line);
	}
	return line;
}

int ReadPpmInteger(std::istream& Stream)
{
	std::istringstream input(ReadPpmString(Stream));
	int result;
	input >> result;
	return result;
}

inline double clamp(double Value, double Min, double Max)
{
	return std::max<double>(std::min<double>(Value, Max), Min);
}

const double gammaValue = 2.2;
inline double gammaTransform(double Value, double Gamma, double Offset)
{
	return clamp(std::pow(Value, Gamma) + Offset, 0.0, 1.0);
}

PortablePixelmap Engine::ReadPixelmap(std::istream& Stream)
{
	std::string magic = ReadPpmString(Stream);
	if (magic != "P6" && magic != "P3")
		throw std::runtime_error("Only 'P3' and 'P6' ppm files are supported at this time.");

	int width = ReadPpmInteger(Stream);
	int height = ReadPpmInteger(Stream);
	int maxValue = ReadPpmInteger(Stream);

	if (magic == "P6")
	{
		char delim;
		Stream.get(delim);
		if (!std::isspace(delim))
			throw std::runtime_error("The header of a 'P6' ppm should be delimited from the pixel data with a single whitespace character.");
	}

	std::function<int(std::istream&)> parseElement;
	if (magic == "P3")
	{
		parseElement = ReadPpmInteger;
	}
	else if (maxValue < 256)
	{
		parseElement = [](std::istream& stream)
		{
			unsigned char result;
			stream >> result;
			return (int)result;
		};
	}
	else
	{
		parseElement = [](std::istream& stream)
		{
			unsigned short result;
			stream >> result;
			return (int)result;
		};
	}

	PortablePixelmap bitmap(width, height);
	auto pixels = bitmap.getPixels();

	stdx::ArraySlice<double> gammaRamp(maxValue + 1);	
	if (magic == "P6") // Only gamma-transform P6 ppms
	{
		for (int x = 0; x <= maxValue; x++)
		{
			double gammaOffset = 0.5 / maxValue;
			gammaRamp[x] = gammaTransform(x / (double)maxValue, 1.0 / gammaValue, gammaOffset);
		}
	}
	else
	{
		for (int x = 0; x <= maxValue; x++)
		{
			gammaRamp[x] = x / (double)maxValue;
		}
	}

	for (int i = height - 1; i >= 0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			int rVal = parseElement(Stream);
			int gVal = parseElement(Stream);
			int bVal = parseElement(Stream);
			double r = gammaRamp[rVal];
			double g = gammaRamp[gVal];
			double b = gammaRamp[bVal];
			pixels[i * width + j] = Vector4(r, g, b, 1.0);

			if (!Stream)
			{
				throw std::runtime_error("The given '" + magic + "' ppm did not contain sufficient pixel data to fill the entire image.");
			}
		}
	}

	return bitmap;
}

std::istream& operator>>(std::istream& Stream, PortablePixelmap& Pixelmap)
{
	Pixelmap = ReadPixelmap(Stream);
	return Stream;
}

void PortablePixelmap::WriteTo(std::ostream& Target)
{
	Target << "P3" << std::endl
		<< getWidth() << " " << getHeight() << std::endl
		<< "255" << std::endl;

	const double maxValue = 255.0;

	int index = 0;
	for (int i = height - 1; i >= 0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			auto pix = pixels[i * width + j];

			Target << (int)(pix.X * maxValue) << " "
				   << (int)(pix.Y * maxValue) << " "
				   << (int)(pix.Z * maxValue) << "  ";
			if (index == 15)
			{
				Target << std::endl;
				index = 0;
			}
			else
			{
				index++;
			}
		}
	}
}