#pragma once
#include "random.h"


int generateRandom(int max) {
	int randomNum = rand();
	float random = (randomNum %max) + 1;
	int myRandom = random;
	return myRandom;
}

int generateRandom0(int max) {
	int randomNum = rand();
	float random = (randomNum %max);
	int myRandom = random;
	return myRandom;
}

bool generateRandomBool() {
	int randomNum = rand();
	float random = (randomNum % 2) + 1;
	int myRandom = random;
	if (myRandom == 1) {
		return true;
	}
	else {
		return false;
	}
}