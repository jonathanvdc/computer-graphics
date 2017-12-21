#pragma once
#include "RenderHandler.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <exception>
#include <functional>
#include <algorithm>
#include "IOutputImage.h"
#include "RenderHandler.h"
#include "IShape.h"
#include "IProjection.h"
#include "MultiLine.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Face.h"
#include "Wireframe.h"
#include "Helpers.h"
#include "MatrixTransformation.h"
#include "MatrixHelpers.h"
#include "SolidColorBrush.h"
#include "NormalizedShape.h"
#include "PerspectiveProjection.h"
#include "ParallelProjection.h"
#include "Cube.h"
#include "Tetrahedron.h"
#include "Octahedron.h"
#include "Icosahedron.h"
#include "Dodecahedron.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Torus.h"
#include "lparser.h"
#include "TurtleMesh.h"
#include "CompositeShape.h"
#include "IsInstance.h"
#include "Buckyball.h"
#include "Mengersponge.h"
#include "BrushTexture.h"
#include "TextureSkin.h"
#include "DepthSkin.h"
#include "EmptyTexture.h"
#include "TexturedShape.h"
#include "CompositeMesh.h"

class MeshHandlerBase : public RenderHandlerBase
{
public:

	typedef std::function<std::shared_ptr<Engine::IMesh>(std::shared_ptr<Engine::Polyhedron>)> PolyhedronLambda;
	typedef std::function<std::shared_ptr<Engine::IMesh>(std::shared_ptr<Engine::Wireframe>)> WireframeLambda;

	virtual bool ShouldFillMesh(const ini::Section& Figure) = 0;
	virtual bool UseZBuffer() = 0;

	void DrawCharacter(Engine::TurtleMesh& Path, LParser::LSystem3D& LSys, char Value, int RecursionLevel);

	std::shared_ptr<Engine::IMesh> CreateL3DMesh(std::string Path, std::shared_ptr<Engine::ISkin> Skin);

	std::shared_ptr<Engine::IMesh> Apply(std::shared_ptr<Engine::IMesh> const& Mesh, PolyhedronLambda Function);

	std::shared_ptr<Engine::IMesh> Apply(std::shared_ptr<Engine::IMesh> const& Mesh, WireframeLambda Function);

	std::shared_ptr<Engine::IMesh> ReadMesh(std::string type, const ini::Section& Figure);

	virtual std::shared_ptr<Engine::ISkin> GetDepthSkin(const ini::Section& Figure, bool IsLine);

	std::shared_ptr<Engine::IMesh> ReadMesh(const ini::Section& Figure);

	std::shared_ptr<Engine::IMesh> ReadTransformedMesh(const ini::Section& Figure, const Matrix<3>& GlobalTransform);

	std::shared_ptr<Engine::IShape> RenderFigure(const ini::Section& Figure, const Matrix<3>& GlobalTransform, std::shared_ptr<Engine::IProjection> Projection);

	std::shared_ptr<Engine::IShape> ParseShape(const ini::Configuration& Configuration);

	virtual std::shared_ptr<Engine::IOutputImage> Render(const ini::Configuration& Configuration);
};