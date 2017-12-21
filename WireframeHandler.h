#pragma once

#include "MeshHandlerBase.h"

class WireframeHandler : public MeshHandlerBase
{
public:
	bool ShouldFillMesh(const ini::Section& Figure) override
	{
		return false;
	}
	bool UseZBuffer() override
	{
		return false;
	}
};