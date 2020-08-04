#include "dxpch.h"
#include "Context.h"
#include "Log.h"

DX::Context::Context(Window* w)
{
	switch (DX::api) {
	case DX::RendererAPI::Directx:
		dxc = DirectxContext(w);
		break;
	case DX::RendererAPI::None:
		DX_CORE_CRITICAL("RendererAPI::None is not supported!");
		break;
	}
}

void DX::Context::SwapBuffers()
{
	switch (DX::api) {
	case DX::RendererAPI::Directx:
		dxc.SwapBuffers();
		break;
	case DX::RendererAPI::None:
		DX_CORE_CRITICAL("RendererAPI::None is not supported!");
		break;
	}
}

void DX::Context::ClearColor(float r, float g, float b, float a)
{
	switch (DX::api) {
	case DX::RendererAPI::Directx:
		dxc.ClearColor(r, g, b, a);
		break;
	case DX::RendererAPI::None:
		DX_CORE_CRITICAL("RendererAPI::None is not supported!");
		break;
	}
}
