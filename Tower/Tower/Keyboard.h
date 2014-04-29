#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include "GameConstants.h"
#include "InputHandler.h"

class Keyboard{

private:

	InputHandler* m_pIH;

public:

	Keyboard();
	~Keyboard();

	bool GetKeyPressed(int keyPressed);
	void Initialise();

};
#endif