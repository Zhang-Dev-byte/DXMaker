#pragma once
#include "dxpch.h"
#include "Window.h"
namespace DX {
	class DX_API Application {
	public:
		Application();
		virtual ~Application();
		static Window& GetWindow();
		static void SetWindow(Window& w);
	private:
		static std::unique_ptr<Window> window;
	};
}