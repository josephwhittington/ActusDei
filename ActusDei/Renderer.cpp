#include "Renderer.h"

bool Renderer::Initialize(ADSystem::Window* window)
{
	// Initialize Phong Renderer
	if (!InitializePhongRenderer(window)) return false;

	return true;
}

bool Renderer::Frame()
{
	// Rendering Code
	ID3D11RenderTargetView* tempRTV[] = { VIEW_RESOURCES.render_target_view };
	PHONG.context->OMSetRenderTargets(1, tempRTV, nullptr);

	float color[4] = { 1, 0, 0, 1 };
	PHONG.context->ClearRenderTargetView(VIEW_RESOURCES.render_target_view, color);

	PHONG.context->RSSetViewports(1, &VIEW_RESOURCES.viewport);

	PHONG.chain->Present(0, 0);
	// Rendering Code

	return true;
}

bool Renderer::InitializePhongRenderer(ADSystem::Window* window)
{
	HWND window_handle = window->GetWindowHandle();
	RECT rect;
	GetClientRect(window_handle, &rect);

	// Attach d3d to the window
	D3D_FEATURE_LEVEL DX11 = D3D_FEATURE_LEVEL_11_0;
	DXGI_SWAP_CHAIN_DESC swap;
	ZeroMemory(&swap, sizeof(DXGI_SWAP_CHAIN_DESC));
	swap.BufferCount = 1;
	swap.OutputWindow = window_handle;
	swap.Windowed = true;
	swap.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swap.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swap.BufferDesc.Width = rect.right - rect.left;
	swap.BufferDesc.Height = rect.bottom - rect.top;
	swap.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swap.SampleDesc.Count = 1;
	float aspect_ratio = swap.BufferDesc.Width / (float)swap.BufferDesc.Height;

	HRESULT result = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, NULL, D3D11_CREATE_DEVICE_DEBUG, &DX11, 1, D3D11_SDK_VERSION, &swap, &PHONG.chain, &PHONG.device, 0, &PHONG.context);
	assert(!FAILED(result));
	if (FAILED(result)) return false;

	ID3D11Resource* backbuffer;
	result = PHONG.chain->GetBuffer(0, __uuidof(backbuffer), (void**)&backbuffer);
	result = PHONG.device->CreateRenderTargetView(backbuffer, NULL, &VIEW_RESOURCES.render_target_view);
	assert(!FAILED(result));
	backbuffer->Release();

	VIEW_RESOURCES.viewport.Width = swap.BufferDesc.Width;
	VIEW_RESOURCES.viewport.Height = swap.BufferDesc.Height;
	VIEW_RESOURCES.viewport.TopLeftY = VIEW_RESOURCES.viewport.TopLeftX = 0;
	VIEW_RESOURCES.viewport.MinDepth = 0;
	VIEW_RESOURCES.viewport.MaxDepth = 1;

	return true;
}