#include "ScreenMenu.h"

/*
	Constructor. Receives the image path and passes it through to the base class Initialise method.
*/
ScreenMenu::ScreenMenu(LPCSTR path) : Screen(path){

	Screen::Initialise(path);

}

/*
	Destructor. Calls the base class destructor method.
*/
ScreenMenu::~ScreenMenu(){

	Screen::~Screen();

}

/*
	Updates the screen.
*/
void ScreenMenu::Tick(){




}

/*
	Renders the screen.
*/
void ScreenMenu::Render(){

	Screen::Render();

}