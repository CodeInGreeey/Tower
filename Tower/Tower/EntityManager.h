#ifndef _EntityMANAGER_H
#define _EntityMANAGER_H

#include "Entity.h"

class EntityManager{

private:

	static EntityManager* instance;

	vector<Entity*> entities;
	vector<Entity*>::iterator entityIterator;

public:

	EntityManager();
	~EntityManager();

	void Initialise();
	void Tick();
	void Render();

	static EntityManager* GetInstance();

	void AddEntity(Entity* entity);

};
#endif