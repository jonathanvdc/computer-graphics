#include "MeshHandlerBase.h"

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

void MeshHandlerBase::DrawCharacter(Engine::TurtleMesh& Path, LParser::LSystem3D& LSys, char Value, int RecursionLevel)
{
	if (Value == '(')
	{
		Path.PushState();
	}
	else if (Value == ')')
	{
		Path.PopState();
	}
	else if (Value == '+')
	{
		Path.TurnLeft(ToRadians(LSys.get_angle()));
	}
	else if (Value == '-')
	{
		Path.TurnRight(ToRadians(LSys.get_angle()));
	}
	else if (Value == '^')
	{
		Path.PitchUp(ToRadians(LSys.get_angle()));
	}
	else if (Value == '&')
	{
		Path.PitchDown(ToRadians(LSys.get_angle()));
	}
	else if (Value == '\\')
	{
		Path.RollLeft(ToRadians(LSys.get_angle()));
	}
	else if (Value == '/')
	{
		Path.RollRight(ToRadians(LSys.get_angle()));
	}
	else if (Value == '|')
	{
		Path.ReverseDirection();
	}
	else if (RecursionLevel == 0)
	{
		if (LSys.draw(Value))
		{
			Path.StartDrawing();
		}
		else
		{
			Path.StopDrawing();
		}
		Path.MoveForward(Value);
	}
	else
	{
		for (char item : LSys.get_replacement(Value))
		{
			DrawCharacter(Path, LSys, item, RecursionLevel - 1);
		}
	}
}

std::shared_ptr<Engine::IMesh> MeshHandlerBase::CreateL3DMesh(std::string Path, std::shared_ptr<Engine::ISkin> Skin)
{
	LParser::LSystem3D lsys;

	std::ifstream fin(Path);
	fin >> lsys;
	fin.close();

	Engine::TurtleMesh tPath;

	for (char item : lsys.get_initiator())
	{
		DrawCharacter(tPath, lsys, item, lsys.get_nr_iterations());
	}

	return tPath.ToMesh(Skin);
}

std::shared_ptr<Engine::IMesh> MeshHandlerBase::Apply(std::shared_ptr<Engine::IMesh> const& Mesh, PolyhedronLambda Function)
{
	if (stdx::isinstance<Engine::ComplexMesh>(Mesh))
	{
		return Function(std::dynamic_pointer_cast<Engine::ComplexMesh>(Mesh)->Lower());
	}
	else if (stdx::isinstance<Engine::Polyhedron>(Mesh))
	{
		return Function(std::dynamic_pointer_cast<Engine::Polyhedron>(Mesh));
	}
	else if (stdx::isinstance<Engine::CompositeMesh>(Mesh))
	{
		auto compositeMesh = std::dynamic_pointer_cast<Engine::CompositeMesh>(Mesh);
		auto meshes = compositeMesh->getMeshes();
		stdx::ArraySlice<std::shared_ptr<Engine::IMesh>> results(meshes.GetLength());
		for (int i = 0; i < results.GetLength(); i++)
		{
			results[i] = Apply(meshes[i], Function);
		}
		return std::make_shared<Engine::CompositeMesh>(results);
	}
	else
	{
		throw std::invalid_argument("Invalid mesh type: Mesh is no polyhedron. Transformation could not be applied.");
	}
}

std::shared_ptr<Engine::IMesh> MeshHandlerBase::Apply(std::shared_ptr<Engine::IMesh> const& Mesh, WireframeLambda Function)
{
	if (stdx::isinstance<Engine::Wireframe>(Mesh))
	{
		return Function(std::dynamic_pointer_cast<Engine::Wireframe>(Mesh));
	}
	else if (stdx::isinstance<Engine::CompositeMesh>(Mesh))
	{
		auto compositeMesh = std::dynamic_pointer_cast<Engine::CompositeMesh>(Mesh);
		auto meshes = compositeMesh->getMeshes();
		stdx::ArraySlice<std::shared_ptr<Engine::IMesh>> results(meshes.GetLength());
		for (int i = 0; i < results.GetLength(); i++)
		{
			results[i] = Apply(meshes[i], Function);
		}
		return std::make_shared<Engine::CompositeMesh>(results);
	}
	else
	{
		PolyhedronLambda func = [&](std::shared_ptr<Engine::Polyhedron> poly) { return Function(poly->ToWireframe()); };
		return Apply(Mesh, func);
	}
}

