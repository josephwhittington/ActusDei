#include "Engine.h"

bool Engine::Initialize(HINSTANCE _hinstance, int _cmdshow, int _window_width /*= 1080*/, int _window_height /*= 768*/)
{
	m_Window = new ADSystem::Window(_hinstance, _cmdshow, _window_width, _window_height);

	if (!m_Window->InitializeWindows())
		return false;

	if (!InitializeRenderers()) return false;

	return true;
}

bool Engine::Run()
{
	MSG msg;

	// Main message loop:
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT)
			break;

		if (GetAsyncKeyState(VK_ESCAPE)) return false;

		// Rendering
		m_Renderer->Frame();
	}
}

bool Engine::Shutdown()
{
	bool shutdown_state = true;
	// Shut down window utility
	if (m_Window)
	{
		if (!m_Window->ShutDownWindows())
		{
			// TODO: Throw shutdown error and log that shit
			shutdown_state = false;
		}
		delete m_Window;
	}

	// Return this to figure if shutdown was successful
	return shutdown_state;
}

bool Engine::InitializeRenderers()
{
	m_Renderer = new Renderer;
	if(!m_Renderer->Initialize(m_Window)) return false;

	return true;
}