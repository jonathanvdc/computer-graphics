#include "RenderHandler.h"

#include <memory>
#include <string>
#include "IOutputImage.h"
#include "ini_configuration.hh"

void RenderHandlers::Register(std::shared_ptr<RenderHandlerBase> Handler, std::string Type)
{
	if (!handlers_initialized)
	{
		handlers = std::map<std::string, std::shared_ptr<RenderHandlerBase>>();
		handlers_initialized = true;
	}
	handlers[Type] = Handler;
}

std::shared_ptr<RenderHandlerBase> RenderHandlers::GetHandler(std::string Type)
{
	return handlers[Type];
}

std::shared_ptr<Engine::IOutputImage> RenderHandlers::Render(std::string Type, const ini::Configuration& Configuration)
{
	return handlers[Type]->Render(Configuration);
}

std::shared_ptr<Engine::IOutputImage> RenderHandlers::Render(const ini::Configuration& Configuration)
{
	std::string type = Configuration["General"]["type"].as_string_or_die();
	return Render(type, Configuration);
}

bool RenderHandlers::handlers_initialized = false;
std::map<std::string, std::shared_ptr<RenderHandlerBase>> RenderHandlers::handlers;