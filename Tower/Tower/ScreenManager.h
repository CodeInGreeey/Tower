#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H

#include "GameConstants.h"

/*
	=======================================================================================
	The ScreenManager class will handle the updating and drawing of all screens in the game.
	=======================================================================================
*/
class ScreenManager{

private:

	//An instance of this class. Used to form a singleton class.
	static	ScreenManager			*m_pInstance;  
	

public:

	//Default constructor.
	ScreenManager();	

	//Default destructor.
	~ScreenManager();								

	 //A method used to return the instance of this class.
	static ScreenManager			*GetInstance();
	
	//Will be used to update all of the screens.
	void							Tick();		   

	//Will be used to render all of the screens.
	void							Render();	   
		

};
#endif