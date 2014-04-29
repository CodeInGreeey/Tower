#include "Keyboard.h"

Keyboard::Keyboard(){

	Initialise();

}

Keyboard::~Keyboard(){



}

void Keyboard::Initialise(){

	m_pIH = InputHandler::GetInstance();

}

bool Keyboard::GetKeyPressed(int keyPressed){

	return m_pIH->GetKeyPressed(keyPressed);

}