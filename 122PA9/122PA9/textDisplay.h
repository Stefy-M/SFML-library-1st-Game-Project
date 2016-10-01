#pragma once
#include "entity.h"
class textDisplay : public entity{

public:
	
	int counter = 0;
	bool destroy = false;
	int lifetime = 200;



	string myString = "Default";

	textDisplay();
	void update();
	



private:
	


};