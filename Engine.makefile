# Compiler flags...
CPP_COMPILER = g++
C_COMPILER = gcc

# Include paths...
Debug_Include_Path=
Release_Include_Path=

# Library paths...
Debug_Library_Path=
Release_Library_Path=

# Additional libraries...
Debug_Libraries=
Release_Libraries=

# Preprocessor definitions...
Debug_Preprocessor_Definitions=-D GCC_BUILD -D _DEBUG -D _CONSOLE -D _LIB
Release_Preprocessor_Definitions=-D GCC_BUILD -D NDEBUG -D _CONSOLE -D _LIB

# Implictly linked object files...
Debug_Implicitly_Linked_Objects=
Release_Implicitly_Linked_Objects=

# Compiler flags...
Debug_Compiler_Flags=-O0 -std=c++11 -g
Release_Compiler_Flags=-O2 -std=c++11

# Builds all configurations for this project...
.PHONY: build_all_configurations
build_all_configurations: Debug Release

# Builds the Debug configuration...
.PHONY: Debug
Debug: create_folders gccDebug/AdditiveBrush.o gccDebug/BitmapLinePath.o gccDebug/BitmapRenderContext.o gccDebug/BrushTexture.o gccDebug/Buckyball.o gccDebug/ComplexMesh.o gccDebug/CompositeLightComponent.o gccDebug/CompositeMesh.o gccDebug/CompositeShape.o gccDebug/Cone.o gccDebug/ConstantDepthBuffer.o gccDebug/CosineInterpolationSampler.o gccDebug/Cube.o gccDebug/CubicInterpolationSampler.o gccDebug/Cylinder.o gccDebug/DepthBrushBase.o gccDebug/DepthSkin.o gccDebug/DepthSkinBase.o gccDebug/DiffuseLightComponent.o gccDebug/Dodecahedron.o gccDebug/EasyBitmap.o gccDebug/EasyImage.o gccDebug/EmptyTexture.o gccDebug/engine.o gccDebug/Face.o gccDebug/Helpers.o gccDebug/Icosahedron.o gccDebug/IndexedLine.o gccDebug/InfinityLight.o gccDebug/ini_configuration.o gccDebug/IOutputImage.o gccDebug/LightingBrush.o gccDebug/LightingHandler.o gccDebug/LightingSkin.o gccDebug/LightingState.o gccDebug/LightingTexture.o gccDebug/LinearInterpolationSampler.o gccDebug/LineDepthBrush.o gccDebug/LinePathBase.o gccDebug/LineSegment.o gccDebug/lparser.o gccDebug/MatrixHelpers.o gccDebug/Mengersponge.o gccDebug/MeshHandlerBase.o gccDebug/MultiLine.o gccDebug/MultiLineRenderCommand.o gccDebug/MultiplicativeBrush.o gccDebug/NearestNeighborClampingSampler.o gccDebug/NearestNeighborWrappingSampler.o gccDebug/NormalizedShape.o gccDebug/Octahedron.o gccDebug/OpacityMask.o gccDebug/OverBrush.o gccDebug/ParallelProjection.o gccDebug/PartialLineSegment.o gccDebug/PerspectiveProjection.o gccDebug/PixelPosition.o gccDebug/PlaneTextureBrush.o gccDebug/PointLight.o gccDebug/PolygonDepthBrush.o gccDebug/Polyhedron.o gccDebug/PortablePixelmap.o gccDebug/ProjectedLineSegment.o gccDebug/ProjectedLineSegmentRenderCommand.o gccDebug/ProjectedMultiLine.o gccDebug/ProjectedMultiLineRenderCommand.o gccDebug/ProjectedPolygonTexture.o gccDebug/RadialGradientBrush.o gccDebug/RadialGradientBrush3.o gccDebug/RectangleBounds.o gccDebug/ReflectionProperties.o gccDebug/RenderBitmapSegmentCommand.o gccDebug/RenderHandlers.o gccDebug/RenderTriangleCommand.o gccDebug/RenderVectorPathCommand.o gccDebug/ScaleTransformation.o gccDebug/ScaleTransformation3D.o gccDebug/Scene.o gccDebug/ShadowPointLight.o gccDebug/SolidColorBrush.o gccDebug/SolidColorBrush3.o gccDebug/SpecularLightComponent.o gccDebug/Sphere.o gccDebug/SphereTextureBrush.o gccDebug/SubtractBrush.o gccDebug/SvgHelpers.o gccDebug/SvgInstructionStream.o gccDebug/SvgVectorPath.o gccDebug/Tetrahedron.o gccDebug/TexturedShape.o gccDebug/TexturedShapeRenderCommand.o gccDebug/TextureSkin.o gccDebug/Torus.o gccDebug/TransformationAnalyzer.o gccDebug/TransformingShapeBase.o gccDebug/TranslateTransformation.o gccDebug/TranslateTransformation3D.o gccDebug/TriangleShape.o gccDebug/TurtleMesh.o gccDebug/TurtleMeshState.o gccDebug/TurtlePath.o gccDebug/TurtleState.o gccDebug/vector.o gccDebug/Vector2.o gccDebug/Vector3.o gccDebug/Vector4.o gccDebug/VectorInstructionStreamBase.o gccDebug/VectorLinePath.o gccDebug/VectorPathBase.o gccDebug/VectorRenderContext.o gccDebug/Wireframe.o gccDebug/WriteLineSegmentCommand.o gccDebug/ZBuffer.o gccDebug/ZBufferingHandlerBase.o
	$(CPP_COMPILER) gccDebug/AdditiveBrush.o gccDebug/BitmapLinePath.o gccDebug/BitmapRenderContext.o gccDebug/BrushTexture.o gccDebug/Buckyball.o gccDebug/ComplexMesh.o gccDebug/CompositeLightComponent.o gccDebug/CompositeMesh.o gccDebug/CompositeShape.o gccDebug/Cone.o gccDebug/ConstantDepthBuffer.o gccDebug/CosineInterpolationSampler.o gccDebug/Cube.o gccDebug/CubicInterpolationSampler.o gccDebug/Cylinder.o gccDebug/DepthBrushBase.o gccDebug/DepthSkin.o gccDebug/DepthSkinBase.o gccDebug/DiffuseLightComponent.o gccDebug/Dodecahedron.o gccDebug/EasyBitmap.o gccDebug/EasyImage.o gccDebug/EmptyTexture.o gccDebug/engine.o gccDebug/Face.o gccDebug/Helpers.o gccDebug/Icosahedron.o gccDebug/IndexedLine.o gccDebug/InfinityLight.o gccDebug/ini_configuration.o gccDebug/IOutputImage.o gccDebug/LightingBrush.o gccDebug/LightingHandler.o gccDebug/LightingSkin.o gccDebug/LightingState.o gccDebug/LightingTexture.o gccDebug/LinearInterpolationSampler.o gccDebug/LineDepthBrush.o gccDebug/LinePathBase.o gccDebug/LineSegment.o gccDebug/lparser.o gccDebug/MatrixHelpers.o gccDebug/Mengersponge.o gccDebug/MeshHandlerBase.o gccDebug/MultiLine.o gccDebug/MultiLineRenderCommand.o gccDebug/MultiplicativeBrush.o gccDebug/NearestNeighborClampingSampler.o gccDebug/NearestNeighborWrappingSampler.o gccDebug/NormalizedShape.o gccDebug/Octahedron.o gccDebug/OpacityMask.o gccDebug/OverBrush.o gccDebug/ParallelProjection.o gccDebug/PartialLineSegment.o gccDebug/PerspectiveProjection.o gccDebug/PixelPosition.o gccDebug/PlaneTextureBrush.o gccDebug/PointLight.o gccDebug/PolygonDepthBrush.o gccDebug/Polyhedron.o gccDebug/PortablePixelmap.o gccDebug/ProjectedLineSegment.o gccDebug/ProjectedLineSegmentRenderCommand.o gccDebug/ProjectedMultiLine.o gccDebug/ProjectedMultiLineRenderCommand.o gccDebug/ProjectedPolygonTexture.o gccDebug/RadialGradientBrush.o gccDebug/RadialGradientBrush3.o gccDebug/RectangleBounds.o gccDebug/ReflectionProperties.o gccDebug/RenderBitmapSegmentCommand.o gccDebug/RenderHandlers.o gccDebug/RenderTriangleCommand.o gccDebug/RenderVectorPathCommand.o gccDebug/ScaleTransformation.o gccDebug/ScaleTransformation3D.o gccDebug/Scene.o gccDebug/ShadowPointLight.o gccDebug/SolidColorBrush.o gccDebug/SolidColorBrush3.o gccDebug/SpecularLightComponent.o gccDebug/Sphere.o gccDebug/SphereTextureBrush.o gccDebug/SubtractBrush.o gccDebug/SvgHelpers.o gccDebug/SvgInstructionStream.o gccDebug/SvgVectorPath.o gccDebug/Tetrahedron.o gccDebug/TexturedShape.o gccDebug/TexturedShapeRenderCommand.o gccDebug/TextureSkin.o gccDebug/Torus.o gccDebug/TransformationAnalyzer.o gccDebug/TransformingShapeBase.o gccDebug/TranslateTransformation.o gccDebug/TranslateTransformation3D.o gccDebug/TriangleShape.o gccDebug/TurtleMesh.o gccDebug/TurtleMeshState.o gccDebug/TurtlePath.o gccDebug/TurtleState.o gccDebug/vector.o gccDebug/Vector2.o gccDebug/Vector3.o gccDebug/Vector4.o gccDebug/VectorInstructionStreamBase.o gccDebug/VectorLinePath.o gccDebug/VectorPathBase.o gccDebug/VectorRenderContext.o gccDebug/Wireframe.o gccDebug/WriteLineSegmentCommand.o gccDebug/ZBuffer.o gccDebug/ZBufferingHandlerBase.o $(Debug_Library_Path) $(Debug_Libraries) -Wl,-rpath,./ -o gccDebug/engine

# Compiles file AdditiveBrush.cpp for the Debug configuration...
-include gccDebug/AdditiveBrush.d
gccDebug/AdditiveBrush.o: AdditiveBrush.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c AdditiveBrush.cpp $(Debug_Include_Path) -o gccDebug/AdditiveBrush.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM AdditiveBrush.cpp $(Debug_Include_Path) > gccDebug/AdditiveBrush.d

# Compiles file BitmapLinePath.cpp for the Debug configuration...
-include gccDebug/BitmapLinePath.d
gccDebug/BitmapLinePath.o: BitmapLinePath.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c BitmapLinePath.cpp $(Debug_Include_Path) -o gccDebug/BitmapLinePath.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM BitmapLinePath.cpp $(Debug_Include_Path) > gccDebug/BitmapLinePath.d

# Compiles file BitmapRenderContext.cpp for the Debug configuration...
-include gccDebug/BitmapRenderContext.d
gccDebug/BitmapRenderContext.o: BitmapRenderContext.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c BitmapRenderContext.cpp $(Debug_Include_Path) -o gccDebug/BitmapRenderContext.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM BitmapRenderContext.cpp $(Debug_Include_Path) > gccDebug/BitmapRenderContext.d

# Compiles file BrushTexture.cpp for the Debug configuration...
-include gccDebug/BrushTexture.d
gccDebug/BrushTexture.o: BrushTexture.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c BrushTexture.cpp $(Debug_Include_Path) -o gccDebug/BrushTexture.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM BrushTexture.cpp $(Debug_Include_Path) > gccDebug/BrushTexture.d

# Compiles file Buckyball.cpp for the Debug configuration...
-include gccDebug/Buckyball.d
gccDebug/Buckyball.o: Buckyball.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Buckyball.cpp $(Debug_Include_Path) -o gccDebug/Buckyball.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Buckyball.cpp $(Debug_Include_Path) > gccDebug/Buckyball.d

# Compiles file ComplexMesh.cpp for the Debug configuration...
-include gccDebug/ComplexMesh.d
gccDebug/ComplexMesh.o: ComplexMesh.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ComplexMesh.cpp $(Debug_Include_Path) -o gccDebug/ComplexMesh.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ComplexMesh.cpp $(Debug_Include_Path) > gccDebug/ComplexMesh.d

