#include "LightingHandler.h"

#include <memory>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "ArraySlice.h"
#include "ISkin.h"
#include "LightingTexture.h"
#include "LightingSkin.h"
#include "ZBufferingHandlerBase.h"
#include "DiffuseLightComponent.h"
#include "SpecularLightComponent.h"
#include "CompositeLightComponent.h"
#include "PointLight.h"
#include "InfinityLight.h"
#include "CompositeMesh.h"
#include "Scene.h"
#include "ShadowPointLight.h"
#include "SolidColorBrush3.h"
#include "PlaneTextureBrush.h"
#include "EasyImage.h"
#include "OverBrush.h"
#include "OpacityMask.h"
#include "PortablePixelmap.h"
#include "ISampler.h"
#include "NearestNeighborClampingSampler.h"
#include "NearestNeighborWrappingSampler.h"
#include "LinearInterpolationSampler.h"
#include "SphereTextureBrush.h"
#include "CosineInterpolationSampler.h"
#include "CubicInterpolationSampler.h"
#include "AdditiveBrush.h"
#include "SubtractBrush.h"
#include "MultiplicativeBrush.h"
#include "RadialGradientBrush3.h"

bool LightingHandler::ShouldFillMesh(const ini::Section& Figure)
{
	return true;
}

std::shared_ptr<Engine::IBitmap> LightingHandler::ReadBitmap(std::string TextureName)
{
	if (imageCache.find(TextureName) != imageCache.end())
	{
		return imageCache[TextureName];
	}
	else if (TextureName.substr(TextureName.size() - 4) == ".ppm")
	{
		auto image = std::make_shared<PortablePixelmap>();
		std::ifstream target(TextureName, std::ios_base::binary | std::ios_base::in);
		target >> *image;
		target.close();
		imageCache[TextureName] = image;
		return image;
	}
	else
	{
		img::EasyImage img;
		std::ifstream target(TextureName, std::ios_base::binary | std::ios_base::in);
		target >> img;
		target.close();
		auto easyBitmap = std::make_shared<Engine::EasyBitmap>(img);
		imageCache[TextureName] = easyBitmap;
		return easyBitmap;
	}
}

std::shared_ptr<Engine::IBitmap> LightingHandler::ParseImage(std::string TextureName)
{
	const std::string randomPrefix = "random:";
	if (TextureName.substr(0, randomPrefix.length()) == randomPrefix)
	{
		std::istringstream argParser(TextureName.substr(randomPrefix.length()));
		int width, height;
		argParser >> width >> height;
		width++;
		height++;

		auto tex = std::make_shared<Engine::EasyBitmap>(width, height);
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				tex->setItem(i, j, Engine::Vector4((rand() % 256) / 256.0, (rand() % 256) / 256.0, (rand() % 256) / 256.0, 1.0));
			}
		}
		return tex;
	}
	else
	{
		return ReadBitmap(TextureName);
	}
}

std::shared_ptr<Engine::ISampler> LightingHandler::ParseSampler(const ini::Configuration& Configuration, const ini::Section& Figure)
{
	std::string type = GetValue<std::string>(Figure["type"], "default");
	if (type == "linear")
	{
		auto underlying = ParseSamplerProperty(Configuration, Figure, "sampler");
		return std::make_shared<Engine::LinearInterpolationSampler>(underlying);
	}
	else if (type == "cosine")
	{
		auto underlying = ParseSamplerProperty(Configuration, Figure, "sampler");
		return std::make_shared<Engine::CosineInterpolationSampler>(underlying);
	}
	else if (type == "cubic")
	{
		auto underlying = ParseSamplerProperty(Configuration, Figure, "sampler");
		return std::make_shared<Engine::CubicInterpolationSampler>(underlying);
	}
	else
	{
		return ParsePrimitiveSampler(type);
	}
}

