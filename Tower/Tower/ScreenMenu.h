#ifndef _SCREENMENU_H
#define _SCREENMENU_H

#include "Screen.h"

/*
	============================================================
	The ScreenMenu class will render and update the menu screen.
	============================================================
*/
class ScreenMenu : public Screen {

private:



public:

	//Default constructor.
	ScreenMenu(LPCSTR path);

	//Default destructor.
	~ScreenMenu();

	//Updates the screen.
	void Tick();

	//Renders the screen.
	void Render();

};
#endif