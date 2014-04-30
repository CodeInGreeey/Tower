#ifndef _SCREEN_H
#define _SCREEN_H

#include "Surface.h"

/*
	======================================================================================
	The Screen class is a base class that will be used to for all screens within the game.
	======================================================================================
*/
class Screen{

protected:

	//A pointer to a surface (the screen).
	Surface						*m_pSurface;

public:

	//Default constructor.
	Screen(LPCSTR path);

	//Default destructor.
	~Screen();

	//Used to initialise the screen.
	virtual void			     Initialise(LPCSTR path);

	//Used to update the screen.
	virtual void				 Tick() = 0;

	//Used to render the screen.
	virtual void				 Render() = 0;


};
#endif