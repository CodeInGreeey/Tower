#ifndef _SURFACE_H
#define _SURFACE_H

#include "GameConstants.h"
#include "D3DDeviceManager.h"

class Surface{


private:

	LPDIRECT3DSURFACE9 surface;
	D3DDeviceManager* m_pDM; //Pointer to D3D device manager	

public:

	Surface();
	~Surface();

	bool Initialise();
	bool InitSurface(LPCSTR path);

	void DrawSurface();
	void Release();

};
#endif