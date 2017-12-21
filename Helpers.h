#pragma once
#include <string>
#include <memory>
#include "ini_configuration.hh"
#include "IBrush.h"
#include "EasyImage.h"
#include "ArraySlice.h"
#include "IShape.h"
#include "IRenderTarget.h"
#include "ICommand.h"
#include "IOutputImage.h"
#include "IProjection.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

struct ImageSpecification
{
	unsigned int Width;
	unsigned int Height;
};

struct ScaledImageSpecification
{
	double Size;
	double Scale;
	std::string ImageType;
};

ImageSpecification ParseImageSpecification(const ini::Configuration& Config);
img::EasyImage CreateImageFromSpecification(const ini::Configuration& Config);

std::shared_ptr<Engine::IDepthBuffer> CreateDepthBuffer(int Width, int Height, bool UseZBuffer);
std::shared_ptr<Engine::IRenderTarget> CreateOutputImage(std::string Type, int Width, int Height, Engine::Vector4 BackgroundColor, bool UseZBuffer);

std::shared_ptr<Engine::IOutputImage> CreateRelativeImage(const ini::Configuration& Config, std::shared_ptr<Engine::IShape> Shape, std::shared_ptr<Engine::IBrush> Brush, bool ZBuffer);

template<typename T>
T GetValue(const ini::Entry& Entry, T Default)
{
	if (Entry.exists())
	{
		return (T)Entry;
	}
	else
	{
		return Default;
	}
}

template<typename T>
stdx::ArraySlice<T> GetArray(const ini::Entry& Entry, stdx::ArraySlice<T> Default)
{
	if (!Entry.exists())
	{
		return Default;
	}
	else
	{
		std::vector<T> vec = Entry;
		stdx::ArraySlice<T> result(vec.size());
		for (int i = 0; i < vec.size(); i++)
		{
			result[i] = vec[i];
		}
		return result;
	}
}

template<>
img::Color GetValue<img::Color>(const ini::Entry& Entry, img::Color Default);

template<>
Engine::Vector2 GetValue<Engine::Vector2>(const ini::Entry& Entry, Engine::Vector2 Default);

template<>
Engine::Vector3 GetValue<Engine::Vector3>(const ini::Entry& Entry, Engine::Vector3 Default);

template<>
Engine::Vector4 GetValue<Engine::Vector4>(const ini::Entry& Entry, Engine::Vector4 Default);

template<>
int GetValue<int>(const ini::Entry& Entry, int Default);

template<>
unsigned int GetValue<unsigned int>(const ini::Entry& Entry, unsigned int Default);

template<>
bool GetValue<bool>(const ini::Entry& Entry, bool Default);

template<>
double GetValue<double>(const ini::Entry& Entry, double Default);

template<>
std::string GetValue<std::string>(const ini::Entry& Entry, std::string Default);

template<>
std::shared_ptr<Engine::IProjection> GetValue<std::shared_ptr<Engine::IProjection>>(const ini::Entry& Entry, std::shared_ptr<Engine::IProjection> Default);

template<typename T>
T GetPi()
{
	return std::atan(1) * 4;
}

template<typename T>
T ToDegrees(T Value)
{
	return Value * 180 / GetPi<T>();
}

template<typename T>
T ToRadians(T Value)
{
	return Value * GetPi<T>() / 180;
}