std::shared_ptr<Engine::IMesh> MeshHandlerBase::ReadMesh(std::string type, const ini::Section& Figure)
{
	const std::string fracName = "Fractal";
	const std::string dualName = "Dual";
	const std::string truncatedName = "Truncated";
	const std::string thickName = "Thick";
	if (type.substr(0, fracName.length()) == fracName)
	{
		auto mesh = ReadMesh(type.substr(fracName.length(), type.length() - fracName.length()), Figure);
		int iterationCount = GetValue<int>(Figure["nrIterations"], 0);
		double scale = GetValue<double>(Figure["fractalScale"], 3.0);
		PolyhedronLambda lambda = [&](std::shared_ptr<Engine::Polyhedron> poly) { return poly->MakeFractal(scale, iterationCount); };
		return Apply(mesh, lambda);
	}
	else if (type.substr(0, dualName.length()) == dualName)
	{
		auto mesh = ReadMesh(type.substr(dualName.length(), type.length() - dualName.length()), Figure);
		PolyhedronLambda lambda = [&](std::shared_ptr<Engine::Polyhedron> poly) { return poly->MakeDual(); };
		return Apply(mesh, lambda);
	}
	else if (type.substr(0, truncatedName.length()) == truncatedName)
	{
		auto mesh = ReadMesh(type.substr(truncatedName.length(), type.length() - truncatedName.length()), Figure);
		double truncation = GetValue<double>(Figure["truncation"], 1.0 / 3.0);
		PolyhedronLambda lambda = [&](std::shared_ptr<Engine::Polyhedron> poly) { return poly->Truncate(truncation); };
		return Apply(mesh, lambda);
	}
	else if (type.substr(0, thickName.length()) == thickName)
	{
		auto mesh = ReadMesh(type.substr(thickName.length(), type.length() - thickName.length()), Figure);
		double r = GetValue<double>(Figure["radius"], 1.0);
		int n = GetValue<int>(Figure["n"], 5);
		int m = GetValue<int>(Figure["m"], 5);
		WireframeLambda lambda = [&](std::shared_ptr<Engine::Wireframe> poly)
		{
			return poly->MakeThickWireframe(r, n, m);
		};
		return Apply(mesh, lambda);
	}
	else if (type == "LineDrawing")
	{
		int nrPoints = GetValue<int>(Figure["nrPoints"], 0);
		stdx::ArraySlice<Engine::Vector3> pts(nrPoints);
		for (int i = 0; i < nrPoints; i++)
		{
			pts[i] = GetValue<Engine::Vector3>(Figure["point" + std::to_string(i)], Engine::Vector3(0, 0, 0));
		}
		int nrLines = GetValue<int>(Figure["nrLines"], 0);
		stdx::ArraySlice<Engine::Face> lines(nrLines);
		for (int i = 0; i < nrLines; i++)
		{
			lines[i] = Engine::Face(GetArray<int>(Figure["line" + std::to_string(i)], stdx::ArraySlice<int>()));
		}
		return std::make_shared<Engine::Wireframe>(pts, lines, GetDepthSkin(Figure, true));
	}
	else if (type == "BuckyBall")
	{
		return std::make_shared<Engine::Buckyball>(GetDepthSkin(Figure, !ShouldFillMesh(Figure)));
	}
	else if (type == "MengerSponge")
	{
		return std::make_shared<Engine::Mengersponge>(GetValue<int>(Figure["nrIterations"], 0), GetDepthSkin(Figure, !ShouldFillMesh(Figure)))->Lower();
	}
	else if (type == "Tetrahedron")
	{
		return std::make_shared<Engine::Tetrahedron>(GetDepthSkin(Figure, !ShouldFillMesh(Figure)));
	}
	else if (type == "Cube")
	{
		return std::make_shared<Engine::Cube>(GetDepthSkin(Figure, !ShouldFillMesh(Figure)));
	}
	else if (type == "Cone")
	{
		return std::make_shared<Engine::Cone>(Figure["height"], Figure["n"], GetDepthSkin(Figure, !ShouldFillMesh(Figure)));
	}
	else if (type == "Cylinder")
	{
		return std::make_shared<Engine::Cylinder>(Figure["height"], Figure["n"], GetDepthSkin(Figure, !ShouldFillMesh(Figure)));
	}
	else if (type == "Octahedron")
	{
		return std::make_shared<Engine::Octahedron>(GetDepthSkin(Figure, !ShouldFillMesh(Figure)));
	}
	else if (type == "Icosahedron")
	{
		return std::make_shared<Engine::Icosahedron>(GetDepthSkin(Figure, !ShouldFillMesh(Figure)));
	}
	else if (type == "Dodecahedron")
	{
		return std::make_shared<Engine::Dodecahedron>(GetDepthSkin(Figure, !ShouldFillMesh(Figure)));
	}
	else if (type == "Sphere")
	{
		return std::make_shared<Engine::Sphere>(Figure["n"], GetDepthSkin(Figure, !ShouldFillMesh(Figure)));
	}
	else if (type == "Torus")
	{
		return std::make_shared<Engine::Torus>(Figure["r"], Figure["R"], Figure["n"], Figure["m"], GetDepthSkin(Figure, !ShouldFillMesh(Figure)));
	}
	else if (type == "3DLSystem")
	{
		return CreateL3DMesh(Figure["inputfile"], GetDepthSkin(Figure, !ShouldFillMesh(Figure)));
	}
	else
	{
		throw std::invalid_argument("Unknown shape type: " + type);
	}
}