# Compiles file CompositeLightComponent.cpp for the Debug configuration...
-include gccDebug/CompositeLightComponent.d
gccDebug/CompositeLightComponent.o: CompositeLightComponent.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c CompositeLightComponent.cpp $(Debug_Include_Path) -o gccDebug/CompositeLightComponent.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM CompositeLightComponent.cpp $(Debug_Include_Path) > gccDebug/CompositeLightComponent.d

# Compiles file CompositeMesh.cpp for the Debug configuration...
-include gccDebug/CompositeMesh.d
gccDebug/CompositeMesh.o: CompositeMesh.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c CompositeMesh.cpp $(Debug_Include_Path) -o gccDebug/CompositeMesh.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM CompositeMesh.cpp $(Debug_Include_Path) > gccDebug/CompositeMesh.d

# Compiles file CompositeShape.cpp for the Debug configuration...
-include gccDebug/CompositeShape.d
gccDebug/CompositeShape.o: CompositeShape.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c CompositeShape.cpp $(Debug_Include_Path) -o gccDebug/CompositeShape.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM CompositeShape.cpp $(Debug_Include_Path) > gccDebug/CompositeShape.d

# Compiles file Cone.cpp for the Debug configuration...
-include gccDebug/Cone.d
gccDebug/Cone.o: Cone.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Cone.cpp $(Debug_Include_Path) -o gccDebug/Cone.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Cone.cpp $(Debug_Include_Path) > gccDebug/Cone.d

# Compiles file ConstantDepthBuffer.cpp for the Debug configuration...
-include gccDebug/ConstantDepthBuffer.d
gccDebug/ConstantDepthBuffer.o: ConstantDepthBuffer.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ConstantDepthBuffer.cpp $(Debug_Include_Path) -o gccDebug/ConstantDepthBuffer.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ConstantDepthBuffer.cpp $(Debug_Include_Path) > gccDebug/ConstantDepthBuffer.d

# Compiles file CosineInterpolationSampler.cpp for the Debug configuration...
-include gccDebug/CosineInterpolationSampler.d
gccDebug/CosineInterpolationSampler.o: CosineInterpolationSampler.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c CosineInterpolationSampler.cpp $(Debug_Include_Path) -o gccDebug/CosineInterpolationSampler.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM CosineInterpolationSampler.cpp $(Debug_Include_Path) > gccDebug/CosineInterpolationSampler.d

# Compiles file Cube.cpp for the Debug configuration...
-include gccDebug/Cube.d
gccDebug/Cube.o: Cube.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Cube.cpp $(Debug_Include_Path) -o gccDebug/Cube.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Cube.cpp $(Debug_Include_Path) > gccDebug/Cube.d

# Compiles file CubicInterpolationSampler.cpp for the Debug configuration...
-include gccDebug/CubicInterpolationSampler.d
gccDebug/CubicInterpolationSampler.o: CubicInterpolationSampler.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c CubicInterpolationSampler.cpp $(Debug_Include_Path) -o gccDebug/CubicInterpolationSampler.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM CubicInterpolationSampler.cpp $(Debug_Include_Path) > gccDebug/CubicInterpolationSampler.d

# Compiles file Cylinder.cpp for the Debug configuration...
-include gccDebug/Cylinder.d
gccDebug/Cylinder.o: Cylinder.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Cylinder.cpp $(Debug_Include_Path) -o gccDebug/Cylinder.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Cylinder.cpp $(Debug_Include_Path) > gccDebug/Cylinder.d

# Compiles file DepthBrushBase.cpp for the Debug configuration...
-include gccDebug/DepthBrushBase.d
gccDebug/DepthBrushBase.o: DepthBrushBase.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c DepthBrushBase.cpp $(Debug_Include_Path) -o gccDebug/DepthBrushBase.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM DepthBrushBase.cpp $(Debug_Include_Path) > gccDebug/DepthBrushBase.d

# Compiles file DepthSkin.cpp for the Debug configuration...
-include gccDebug/DepthSkin.d
gccDebug/DepthSkin.o: DepthSkin.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c DepthSkin.cpp $(Debug_Include_Path) -o gccDebug/DepthSkin.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM DepthSkin.cpp $(Debug_Include_Path) > gccDebug/DepthSkin.d

# Compiles file DepthSkinBase.cpp for the Debug configuration...
-include gccDebug/DepthSkinBase.d
gccDebug/DepthSkinBase.o: DepthSkinBase.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c DepthSkinBase.cpp $(Debug_Include_Path) -o gccDebug/DepthSkinBase.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM DepthSkinBase.cpp $(Debug_Include_Path) > gccDebug/DepthSkinBase.d

# Compiles file DiffuseLightComponent.cpp for the Debug configuration...
-include gccDebug/DiffuseLightComponent.d
gccDebug/DiffuseLightComponent.o: DiffuseLightComponent.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c DiffuseLightComponent.cpp $(Debug_Include_Path) -o gccDebug/DiffuseLightComponent.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM DiffuseLightComponent.cpp $(Debug_Include_Path) > gccDebug/DiffuseLightComponent.d

# Compiles file Dodecahedron.cpp for the Debug configuration...
-include gccDebug/Dodecahedron.d
gccDebug/Dodecahedron.o: Dodecahedron.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Dodecahedron.cpp $(Debug_Include_Path) -o gccDebug/Dodecahedron.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Dodecahedron.cpp $(Debug_Include_Path) > gccDebug/Dodecahedron.d

# Compiles file EasyBitmap.cpp for the Debug configuration...
-include gccDebug/EasyBitmap.d
gccDebug/EasyBitmap.o: EasyBitmap.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c EasyBitmap.cpp $(Debug_Include_Path) -o gccDebug/EasyBitmap.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM EasyBitmap.cpp $(Debug_Include_Path) > gccDebug/EasyBitmap.d

# Compiles file EasyImage.cc for the Debug configuration...
-include gccDebug/EasyImage.d
gccDebug/EasyImage.o: EasyImage.cc
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c EasyImage.cc $(Debug_Include_Path) -o gccDebug/EasyImage.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM EasyImage.cc $(Debug_Include_Path) > gccDebug/EasyImage.d

# Compiles file EmptyTexture.cpp for the Debug configuration...
-include gccDebug/EmptyTexture.d
gccDebug/EmptyTexture.o: EmptyTexture.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c EmptyTexture.cpp $(Debug_Include_Path) -o gccDebug/EmptyTexture.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM EmptyTexture.cpp $(Debug_Include_Path) > gccDebug/EmptyTexture.d

# Compiles file engine.cc for the Debug configuration...
-include gccDebug/engine.d
gccDebug/engine.o: engine.cc
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c engine.cc $(Debug_Include_Path) -o gccDebug/engine.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM engine.cc $(Debug_Include_Path) > gccDebug/engine.d

# Compiles file Face.cpp for the Debug configuration...
-include gccDebug/Face.d
gccDebug/Face.o: Face.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Face.cpp $(Debug_Include_Path) -o gccDebug/Face.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Face.cpp $(Debug_Include_Path) > gccDebug/Face.d

# Compiles file Helpers.cpp for the Debug configuration...
-include gccDebug/Helpers.d
gccDebug/Helpers.o: Helpers.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Helpers.cpp $(Debug_Include_Path) -o gccDebug/Helpers.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Helpers.cpp $(Debug_Include_Path) > gccDebug/Helpers.d

# Compiles file Icosahedron.cpp for the Debug configuration...
-include gccDebug/Icosahedron.d
gccDebug/Icosahedron.o: Icosahedron.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Icosahedron.cpp $(Debug_Include_Path) -o gccDebug/Icosahedron.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Icosahedron.cpp $(Debug_Include_Path) > gccDebug/Icosahedron.d

# Compiles file IndexedLine.cpp for the Debug configuration...
-include gccDebug/IndexedLine.d
gccDebug/IndexedLine.o: IndexedLine.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c IndexedLine.cpp $(Debug_Include_Path) -o gccDebug/IndexedLine.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM IndexedLine.cpp $(Debug_Include_Path) > gccDebug/IndexedLine.d

# Compiles file InfinityLight.cpp for the Debug configuration...
-include gccDebug/InfinityLight.d
gccDebug/InfinityLight.o: InfinityLight.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c InfinityLight.cpp $(Debug_Include_Path) -o gccDebug/InfinityLight.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM InfinityLight.cpp $(Debug_Include_Path) > gccDebug/InfinityLight.d

# Compiles file ini_configuration.cc for the Debug configuration...
-include gccDebug/ini_configuration.d
gccDebug/ini_configuration.o: ini_configuration.cc
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ini_configuration.cc $(Debug_Include_Path) -o gccDebug/ini_configuration.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ini_configuration.cc $(Debug_Include_Path) > gccDebug/ini_configuration.d

# Compiles file IOutputImage.cpp for the Debug configuration...
-include gccDebug/IOutputImage.d
gccDebug/IOutputImage.o: IOutputImage.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c IOutputImage.cpp $(Debug_Include_Path) -o gccDebug/IOutputImage.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM IOutputImage.cpp $(Debug_Include_Path) > gccDebug/IOutputImage.d

# Compiles file LightingBrush.cpp for the Debug configuration...
-include gccDebug/LightingBrush.d
gccDebug/LightingBrush.o: LightingBrush.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c LightingBrush.cpp $(Debug_Include_Path) -o gccDebug/LightingBrush.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM LightingBrush.cpp $(Debug_Include_Path) > gccDebug/LightingBrush.d

# Compiles file LightingHandler.cpp for the Debug configuration...
-include gccDebug/LightingHandler.d
gccDebug/LightingHandler.o: LightingHandler.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c LightingHandler.cpp $(Debug_Include_Path) -o gccDebug/LightingHandler.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM LightingHandler.cpp $(Debug_Include_Path) > gccDebug/LightingHandler.d

# Compiles file LightingSkin.cpp for the Debug configuration...
-include gccDebug/LightingSkin.d
gccDebug/LightingSkin.o: LightingSkin.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c LightingSkin.cpp $(Debug_Include_Path) -o gccDebug/LightingSkin.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM LightingSkin.cpp $(Debug_Include_Path) > gccDebug/LightingSkin.d

# Compiles file LightingState.cpp for the Debug configuration...
-include gccDebug/LightingState.d
gccDebug/LightingState.o: LightingState.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c LightingState.cpp $(Debug_Include_Path) -o gccDebug/LightingState.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM LightingState.cpp $(Debug_Include_Path) > gccDebug/LightingState.d

# Compiles file LightingTexture.cpp for the Debug configuration...
-include gccDebug/LightingTexture.d
gccDebug/LightingTexture.o: LightingTexture.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c LightingTexture.cpp $(Debug_Include_Path) -o gccDebug/LightingTexture.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM LightingTexture.cpp $(Debug_Include_Path) > gccDebug/LightingTexture.d

# Compiles file LinearInterpolationSampler.cpp for the Debug configuration...
-include gccDebug/LinearInterpolationSampler.d
gccDebug/LinearInterpolationSampler.o: LinearInterpolationSampler.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c LinearInterpolationSampler.cpp $(Debug_Include_Path) -o gccDebug/LinearInterpolationSampler.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM LinearInterpolationSampler.cpp $(Debug_Include_Path) > gccDebug/LinearInterpolationSampler.d

# Compiles file LineDepthBrush.cpp for the Debug configuration...
-include gccDebug/LineDepthBrush.d
gccDebug/LineDepthBrush.o: LineDepthBrush.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c LineDepthBrush.cpp $(Debug_Include_Path) -o gccDebug/LineDepthBrush.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM LineDepthBrush.cpp $(Debug_Include_Path) > gccDebug/LineDepthBrush.d

# Compiles file LinePathBase.cpp for the Debug configuration...
-include gccDebug/LinePathBase.d
gccDebug/LinePathBase.o: LinePathBase.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c LinePathBase.cpp $(Debug_Include_Path) -o gccDebug/LinePathBase.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM LinePathBase.cpp $(Debug_Include_Path) > gccDebug/LinePathBase.d

