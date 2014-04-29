#ifndef _GAME_H
#define _GAME_H

#include "GameConstants.h"
#include "Sprite.h"
#include "Keyboard.h"
#include "Surface.h"

class Game{

private:

	Sprite* slimey;
	RECT sourceRect;

public:

	Game();
	~Game();

	bool Initialise();

	void Tick();
	void Render();


};
#endif