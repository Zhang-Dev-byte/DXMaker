#pragma once
#include "dxpch.h"
#include "Application.h"
#include "Log.h"
#include "LayerStack.h"
namespace DX {
	extern LayerStack layerStack = LayerStack();
	extern Application* CreateApplication();
	extern void PushLayer(Layer* l) {
		layerStack.PushLayer(l);
	}
	extern void AttachLayers() {
		for (auto l : layerStack) {
			l->OnAttach();
		}
	}
	extern void UpdateLayers() {
		for (auto l : layerStack) {
			l->OnUpdate();
		}
	}
	extern void RenderLayers() {
		for (auto l : layerStack) {
			l->OnRender();
		}
	}
}


int main(int, char**) {
	DX::Log::Init();
	DX::Application::SetWindow(DX::Window("DXMaker", 1280, 720));

	auto app = DX::CreateApplication();
	DX::AttachLayers();

	while (!DX::Application::GetWindow().ShouldClose()) {
		if (DX::Application::GetWindow().Message()) {
			DX::Application::GetWindow().ProcessMessage();

			continue;
		}

		DX::UpdateLayers();
		DX::RenderLayers();
	}
	delete app;
}