# Compiles file LineSegment.cpp for the Debug configuration...
-include gccDebug/LineSegment.d
gccDebug/LineSegment.o: LineSegment.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c LineSegment.cpp $(Debug_Include_Path) -o gccDebug/LineSegment.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM LineSegment.cpp $(Debug_Include_Path) > gccDebug/LineSegment.d

# Compiles file lparser.cc for the Debug configuration...
-include gccDebug/lparser.d
gccDebug/lparser.o: lparser.cc
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c lparser.cc $(Debug_Include_Path) -o gccDebug/lparser.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM lparser.cc $(Debug_Include_Path) > gccDebug/lparser.d

# Compiles file MatrixHelpers.cpp for the Debug configuration...
-include gccDebug/MatrixHelpers.d
gccDebug/MatrixHelpers.o: MatrixHelpers.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c MatrixHelpers.cpp $(Debug_Include_Path) -o gccDebug/MatrixHelpers.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM MatrixHelpers.cpp $(Debug_Include_Path) > gccDebug/MatrixHelpers.d

# Compiles file Mengersponge.cpp for the Debug configuration...
-include gccDebug/Mengersponge.d
gccDebug/Mengersponge.o: Mengersponge.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Mengersponge.cpp $(Debug_Include_Path) -o gccDebug/Mengersponge.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Mengersponge.cpp $(Debug_Include_Path) > gccDebug/Mengersponge.d

# Compiles file MeshHandlerBase.cpp for the Debug configuration...
-include gccDebug/MeshHandlerBase.d
gccDebug/MeshHandlerBase.o: MeshHandlerBase.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c MeshHandlerBase.cpp $(Debug_Include_Path) -o gccDebug/MeshHandlerBase.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM MeshHandlerBase.cpp $(Debug_Include_Path) > gccDebug/MeshHandlerBase.d

# Compiles file MultiLine.cpp for the Debug configuration...
-include gccDebug/MultiLine.d
gccDebug/MultiLine.o: MultiLine.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c MultiLine.cpp $(Debug_Include_Path) -o gccDebug/MultiLine.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM MultiLine.cpp $(Debug_Include_Path) > gccDebug/MultiLine.d

# Compiles file MultiLineRenderCommand.cpp for the Debug configuration...
-include gccDebug/MultiLineRenderCommand.d
gccDebug/MultiLineRenderCommand.o: MultiLineRenderCommand.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c MultiLineRenderCommand.cpp $(Debug_Include_Path) -o gccDebug/MultiLineRenderCommand.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM MultiLineRenderCommand.cpp $(Debug_Include_Path) > gccDebug/MultiLineRenderCommand.d

# Compiles file MultiplicativeBrush.cpp for the Debug configuration...
-include gccDebug/MultiplicativeBrush.d
gccDebug/MultiplicativeBrush.o: MultiplicativeBrush.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c MultiplicativeBrush.cpp $(Debug_Include_Path) -o gccDebug/MultiplicativeBrush.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM MultiplicativeBrush.cpp $(Debug_Include_Path) > gccDebug/MultiplicativeBrush.d

# Compiles file NearestNeighborClampingSampler.cpp for the Debug configuration...
-include gccDebug/NearestNeighborClampingSampler.d
gccDebug/NearestNeighborClampingSampler.o: NearestNeighborClampingSampler.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c NearestNeighborClampingSampler.cpp $(Debug_Include_Path) -o gccDebug/NearestNeighborClampingSampler.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM NearestNeighborClampingSampler.cpp $(Debug_Include_Path) > gccDebug/NearestNeighborClampingSampler.d

# Compiles file NearestNeighborWrappingSampler.cpp for the Debug configuration...
-include gccDebug/NearestNeighborWrappingSampler.d
gccDebug/NearestNeighborWrappingSampler.o: NearestNeighborWrappingSampler.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c NearestNeighborWrappingSampler.cpp $(Debug_Include_Path) -o gccDebug/NearestNeighborWrappingSampler.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM NearestNeighborWrappingSampler.cpp $(Debug_Include_Path) > gccDebug/NearestNeighborWrappingSampler.d

# Compiles file NormalizedShape.cpp for the Debug configuration...
-include gccDebug/NormalizedShape.d
gccDebug/NormalizedShape.o: NormalizedShape.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c NormalizedShape.cpp $(Debug_Include_Path) -o gccDebug/NormalizedShape.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM NormalizedShape.cpp $(Debug_Include_Path) > gccDebug/NormalizedShape.d

# Compiles file Octahedron.cpp for the Debug configuration...
-include gccDebug/Octahedron.d
gccDebug/Octahedron.o: Octahedron.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Octahedron.cpp $(Debug_Include_Path) -o gccDebug/Octahedron.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Octahedron.cpp $(Debug_Include_Path) > gccDebug/Octahedron.d

# Compiles file OpacityMask.cpp for the Debug configuration...
-include gccDebug/OpacityMask.d
gccDebug/OpacityMask.o: OpacityMask.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c OpacityMask.cpp $(Debug_Include_Path) -o gccDebug/OpacityMask.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM OpacityMask.cpp $(Debug_Include_Path) > gccDebug/OpacityMask.d

# Compiles file OverBrush.cpp for the Debug configuration...
-include gccDebug/OverBrush.d
gccDebug/OverBrush.o: OverBrush.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c OverBrush.cpp $(Debug_Include_Path) -o gccDebug/OverBrush.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM OverBrush.cpp $(Debug_Include_Path) > gccDebug/OverBrush.d

# Compiles file ParallelProjection.cpp for the Debug configuration...
-include gccDebug/ParallelProjection.d
gccDebug/ParallelProjection.o: ParallelProjection.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ParallelProjection.cpp $(Debug_Include_Path) -o gccDebug/ParallelProjection.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ParallelProjection.cpp $(Debug_Include_Path) > gccDebug/ParallelProjection.d

# Compiles file PartialLineSegment.cpp for the Debug configuration...
-include gccDebug/PartialLineSegment.d
gccDebug/PartialLineSegment.o: PartialLineSegment.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c PartialLineSegment.cpp $(Debug_Include_Path) -o gccDebug/PartialLineSegment.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM PartialLineSegment.cpp $(Debug_Include_Path) > gccDebug/PartialLineSegment.d

# Compiles file PerspectiveProjection.cpp for the Debug configuration...
-include gccDebug/PerspectiveProjection.d
gccDebug/PerspectiveProjection.o: PerspectiveProjection.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c PerspectiveProjection.cpp $(Debug_Include_Path) -o gccDebug/PerspectiveProjection.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM PerspectiveProjection.cpp $(Debug_Include_Path) > gccDebug/PerspectiveProjection.d

# Compiles file PixelPosition.cpp for the Debug configuration...
-include gccDebug/PixelPosition.d
gccDebug/PixelPosition.o: PixelPosition.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c PixelPosition.cpp $(Debug_Include_Path) -o gccDebug/PixelPosition.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM PixelPosition.cpp $(Debug_Include_Path) > gccDebug/PixelPosition.d

# Compiles file PlaneTextureBrush.cpp for the Debug configuration...
-include gccDebug/PlaneTextureBrush.d
gccDebug/PlaneTextureBrush.o: PlaneTextureBrush.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c PlaneTextureBrush.cpp $(Debug_Include_Path) -o gccDebug/PlaneTextureBrush.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM PlaneTextureBrush.cpp $(Debug_Include_Path) > gccDebug/PlaneTextureBrush.d

# Compiles file PointLight.cpp for the Debug configuration...
-include gccDebug/PointLight.d
gccDebug/PointLight.o: PointLight.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c PointLight.cpp $(Debug_Include_Path) -o gccDebug/PointLight.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM PointLight.cpp $(Debug_Include_Path) > gccDebug/PointLight.d

# Compiles file PolygonDepthBrush.cpp for the Debug configuration...
-include gccDebug/PolygonDepthBrush.d
gccDebug/PolygonDepthBrush.o: PolygonDepthBrush.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c PolygonDepthBrush.cpp $(Debug_Include_Path) -o gccDebug/PolygonDepthBrush.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM PolygonDepthBrush.cpp $(Debug_Include_Path) > gccDebug/PolygonDepthBrush.d

# Compiles file Polyhedron.cpp for the Debug configuration...
-include gccDebug/Polyhedron.d
gccDebug/Polyhedron.o: Polyhedron.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Polyhedron.cpp $(Debug_Include_Path) -o gccDebug/Polyhedron.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Polyhedron.cpp $(Debug_Include_Path) > gccDebug/Polyhedron.d

# Compiles file PortablePixelmap.cpp for the Debug configuration...
-include gccDebug/PortablePixelmap.d
gccDebug/PortablePixelmap.o: PortablePixelmap.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c PortablePixelmap.cpp $(Debug_Include_Path) -o gccDebug/PortablePixelmap.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM PortablePixelmap.cpp $(Debug_Include_Path) > gccDebug/PortablePixelmap.d

# Compiles file ProjectedLineSegment.cpp for the Debug configuration...
-include gccDebug/ProjectedLineSegment.d
gccDebug/ProjectedLineSegment.o: ProjectedLineSegment.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ProjectedLineSegment.cpp $(Debug_Include_Path) -o gccDebug/ProjectedLineSegment.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ProjectedLineSegment.cpp $(Debug_Include_Path) > gccDebug/ProjectedLineSegment.d

# Compiles file ProjectedLineSegmentRenderCommand.cpp for the Debug configuration...
-include gccDebug/ProjectedLineSegmentRenderCommand.d
gccDebug/ProjectedLineSegmentRenderCommand.o: ProjectedLineSegmentRenderCommand.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ProjectedLineSegmentRenderCommand.cpp $(Debug_Include_Path) -o gccDebug/ProjectedLineSegmentRenderCommand.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ProjectedLineSegmentRenderCommand.cpp $(Debug_Include_Path) > gccDebug/ProjectedLineSegmentRenderCommand.d

# Compiles file ProjectedMultiLine.cpp for the Debug configuration...
-include gccDebug/ProjectedMultiLine.d
gccDebug/ProjectedMultiLine.o: ProjectedMultiLine.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ProjectedMultiLine.cpp $(Debug_Include_Path) -o gccDebug/ProjectedMultiLine.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ProjectedMultiLine.cpp $(Debug_Include_Path) > gccDebug/ProjectedMultiLine.d

# Compiles file ProjectedMultiLineRenderCommand.cpp for the Debug configuration...
-include gccDebug/ProjectedMultiLineRenderCommand.d
gccDebug/ProjectedMultiLineRenderCommand.o: ProjectedMultiLineRenderCommand.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ProjectedMultiLineRenderCommand.cpp $(Debug_Include_Path) -o gccDebug/ProjectedMultiLineRenderCommand.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ProjectedMultiLineRenderCommand.cpp $(Debug_Include_Path) > gccDebug/ProjectedMultiLineRenderCommand.d

# Compiles file ProjectedPolygonTexture.cpp for the Debug configuration...
-include gccDebug/ProjectedPolygonTexture.d
gccDebug/ProjectedPolygonTexture.o: ProjectedPolygonTexture.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ProjectedPolygonTexture.cpp $(Debug_Include_Path) -o gccDebug/ProjectedPolygonTexture.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ProjectedPolygonTexture.cpp $(Debug_Include_Path) > gccDebug/ProjectedPolygonTexture.d

# Compiles file RadialGradientBrush.cpp for the Debug configuration...
-include gccDebug/RadialGradientBrush.d
gccDebug/RadialGradientBrush.o: RadialGradientBrush.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c RadialGradientBrush.cpp $(Debug_Include_Path) -o gccDebug/RadialGradientBrush.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM RadialGradientBrush.cpp $(Debug_Include_Path) > gccDebug/RadialGradientBrush.d

