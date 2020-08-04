#pragma once
#include "dxpch.h"
#include "Application.h"
#include "Log.h"
namespace DX {
	extern Application* CreateApplication();
}

int main(int, char**) {
	DX::Log::Init();
	auto app = DX::CreateApplication();
	delete app;
	while (true);
}