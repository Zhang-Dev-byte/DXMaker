#pragma once
#include "dxpch.h"
#include "Layer.h"
#include <vector>
namespace DX {
	class DX_API LayerStack {
	public:
		void PushLayer(Layer* layer);
		std::vector<Layer*>::const_iterator begin();
		std::vector<Layer*>::const_iterator end();
	private:
		std::vector<Layer*> layers;
	};
}