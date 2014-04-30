#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H

#include "GameConstants.h"
#include "Screen.h"

/*
	=============================================
	An enum to store identifiers for the screens.
	=============================================
*/
enum Screens{

	Menu = 0,

};

/*
	=======================================================================================
	The ScreenManager class will handle the updating and drawing of all screens in the game.
	=======================================================================================
*/
class ScreenManager{

private:

	static	ScreenManager			*m_pInstance;												//An instance of this class. Used to form a singleton class.

	vector<Screen*>					 m_pvScreens;												//A vector list of screens.
	vector<Screen*>::iterator		 m_pvScreensIter;											//An iterator for the vector list of screens.

	Screens							 m_iCurrentScreen;											//An integer to represent the index of the current screen within the vector list.
	

public:


	ScreenManager();																			//Default constructor.
	~ScreenManager();																			//Default destructor.						

	void							 Initialise();												//Initialise the screen manager.
	
	static ScreenManager*			 GetInstance();											    //A method used to return the instance of this class.

	
	void							 AddScreen(Screen* newScreen);								//Used to add a screen to the screens list.
	void							 ChangeScreen(Screens screenIdentifier);					//Changes the screen
	void							 Tick();													//Will be used to update all of the screens.	
	void							 Render();													//Will be used to render all of the screens.

	Screens							 GetCurrentScreen();										//Returns the identifier of the current screen.
		

};
#endif