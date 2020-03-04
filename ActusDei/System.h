#pragma once
#include <windows.h>

namespace ADSystem
{
	class Window 
	{
	public:
		explicit Window(int _window_width, int _window_height);

		bool InitializeWindows()
		{

		}

	private:
		HWND m_hwnd;
		HINSTANCE m_hinstance;
		int m_screen_height, m_screen_width;
		int m_window_height, m_window_width;
	};
}