#ifndef _INPUTHANDLER_H
#define _INPUTHANDLER_H

#include "GameConstants.h"

enum Keys{

	Up = 1,
	Down = 2,
	Right = 3,
	Left = 4,
	Enter = 5,
	Space = 6,

};

class InputHandler{

private:

	bool keys[6];

	static InputHandler* instance;

public:

	InputHandler();
	~InputHandler();

	void Initialise();

	bool GetKeyPressed(int keyPressed);

	void UpPressed();
	void DownPressed();
	void RightPressed();
	void LeftPressed();
	void BPressed();

	void UpReleased();
	void DownReleased();
	void RightReleased();
	void LeftReleased();
	void BReleased();

	static InputHandler* GetInstance();

};
#endif