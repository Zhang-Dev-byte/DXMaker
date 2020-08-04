#pragma once
#include "dxpch.h"
namespace DX {
	enum DX_API RendererAPI {
		None = 0,
		Directx = 1
	};
	extern RendererAPI api = RendererAPI::Directx;
}