#include "InputHandler.h"

InputHandler* InputHandler::instance = NULL;

InputHandler::InputHandler(){

	Initialise();

}

InputHandler::~InputHandler(){



}

InputHandler* InputHandler::GetInstance(){

	if(instance == NULL)
		instance = new InputHandler();

	return instance;

}

void InputHandler::Initialise(){

	for(int i = 0; i < 6; i++)
		keys[i] = false;

}

bool InputHandler::GetKeyPressed(int keyPressed){

	if(keyPressed == Up)
		return keys[Up];

	if(keyPressed == Down)
		return keys[Down];

	if(keyPressed == Left)
		return keys[Left];

	if(keyPressed == Right)
		return keys[Right];

	if(keyPressed == Enter)
		return keys[Enter];

	return false;

}

void InputHandler::DownPressed(){

	keys[Down] = true;
	keys[Up]= false;

}

void InputHandler::UpPressed(){

	keys[Up] = true;
	keys[Down] = false;

}

void InputHandler::RightPressed(){

	keys[Right] = true;
	keys[Left] = false;

}

void InputHandler::LeftPressed(){

	keys[Left] = true;
	keys[Right] = false;

}

void InputHandler::BPressed(){

	keys[Enter] = true;

}

void InputHandler::BReleased(){

	keys[Enter] = false;

}

void InputHandler::UpReleased(){

	keys[Up] = false;

}

void InputHandler::DownReleased(){

	keys[Down] = false;

}

void InputHandler::RightReleased(){

	keys[Right] = false;

}

void InputHandler::LeftReleased(){

	keys[Left] = false;

}

