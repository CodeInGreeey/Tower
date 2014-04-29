#include "Sprite.h"

/*
	Default constructor.
*/
Sprite::Sprite(){

	Initialise();

}

/*
	Default destructor.
*/
Sprite::~Sprite(){



}

/*
	Class initialisation method.
*/
bool Sprite::Initialise(){

	m_pD3DSprite = NULL;
	m_pD3DTexture = NULL;
	m_pDM = NULL;

	return true;

}

/*
	Release the memory.
*/
void Sprite::Release(){

	m_pD3DSprite->Release();
	m_pD3DTexture->Release();

}

/*
	Initialise the sprite.
*/
bool Sprite::InitSprite(LPCSTR path){

	//Get the device manager instance.
	m_pDM = D3DDeviceManager::GetInstance();

	//Create the sprite, and check if it failed.
	if(FAILED(D3DXCreateSprite(m_pDM->GetDevice(), &m_pD3DSprite))){

		MessageBox(NULL, "Sprite creation failed.", NULL, NULL);
		return false;

	}	

	//Create the texture, and check if it has failed.
	if(FAILED(D3DXCreateTextureFromFileEx(m_pDM->GetDevice(), path, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 
								0, 0, 
								D3DFMT_A8R8G8B8, 
								D3DPOOL_DEFAULT,
								D3DX_DEFAULT,
								D3DX_DEFAULT,
								D3DCOLOR_XRGB(255, 0, 255),
								NULL,
								NULL,
								&m_pD3DTexture))){

		MessageBox(NULL, "Could not get texture from file.", NULL, NULL);
		return false;

	}

	if(FAILED(D3DXGetImageInfoFromFile(path, &m_ImageInfo))){

		MessageBox(NULL, "Could not get image info.", NULL, NULL);

	}

	return true;

}

void Sprite::SetTexture(LPCSTR path){

//Create the texture, and check if it has failed.
	if(FAILED(D3DXCreateTextureFromFile(m_pDM->GetDevice(), path, &m_pD3DTexture))){

		MessageBox(NULL, "Could not get texture from file.", NULL, NULL);

	}

}

int Sprite::GetTextureHeight(){

	return m_ImageInfo.Height;

}

int Sprite::GetTextureWidth(){

	return m_ImageInfo.Width;

}

/*
	Default draw sprite method.
*/
void Sprite::DrawSprite(){

	m_pD3DSprite->Begin(D3DXSPRITE_ALPHABLEND);
	m_pD3DSprite->Draw(m_pD3DTexture, NULL, NULL, &(D3DXVECTOR3(0,0,0)), 0xFFFFFFFF);
	m_pD3DSprite->End();

}

/*
	Draw sprite method with x & y position.
*/
void Sprite::DrawSprite(float x, float y){

	m_pD3DSprite->Begin(D3DXSPRITE_ALPHABLEND);
	m_pD3DSprite->Draw(m_pD3DTexture, NULL, NULL, &(D3DXVECTOR3(x,y,0)), 0xFFFFFFFF);
	m_pD3DSprite->End();

}

/*
	Draw sprite method with x & y position, and source rectangle (for use with spritesheet).
*/
void Sprite::DrawSprite(float x, float y, RECT sourceRect){

	m_pD3DSprite->Begin(D3DXSPRITE_ALPHABLEND);
	m_pD3DSprite->Draw(m_pD3DTexture, &sourceRect, NULL, &(D3DXVECTOR3(x,y,0)), 0xFFFFFFFF);
	m_pD3DSprite->End();

}