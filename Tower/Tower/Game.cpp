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

	slimey = new Sprite();
	slimey->InitSprite("Images\\Entities\\slimey.png");

	return true;

}

/*
	Do all of your update code in here.
*/
void Game::Tick(){

	
}

/*
	Do all of your sprite rendering in here.
*/
void Game::Render(){

	
}

