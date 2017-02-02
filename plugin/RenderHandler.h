//
// RenderHandler.h
//

#pragma once

#include "Renderable.h"
#include "Signal.h"

#include <d3dx9.h>
#include <imgui.h>

#include <memory>
#include <list>

class RenderHooks;

extern IDirect3DDevice9* g_pDevice;

class RenderHandler
{
	friend class RenderHooks;

public:
	RenderHandler();
	~RenderHandler();

	void AddRenderable(Renderable* renderable);
	void RemoveRenderable(Renderable* renderable);

private:

	// Called by RenderHooks
	void CreateDeviceObjects();
	void InvalidateDeviceObjects();

	void PerformRender(Renderable::RenderPhase phase);

	void Render3D();

private:
	bool m_deviceAcquired = false; // implies that g_pDevice is valid to use

	std::list<Renderable*> m_renderables;
};

// utility function to reset the state of the current direct3d9 device
void ResetDeviceState();
