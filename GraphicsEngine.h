#pragma once
#include <d3d11.h>

class SwapChain;
class DeviceContext;



class GraphicsEngine
{
public:
	GraphicsEngine();

	~GraphicsEngine();

	bool init();

	bool release();

	static GraphicsEngine* get();

	SwapChain* createSwapChain();

	DeviceContext* getImmediateDeviceContext();

private:
	ID3D11Device* m_d3d_device;

	D3D_FEATURE_LEVEL m_feature_level;

	// ID3D11DeviceContext* m_imm_context;

	DeviceContext* m_imm_device_context;

	IDXGIDevice* m_dxgi_device;

	IDXGIAdapter* m_dxgi_adapter;

	IDXGIFactory* m_dxgi_factory;

	friend class SwapChain;


};