# Compiles file RadialGradientBrush3.cpp for the Debug configuration...
-include gccDebug/RadialGradientBrush3.d
gccDebug/RadialGradientBrush3.o: RadialGradientBrush3.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c RadialGradientBrush3.cpp $(Debug_Include_Path) -o gccDebug/RadialGradientBrush3.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM RadialGradientBrush3.cpp $(Debug_Include_Path) > gccDebug/RadialGradientBrush3.d

# Compiles file RectangleBounds.cpp for the Debug configuration...
-include gccDebug/RectangleBounds.d
gccDebug/RectangleBounds.o: RectangleBounds.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c RectangleBounds.cpp $(Debug_Include_Path) -o gccDebug/RectangleBounds.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM RectangleBounds.cpp $(Debug_Include_Path) > gccDebug/RectangleBounds.d

# Compiles file ReflectionProperties.cpp for the Debug configuration...
-include gccDebug/ReflectionProperties.d
gccDebug/ReflectionProperties.o: ReflectionProperties.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ReflectionProperties.cpp $(Debug_Include_Path) -o gccDebug/ReflectionProperties.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ReflectionProperties.cpp $(Debug_Include_Path) > gccDebug/ReflectionProperties.d

# Compiles file RenderBitmapSegmentCommand.cpp for the Debug configuration...
-include gccDebug/RenderBitmapSegmentCommand.d
gccDebug/RenderBitmapSegmentCommand.o: RenderBitmapSegmentCommand.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c RenderBitmapSegmentCommand.cpp $(Debug_Include_Path) -o gccDebug/RenderBitmapSegmentCommand.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM RenderBitmapSegmentCommand.cpp $(Debug_Include_Path) > gccDebug/RenderBitmapSegmentCommand.d

# Compiles file RenderHandlers.cpp for the Debug configuration...
-include gccDebug/RenderHandlers.d
gccDebug/RenderHandlers.o: RenderHandlers.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c RenderHandlers.cpp $(Debug_Include_Path) -o gccDebug/RenderHandlers.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM RenderHandlers.cpp $(Debug_Include_Path) > gccDebug/RenderHandlers.d

# Compiles file RenderTriangleCommand.cpp for the Debug configuration...
-include gccDebug/RenderTriangleCommand.d
gccDebug/RenderTriangleCommand.o: RenderTriangleCommand.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c RenderTriangleCommand.cpp $(Debug_Include_Path) -o gccDebug/RenderTriangleCommand.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM RenderTriangleCommand.cpp $(Debug_Include_Path) > gccDebug/RenderTriangleCommand.d

# Compiles file RenderVectorPathCommand.cpp for the Debug configuration...
-include gccDebug/RenderVectorPathCommand.d
gccDebug/RenderVectorPathCommand.o: RenderVectorPathCommand.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c RenderVectorPathCommand.cpp $(Debug_Include_Path) -o gccDebug/RenderVectorPathCommand.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM RenderVectorPathCommand.cpp $(Debug_Include_Path) > gccDebug/RenderVectorPathCommand.d

# Compiles file ScaleTransformation.cpp for the Debug configuration...
-include gccDebug/ScaleTransformation.d
gccDebug/ScaleTransformation.o: ScaleTransformation.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ScaleTransformation.cpp $(Debug_Include_Path) -o gccDebug/ScaleTransformation.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ScaleTransformation.cpp $(Debug_Include_Path) > gccDebug/ScaleTransformation.d

# Compiles file ScaleTransformation3D.cpp for the Debug configuration...
-include gccDebug/ScaleTransformation3D.d
gccDebug/ScaleTransformation3D.o: ScaleTransformation3D.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ScaleTransformation3D.cpp $(Debug_Include_Path) -o gccDebug/ScaleTransformation3D.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ScaleTransformation3D.cpp $(Debug_Include_Path) > gccDebug/ScaleTransformation3D.d

# Compiles file Scene.cpp for the Debug configuration...
-include gccDebug/Scene.d
gccDebug/Scene.o: Scene.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Scene.cpp $(Debug_Include_Path) -o gccDebug/Scene.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Scene.cpp $(Debug_Include_Path) > gccDebug/Scene.d

# Compiles file ShadowPointLight.cpp for the Debug configuration...
-include gccDebug/ShadowPointLight.d
gccDebug/ShadowPointLight.o: ShadowPointLight.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ShadowPointLight.cpp $(Debug_Include_Path) -o gccDebug/ShadowPointLight.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ShadowPointLight.cpp $(Debug_Include_Path) > gccDebug/ShadowPointLight.d

# Compiles file SolidColorBrush.cpp for the Debug configuration...
-include gccDebug/SolidColorBrush.d
gccDebug/SolidColorBrush.o: SolidColorBrush.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c SolidColorBrush.cpp $(Debug_Include_Path) -o gccDebug/SolidColorBrush.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM SolidColorBrush.cpp $(Debug_Include_Path) > gccDebug/SolidColorBrush.d

# Compiles file SolidColorBrush3.cpp for the Debug configuration...
-include gccDebug/SolidColorBrush3.d
gccDebug/SolidColorBrush3.o: SolidColorBrush3.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c SolidColorBrush3.cpp $(Debug_Include_Path) -o gccDebug/SolidColorBrush3.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM SolidColorBrush3.cpp $(Debug_Include_Path) > gccDebug/SolidColorBrush3.d

# Compiles file SpecularLightComponent.cpp for the Debug configuration...
-include gccDebug/SpecularLightComponent.d
gccDebug/SpecularLightComponent.o: SpecularLightComponent.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c SpecularLightComponent.cpp $(Debug_Include_Path) -o gccDebug/SpecularLightComponent.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM SpecularLightComponent.cpp $(Debug_Include_Path) > gccDebug/SpecularLightComponent.d

# Compiles file Sphere.cpp for the Debug configuration...
-include gccDebug/Sphere.d
gccDebug/Sphere.o: Sphere.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Sphere.cpp $(Debug_Include_Path) -o gccDebug/Sphere.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Sphere.cpp $(Debug_Include_Path) > gccDebug/Sphere.d

# Compiles file SphereTextureBrush.cpp for the Debug configuration...
-include gccDebug/SphereTextureBrush.d
gccDebug/SphereTextureBrush.o: SphereTextureBrush.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c SphereTextureBrush.cpp $(Debug_Include_Path) -o gccDebug/SphereTextureBrush.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM SphereTextureBrush.cpp $(Debug_Include_Path) > gccDebug/SphereTextureBrush.d

# Compiles file SubtractBrush.cpp for the Debug configuration...
-include gccDebug/SubtractBrush.d
gccDebug/SubtractBrush.o: SubtractBrush.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c SubtractBrush.cpp $(Debug_Include_Path) -o gccDebug/SubtractBrush.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM SubtractBrush.cpp $(Debug_Include_Path) > gccDebug/SubtractBrush.d

# Compiles file SvgHelpers.cpp for the Debug configuration...
-include gccDebug/SvgHelpers.d
gccDebug/SvgHelpers.o: SvgHelpers.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c SvgHelpers.cpp $(Debug_Include_Path) -o gccDebug/SvgHelpers.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM SvgHelpers.cpp $(Debug_Include_Path) > gccDebug/SvgHelpers.d

# Compiles file SvgInstructionStream.cpp for the Debug configuration...
-include gccDebug/SvgInstructionStream.d
gccDebug/SvgInstructionStream.o: SvgInstructionStream.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c SvgInstructionStream.cpp $(Debug_Include_Path) -o gccDebug/SvgInstructionStream.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM SvgInstructionStream.cpp $(Debug_Include_Path) > gccDebug/SvgInstructionStream.d

# Compiles file SvgVectorPath.cpp for the Debug configuration...
-include gccDebug/SvgVectorPath.d
gccDebug/SvgVectorPath.o: SvgVectorPath.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c SvgVectorPath.cpp $(Debug_Include_Path) -o gccDebug/SvgVectorPath.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM SvgVectorPath.cpp $(Debug_Include_Path) > gccDebug/SvgVectorPath.d

# Compiles file Tetrahedron.cpp for the Debug configuration...
-include gccDebug/Tetrahedron.d
gccDebug/Tetrahedron.o: Tetrahedron.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Tetrahedron.cpp $(Debug_Include_Path) -o gccDebug/Tetrahedron.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Tetrahedron.cpp $(Debug_Include_Path) > gccDebug/Tetrahedron.d

# Compiles file TexturedShape.cpp for the Debug configuration...
-include gccDebug/TexturedShape.d
gccDebug/TexturedShape.o: TexturedShape.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c TexturedShape.cpp $(Debug_Include_Path) -o gccDebug/TexturedShape.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM TexturedShape.cpp $(Debug_Include_Path) > gccDebug/TexturedShape.d

# Compiles file TexturedShapeRenderCommand.cpp for the Debug configuration...
-include gccDebug/TexturedShapeRenderCommand.d
gccDebug/TexturedShapeRenderCommand.o: TexturedShapeRenderCommand.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c TexturedShapeRenderCommand.cpp $(Debug_Include_Path) -o gccDebug/TexturedShapeRenderCommand.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM TexturedShapeRenderCommand.cpp $(Debug_Include_Path) > gccDebug/TexturedShapeRenderCommand.d

# Compiles file TextureSkin.cpp for the Debug configuration...
-include gccDebug/TextureSkin.d
gccDebug/TextureSkin.o: TextureSkin.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c TextureSkin.cpp $(Debug_Include_Path) -o gccDebug/TextureSkin.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM TextureSkin.cpp $(Debug_Include_Path) > gccDebug/TextureSkin.d

# Compiles file Torus.cpp for the Debug configuration...
-include gccDebug/Torus.d
gccDebug/Torus.o: Torus.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Torus.cpp $(Debug_Include_Path) -o gccDebug/Torus.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Torus.cpp $(Debug_Include_Path) > gccDebug/Torus.d

# Compiles file TransformationAnalyzer.cpp for the Debug configuration...
-include gccDebug/TransformationAnalyzer.d
gccDebug/TransformationAnalyzer.o: TransformationAnalyzer.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c TransformationAnalyzer.cpp $(Debug_Include_Path) -o gccDebug/TransformationAnalyzer.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM TransformationAnalyzer.cpp $(Debug_Include_Path) > gccDebug/TransformationAnalyzer.d

# Compiles file TransformingShapeBase.cpp for the Debug configuration...
-include gccDebug/TransformingShapeBase.d
gccDebug/TransformingShapeBase.o: TransformingShapeBase.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c TransformingShapeBase.cpp $(Debug_Include_Path) -o gccDebug/TransformingShapeBase.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM TransformingShapeBase.cpp $(Debug_Include_Path) > gccDebug/TransformingShapeBase.d

# Compiles file TranslateTransformation.cpp for the Debug configuration...
-include gccDebug/TranslateTransformation.d
gccDebug/TranslateTransformation.o: TranslateTransformation.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c TranslateTransformation.cpp $(Debug_Include_Path) -o gccDebug/TranslateTransformation.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM TranslateTransformation.cpp $(Debug_Include_Path) > gccDebug/TranslateTransformation.d

# Compiles file TranslateTransformation3D.cpp for the Debug configuration...
-include gccDebug/TranslateTransformation3D.d
gccDebug/TranslateTransformation3D.o: TranslateTransformation3D.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c TranslateTransformation3D.cpp $(Debug_Include_Path) -o gccDebug/TranslateTransformation3D.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM TranslateTransformation3D.cpp $(Debug_Include_Path) > gccDebug/TranslateTransformation3D.d

# Compiles file TriangleShape.cpp for the Debug configuration...
-include gccDebug/TriangleShape.d
gccDebug/TriangleShape.o: TriangleShape.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c TriangleShape.cpp $(Debug_Include_Path) -o gccDebug/TriangleShape.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM TriangleShape.cpp $(Debug_Include_Path) > gccDebug/TriangleShape.d

# Compiles file TurtleMesh.cpp for the Debug configuration...
-include gccDebug/TurtleMesh.d
gccDebug/TurtleMesh.o: TurtleMesh.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c TurtleMesh.cpp $(Debug_Include_Path) -o gccDebug/TurtleMesh.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM TurtleMesh.cpp $(Debug_Include_Path) > gccDebug/TurtleMesh.d