std::shared_ptr<Engine::ISampler> LightingHandler::ParsePrimitiveSampler(std::string Type)
{
	if (Type == "default" || Type == "nearest-neighbor" || Type == "nearest-neighbor-wrap" || Type == "wrap")
	{
		return Engine::NearestNeighborWrappingSampler::getInstance();
	}
	else if (Type == "nearest-neighbor-clamp" || Type == "clamp")
	{
		return Engine::NearestNeighborClampingSampler::getInstance();
	}
	if (Type == "linear")
	{
		auto underlying = ParsePrimitiveSampler("default");
		return std::make_shared<Engine::LinearInterpolationSampler>(underlying);
	}
	else if (Type == "cosine")
	{
		auto underlying = ParsePrimitiveSampler("default");
		return std::make_shared<Engine::CosineInterpolationSampler>(underlying);
	}
	else if (Type == "cubic")
	{
		auto underlying = ParsePrimitiveSampler("default");
		return std::make_shared<Engine::CubicInterpolationSampler>(underlying);
	}
	else
	{
		throw std::runtime_error("Sampler type '" + Type + "' was not recognized as a primitive sampler type.");
	}
}

std::shared_ptr<Engine::ISampler> LightingHandler::ParseSamplerProperty(const ini::Configuration& Configuration, const ini::Section& Figure, std::string Name)
{
	std::string reference = GetValue<std::string>(Figure[Name + "Reference"], "");
	if (reference == "")
	{
		std::string samplerVal = GetValue<std::string>(Figure[Name], "default");
		return ParsePrimitiveSampler(samplerVal);
	}
	else
	{
		return ParseSampler(Configuration, Configuration[reference]);
	}
}

std::shared_ptr<Engine::IBrush3> LightingHandler::ParseBrush3(const ini::Configuration& Configuration, const ini::Section& Figure)
{
	std::string texType = GetValue<std::string>(Figure["type"], "solid");

	const static std::string blendPrefix = "blend-";

	if (texType == "solid")
	{
		Engine::Vector4 color(GetValue<Engine::Vector3>(Figure["color"], Engine::Vector3(0.0)), 1.0);
		return std::make_shared<Engine::SolidColorBrush3>(color);
	}
	else if (texType == "opacity-mask")
	{
		auto mask = ParseReflectionBrush3(Configuration, Figure, "mask");
		auto brush = ParseReflectionBrush3(Configuration, Figure, "brush");

		return std::make_shared<Engine::OpacityMask>(brush, mask);
	}
	else if (texType.substr(0, blendPrefix.length()) == blendPrefix)
	{
		auto top = ParseReflectionBrush3(Configuration, Figure, "top");
		auto bottom = ParseReflectionBrush3(Configuration, Figure, "bottom");

		std::string blendType = texType.substr(blendPrefix.length());

		if (blendType == "over")
		{
			return std::make_shared<Engine::OverBrush>(top, bottom);
		}
		else if (blendType == "add" || blendType == "additive")
		{
			return std::make_shared<Engine::AdditiveBrush>(top, bottom);
		}
		else if (blendType == "multiply" || blendType == "multiplicative")
		{
			return std::make_shared<Engine::MultiplicativeBrush>(top, bottom);
		}
		else if (blendType == "subtract")
		{
			return std::make_shared<Engine::SubtractBrush>(top, bottom);
		}
	}
	if (texType == "plane-texture")
	{
		std::string texName = GetValue<std::string>(Figure["texture"], "random:10 10");

		auto tex = ParseImage(texName);

		auto planePos = GetValue<Engine::Vector3>(Figure["position"], Engine::Vector3());
		auto u = GetValue<Engine::Vector3>(Figure["uDirection"], Engine::Vector3());
		auto v = GetValue<Engine::Vector3>(Figure["vDirection"], Engine::Vector3());


		return std::make_shared<Engine::PlaneTextureBrush>(globalTransformation.Transform(planePos),
			globalTransformation.TransformDirection(u),
			globalTransformation.TransformDirection(v),
			tex,
			ParseSamplerProperty(Configuration, Figure, "sampler"));
	}
	else if (texType == "sphere-texture")
	{
		std::string texName = GetValue<std::string>(Figure["texture"], "random:10 10");

		auto tex = ParseImage(texName);

		auto spherePos = GetValue<Engine::Vector3>(Figure["position"], Engine::Vector3());

		return std::make_shared<Engine::SphereTextureBrush>(globalTransformation.Transform(spherePos),
			tex,
			ParseSamplerProperty(Configuration, Figure, "sampler"));
	}
	else if (texType == "radial-gradient")
	{
		auto spherePos = globalTransformation.Transform(GetValue<Engine::Vector3>(Figure["position"], Engine::Vector3()));
		double radius = GetValue<double>(Figure["radius"], 1);

		auto center = ParseReflectionBrush3(Configuration, Figure, "center");
		auto periphery = ParseReflectionBrush3(Configuration, Figure, "periphery");

		return std::make_shared<Engine::RadialGradientBrush3>(spherePos, radius, center, periphery);
	}
	else
	{
		throw std::runtime_error("Could not recognize texture type '" + texType + "' in section '" + Figure.get_name() + "'.");
	}
}

