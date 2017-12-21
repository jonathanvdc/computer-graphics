#pragma once

#include <memory>
#include <unordered_map>
#include "ArraySlice.h"
#include "ZBufferingHandlerBase.h"
#include "IBrush.h"
#include "IBitmap.h"
#include "ISampler.h"
#include "IOutputImage.h"
#include "ISkin.h"
#include "ISampler.h"
#include "IBrush3.h"
#include "ILight.h"
#include "ILightComponent.h"
#include "LightingState.h"
#include "ini_configuration.hh"

class LightingHandler : public ZBufferingHandlerBase
{
public:
	/// \brief Determines whether the given figure should be filled or not.
	bool ShouldFillMesh(const ini::Section& Figure) override;

	/// \brief Loads the image referred to by the given path into memory.
	std::shared_ptr<Engine::IBitmap> ReadBitmap(std::string TextureName);

	/// \brief Parses the given texture name and loads the image it refers to into memory.
	std::shared_ptr<Engine::IBitmap> ParseImage(std::string TextureName);

	/// \brief Parses a sampler section.
	std::shared_ptr<Engine::ISampler> ParseSampler(const ini::Configuration& Configuration, const ini::Section& Figure);

	/// \brief Parses a sampler name.
	std::shared_ptr<Engine::ISampler> ParsePrimitiveSampler(std::string Type);

	/// \brief Parses a sampler entry.
	std::shared_ptr<Engine::ISampler> ParseSamplerProperty(const ini::Configuration& Configuration, const ini::Section& Figure, std::string Name);

	/// \brief Parses a 3D brush.
	std::shared_ptr<Engine::IBrush3> ParseBrush3(const ini::Configuration& Configuration, const ini::Section& Figure);

	/// \brief Parses a reflection brush.
	std::shared_ptr<Engine::IBrush3> ParseReflectionBrush3(const ini::Configuration& Configuration, const ini::Section& Figure, std::string Name);

	/// \brief Creates a depth skin for the given figure.
	std::shared_ptr<Engine::ISkin> GetDepthSkin(const ini::Section& Figure, bool IsLine) override;

	/// \brief Determines whether the given brush is transparent in an additive
	//  blending context, i.e. is black.
	bool IsAdditiveTransparent(std::shared_ptr<Engine::IBrush3> Brush);

	/// \brief Parses the light component in the given section.
	std::shared_ptr<Engine::ILightComponent> ParseLightComponent(const ini::Section& Light);

	/// \brief Parses the light in the given section.
	std::shared_ptr<Engine::ILight> ParseLight(const ini::Section& Light, int ShadowMaskSize);

	/// \brief Renders the the scene in the given configuration.
	std::shared_ptr<Engine::IOutputImage> Render(const ini::Configuration& Configuration) override;

private:
	std::shared_ptr<Engine::LightingState> lightState;
	std::shared_ptr<Engine::IMesh> sceneContents;
	std::unordered_map<std::string, std::shared_ptr<Engine::IBitmap>> imageCache;
	const ini::Configuration* config;
	Engine::MatrixTransformation globalTransformation;
};