#include "dxpch.h"
#include "LayerStack.h"

void DX::LayerStack::PushLayer(Layer* layer)
{
	layers.push_back(layer);
}

std::vector<DX::Layer*>::const_iterator DX::LayerStack::begin()
{
	return layers.begin();
}

std::vector<DX::Layer*>::const_iterator DX::LayerStack::end()
{
	return layers.end();
}
