#pragma once
#include "dxpch.h"
namespace DX {
	class DX_API Layer {
	public:
		virtual void OnAttach() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnRender() = 0;
	};
}