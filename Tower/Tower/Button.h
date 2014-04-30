#ifndef _BUTTON_H
#define _BUTTON_H

#include "Sprite.h"

/*
	========================================
	A base class for all buttons in the game.
	========================================
*/
class Button{

protected:

	Sprite*							m_pButtonSprite;								//A sprite for the button.
	RECT							m_pButtonHitBox;								//The hit box for the button.
	D3DXVECTOR2						m_dButtonPos;									//The button position on screen.

public:

	Button(D3DXVECTOR2 pos, LPCSTR path);											//Constructor.
	~Button();																		//Destructor.

	virtual void Initialise(D3DXVECTOR2 pos, LPCSTR path) = 0;						//The initialise method. Initialises the button.
	virtual void Tick() = 0;														//Updates the button.
	virtual void Render() = 0;														//Renders the button.

	virtual bool IsClicked(D3DXVECTOR2 mousePos);									//Checks if the button has been clicked.

};
#endif