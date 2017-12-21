#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <memory>
#include "ini_configuration.hh"
#include "IOutputImage.h"

struct RenderHandlerBase
{
	virtual std::shared_ptr<Engine::IOutputImage> Render(const ini::Configuration& Configuration) = 0;
};

class RenderHandlers
{
public:
	static void Register(std::shared_ptr<RenderHandlerBase> Handler, std::string Type);

	static std::shared_ptr<RenderHandlerBase> GetHandler(std::string Type);
	static std::shared_ptr<Engine::IOutputImage> Render(std::string Type, const ini::Configuration& Configuration);
	static std::shared_ptr<Engine::IOutputImage> Render(const ini::Configuration& Configuration);

private:
	static bool handlers_initialized;
	static std::map<std::string, std::shared_ptr<RenderHandlerBase>> handlers;
};