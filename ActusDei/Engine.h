#pragma once

#include "System.h"
#include "Renderer.h"

class Engine
{
public:
	Engine() = default;
	~Engine() = default;

	bool Initialize(HINSTANCE _hinstance, int _cmdshow, int _window_width = 1080, int _window_height = 768);
	bool Run();
	bool Shutdown();

private:
	bool InitializeRenderers();

private:
	ADSystem::Window* m_Window;
	Renderer* m_Renderer;
};