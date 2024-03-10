#pragma once
#include <Core/Sunflower.h>

namespace SunflowerCollisions
{

	bool CircleCircle(Sunflower::GameObject* object1, Sunflower::GameObject* object2)
	{
		float xDist = object1->position.x - object2->position.x;
		float yDist = object1->position.y - object2->position.y;
		return sqrt((xDist*xDist + yDist*yDist)) <= (object1->scale.x + object2->scale.x);
	};

};