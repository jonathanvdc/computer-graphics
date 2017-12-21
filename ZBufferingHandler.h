#pragma once

#include "ZBufferingHandlerBase.h"

class ZBufferingHandler : public ZBufferingHandlerBase
{
public:
	bool ShouldFillMesh(const ini::Section& Figure)
	{
		return true;
	}
};