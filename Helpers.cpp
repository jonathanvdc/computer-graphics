#include "Helpers.h"
#include "SvgRenderTarget.h"
#include "EasyBitmap.h"
#include "NormalizedShape.h"
#include "PerspectiveProjection.h"
#include "ParallelProjection.h"
#include "PortablePixelmap.h"

ImageSpecification ParseImageSpecification(const ini::Configuration& Config)
{
	return{ (unsigned int)(int)Config["ImageProperties"]["width"], (unsigned int)(int)Config["ImageProperties"]["height"] };
}

img::EasyImage CreateImageFromSpecification(const ini::Configuration& Config)
{
	auto specs = ParseImageSpecification(Config);
	return img::EasyImage(specs.Width, specs.Height);
}

std::shared_ptr<Engine::IDepthBuffer> CreateDepthBuffer(int Width, int Height, bool UseZBuffer)
{
	return UseZBuffer ?
		(std::shared_ptr<Engine::IDepthBuffer>)std::make_shared<Engine::ZBuffer>(Width, Height) : 
		(std::shared_ptr<Engine::IDepthBuffer>)std::make_shared<Engine::ConstantDepthBuffer>(Width, Height);
}

std::shared_ptr<Engine::IRenderTarget> CreateOutputImage(std::string Type, int Width, int Height, Engine::Vector4 BackgroundColor, bool UseZBuffer)
{
	if (Type == "svg")
	{
		auto image = std::make_shared<Engine::SvgRenderTarget>(Width, Height);
		return image;
	}
	else if (Type == "ppm")
	{
		auto zbuf = CreateDepthBuffer(Width, Height, UseZBuffer);
		return std::make_shared<Engine::PortablePixelmap>(Width, Height, BackgroundColor, zbuf);
	}
	else
	{
		auto zbuf = CreateDepthBuffer(Width, Height, UseZBuffer);
		return std::make_shared<Engine::EasyBitmap>(Width, Height, BackgroundColor, zbuf);
	}
}

std::shared_ptr<Engine::IOutputImage> CreateRelativeImage(const ini::Configuration& Config, std::shared_ptr<Engine::IShape> Shape, std::shared_ptr<Engine::IBrush> Brush, bool UseZBuffer)
{
	double size = GetValue<double>(Config["General"]["size"], 256);
	double scale = GetValue<double>(Config["General"]["scale"], 0.95);
	std::string imagetype = GetValue<std::string>(Config["General"]["outputtype"], "bmp");

	Engine::NormalizedShape renderShape(Shape, size, scale);

	auto bounds = renderShape.getBounds();
	Engine::Vector4 bgColor(GetValue<Engine::Vector3>(Config["General"]["backgroundcolor"], Engine::Vector3(0, 0, 0)), 1);
	
	auto image = CreateOutputImage(imagetype, bounds.MaxX, bounds.MaxY, bgColor, UseZBuffer);
	renderShape.Render(Brush)->Execute(image);
	return std::dynamic_pointer_cast<Engine::IOutputImage>(image);
}

template<>
img::Color GetValue<img::Color>(const ini::Entry& Entry, img::Color Default)
{
	ini::DoubleTuple result;
	if (Entry.as_double_tuple_if_exists(result))
	{
		return img::Color(result[0] * 255, result[1] * 255, result[2] * 255);
	}
	else
	{
		return Default;
	}
}

template<>
Engine::Vector2 GetValue<Engine::Vector2>(const ini::Entry& Entry, Engine::Vector2 Default)
{
	auto result = Entry.as_double_tuple_or_default(std::vector<double>({ Default.X, Default.Y }));
	return Engine::Vector2(result.at(0), result.at(1));
}

template<>
Engine::Vector3 GetValue<Engine::Vector3>(const ini::Entry& Entry, Engine::Vector3 Default)
{
	auto result = Entry.as_double_tuple_or_default(std::vector<double>({ Default.X, Default.Y, Default.Z }));
	return Engine::Vector3(result.at(0), result.at(1), result.at(2));
}

template<>
Engine::Vector4 GetValue<Engine::Vector4>(const ini::Entry& Entry, Engine::Vector4 Default)
{
	auto result = Entry.as_double_tuple_or_default(std::vector<double>({ Default.X, Default.Y, Default.Z, Default.W }));
	return Engine::Vector4(result.at(0), result.at(1), result.at(2), result.at(3));
}

template<>
int GetValue<int>(const ini::Entry& Entry, int Default)
{
	return Entry.as_int_or_default(Default);
}

template<>
unsigned int GetValue<unsigned int>(const ini::Entry& Entry, unsigned int Default)
{
	return (unsigned int)GetValue<int>(Entry, (int)Default);
}

template<>
bool GetValue<bool>(const ini::Entry& Entry, bool Default)
{
	return Entry.as_bool_or_default(Default);
}

template<>
double GetValue<double>(const ini::Entry& Entry, double Default)
{
	return Entry.as_double_or_default(Default);
}

template<>
std::string GetValue<std::string>(const ini::Entry& Entry, std::string Default)
{
	return Entry.as_string_or_default(Default);
}

template<>
std::shared_ptr<Engine::IProjection> GetValue<std::shared_ptr<Engine::IProjection>>(const ini::Entry& Entry, std::shared_ptr<Engine::IProjection> Default)
{
	if (!Entry.exists())
	{
		return Default;
	}
	std::string val = GetValue<std::string>(Entry, "perspective");
	if (val == "parallel")
	{
		return std::make_shared<Engine::ParallelProjection>();
	}
	else if (val == "perspective")
	{
		return std::make_shared<Engine::PerspectiveProjection>(1.0);
	}
	else
	{
		throw std::invalid_argument("'" + val + "' was not recognized as a valid projection type.");
	}
}