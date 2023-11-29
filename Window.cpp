
#include "Window.h"
#include <iostream>


Window* window = nullptr;


Window::Window()
{
}

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CREATE:
		window->onCreate();
		break;
		
	case WM_DESTROY:
		window->onDestroy();
		::PostQuitMessage(0);
		break;

	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return NULL;

}

Window::~Window()
{
}

bool Window::init()
{
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	// wc.cbsi\ze = sizeof(WNDCLASSEX)
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = L"MyWindowClass";
	wc.lpszMenuName = L"";
	wc.style = NULL;
	wc.lpfnWndProc = &WndProc;

	if (!window) window = this;


	if (!::RegisterClassEx(&wc)) return false;

	// creation of the window
	m_hwnd = ::CreateWindowExW(WS_EX_OVERLAPPEDWINDOW, L"MyWindowClass", L"DirectX Application", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, NULL);

	if (!m_hwnd) return false;

	// show up the window
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);

	
	// set this flag to indicate window running
	m_is_run = true;
	return true;
}

bool Window::release()
{
	if (!::DestroyWindow(m_hwnd)) return false;
	return true;
}

bool Window::broadcast()
{
	MSG msg;

	while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	window->onUpdate();

	Sleep(0);

	return true;
}

bool Window::isRun()
{

	return m_is_run;
}

void Window::onDestroy()
{
	m_is_run = false;
}