#include <DXMaker.h>
#include "Sandbox2D.h"

class SandboxApp : public DX::Application {
public:
	SandboxApp() {
		DX::PushLayer(new Sandbox2D());
	}
	virtual ~SandboxApp() {

	}
};

DX::Application* DX::CreateApplication() {
	return new SandboxApp();
}