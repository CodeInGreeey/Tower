#include "Entity.h"

Entity::Entity(EntityID id, D3DXVECTOR2 pos, LPCSTR path, RECT sourceRect){

	SetID(id);
	Initialise(pos, path, sourceRect);

}

Entity::~Entity(){

	m_pObjSprite->Release();

}

void Entity::SetID(EntityID id){

	m_ObjID = id;

}

EntityID Entity::GetID(){

	return m_ObjID;

}

void Entity::Initialise(D3DXVECTOR2 pos, LPCSTR path, RECT sourceRect){

	m_iPosX = pos.x;
	m_iPosY = pos.y;

	m_pObjSprite = new Sprite();
	m_pObjSprite->InitSprite(path);

	m_iSizeX = m_pObjSprite->GetTextureWidth();
	m_iSizeY = m_pObjSprite->GetTextureHeight();

	m_rSource = sourceRect;

}

void Entity::SetBoundingRect(){

	SetRect(&m_rHitBox, m_iPosX, m_iPosY, (m_iPosX + m_iSizeX), (m_iSizeY + m_iSizeX));

}

RECT Entity::GetBoundingRect(){

	return m_rHitBox;

}

void Entity::Tick(){



}

void Entity::Render(){

	if(m_rSource.bottom != m_rSource.top)
		m_pObjSprite->DrawSprite(m_iPosX, m_iPosY, m_rSource);

	else
		m_pObjSprite->DrawSprite(m_iPosX, m_iPosY);

}


float Entity::GetX(){ return m_iPosX; }
float Entity::GetY(){ return m_iPosY; }
float Entity::GetSizeX(){ return m_iSizeX; }
float Entity::GetSizeY(){ return m_iSizeY; }