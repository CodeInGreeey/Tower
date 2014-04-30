#include "Surface.h"

Surface::Surface(){

	Initialise();

}

Surface::~Surface(){



}

void Surface::Release(){

	surface->Release();

}

bool Surface::Initialise(){

	m_pDM = D3DDeviceManager::GetInstance();

	return true;

}

bool Surface::InitSurface(LPCSTR path){

	if(FAILED(m_pDM->GetDevice()->CreateOffscreenPlainSurface(WIDTH, HEIGHT,  D3DFMT_X8R8G8B8, D3DPOOL_SYSTEMMEM, &surface, NULL))){

		MessageBox(NULL, "Could not create surface.", NULL, NULL);
		return false;

	}

	if(FAILED(D3DXLoadSurfaceFromFile(surface,NULL,NULL,path,NULL,D3DX_DEFAULT,0,NULL))){

		MessageBox(NULL, "Could not load surface. Is the file name correct?", NULL, NULL);
		return false;

	}

	return true;

}

void Surface::DrawSurface(){

	if(m_pDM!=NULL){
		m_pDM->GetDevice()->UpdateSurface(surface,NULL, m_pDM->GetBackBuffer(),NULL);
		m_pDM->ReleaseBackBuffer();
	}

}