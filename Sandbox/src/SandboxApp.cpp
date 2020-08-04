#include <DXMaker.h>

class SandboxApp : public DX::Application {
public:
	SandboxApp() {
	}
	virtual ~SandboxApp() {

	}
};

DX::Application* DX::CreateApplication() {
	return new SandboxApp();
}