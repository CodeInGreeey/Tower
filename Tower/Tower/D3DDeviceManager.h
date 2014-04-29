#ifndef _D3DDEVICEMANAGER_H
#define _D3DDEVICEMANAGER_H

#include "GameConstants.h"

class D3DDeviceManager{

private:

	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3DDevice;

	LPDIRECT3DSURFACE9 m_pBackBuffer;

	static D3DDeviceManager* instance;

public:

	D3DDeviceManager();
	~D3DDeviceManager();

	static D3DDeviceManager* GetInstance();

	LPDIRECT3DDEVICE9 GetDevice();

	LPDIRECT3DSURFACE9 GetBackBuffer();
	void ReleaseBackBuffer();

	void BeginDraw();
	void EndDraw();

	bool InitD3D(HWND hwnd);

};
#endif