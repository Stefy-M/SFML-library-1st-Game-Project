#pragma once

#include "entity.h"
class pickup : public entity {

public:
	bool isDiamond = true;
	bool destroy = false;
	int DiamondVal = 5;

	pickup();
	void update();




private:



};