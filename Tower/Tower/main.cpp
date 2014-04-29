#include "GameConstants.h"
#include "D3DDeviceManager.h"
#include "InputHandler.h"
#include "Game.h"


using namespace std;

HWND hwnd; //Window handle

D3DDeviceManager* m_pDM; //A pointer to the device manager
InputHandler* m_pIH; //A pointer to the input handler
Game* game; //A pointer to the game

#pragma region
bool InitD3D();
bool InitGame();
void InitialiseObjects();
void Tick();
void Render();
#pragma endregion Forward Declarations

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){

	switch(msg){

	case WM_DESTROY:
		{

			PostQuitMessage(0);
			return 0;

		}
	case WM_QUIT:
		{

			PostQuitMessage(0);
			return 0;

		}
	case WM_CLOSE:
		{

			PostQuitMessage(0);
			return 0;

		}
	case WM_KEYDOWN:
		{

			if(wParam == 'W')
				m_pIH->UpPressed();

			if(wParam == 'S')
				m_pIH->DownPressed();

			if(wParam == 'A')
				m_pIH->LeftPressed();

			if(wParam == 'D')
				m_pIH->RightPressed();

			if(wParam == 'B')
				m_pIH->BPressed();

			return 0;

		}
	case WM_KEYUP:
		{

			if(wParam == 'W')
				m_pIH->UpReleased();

			if(wParam == 'S')
				m_pIH->DownReleased();

			if(wParam == 'A')
				m_pIH->LeftReleased();

			if(wParam == 'D')
				m_pIH->RightReleased();

			if(wParam == 'B')
				m_pIH->BReleased();

			return 0;

		}



	}

	return DefWindowProc(hwnd, msg, wParam, lParam);

}

bool InitWindow(HINSTANCE hInst, int nCmdShow){

	//Create the window class object
	WNDCLASSEX w;

	//Evacuate the window class
	ZeroMemory(&w, sizeof(w));

	//Initialise all window class information
	w.cbClsExtra=0;
	w.cbSize=sizeof(w);
	w.cbWndExtra=0;
	w.hbrBackground=(HBRUSH)(COLOR_WINDOW+2);
	w.hCursor=LoadCursor(hInst, IDC_ARROW);
	w.hIcon=LoadIcon(hInst, IDI_APPLICATION);
	w.hIconSm=LoadIcon(hInst, IDI_APPLICATION);
	w.hInstance=hInst;
	w.lpfnWndProc=(WNDPROC)WndProc;
	w.lpszClassName="Wrapper";
	w.lpszMenuName=NULL;
	w.style= CS_HREDRAW | CS_VREDRAW;

	//Register the window class
	if(!(RegisterClassEx(&w))){

		MessageBox(NULL, "Class registration failed.", NULL, NULL);
		return false;

	}

	//Create the window class and store it in the window handle
	if(!(hwnd = CreateWindow("Wrapper", "Tower: Alpha - 0.001", WS_OVERLAPPEDWINDOW, 0, 0, WIDTH, HEIGHT, NULL, NULL, hInst, NULL))){

		MessageBox(NULL, "Window creation failed.", NULL, NULL);
		return false;

	}

	//Update & show the window
	UpdateWindow(hwnd);
	ShowWindow(hwnd, nCmdShow);

	return true;

}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR nCmdLine, int nCmdShow){

	if(!(InitWindow(hInst, nCmdShow)))
		return false;

	if(!(InitD3D()))
		return false;

	if(!(InitGame()))
		return false;

	InitialiseObjects();
	
	MSG msg = {0};

	while(msg.message != WM_QUIT){

		if(PeekMessage(&msg, hwnd, 0U, 0U, PM_REMOVE)){

			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}else{

			Tick();
			Render();
		
		}


	}

	return true;

}

/*
	Initialise D3D.
*/
bool InitD3D(){

	m_pDM = D3DDeviceManager::GetInstance();

	if(!(m_pDM->InitD3D(hwnd)))
		return false;

	return true;
}

/*
	Initialise game.
*/
bool InitGame(){

	game = new Game();

	if(!(game->Initialise()))
		return false;

	return true;

}

/*
	Initialises objects.
*/
void InitialiseObjects(){

	m_pIH = InputHandler::GetInstance();

}

/*
	Update method.
*/
void Tick(){

	game->Tick();

}

/*
	Render method.
*/
void Render(){


	m_pDM->BeginDraw();

	game->Render();

	m_pDM->EndDraw();

}


