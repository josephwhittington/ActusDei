#include "System.h"

ADSystem::Window::Window(HINSTANCE _hinstance, int _cmdshow, int _window_width, int _window_height)
{
	m_hinstance = _hinstance;
	m_cmdShow = _cmdshow;
	m_window_width = _window_width;
	m_window_height = _window_height;
}

bool ADSystem::Window::InitializeWindows()
{
	// Register class
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hinstance;
	wcex.hIcon = LoadIcon(m_hinstance, IDI_WINLOGO);
	wcex.hCursor = LoadCursor(m_hinstance, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = m_window_title;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_WINLOGO);

	RegisterClassExW(&wcex);
	// Register class

	// Determine the resolution of the clients desktop screen.
	int m_screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int m_screenHeight = GetSystemMetrics(SM_CYSCREEN);

	m_hwnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		m_window_title,
		m_window_title,
		WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
		(m_screenWidth - m_window_width) / 2,
		(m_screenHeight - m_window_height) / 2,
		m_window_width,
		m_window_height,
		nullptr,
		nullptr,
		m_hinstance,
		nullptr
	);

	ShowWindow(m_hwnd, m_cmdShow);
	UpdateWindow(m_hwnd);
	// iNITIALIZE WINDOW

	// TODO: Add error checking here and log if failed

	return true;
}

bool ADSystem::Window::ShutDownWindows()
{
	return true;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	unsigned int thing;
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case WM_QUIT:
		{
			DestroyWindow(hWnd);
			break;
		}
		default:
			return DefWindowProcW(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, message, wParam, lParam);
	}
	return 0;
}