#include "D3DDeviceManager.h"


D3DDeviceManager* D3DDeviceManager::instance = NULL;

/*
	Default constructor
*/
D3DDeviceManager::D3DDeviceManager(){





}

/*
	Destructor
*/
D3DDeviceManager::~D3DDeviceManager(){





}

/*
	Get the D3DDeviceManager instance
*/
D3DDeviceManager* D3DDeviceManager::GetInstance(){

	if(instance == NULL)
		instance = new D3DDeviceManager();

	return instance;

}

/*
	Return the device
*/
LPDIRECT3DDEVICE9 D3DDeviceManager::GetDevice(){

	return m_pD3DDevice;

}

/*
	Initialise the D3D device
*/	
bool D3DDeviceManager::InitD3D(HWND hwnd){

	//Initialise d3d pointer
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	//Ensure d3d pointer has been initialised correctly
	if(m_pD3D==NULL){

		MessageBox(NULL, "Failed to create D3D pointer.", NULL, NULL);
		return false;

	}

	//Create the present parameters
	D3DPRESENT_PARAMETERS pp;

	//Evacuate the present parameters
	ZeroMemory(&pp, sizeof(pp));

	//Initialise present parameters
	pp.BackBufferCount=1;
	pp.BackBufferFormat=D3DFMT_UNKNOWN;
	pp.BackBufferHeight=HEIGHT;
	pp.BackBufferWidth=WIDTH;
	pp.PresentationInterval=D3DPRESENT_INTERVAL_ONE;
	pp.hDeviceWindow=hwnd;
	pp.SwapEffect=D3DSWAPEFFECT_DISCARD;
	pp.Windowed=TRUE;

	//Create device and check that it does not fail
	if(FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &m_pD3DDevice))){

		MessageBox(NULL, "D3D device creation failed.", NULL, NULL);
		return false;

	}

	if(FAILED(m_pD3DDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &m_pBackBuffer))){

		MessageBox(NULL, "Could not get back buffer!", NULL, NULL);
		return false;

	}

	return true;

}

/*
	Return the back buffer.
*/
LPDIRECT3DSURFACE9 D3DDeviceManager::GetBackBuffer(){

	return m_pBackBuffer;

}

/*
	Release back buffer.
*/
void D3DDeviceManager::ReleaseBackBuffer(){

	if(m_pBackBuffer!=NULL)
		m_pBackBuffer->Release();

}

/*
	Begin the draw.
*/
void D3DDeviceManager::BeginDraw(){

	//Clear the screen and begin the scene
	m_pD3DDevice->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, NULL);
	m_pD3DDevice->BeginScene();

}

//End the draw
void D3DDeviceManager::EndDraw(){

	//End the scene and present
	m_pD3DDevice->EndScene();
	m_pD3DDevice->Present(NULL, NULL, NULL, NULL);


}