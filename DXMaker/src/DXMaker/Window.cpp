#include "dxpch.h"
#include "Window.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

    switch (message)
    {
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    } break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}
DX::Window::Window(const std::string& title, int width, int height)
{
	this->title = title;
	this->width = width;
	this->height = height;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = L"DXMakerWndClass";

    RegisterClassEx(&wc);

    RECT wr = { 0, 0, this->width, this->height };
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

    hWnd = CreateWindowEx(NULL, L"DXMakerWndClass", std::wstring(this->title.begin(), this->title.end()).c_str(), WS_OVERLAPPEDWINDOW, 300, 300, wr.right - wr.left, wr.bottom - wr.top, NULL, NULL, GetModuleHandle(NULL), NULL);

    ShowWindow(hWnd, SW_SHOW);
}

bool DX::Window::Message()
{
    return PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
}

void DX::Window::ProcessMessage()
{
    TranslateMessage(&msg);

    DispatchMessage(&msg);
}

bool DX::Window::ShouldClose()
{
    return (msg.message == WM_QUIT);
}
