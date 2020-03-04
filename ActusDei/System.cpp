#include "System.h"


//************************************ 
// Desc:      Window Constructor
// @PARAMS
// HINSTANCE _hinstance -> window instance handle
// int _cmdshow -> Don't actually know what this is TBH, pass it in anyway
// int _window_width -> width of the window
// int _window_height -> height of the window
//************************************
ADSystem::Window::Window(HINSTANCE _hinstance, int _cmdshow, int _window_width, int _window_height)
{
	m_hinstance = _hinstance;
	m_cmdShow = _cmdshow;
	m_window_width = _window_width;
	m_window_height = _window_height;
}

//************************************ 
// Returns:   bool
// Desc:      Initializes Windows, returns false if error occurred
//************************************
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

//************************************ 
// Returns:   bool
// Desc:      Shuts down windows, returns false if error occurred
//************************************
bool ADSystem::Window::ShutDownWindows()
{
	return true;
}

HWND ADSystem::Window::GetWindowHandle()
{
	return m_hwnd;
}

int ADSystem::Window::GetWindowWidth()
{
	return m_window_width;
}

int ADSystem::Window::GetWindowHeight()
{
	return m_window_height;
}

//************************************ 
// Returns:   LRESULT
// Desc:      SHandles Windows messages, super important
//************************************
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
	case WM_SIZE:
	{
		if (true)
		{
			break;
		}
		break;
	}
	default:
		return DefWindowProcW(hWnd, message, wParam, lParam);
	}
	return 0;
}