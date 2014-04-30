#ifndef _GAME_H
#define _GAME_H

#include "GameConstants.h"
#include "Sprite.h"
#include "Keyboard.h"
#include "Surface.h"
#include "Timer.h"

class Game{

private:

	Sprite* slimey;
	RECT sourceRect;

	D3DXVECTOR2 position;

	Timer* timer;

public:

	Game();
	~Game();

	bool Initialise();

	void Tick();
	void Render();


};
#endif