# Compiles file TurtleMeshState.cpp for the Debug configuration...
-include gccDebug/TurtleMeshState.d
gccDebug/TurtleMeshState.o: TurtleMeshState.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c TurtleMeshState.cpp $(Debug_Include_Path) -o gccDebug/TurtleMeshState.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM TurtleMeshState.cpp $(Debug_Include_Path) > gccDebug/TurtleMeshState.d

# Compiles file TurtlePath.cpp for the Debug configuration...
-include gccDebug/TurtlePath.d
gccDebug/TurtlePath.o: TurtlePath.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c TurtlePath.cpp $(Debug_Include_Path) -o gccDebug/TurtlePath.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM TurtlePath.cpp $(Debug_Include_Path) > gccDebug/TurtlePath.d

# Compiles file TurtleState.cpp for the Debug configuration...
-include gccDebug/TurtleState.d
gccDebug/TurtleState.o: TurtleState.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c TurtleState.cpp $(Debug_Include_Path) -o gccDebug/TurtleState.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM TurtleState.cpp $(Debug_Include_Path) > gccDebug/TurtleState.d

# Compiles file vector.cc for the Debug configuration...
-include gccDebug/vector.d
gccDebug/vector.o: vector.cc
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c vector.cc $(Debug_Include_Path) -o gccDebug/vector.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM vector.cc $(Debug_Include_Path) > gccDebug/vector.d

# Compiles file Vector2.cpp for the Debug configuration...
-include gccDebug/Vector2.d
gccDebug/Vector2.o: Vector2.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Vector2.cpp $(Debug_Include_Path) -o gccDebug/Vector2.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Vector2.cpp $(Debug_Include_Path) > gccDebug/Vector2.d

# Compiles file Vector3.cpp for the Debug configuration...
-include gccDebug/Vector3.d
gccDebug/Vector3.o: Vector3.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Vector3.cpp $(Debug_Include_Path) -o gccDebug/Vector3.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Vector3.cpp $(Debug_Include_Path) > gccDebug/Vector3.d

# Compiles file Vector4.cpp for the Debug configuration...
-include gccDebug/Vector4.d
gccDebug/Vector4.o: Vector4.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Vector4.cpp $(Debug_Include_Path) -o gccDebug/Vector4.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Vector4.cpp $(Debug_Include_Path) > gccDebug/Vector4.d

# Compiles file VectorInstructionStreamBase.cpp for the Debug configuration...
-include gccDebug/VectorInstructionStreamBase.d
gccDebug/VectorInstructionStreamBase.o: VectorInstructionStreamBase.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c VectorInstructionStreamBase.cpp $(Debug_Include_Path) -o gccDebug/VectorInstructionStreamBase.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM VectorInstructionStreamBase.cpp $(Debug_Include_Path) > gccDebug/VectorInstructionStreamBase.d

# Compiles file VectorLinePath.cpp for the Debug configuration...
-include gccDebug/VectorLinePath.d
gccDebug/VectorLinePath.o: VectorLinePath.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c VectorLinePath.cpp $(Debug_Include_Path) -o gccDebug/VectorLinePath.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM VectorLinePath.cpp $(Debug_Include_Path) > gccDebug/VectorLinePath.d

# Compiles file VectorPathBase.cpp for the Debug configuration...
-include gccDebug/VectorPathBase.d
gccDebug/VectorPathBase.o: VectorPathBase.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c VectorPathBase.cpp $(Debug_Include_Path) -o gccDebug/VectorPathBase.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM VectorPathBase.cpp $(Debug_Include_Path) > gccDebug/VectorPathBase.d

# Compiles file VectorRenderContext.cpp for the Debug configuration...
-include gccDebug/VectorRenderContext.d
gccDebug/VectorRenderContext.o: VectorRenderContext.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c VectorRenderContext.cpp $(Debug_Include_Path) -o gccDebug/VectorRenderContext.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM VectorRenderContext.cpp $(Debug_Include_Path) > gccDebug/VectorRenderContext.d

# Compiles file Wireframe.cpp for the Debug configuration...
-include gccDebug/Wireframe.d
gccDebug/Wireframe.o: Wireframe.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Wireframe.cpp $(Debug_Include_Path) -o gccDebug/Wireframe.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Wireframe.cpp $(Debug_Include_Path) > gccDebug/Wireframe.d

# Compiles file WriteLineSegmentCommand.cpp for the Debug configuration...
-include gccDebug/WriteLineSegmentCommand.d
gccDebug/WriteLineSegmentCommand.o: WriteLineSegmentCommand.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c WriteLineSegmentCommand.cpp $(Debug_Include_Path) -o gccDebug/WriteLineSegmentCommand.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM WriteLineSegmentCommand.cpp $(Debug_Include_Path) > gccDebug/WriteLineSegmentCommand.d

# Compiles file ZBuffer.cpp for the Debug configuration...
-include gccDebug/ZBuffer.d
gccDebug/ZBuffer.o: ZBuffer.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ZBuffer.cpp $(Debug_Include_Path) -o gccDebug/ZBuffer.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ZBuffer.cpp $(Debug_Include_Path) > gccDebug/ZBuffer.d

# Compiles file ZBufferingHandlerBase.cpp for the Debug configuration...
-include gccDebug/ZBufferingHandlerBase.d
gccDebug/ZBufferingHandlerBase.o: ZBufferingHandlerBase.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c ZBufferingHandlerBase.cpp $(Debug_Include_Path) -o gccDebug/ZBufferingHandlerBase.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM ZBufferingHandlerBase.cpp $(Debug_Include_Path) > gccDebug/ZBufferingHandlerBase.d

# Builds the Release configuration...
.PHONY: Release
Release: create_folders AdditiveBrush.o BitmapLinePath.o BitmapRenderContext.o BrushTexture.o Buckyball.o ComplexMesh.o CompositeLightComponent.o CompositeMesh.o CompositeShape.o Cone.o ConstantDepthBuffer.o CosineInterpolationSampler.o Cube.o CubicInterpolationSampler.o Cylinder.o DepthBrushBase.o DepthSkin.o DepthSkinBase.o DiffuseLightComponent.o Dodecahedron.o EasyBitmap.o EasyImage.o EmptyTexture.o engine.o Face.o Helpers.o Icosahedron.o IndexedLine.o InfinityLight.o ini_configuration.o IOutputImage.o LightingBrush.o LightingHandler.o LightingSkin.o LightingState.o LightingTexture.o LinearInterpolationSampler.o LineDepthBrush.o LinePathBase.o LineSegment.o lparser.o MatrixHelpers.o Mengersponge.o MeshHandlerBase.o MultiLine.o MultiLineRenderCommand.o MultiplicativeBrush.o NearestNeighborClampingSampler.o NearestNeighborWrappingSampler.o NormalizedShape.o Octahedron.o OpacityMask.o OverBrush.o ParallelProjection.o PartialLineSegment.o PerspectiveProjection.o PixelPosition.o PlaneTextureBrush.o PointLight.o PolygonDepthBrush.o Polyhedron.o PortablePixelmap.o ProjectedLineSegment.o ProjectedLineSegmentRenderCommand.o ProjectedMultiLine.o ProjectedMultiLineRenderCommand.o ProjectedPolygonTexture.o RadialGradientBrush.o RadialGradientBrush3.o RectangleBounds.o ReflectionProperties.o RenderBitmapSegmentCommand.o RenderHandlers.o RenderTriangleCommand.o RenderVectorPathCommand.o ScaleTransformation.o ScaleTransformation3D.o Scene.o ShadowPointLight.o SolidColorBrush.o SolidColorBrush3.o SpecularLightComponent.o Sphere.o SphereTextureBrush.o SubtractBrush.o SvgHelpers.o SvgInstructionStream.o SvgVectorPath.o Tetrahedron.o TexturedShape.o TexturedShapeRenderCommand.o TextureSkin.o Torus.o TransformationAnalyzer.o TransformingShapeBase.o TranslateTransformation.o TranslateTransformation3D.o TriangleShape.o TurtleMesh.o TurtleMeshState.o TurtlePath.o TurtleState.o vector.o Vector2.o Vector3.o Vector4.o VectorInstructionStreamBase.o VectorLinePath.o VectorPathBase.o VectorRenderContext.o Wireframe.o WriteLineSegmentCommand.o ZBuffer.o ZBufferingHandlerBase.o
	$(CPP_COMPILER) AdditiveBrush.o BitmapLinePath.o BitmapRenderContext.o BrushTexture.o Buckyball.o ComplexMesh.o CompositeLightComponent.o CompositeMesh.o CompositeShape.o Cone.o ConstantDepthBuffer.o CosineInterpolationSampler.o Cube.o CubicInterpolationSampler.o Cylinder.o DepthBrushBase.o DepthSkin.o DepthSkinBase.o DiffuseLightComponent.o Dodecahedron.o EasyBitmap.o EasyImage.o EmptyTexture.o engine.o Face.o Helpers.o Icosahedron.o IndexedLine.o InfinityLight.o ini_configuration.o IOutputImage.o LightingBrush.o LightingHandler.o LightingSkin.o LightingState.o LightingTexture.o LinearInterpolationSampler.o LineDepthBrush.o LinePathBase.o LineSegment.o lparser.o MatrixHelpers.o Mengersponge.o MeshHandlerBase.o MultiLine.o MultiLineRenderCommand.o MultiplicativeBrush.o NearestNeighborClampingSampler.o NearestNeighborWrappingSampler.o NormalizedShape.o Octahedron.o OpacityMask.o OverBrush.o ParallelProjection.o PartialLineSegment.o PerspectiveProjection.o PixelPosition.o PlaneTextureBrush.o PointLight.o PolygonDepthBrush.o Polyhedron.o PortablePixelmap.o ProjectedLineSegment.o ProjectedLineSegmentRenderCommand.o ProjectedMultiLine.o ProjectedMultiLineRenderCommand.o ProjectedPolygonTexture.o RadialGradientBrush.o RadialGradientBrush3.o RectangleBounds.o ReflectionProperties.o RenderBitmapSegmentCommand.o RenderHandlers.o RenderTriangleCommand.o RenderVectorPathCommand.o ScaleTransformation.o ScaleTransformation3D.o Scene.o ShadowPointLight.o SolidColorBrush.o SolidColorBrush3.o SpecularLightComponent.o Sphere.o SphereTextureBrush.o SubtractBrush.o SvgHelpers.o SvgInstructionStream.o SvgVectorPath.o Tetrahedron.o TexturedShape.o TexturedShapeRenderCommand.o TextureSkin.o Torus.o TransformationAnalyzer.o TransformingShapeBase.o TranslateTransformation.o TranslateTransformation3D.o TriangleShape.o TurtleMesh.o TurtleMeshState.o TurtlePath.o TurtleState.o vector.o Vector2.o Vector3.o Vector4.o VectorInstructionStreamBase.o VectorLinePath.o VectorPathBase.o VectorRenderContext.o Wireframe.o WriteLineSegmentCommand.o ZBuffer.o ZBufferingHandlerBase.o $(Release_Library_Path) $(Release_Libraries) -Wl,-rpath,./ -o engine

# Compiles file AdditiveBrush.cpp for the Release configuration...
-include AdditiveBrush.d
AdditiveBrush.o: AdditiveBrush.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c AdditiveBrush.cpp $(Release_Include_Path) -o AdditiveBrush.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM AdditiveBrush.cpp $(Release_Include_Path) > AdditiveBrush.d

# Compiles file BitmapLinePath.cpp for the Release configuration...
-include BitmapLinePath.d
BitmapLinePath.o: BitmapLinePath.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c BitmapLinePath.cpp $(Release_Include_Path) -o BitmapLinePath.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM BitmapLinePath.cpp $(Release_Include_Path) > BitmapLinePath.d

