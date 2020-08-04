#include "dxpch.h"
#include "Keyboard.h"

std::queue<int> DX::Keyboard::events = std::queue<int>();
std::queue<int> DX::Keyboard::eventsup = std::queue<int>();
void DX::Keyboard::OnKeyPressed(int key)
{
	events.push(key);
}

void DX::Keyboard::OnKeyReleased(int key)
{
	eventsup.push(key);
}

bool DX::Keyboard::GetKey(int key)
{
	if (!events.empty()) {
		if (events.front() == key) {
			events.pop();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool DX::Keyboard::GetKeyUp(int key)
{
	if (!eventsup.empty()) {
		if (eventsup.front() == key) {
			eventsup.pop();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
