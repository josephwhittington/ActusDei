#pragma once

#include <Windows.h>
#include <d3d11.h>

namespace ADSystem
{
	struct RendererResources
	{
		ID3D11Device* device;
		ID3D11DeviceContext* context;
		IDXGISwapChain* chain;
	};

	struct ViewResources
	{
		ID3D11RenderTargetView* render_target_view;
		D3D11_VIEWPORT viewport;
	};
}