std::shared_ptr<Engine::ISkin> MeshHandlerBase::GetDepthSkin(const ini::Section& Figure, bool IsLine)
{
	if (IsLine || !UseZBuffer())
	{
		return std::make_shared<Engine::TextureSkin>(std::make_shared<Engine::EmptyTexture>());
	}
	else
	{
		return std::make_shared<Engine::DepthSkin>();
	}
}

std::shared_ptr<Engine::IMesh> MeshHandlerBase::ReadMesh(const ini::Section& Figure)
{
	std::string type = GetValue<std::string>(Figure["type"], "LineDrawing");
	auto mesh = ReadMesh(type, Figure);
	if (!ShouldFillMesh(Figure))
	{
		WireframeLambda lambda = [&](std::shared_ptr<Engine::Wireframe> poly) { return poly; };
		mesh = Apply(mesh, lambda); // Will convert the mesh to wireframe.
	}
	return mesh;
}

std::shared_ptr<Engine::IMesh> MeshHandlerBase::ReadTransformedMesh(const ini::Section& Figure, const Matrix<3>& GlobalTransform)
{
	double scale = GetValue<double>(Figure["scale"], 1.0);
	double rotateX = ToRadians(GetValue<double>(Figure["rotateX"], 0.0));
	double rotateY = ToRadians(GetValue<double>(Figure["rotateY"], 0.0));
	double rotateZ = ToRadians(GetValue<double>(Figure["rotateZ"], 0.0));
	auto center = GetValue<Engine::Vector3>(Figure["center"], { 0.0, 0.0, 0.0 });
	auto color = Engine::Vector4(GetValue<Engine::Vector3>(Figure["color"], { 1, 1, 1 }), 1.0);

	auto scaleTrans = Engine::Scale(scale);
	auto rotX = Engine::RotateX(rotateX);
	auto rotY = Engine::RotateY(rotateY);
	auto rotZ = Engine::RotateZ(rotateZ);
	auto transl = Engine::Translate(center);
	auto localTrans = scaleTrans * rotX * rotY * rotZ * transl;

	auto transMatrix = localTrans * GlobalTransform;

	auto result = ReadMesh(Figure);

	return result->Transform(std::make_shared<Engine::MatrixTransformation>(transMatrix));
}

std::shared_ptr<Engine::IShape> MeshHandlerBase::RenderFigure(const ini::Section& Figure, const Matrix<3>& GlobalTransform, std::shared_ptr<Engine::IProjection> Projection)
{
	auto color = Engine::Vector4(GetValue<Engine::Vector3>(Figure["color"], { 1, 1, 1 }), 1.0);

	auto brush = std::make_shared<Engine::SolidColorBrush>(color);

	auto result = ReadTransformedMesh(Figure, GlobalTransform);

	return std::make_shared<Engine::TexturedShape>(result->Project(Projection), std::make_shared<Engine::BrushTexture>(brush));
}

std::shared_ptr<Engine::IShape> MeshHandlerBase::ParseShape(const ini::Configuration& Configuration)
{
	Engine::Vector3 eye = GetValue<Engine::Vector3>(Configuration["General"]["eye"], Engine::Vector3(0, 0, 0));
	Engine::Vector4 bgColor = Engine::Vector4(GetValue<Engine::Vector3>(Configuration["General"]["backgroundColor"], { 1, 1, 1 }), 1.0);
	int nrOfFigures = GetValue<int>(Configuration["General"]["nrFigures"], 0);

	auto globalTransform = Engine::EyePointTransform(eye);
	auto proj = GetValue<std::shared_ptr<Engine::IProjection>>(Configuration["General"]["projection"], std::make_shared<Engine::PerspectiveProjection>(1.0));

	stdx::ArraySlice<std::shared_ptr<Engine::IShape>> shapes(nrOfFigures);
	for (int i = 0; i < nrOfFigures; i++)
	{
		shapes[i] = RenderFigure(Configuration["Figure" + std::to_string(i)], globalTransform, proj);
	}
	return std::make_shared<Engine::CompositeShape>(shapes);
}

std::shared_ptr<Engine::IOutputImage> MeshHandlerBase::Render(const ini::Configuration& Configuration)
{
	auto shape = ParseShape(Configuration);

	return CreateRelativeImage(Configuration, shape, std::make_shared<Engine::SolidColorBrush>(Engine::Vector4(0.0, 1.0, 0.0, 1.0)), UseZBuffer());
}