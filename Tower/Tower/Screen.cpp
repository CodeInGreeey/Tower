#include "Screen.h"

/*
	Default constructor. Takes the path for the screen image.
*/
Screen::Screen(LPCSTR path){

	Initialise(path);

}

/*
	Destructor.
*/
Screen::~Screen(){

	m_pSurface->Release();

}

/*
	Initialise method. 
*/
void Screen::Initialise(LPCSTR path){

	m_pSurface = new Surface();
	m_pSurface->InitSurface(path);

}

/*
	Updates the screen.
*/
void Screen::Tick(){



}

/*
	Renders the screen.
*/
void Screen::Render(){

	m_pSurface->DrawSurface();

}

