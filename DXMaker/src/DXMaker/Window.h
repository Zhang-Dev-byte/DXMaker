#pragma once
#include "dxpch.h"

namespace DX {
	class DX_API Window {
	public:
		Window(const std::string& title, int width, int height);
		bool Message();
		void ProcessMessage();
		bool ShouldClose();
		HWND& GetHWND();
	private:
		std::string title;
		int width;
		int height;
		HWND hWnd;
		WNDCLASSEX wc;
		MSG msg = { 0 };
	};
}