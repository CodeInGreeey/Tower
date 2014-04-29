#ifndef _SPRITE_H
#define _SPRITE_H

#include "GameConstants.h"
#include "D3DDeviceManager.h"

class Sprite{

private:

	LPD3DXSPRITE m_pD3DSprite; //Long pointer to a sprite
	LPDIRECT3DTEXTURE9 m_pD3DTexture; //Long pointer to a texture

	D3DDeviceManager* m_pDM; //Pointer to D3D device manager	
	D3DXIMAGE_INFO m_ImageInfo;
	

public:

	Sprite();
	~Sprite();

	bool Initialise();
	bool InitSprite(LPCSTR path);

	int GetTextureWidth();
	int GetTextureHeight();

	void SetTexture(LPCSTR path);
	void Release();

	void DrawSprite();
	void DrawSprite(float x, float y);
	void DrawSprite(float x, float y, RECT sourceRect);

};
#endif