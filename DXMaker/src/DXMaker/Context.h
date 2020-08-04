#pragma once
#include "dxpch.h"
#include "RendererAPI.h"
#include "Window.h"

#include "Directx/DirectxContext.h"

namespace DX {
	class DX_API Context {
	public:
		Context() = default;
		Context(Window* w);
		void SwapBuffers();
		void ClearColor(float r, float g, float b, float a);
	private:
		DirectxContext dxc;
	};
}