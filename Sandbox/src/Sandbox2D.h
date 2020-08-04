#pragma once
#include <DXMaker.h>

class Sandbox2D : public DX::Layer {
public:
	virtual void OnAttach() override 
	{
		DX::Debug::Log("Layer Test!");
	}
	virtual void OnUpdate() override 
	{
	}
	virtual void OnRender() override 
	{
	}
};