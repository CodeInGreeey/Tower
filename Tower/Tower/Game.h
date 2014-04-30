#ifndef _GAME_H
#define _GAME_H

#include "GameConstants.h"
#include "Sprite.h"
#include "Keyboard.h"
#include "Surface.h"
#include "Timer.h"
#include "ScreenManager.h"
#include "ScreenMenu.h"

class Game{

private:

	ScreenManager* m_pScreenManager;

public:

	Game();
	~Game();

	bool Initialise();

	void Tick();
	void Render();


};
#endif