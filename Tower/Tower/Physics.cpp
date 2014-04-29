#include "Physics.h"

bool Physics::HasCollided(Entity* entOne, Entity* entTwo){

	RECT tR;

	if(IntersectRect(&tR, &entOne->GetBoundingRect(), &entTwo->GetBoundingRect()))
		return true;

	return false;

}