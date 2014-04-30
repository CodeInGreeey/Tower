#include "Button.h"

/*
	Constructor. 
*/
Button::Button(D3DXVECTOR2 pos, LPCSTR path){

	Initialise(pos, path);

}

/*
	Destructor.
*/
Button::~Button(){

	m_pButtonSprite->Release();

}

/*
	Initialise the button.
*/
void Button::Initialise(D3DXVECTOR2 pos, LPCSTR path){

	m_pButtonSprite = new Sprite();
	m_pButtonSprite->InitSprite(path);

	m_dButtonPos = pos;

	SetRect(&m_pButtonHitBox, pos.x, pos.y, pos.x + m_pButtonSprite->GetTextureWidth(), pos.y + m_pButtonSprite->GetTextureHeight());

}

/*
	Returns true if the button has been clicked.
*/
bool Button::IsClicked(D3DXVECTOR2 mousePos){

	if(mousePos.x > m_pButtonHitBox.left && mousePos.x < m_pButtonHitBox.right 
		&& mousePos.y > m_pButtonHitBox.top && mousePos.y < m_pButtonHitBox.bottom) return true;

	return false;

}

/*
	Updates the button.
*/
void Button::Tick(){



}

/*
	Renders the button.
*/
void Button::Render(){

	m_pButtonSprite->DrawSprite(m_dButtonPos.x, m_dButtonPos.y);

}