# Compiles file BitmapRenderContext.cpp for the Release configuration...
-include BitmapRenderContext.d
BitmapRenderContext.o: BitmapRenderContext.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c BitmapRenderContext.cpp $(Release_Include_Path) -o BitmapRenderContext.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM BitmapRenderContext.cpp $(Release_Include_Path) > BitmapRenderContext.d

# Compiles file BrushTexture.cpp for the Release configuration...
-include BrushTexture.d
BrushTexture.o: BrushTexture.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c BrushTexture.cpp $(Release_Include_Path) -o BrushTexture.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM BrushTexture.cpp $(Release_Include_Path) > BrushTexture.d

# Compiles file Buckyball.cpp for the Release configuration...
-include Buckyball.d
Buckyball.o: Buckyball.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Buckyball.cpp $(Release_Include_Path) -o Buckyball.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Buckyball.cpp $(Release_Include_Path) > Buckyball.d

# Compiles file ComplexMesh.cpp for the Release configuration...
-include ComplexMesh.d
ComplexMesh.o: ComplexMesh.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ComplexMesh.cpp $(Release_Include_Path) -o ComplexMesh.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ComplexMesh.cpp $(Release_Include_Path) > ComplexMesh.d

# Compiles file CompositeLightComponent.cpp for the Release configuration...
-include CompositeLightComponent.d
CompositeLightComponent.o: CompositeLightComponent.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c CompositeLightComponent.cpp $(Release_Include_Path) -o CompositeLightComponent.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM CompositeLightComponent.cpp $(Release_Include_Path) > CompositeLightComponent.d

# Compiles file CompositeMesh.cpp for the Release configuration...
-include CompositeMesh.d
CompositeMesh.o: CompositeMesh.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c CompositeMesh.cpp $(Release_Include_Path) -o CompositeMesh.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM CompositeMesh.cpp $(Release_Include_Path) > CompositeMesh.d

# Compiles file CompositeShape.cpp for the Release configuration...
-include CompositeShape.d
CompositeShape.o: CompositeShape.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c CompositeShape.cpp $(Release_Include_Path) -o CompositeShape.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM CompositeShape.cpp $(Release_Include_Path) > CompositeShape.d

# Compiles file Cone.cpp for the Release configuration...
-include Cone.d
Cone.o: Cone.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Cone.cpp $(Release_Include_Path) -o Cone.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Cone.cpp $(Release_Include_Path) > Cone.d

# Compiles file ConstantDepthBuffer.cpp for the Release configuration...
-include ConstantDepthBuffer.d
ConstantDepthBuffer.o: ConstantDepthBuffer.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ConstantDepthBuffer.cpp $(Release_Include_Path) -o ConstantDepthBuffer.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ConstantDepthBuffer.cpp $(Release_Include_Path) > ConstantDepthBuffer.d

# Compiles file CosineInterpolationSampler.cpp for the Release configuration...
-include CosineInterpolationSampler.d
CosineInterpolationSampler.o: CosineInterpolationSampler.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c CosineInterpolationSampler.cpp $(Release_Include_Path) -o CosineInterpolationSampler.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM CosineInterpolationSampler.cpp $(Release_Include_Path) > CosineInterpolationSampler.d

# Compiles file Cube.cpp for the Release configuration...
-include Cube.d
Cube.o: Cube.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Cube.cpp $(Release_Include_Path) -o Cube.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Cube.cpp $(Release_Include_Path) > Cube.d

# Compiles file CubicInterpolationSampler.cpp for the Release configuration...
-include CubicInterpolationSampler.d
CubicInterpolationSampler.o: CubicInterpolationSampler.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c CubicInterpolationSampler.cpp $(Release_Include_Path) -o CubicInterpolationSampler.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM CubicInterpolationSampler.cpp $(Release_Include_Path) > CubicInterpolationSampler.d

# Compiles file Cylinder.cpp for the Release configuration...
-include Cylinder.d
Cylinder.o: Cylinder.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Cylinder.cpp $(Release_Include_Path) -o Cylinder.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Cylinder.cpp $(Release_Include_Path) > Cylinder.d

# Compiles file DepthBrushBase.cpp for the Release configuration...
-include DepthBrushBase.d
DepthBrushBase.o: DepthBrushBase.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c DepthBrushBase.cpp $(Release_Include_Path) -o DepthBrushBase.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM DepthBrushBase.cpp $(Release_Include_Path) > DepthBrushBase.d

# Compiles file DepthSkin.cpp for the Release configuration...
-include DepthSkin.d
DepthSkin.o: DepthSkin.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c DepthSkin.cpp $(Release_Include_Path) -o DepthSkin.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM DepthSkin.cpp $(Release_Include_Path) > DepthSkin.d

# Compiles file DepthSkinBase.cpp for the Release configuration...
-include DepthSkinBase.d
DepthSkinBase.o: DepthSkinBase.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c DepthSkinBase.cpp $(Release_Include_Path) -o DepthSkinBase.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM DepthSkinBase.cpp $(Release_Include_Path) > DepthSkinBase.d

# Compiles file DiffuseLightComponent.cpp for the Release configuration...
-include DiffuseLightComponent.d
DiffuseLightComponent.o: DiffuseLightComponent.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c DiffuseLightComponent.cpp $(Release_Include_Path) -o DiffuseLightComponent.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM DiffuseLightComponent.cpp $(Release_Include_Path) > DiffuseLightComponent.d

# Compiles file Dodecahedron.cpp for the Release configuration...
-include Dodecahedron.d
Dodecahedron.o: Dodecahedron.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Dodecahedron.cpp $(Release_Include_Path) -o Dodecahedron.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Dodecahedron.cpp $(Release_Include_Path) > Dodecahedron.d

# Compiles file EasyBitmap.cpp for the Release configuration...
-include EasyBitmap.d
EasyBitmap.o: EasyBitmap.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c EasyBitmap.cpp $(Release_Include_Path) -o EasyBitmap.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM EasyBitmap.cpp $(Release_Include_Path) > EasyBitmap.d

# Compiles file EasyImage.cc for the Release configuration...
-include EasyImage.d
EasyImage.o: EasyImage.cc
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c EasyImage.cc $(Release_Include_Path) -o EasyImage.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM EasyImage.cc $(Release_Include_Path) > EasyImage.d

# Compiles file EmptyTexture.cpp for the Release configuration...
-include EmptyTexture.d
EmptyTexture.o: EmptyTexture.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c EmptyTexture.cpp $(Release_Include_Path) -o EmptyTexture.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM EmptyTexture.cpp $(Release_Include_Path) > EmptyTexture.d

# Compiles file engine.cc for the Release configuration...
-include engine.d
engine.o: engine.cc
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c engine.cc $(Release_Include_Path) -o engine.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM engine.cc $(Release_Include_Path) > engine.d

# Compiles file Face.cpp for the Release configuration...
-include Face.d
Face.o: Face.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Face.cpp $(Release_Include_Path) -o Face.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Face.cpp $(Release_Include_Path) > Face.d

# Compiles file Helpers.cpp for the Release configuration...
-include Helpers.d
Helpers.o: Helpers.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Helpers.cpp $(Release_Include_Path) -o Helpers.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Helpers.cpp $(Release_Include_Path) > Helpers.d

# Compiles file Icosahedron.cpp for the Release configuration...
-include Icosahedron.d
Icosahedron.o: Icosahedron.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Icosahedron.cpp $(Release_Include_Path) -o Icosahedron.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Icosahedron.cpp $(Release_Include_Path) > Icosahedron.d

# Compiles file IndexedLine.cpp for the Release configuration...
-include IndexedLine.d
IndexedLine.o: IndexedLine.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c IndexedLine.cpp $(Release_Include_Path) -o IndexedLine.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM IndexedLine.cpp $(Release_Include_Path) > IndexedLine.d

# Compiles file InfinityLight.cpp for the Release configuration...
-include InfinityLight.d
InfinityLight.o: InfinityLight.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c InfinityLight.cpp $(Release_Include_Path) -o InfinityLight.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM InfinityLight.cpp $(Release_Include_Path) > InfinityLight.d

# Compiles file ini_configuration.cc for the Release configuration...
-include ini_configuration.d
ini_configuration.o: ini_configuration.cc
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ini_configuration.cc $(Release_Include_Path) -o ini_configuration.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ini_configuration.cc $(Release_Include_Path) > ini_configuration.d

# Compiles file IOutputImage.cpp for the Release configuration...
-include IOutputImage.d
IOutputImage.o: IOutputImage.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c IOutputImage.cpp $(Release_Include_Path) -o IOutputImage.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM IOutputImage.cpp $(Release_Include_Path) > IOutputImage.d

# Compiles file LightingBrush.cpp for the Release configuration...
-include LightingBrush.d
LightingBrush.o: LightingBrush.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c LightingBrush.cpp $(Release_Include_Path) -o LightingBrush.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM LightingBrush.cpp $(Release_Include_Path) > LightingBrush.d

# Compiles file LightingHandler.cpp for the Release configuration...
-include LightingHandler.d
LightingHandler.o: LightingHandler.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c LightingHandler.cpp $(Release_Include_Path) -o LightingHandler.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM LightingHandler.cpp $(Release_Include_Path) > LightingHandler.d

# Compiles file LightingSkin.cpp for the Release configuration...
-include LightingSkin.d
LightingSkin.o: LightingSkin.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c LightingSkin.cpp $(Release_Include_Path) -o LightingSkin.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM LightingSkin.cpp $(Release_Include_Path) > LightingSkin.d

# Compiles file LightingState.cpp for the Release configuration...
-include LightingState.d
LightingState.o: LightingState.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c LightingState.cpp $(Release_Include_Path) -o LightingState.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM LightingState.cpp $(Release_Include_Path) > LightingState.d

# Compiles file LightingTexture.cpp for the Release configuration...
-include LightingTexture.d
LightingTexture.o: LightingTexture.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c LightingTexture.cpp $(Release_Include_Path) -o LightingTexture.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM LightingTexture.cpp $(Release_Include_Path) > LightingTexture.d

# Compiles file LinearInterpolationSampler.cpp for the Release configuration...
-include LinearInterpolationSampler.d
LinearInterpolationSampler.o: LinearInterpolationSampler.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c LinearInterpolationSampler.cpp $(Release_Include_Path) -o LinearInterpolationSampler.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM LinearInterpolationSampler.cpp $(Release_Include_Path) > LinearInterpolationSampler.d

# Compiles file LineDepthBrush.cpp for the Release configuration...
-include LineDepthBrush.d
LineDepthBrush.o: LineDepthBrush.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c LineDepthBrush.cpp $(Release_Include_Path) -o LineDepthBrush.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM LineDepthBrush.cpp $(Release_Include_Path) > LineDepthBrush.d

# Compiles file LinePathBase.cpp for the Release configuration...
-include LinePathBase.d
LinePathBase.o: LinePathBase.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c LinePathBase.cpp $(Release_Include_Path) -o LinePathBase.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM LinePathBase.cpp $(Release_Include_Path) > LinePathBase.d

# Compiles file LineSegment.cpp for the Release configuration...
-include LineSegment.d
LineSegment.o: LineSegment.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c LineSegment.cpp $(Release_Include_Path) -o LineSegment.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM LineSegment.cpp $(Release_Include_Path) > LineSegment.d

# Compiles file lparser.cc for the Release configuration...
-include lparser.d
lparser.o: lparser.cc
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c lparser.cc $(Release_Include_Path) -o lparser.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM lparser.cc $(Release_Include_Path) > lparser.d

# Compiles file MatrixHelpers.cpp for the Release configuration...
-include MatrixHelpers.d
MatrixHelpers.o: MatrixHelpers.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c MatrixHelpers.cpp $(Release_Include_Path) -o MatrixHelpers.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM MatrixHelpers.cpp $(Release_Include_Path) > MatrixHelpers.d

# Compiles file Mengersponge.cpp for the Release configuration...
-include Mengersponge.d
Mengersponge.o: Mengersponge.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Mengersponge.cpp $(Release_Include_Path) -o Mengersponge.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Mengersponge.cpp $(Release_Include_Path) > Mengersponge.d

