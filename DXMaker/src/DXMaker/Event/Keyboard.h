#pragma once
#include "dxpch.h"

namespace DX {
	class DX_API Keyboard {
	public:
		static void OnKeyPressed(int key);
		static void OnKeyReleased(int key);
		static bool GetKey(int key);
		static bool GetKeyUp(int key);
	private:
		static std::queue<int> events;
		static std::queue<int> eventsup;
	};
}