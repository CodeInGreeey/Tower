#include "EntityManager.h"

EntityManager* EntityManager::instance = NULL;

EntityManager::EntityManager(){

	Initialise();

}

EntityManager::~EntityManager(){

}

void EntityManager::Initialise(){



}

EntityManager* EntityManager::GetInstance(){

	if(instance == NULL)
		instance = new EntityManager();

	return instance;

}

void EntityManager::AddEntity(Entity* entity){

	entities.push_back(entity);

}

void EntityManager::Tick(){

	for(entityIterator = entities.begin(); entityIterator != entities.end(); entityIterator++){

		(*entityIterator)->Tick();

	}

}

void EntityManager::Render(){

	for(entityIterator = entities.begin(); entityIterator!=entities.end(); entityIterator++){

		(*entityIterator)->Render();

	}

}