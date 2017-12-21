#pragma once

#include "ZBufferingHandlerBase.h"

class ZBufferedWireframeHandler : public ZBufferingHandlerBase
{
public:
	bool ShouldFillMesh(const ini::Section& Figure)
	{
		return false;
	}
};