#pragma once

#include <assert.h>

#include "SystemResources.h"
#include "System.h"

// Macros
#define D3D11_SAFE_RELEASE(ptr) if((ptr)) (ptr)->Release()

class Renderer
{
public:
	Renderer() = default;
	~Renderer() = default;

	bool Initialize(ADSystem::Window* window);
	bool Shutdown();

	bool Frame();

private:
	bool InitializePhongRenderer(ADSystem::Window* window);
	bool ShutdownPhongRenderer();

private:
	ADSystem::ViewResources VIEW_RESOURCES;
	ADSystem::RendererResources PHONG;
};