std::shared_ptr<Engine::IBrush3> LightingHandler::ParseReflectionBrush3(const ini::Configuration& Configuration, const ini::Section& Figure, std::string Name)
{
	std::string texName = GetValue<std::string>(Figure[Name + "Texture"], "");

	static const std::string reflectionSuffix = "Reflection";
	static const std::string colorSuffix = "Color";
	static const std::string lightSuffix = "Light";

	if (texName == "")
	{
		auto colorEntry = Figure[Name + colorSuffix];
		if (colorEntry.exists())
		{
			Engine::Vector4 reflection(GetValue<Engine::Vector3>(colorEntry, Engine::Vector3(0.0)), 1.0);
			return std::make_shared<Engine::SolidColorBrush3>(reflection);
		}
		else if (Figure[Name + lightSuffix].exists())
		{
			Engine::Vector4 reflection(GetValue<Engine::Vector3>(Figure[Name + lightSuffix], Engine::Vector3(0.0)), 1.0);
			return std::make_shared<Engine::SolidColorBrush3>(reflection);
		}
		else
		{
			Engine::Vector4 reflection(GetValue<Engine::Vector3>(Figure[Name + reflectionSuffix], Engine::Vector3(0.0)), 1.0);
			return std::make_shared<Engine::SolidColorBrush3>(reflection);
		}
	}
	else
	{
		return ParseBrush3(Configuration, Configuration[texName]);
	}
}

std::shared_ptr<Engine::ISkin> LightingHandler::GetDepthSkin(const ini::Section& Figure, bool IsLine)
{
	if (IsLine)
	{
		return std::make_shared<Engine::TextureSkin>(std::make_shared<Engine::EmptyTexture>());
	}

	auto ambient = ParseReflectionBrush3(*config, Figure, "ambient");
	auto diffuse = ParseReflectionBrush3(*config, Figure, "diffuse");
	auto specular = ParseReflectionBrush3(*config, Figure, "specular");

	double reflectivity = GetValue<double>(Figure["reflectionCoefficient"], 1.0);
	Engine::ReflectionProperties props(ambient, diffuse, specular, reflectivity);
	return std::make_shared<Engine::LightingSkin>(props, lightState);
}

bool LightingHandler::IsAdditiveTransparent(std::shared_ptr<Engine::IBrush3> Brush)
{
	if (stdx::isinstance<Engine::SolidColorBrush3>(Brush))
	{
		return std::dynamic_pointer_cast<Engine::SolidColorBrush3>(Brush)->Color.getXYZ() == Engine::Vector3();
	}
	else
	{
		return false;
	}
}

std::shared_ptr<Engine::ILightComponent> LightingHandler::ParseLightComponent(const ini::Section& Light)
{
	lightState->AmbientColor += Engine::Vector4(GetValue<Engine::Vector3>(Light["ambientLight"], Engine::Vector3()), 0.0);
	auto diffuseLight = ParseReflectionBrush3(*config, Light, "diffuse");
	auto specularLight = ParseReflectionBrush3(*config, Light, "specular");
	if (IsAdditiveTransparent(specularLight))
	{
		return std::make_shared<Engine::DiffuseLightComponent>(diffuseLight);
	}
	else if (IsAdditiveTransparent(diffuseLight))
	{
		return std::make_shared<Engine::SpecularLightComponent>(specularLight);
	}
	else
	{
		return std::make_shared<Engine::CompositeLightComponent>(
			std::make_shared<Engine::DiffuseLightComponent>(diffuseLight),
			std::make_shared<Engine::SpecularLightComponent>(specularLight));
	}
}

