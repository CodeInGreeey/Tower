#ifndef _Entity_H
#define _Entity_H

#include "Sprite.h"

/*
	This enum will be used to store the game object's ID so we can check what type it is.
*/
enum EntityID{

	EntPlayer,

};

class Entity{

protected:

	//The ID of the game object.
	EntityID			m_ObjID;

	//A sprite object to load, display and animate the Game Object's sprite.
	Sprite*					m_pObjSprite;

	//The position and size values of the game object.
	float					m_iPosX, 
							m_iPosY,
							m_iSizeX, 
							m_iSizeY;

	//The bounding and source rectangles for the game object.
	RECT					m_rHitBox, m_rSource;

	//Private methods.
	virtual void SetID(EntityID id);
	virtual void Initialise(D3DXVECTOR2 pos, LPCSTR path, RECT sourceRect);

public:

	Entity(EntityID id, D3DXVECTOR2 pos, LPCSTR path, RECT sourceRect);
	~Entity();

	virtual void Tick() = 0;
	virtual void Render() = 0;

	virtual float GetX();
	virtual float GetY();
	virtual float GetSizeX();
	virtual float GetSizeY();

	virtual void SetBoundingRect();

	virtual EntityID GetID();
	virtual RECT GetBoundingRect();

};
#endif