# Compiles file MeshHandlerBase.cpp for the Release configuration...
-include MeshHandlerBase.d
MeshHandlerBase.o: MeshHandlerBase.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c MeshHandlerBase.cpp $(Release_Include_Path) -o MeshHandlerBase.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM MeshHandlerBase.cpp $(Release_Include_Path) > MeshHandlerBase.d

# Compiles file MultiLine.cpp for the Release configuration...
-include MultiLine.d
MultiLine.o: MultiLine.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c MultiLine.cpp $(Release_Include_Path) -o MultiLine.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM MultiLine.cpp $(Release_Include_Path) > MultiLine.d

# Compiles file MultiLineRenderCommand.cpp for the Release configuration...
-include MultiLineRenderCommand.d
MultiLineRenderCommand.o: MultiLineRenderCommand.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c MultiLineRenderCommand.cpp $(Release_Include_Path) -o MultiLineRenderCommand.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM MultiLineRenderCommand.cpp $(Release_Include_Path) > MultiLineRenderCommand.d

# Compiles file MultiplicativeBrush.cpp for the Release configuration...
-include MultiplicativeBrush.d
MultiplicativeBrush.o: MultiplicativeBrush.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c MultiplicativeBrush.cpp $(Release_Include_Path) -o MultiplicativeBrush.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM MultiplicativeBrush.cpp $(Release_Include_Path) > MultiplicativeBrush.d

# Compiles file NearestNeighborClampingSampler.cpp for the Release configuration...
-include NearestNeighborClampingSampler.d
NearestNeighborClampingSampler.o: NearestNeighborClampingSampler.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c NearestNeighborClampingSampler.cpp $(Release_Include_Path) -o NearestNeighborClampingSampler.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM NearestNeighborClampingSampler.cpp $(Release_Include_Path) > NearestNeighborClampingSampler.d

# Compiles file NearestNeighborWrappingSampler.cpp for the Release configuration...
-include NearestNeighborWrappingSampler.d
NearestNeighborWrappingSampler.o: NearestNeighborWrappingSampler.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c NearestNeighborWrappingSampler.cpp $(Release_Include_Path) -o NearestNeighborWrappingSampler.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM NearestNeighborWrappingSampler.cpp $(Release_Include_Path) > NearestNeighborWrappingSampler.d

# Compiles file NormalizedShape.cpp for the Release configuration...
-include NormalizedShape.d
NormalizedShape.o: NormalizedShape.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c NormalizedShape.cpp $(Release_Include_Path) -o NormalizedShape.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM NormalizedShape.cpp $(Release_Include_Path) > NormalizedShape.d

# Compiles file Octahedron.cpp for the Release configuration...
-include Octahedron.d
Octahedron.o: Octahedron.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Octahedron.cpp $(Release_Include_Path) -o Octahedron.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Octahedron.cpp $(Release_Include_Path) > Octahedron.d

# Compiles file OpacityMask.cpp for the Release configuration...
-include OpacityMask.d
OpacityMask.o: OpacityMask.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c OpacityMask.cpp $(Release_Include_Path) -o OpacityMask.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM OpacityMask.cpp $(Release_Include_Path) > OpacityMask.d

# Compiles file OverBrush.cpp for the Release configuration...
-include OverBrush.d
OverBrush.o: OverBrush.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c OverBrush.cpp $(Release_Include_Path) -o OverBrush.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM OverBrush.cpp $(Release_Include_Path) > OverBrush.d

# Compiles file ParallelProjection.cpp for the Release configuration...
-include ParallelProjection.d
ParallelProjection.o: ParallelProjection.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ParallelProjection.cpp $(Release_Include_Path) -o ParallelProjection.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ParallelProjection.cpp $(Release_Include_Path) > ParallelProjection.d

# Compiles file PartialLineSegment.cpp for the Release configuration...
-include PartialLineSegment.d
PartialLineSegment.o: PartialLineSegment.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c PartialLineSegment.cpp $(Release_Include_Path) -o PartialLineSegment.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM PartialLineSegment.cpp $(Release_Include_Path) > PartialLineSegment.d

# Compiles file PerspectiveProjection.cpp for the Release configuration...
-include PerspectiveProjection.d
PerspectiveProjection.o: PerspectiveProjection.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c PerspectiveProjection.cpp $(Release_Include_Path) -o PerspectiveProjection.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM PerspectiveProjection.cpp $(Release_Include_Path) > PerspectiveProjection.d

# Compiles file PixelPosition.cpp for the Release configuration...
-include PixelPosition.d
PixelPosition.o: PixelPosition.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c PixelPosition.cpp $(Release_Include_Path) -o PixelPosition.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM PixelPosition.cpp $(Release_Include_Path) > PixelPosition.d

# Compiles file PlaneTextureBrush.cpp for the Release configuration...
-include PlaneTextureBrush.d
PlaneTextureBrush.o: PlaneTextureBrush.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c PlaneTextureBrush.cpp $(Release_Include_Path) -o PlaneTextureBrush.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM PlaneTextureBrush.cpp $(Release_Include_Path) > PlaneTextureBrush.d

# Compiles file PointLight.cpp for the Release configuration...
-include PointLight.d
PointLight.o: PointLight.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c PointLight.cpp $(Release_Include_Path) -o PointLight.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM PointLight.cpp $(Release_Include_Path) > PointLight.d

# Compiles file PolygonDepthBrush.cpp for the Release configuration...
-include PolygonDepthBrush.d
PolygonDepthBrush.o: PolygonDepthBrush.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c PolygonDepthBrush.cpp $(Release_Include_Path) -o PolygonDepthBrush.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM PolygonDepthBrush.cpp $(Release_Include_Path) > PolygonDepthBrush.d

# Compiles file Polyhedron.cpp for the Release configuration...
-include Polyhedron.d
Polyhedron.o: Polyhedron.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Polyhedron.cpp $(Release_Include_Path) -o Polyhedron.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Polyhedron.cpp $(Release_Include_Path) > Polyhedron.d

# Compiles file PortablePixelmap.cpp for the Release configuration...
-include PortablePixelmap.d
PortablePixelmap.o: PortablePixelmap.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c PortablePixelmap.cpp $(Release_Include_Path) -o PortablePixelmap.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM PortablePixelmap.cpp $(Release_Include_Path) > PortablePixelmap.d

# Compiles file ProjectedLineSegment.cpp for the Release configuration...
-include ProjectedLineSegment.d
ProjectedLineSegment.o: ProjectedLineSegment.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ProjectedLineSegment.cpp $(Release_Include_Path) -o ProjectedLineSegment.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ProjectedLineSegment.cpp $(Release_Include_Path) > ProjectedLineSegment.d

# Compiles file ProjectedLineSegmentRenderCommand.cpp for the Release configuration...
-include ProjectedLineSegmentRenderCommand.d
ProjectedLineSegmentRenderCommand.o: ProjectedLineSegmentRenderCommand.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ProjectedLineSegmentRenderCommand.cpp $(Release_Include_Path) -o ProjectedLineSegmentRenderCommand.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ProjectedLineSegmentRenderCommand.cpp $(Release_Include_Path) > ProjectedLineSegmentRenderCommand.d

# Compiles file ProjectedMultiLine.cpp for the Release configuration...
-include ProjectedMultiLine.d
ProjectedMultiLine.o: ProjectedMultiLine.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ProjectedMultiLine.cpp $(Release_Include_Path) -o ProjectedMultiLine.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ProjectedMultiLine.cpp $(Release_Include_Path) > ProjectedMultiLine.d

# Compiles file ProjectedMultiLineRenderCommand.cpp for the Release configuration...
-include ProjectedMultiLineRenderCommand.d
ProjectedMultiLineRenderCommand.o: ProjectedMultiLineRenderCommand.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ProjectedMultiLineRenderCommand.cpp $(Release_Include_Path) -o ProjectedMultiLineRenderCommand.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ProjectedMultiLineRenderCommand.cpp $(Release_Include_Path) > ProjectedMultiLineRenderCommand.d

# Compiles file ProjectedPolygonTexture.cpp for the Release configuration...
-include ProjectedPolygonTexture.d
ProjectedPolygonTexture.o: ProjectedPolygonTexture.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ProjectedPolygonTexture.cpp $(Release_Include_Path) -o ProjectedPolygonTexture.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ProjectedPolygonTexture.cpp $(Release_Include_Path) > ProjectedPolygonTexture.d

# Compiles file RadialGradientBrush.cpp for the Release configuration...
-include RadialGradientBrush.d
RadialGradientBrush.o: RadialGradientBrush.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c RadialGradientBrush.cpp $(Release_Include_Path) -o RadialGradientBrush.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM RadialGradientBrush.cpp $(Release_Include_Path) > RadialGradientBrush.d

# Compiles file RadialGradientBrush3.cpp for the Release configuration...
-include RadialGradientBrush3.d
RadialGradientBrush3.o: RadialGradientBrush3.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c RadialGradientBrush3.cpp $(Release_Include_Path) -o RadialGradientBrush3.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM RadialGradientBrush3.cpp $(Release_Include_Path) > RadialGradientBrush3.d

# Compiles file RectangleBounds.cpp for the Release configuration...
-include RectangleBounds.d
RectangleBounds.o: RectangleBounds.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c RectangleBounds.cpp $(Release_Include_Path) -o RectangleBounds.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM RectangleBounds.cpp $(Release_Include_Path) > RectangleBounds.d

# Compiles file ReflectionProperties.cpp for the Release configuration...
-include ReflectionProperties.d
ReflectionProperties.o: ReflectionProperties.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ReflectionProperties.cpp $(Release_Include_Path) -o ReflectionProperties.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ReflectionProperties.cpp $(Release_Include_Path) > ReflectionProperties.d

# Compiles file RenderBitmapSegmentCommand.cpp for the Release configuration...
-include RenderBitmapSegmentCommand.d
RenderBitmapSegmentCommand.o: RenderBitmapSegmentCommand.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c RenderBitmapSegmentCommand.cpp $(Release_Include_Path) -o RenderBitmapSegmentCommand.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM RenderBitmapSegmentCommand.cpp $(Release_Include_Path) > RenderBitmapSegmentCommand.d

# Compiles file RenderHandlers.cpp for the Release configuration...
-include RenderHandlers.d
RenderHandlers.o: RenderHandlers.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c RenderHandlers.cpp $(Release_Include_Path) -o RenderHandlers.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM RenderHandlers.cpp $(Release_Include_Path) > RenderHandlers.d

# Compiles file RenderTriangleCommand.cpp for the Release configuration...
-include RenderTriangleCommand.d
RenderTriangleCommand.o: RenderTriangleCommand.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c RenderTriangleCommand.cpp $(Release_Include_Path) -o RenderTriangleCommand.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM RenderTriangleCommand.cpp $(Release_Include_Path) > RenderTriangleCommand.d

# Compiles file RenderVectorPathCommand.cpp for the Release configuration...
-include RenderVectorPathCommand.d
RenderVectorPathCommand.o: RenderVectorPathCommand.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c RenderVectorPathCommand.cpp $(Release_Include_Path) -o RenderVectorPathCommand.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM RenderVectorPathCommand.cpp $(Release_Include_Path) > RenderVectorPathCommand.d

# Compiles file ScaleTransformation.cpp for the Release configuration...
-include ScaleTransformation.d
ScaleTransformation.o: ScaleTransformation.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ScaleTransformation.cpp $(Release_Include_Path) -o ScaleTransformation.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ScaleTransformation.cpp $(Release_Include_Path) > ScaleTransformation.d

# Compiles file ScaleTransformation3D.cpp for the Release configuration...
-include ScaleTransformation3D.d
ScaleTransformation3D.o: ScaleTransformation3D.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ScaleTransformation3D.cpp $(Release_Include_Path) -o ScaleTransformation3D.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ScaleTransformation3D.cpp $(Release_Include_Path) > ScaleTransformation3D.d

# Compiles file Scene.cpp for the Release configuration...
-include Scene.d
Scene.o: Scene.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Scene.cpp $(Release_Include_Path) -o Scene.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Scene.cpp $(Release_Include_Path) > Scene.d

