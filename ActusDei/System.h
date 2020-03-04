#pragma once
#include <windows.h>

#include "SystemResources.h"

namespace ADSystem
{
	class Window 
	{
	public:
		explicit Window(HINSTANCE _hinstance, int _cmdshow, int _window_width, int _window_height);

		bool InitializeWindows();
		bool ShutDownWindows();

		// Getters/ Setters
		HWND GetWindowHandle();
		int GetWindowWidth();
		int GetWindowHeight();

	private:
		HWND m_hwnd;
		HINSTANCE m_hinstance;
		LPCSTR m_class_title = "Actus Dei";
		LPCWSTR m_window_title = L"Actus Dei";
		int m_cmdShow;
		int m_screen_height, m_screen_width;
		int m_window_height, m_window_width;
	};

	class ResourceManager
	{
	public:
		
	};
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);