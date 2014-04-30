#include "ScreenManager.h"

//Sets the instance to null
ScreenManager* ScreenManager::m_pInstance = NULL;		

/*
	Default constructor.
*/
ScreenManager::ScreenManager(){

	Initialise();

}

/*	
	Default destructor.
*/
ScreenManager::~ScreenManager(){
	


}

/*
	Returns the class instance.
*/
ScreenManager* ScreenManager::GetInstance(){

	if(m_pInstance == NULL)
		m_pInstance = new ScreenManager();

	return m_pInstance;

}

/*
	Initialise the class.
*/
void ScreenManager::Initialise(){

	m_iCurrentScreen = Menu;

}

/*
	Adds a new screen at the correct position in the screens list.
*/
void ScreenManager::AddScreen(Screen* newScreen){

	m_pvScreens.push_back(newScreen);

}

/*
	Changes current screen.
*/
void ScreenManager::ChangeScreen(Screens screenIdentifier){

	m_iCurrentScreen = screenIdentifier;

}

/*
	Returns the current screen identifier.
*/
Screens ScreenManager::GetCurrentScreen(){

	return m_iCurrentScreen;

}

/*
	Updates the current screen.
*/
void ScreenManager::Tick(){

	m_pvScreens[m_iCurrentScreen]->Tick();

}

/*
	Draws the current screen.
*/
void ScreenManager::Render(){

	m_pvScreens[m_iCurrentScreen]->Render();

}