std::shared_ptr<Engine::ILight> LightingHandler::ParseLight(const ini::Section& Light, int ShadowMaskSize)
{
	auto component = ParseLightComponent(Light);
	if (GetValue<bool>(Light["infinity"], false))
	{
		auto dir = globalTransformation.TransformDirection(GetValue<Engine::Vector3>(Light["direction"], Engine::Vector3()) * -1);
		return std::make_shared<Engine::InfinityLight>(dir, component);
	}
	else
	{
		auto pos = GetValue<Engine::Vector3>(Light["location"], Engine::Vector3());
		auto loc = globalTransformation.Transform(pos);

		if (ShadowMaskSize > 0)
		{
			auto proj = std::make_shared<Engine::PerspectiveProjection>(1.0);
			auto brush = std::make_shared<SolidColorBrush>(Engine::Vector4(0.0));

			auto globalTrans = std::make_shared<Engine::MatrixTransformation>(Matrix<3>::inv(globalTransformation.getTransformation()) * Engine::EyePointTransform(pos));

			Engine::Scene scene(sceneContents, globalTrans, proj, brush, ShadowMaskSize, 0.99);

			auto bounds = scene.getBounds();
			auto mask = std::make_shared<Engine::ZBuffer>(bounds.getWidth(), bounds.getHeight());

			auto target = std::make_shared<Engine::EmptyBitmap>(bounds.getWidth(), bounds.getHeight(), mask);

			scene.Render(target);

			OutputZBuffer(Light, GetValue<std::string>(Light["name"], Light.get_name()), mask);

			return std::make_shared<Engine::ShadowPointLight>(loc, component, mask, globalTrans, proj, scene.getProjectedShape()->GetTransformation());
		}
		else
		{
			return std::make_shared<Engine::PointLight>(loc, component);
		}
	}
}

std::shared_ptr<Engine::IOutputImage> LightingHandler::Render(const ini::Configuration& Configuration)
{
	imageCache.clear();
	this->config = &Configuration;

	auto eye = GetValue<Engine::Vector3>(Configuration["General"]["eye"], Engine::Vector3(0, 0, 0));
	int lightCount = GetValue<int>(Configuration["General"]["nrLights"], 0);

	auto globalTransformMatrix = Engine::EyePointTransform(eye);
	this->globalTransformation = Engine::MatrixTransformation(globalTransformMatrix);

	int nrOfFigures = GetValue<int>(Configuration["General"]["nrFigures"], 0);

	this->lightState = std::make_shared<Engine::LightingState>(Engine::Vector4(Engine::Vector3(), 1.0), stdx::ArraySlice<std::shared_ptr<Engine::ILight>>());

	stdx::ArraySlice<std::shared_ptr<Engine::IMesh>> meshes(nrOfFigures);
	for (int i = 0; i < nrOfFigures; i++)
	{
		meshes[i] = ReadTransformedMesh(Configuration["Figure" + std::to_string(i)], globalTransformMatrix);
	}

	sceneContents = std::make_shared<Engine::CompositeMesh>(meshes);

	int shadowMaskSize = GetValue<bool>(Configuration["General"]["shadowEnabled"], false) ? GetValue<int>(Configuration["General"]["shadowMask"], 256) : 0;

	stdx::ArraySlice<std::shared_ptr<Engine::ILight>> lights(lightCount);
	for (int i = 0; i < lightCount; i++)
	{
		lights[i] = ParseLight(Configuration["Light" + std::to_string(i)], shadowMaskSize);
	}
	this->lightState->Lights = lights;

	auto proj = GetValue<std::shared_ptr<Engine::IProjection>>(Configuration["General"]["projection"], std::make_shared<Engine::PerspectiveProjection>(1.0));

	auto shape = sceneContents->Project(proj);

	auto image = CreateRelativeImage(Configuration, shape, std::make_shared<Engine::SolidColorBrush>(Engine::Vector4(0.0, 1.0, 0.0, 1.0)), UseZBuffer());

	OutputZBuffer(Configuration["General"], image);

	return image;
}