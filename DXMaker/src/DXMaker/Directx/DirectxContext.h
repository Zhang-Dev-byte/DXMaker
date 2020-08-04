#pragma once
#include "dxpch.h"
#include "DXMaker/Window.h"
namespace DX {
	class DX_API DirectxContext {
	public:
		DirectxContext() = default;
		DirectxContext(Window* w);
		void SwapBuffers();
		void ClearColor(float r, float g, float b, float a);
	private:
		wrl::ComPtr<ID3D11Device> pDevice;
		wrl::ComPtr<IDXGISwapChain> pSwap;
		wrl::ComPtr<ID3D11DeviceContext> pContext;
		wrl::ComPtr<ID3D11RenderTargetView> pTarget;
		Window* window;
	};
}