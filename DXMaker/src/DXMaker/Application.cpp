#include "dxpch.h"
#include "Application.h"

std::unique_ptr<DX::Window> DX::Application::window = nullptr;

DX::Application::Application()
{
}

DX::Application::~Application()
{
}

DX::Window& DX::Application::GetWindow()
{
	return *window;
}

void DX::Application::SetWindow(Window& w)
{
	window = std::make_unique<Window>(w);
}
