#pragma once

#include <assert.h>

#include "SystemResources.h"
#include "System.h"

class Renderer
{
public:
	Renderer() = default;
	~Renderer() = default;

	bool Initialize(ADSystem::Window* window);

	bool Frame();

private:
	bool InitializePhongRenderer(ADSystem::Window* window);

private:
	ADSystem::ViewResources VIEW_RESOURCES;
	ADSystem::RendererResources PHONG;
};