# Compiles file ShadowPointLight.cpp for the Release configuration...
-include ShadowPointLight.d
ShadowPointLight.o: ShadowPointLight.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ShadowPointLight.cpp $(Release_Include_Path) -o ShadowPointLight.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ShadowPointLight.cpp $(Release_Include_Path) > ShadowPointLight.d

# Compiles file SolidColorBrush.cpp for the Release configuration...
-include SolidColorBrush.d
SolidColorBrush.o: SolidColorBrush.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c SolidColorBrush.cpp $(Release_Include_Path) -o SolidColorBrush.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM SolidColorBrush.cpp $(Release_Include_Path) > SolidColorBrush.d

# Compiles file SolidColorBrush3.cpp for the Release configuration...
-include SolidColorBrush3.d
SolidColorBrush3.o: SolidColorBrush3.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c SolidColorBrush3.cpp $(Release_Include_Path) -o SolidColorBrush3.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM SolidColorBrush3.cpp $(Release_Include_Path) > SolidColorBrush3.d

# Compiles file SpecularLightComponent.cpp for the Release configuration...
-include SpecularLightComponent.d
SpecularLightComponent.o: SpecularLightComponent.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c SpecularLightComponent.cpp $(Release_Include_Path) -o SpecularLightComponent.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM SpecularLightComponent.cpp $(Release_Include_Path) > SpecularLightComponent.d

# Compiles file Sphere.cpp for the Release configuration...
-include Sphere.d
Sphere.o: Sphere.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Sphere.cpp $(Release_Include_Path) -o Sphere.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Sphere.cpp $(Release_Include_Path) > Sphere.d

# Compiles file SphereTextureBrush.cpp for the Release configuration...
-include SphereTextureBrush.d
SphereTextureBrush.o: SphereTextureBrush.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c SphereTextureBrush.cpp $(Release_Include_Path) -o SphereTextureBrush.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM SphereTextureBrush.cpp $(Release_Include_Path) > SphereTextureBrush.d

# Compiles file SubtractBrush.cpp for the Release configuration...
-include SubtractBrush.d
SubtractBrush.o: SubtractBrush.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c SubtractBrush.cpp $(Release_Include_Path) -o SubtractBrush.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM SubtractBrush.cpp $(Release_Include_Path) > SubtractBrush.d

# Compiles file SvgHelpers.cpp for the Release configuration...
-include SvgHelpers.d
SvgHelpers.o: SvgHelpers.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c SvgHelpers.cpp $(Release_Include_Path) -o SvgHelpers.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM SvgHelpers.cpp $(Release_Include_Path) > SvgHelpers.d

# Compiles file SvgInstructionStream.cpp for the Release configuration...
-include SvgInstructionStream.d
SvgInstructionStream.o: SvgInstructionStream.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c SvgInstructionStream.cpp $(Release_Include_Path) -o SvgInstructionStream.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM SvgInstructionStream.cpp $(Release_Include_Path) > SvgInstructionStream.d

# Compiles file SvgVectorPath.cpp for the Release configuration...
-include SvgVectorPath.d
SvgVectorPath.o: SvgVectorPath.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c SvgVectorPath.cpp $(Release_Include_Path) -o SvgVectorPath.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM SvgVectorPath.cpp $(Release_Include_Path) > SvgVectorPath.d

# Compiles file Tetrahedron.cpp for the Release configuration...
-include Tetrahedron.d
Tetrahedron.o: Tetrahedron.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Tetrahedron.cpp $(Release_Include_Path) -o Tetrahedron.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Tetrahedron.cpp $(Release_Include_Path) > Tetrahedron.d

# Compiles file TexturedShape.cpp for the Release configuration...
-include TexturedShape.d
TexturedShape.o: TexturedShape.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c TexturedShape.cpp $(Release_Include_Path) -o TexturedShape.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM TexturedShape.cpp $(Release_Include_Path) > TexturedShape.d

# Compiles file TexturedShapeRenderCommand.cpp for the Release configuration...
-include TexturedShapeRenderCommand.d
TexturedShapeRenderCommand.o: TexturedShapeRenderCommand.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c TexturedShapeRenderCommand.cpp $(Release_Include_Path) -o TexturedShapeRenderCommand.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM TexturedShapeRenderCommand.cpp $(Release_Include_Path) > TexturedShapeRenderCommand.d

# Compiles file TextureSkin.cpp for the Release configuration...
-include TextureSkin.d
TextureSkin.o: TextureSkin.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c TextureSkin.cpp $(Release_Include_Path) -o TextureSkin.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM TextureSkin.cpp $(Release_Include_Path) > TextureSkin.d

# Compiles file Torus.cpp for the Release configuration...
-include Torus.d
Torus.o: Torus.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Torus.cpp $(Release_Include_Path) -o Torus.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Torus.cpp $(Release_Include_Path) > Torus.d

# Compiles file TransformationAnalyzer.cpp for the Release configuration...
-include TransformationAnalyzer.d
TransformationAnalyzer.o: TransformationAnalyzer.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c TransformationAnalyzer.cpp $(Release_Include_Path) -o TransformationAnalyzer.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM TransformationAnalyzer.cpp $(Release_Include_Path) > TransformationAnalyzer.d

# Compiles file TransformingShapeBase.cpp for the Release configuration...
-include TransformingShapeBase.d
TransformingShapeBase.o: TransformingShapeBase.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c TransformingShapeBase.cpp $(Release_Include_Path) -o TransformingShapeBase.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM TransformingShapeBase.cpp $(Release_Include_Path) > TransformingShapeBase.d

# Compiles file TranslateTransformation.cpp for the Release configuration...
-include TranslateTransformation.d
TranslateTransformation.o: TranslateTransformation.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c TranslateTransformation.cpp $(Release_Include_Path) -o TranslateTransformation.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM TranslateTransformation.cpp $(Release_Include_Path) > TranslateTransformation.d

# Compiles file TranslateTransformation3D.cpp for the Release configuration...
-include TranslateTransformation3D.d
TranslateTransformation3D.o: TranslateTransformation3D.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c TranslateTransformation3D.cpp $(Release_Include_Path) -o TranslateTransformation3D.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM TranslateTransformation3D.cpp $(Release_Include_Path) > TranslateTransformation3D.d

# Compiles file TriangleShape.cpp for the Release configuration...
-include TriangleShape.d
TriangleShape.o: TriangleShape.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c TriangleShape.cpp $(Release_Include_Path) -o TriangleShape.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM TriangleShape.cpp $(Release_Include_Path) > TriangleShape.d

# Compiles file TurtleMesh.cpp for the Release configuration...
-include TurtleMesh.d
TurtleMesh.o: TurtleMesh.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c TurtleMesh.cpp $(Release_Include_Path) -o TurtleMesh.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM TurtleMesh.cpp $(Release_Include_Path) > TurtleMesh.d

# Compiles file TurtleMeshState.cpp for the Release configuration...
-include TurtleMeshState.d
TurtleMeshState.o: TurtleMeshState.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c TurtleMeshState.cpp $(Release_Include_Path) -o TurtleMeshState.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM TurtleMeshState.cpp $(Release_Include_Path) > TurtleMeshState.d

# Compiles file TurtlePath.cpp for the Release configuration...
-include TurtlePath.d
TurtlePath.o: TurtlePath.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c TurtlePath.cpp $(Release_Include_Path) -o TurtlePath.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM TurtlePath.cpp $(Release_Include_Path) > TurtlePath.d

# Compiles file TurtleState.cpp for the Release configuration...
-include TurtleState.d
TurtleState.o: TurtleState.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c TurtleState.cpp $(Release_Include_Path) -o TurtleState.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM TurtleState.cpp $(Release_Include_Path) > TurtleState.d

# Compiles file vector.cc for the Release configuration...
-include vector.d
vector.o: vector.cc
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c vector.cc $(Release_Include_Path) -o vector.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM vector.cc $(Release_Include_Path) > vector.d

# Compiles file Vector2.cpp for the Release configuration...
-include Vector2.d
Vector2.o: Vector2.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Vector2.cpp $(Release_Include_Path) -o Vector2.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Vector2.cpp $(Release_Include_Path) > Vector2.d

# Compiles file Vector3.cpp for the Release configuration...
-include Vector3.d
Vector3.o: Vector3.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Vector3.cpp $(Release_Include_Path) -o Vector3.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Vector3.cpp $(Release_Include_Path) > Vector3.d

# Compiles file Vector4.cpp for the Release configuration...
-include Vector4.d
Vector4.o: Vector4.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Vector4.cpp $(Release_Include_Path) -o Vector4.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Vector4.cpp $(Release_Include_Path) > Vector4.d

# Compiles file VectorInstructionStreamBase.cpp for the Release configuration...
-include VectorInstructionStreamBase.d
VectorInstructionStreamBase.o: VectorInstructionStreamBase.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c VectorInstructionStreamBase.cpp $(Release_Include_Path) -o VectorInstructionStreamBase.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM VectorInstructionStreamBase.cpp $(Release_Include_Path) > VectorInstructionStreamBase.d

# Compiles file VectorLinePath.cpp for the Release configuration...
-include VectorLinePath.d
VectorLinePath.o: VectorLinePath.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c VectorLinePath.cpp $(Release_Include_Path) -o VectorLinePath.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM VectorLinePath.cpp $(Release_Include_Path) > VectorLinePath.d

# Compiles file VectorPathBase.cpp for the Release configuration...
-include VectorPathBase.d
VectorPathBase.o: VectorPathBase.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c VectorPathBase.cpp $(Release_Include_Path) -o VectorPathBase.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM VectorPathBase.cpp $(Release_Include_Path) > VectorPathBase.d

# Compiles file VectorRenderContext.cpp for the Release configuration...
-include VectorRenderContext.d
VectorRenderContext.o: VectorRenderContext.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c VectorRenderContext.cpp $(Release_Include_Path) -o VectorRenderContext.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM VectorRenderContext.cpp $(Release_Include_Path) > VectorRenderContext.d

# Compiles file Wireframe.cpp for the Release configuration...
-include Wireframe.d
Wireframe.o: Wireframe.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Wireframe.cpp $(Release_Include_Path) -o Wireframe.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Wireframe.cpp $(Release_Include_Path) > Wireframe.d

# Compiles file WriteLineSegmentCommand.cpp for the Release configuration...
-include WriteLineSegmentCommand.d
WriteLineSegmentCommand.o: WriteLineSegmentCommand.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c WriteLineSegmentCommand.cpp $(Release_Include_Path) -o WriteLineSegmentCommand.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM WriteLineSegmentCommand.cpp $(Release_Include_Path) > WriteLineSegmentCommand.d

# Compiles file ZBuffer.cpp for the Release configuration...
-include ZBuffer.d
ZBuffer.o: ZBuffer.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ZBuffer.cpp $(Release_Include_Path) -o ZBuffer.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ZBuffer.cpp $(Release_Include_Path) > ZBuffer.d

# Compiles file ZBufferingHandlerBase.cpp for the Release configuration...
-include ZBufferingHandlerBase.d
ZBufferingHandlerBase.o: ZBufferingHandlerBase.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c ZBufferingHandlerBase.cpp $(Release_Include_Path) -o ZBufferingHandlerBase.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM ZBufferingHandlerBase.cpp $(Release_Include_Path) > ZBufferingHandlerBase.d

# Creates the intermediate and output folders for each configuration...
.PHONY: create_folders
create_folders:
	mkdir -p gccDebug
	

# Cleans intermediate and output files (objects, libraries, executables)...
.PHONY: clean
clean:
	rm -f gccDebug/*.o
	rm -f gccDebug/*.d
	rm -f gccDebug/*.a
	rm -f gccDebug/*.so
	rm -f gccDebug/*.dll
	rm -f gccDebug/*.exe
	rm -f *.o
	rm -f *.d
	rm -f *.a
	rm -f *.so
	rm -f *.dll
	rm -f *.exe

