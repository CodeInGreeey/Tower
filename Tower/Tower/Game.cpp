#include "Game.h"

/*
	Default constructor.
*/
Game::Game(){

	

}

/*
	Destructor.
*/
Game::~Game(){


	
}

/*
	Initialise method. Initialise all of your sprites in here and it will make life easier.
*/
bool Game::Initialise(){

	m_pScreenManager = ScreenManager::GetInstance();
	m_pScreenManager->AddScreen(new ScreenMenu("Images\\GUI\\UI\\Screens\\menuScreen.png"));

	return true;

}

/*
	Do all of your update code in here.
*/
void Game::Tick(){

	m_pScreenManager->Tick();
	
}

/*
	Do all of your sprite rendering in here.
*/
void Game::Render(){

	m_pScreenManager->Render();
	
}

