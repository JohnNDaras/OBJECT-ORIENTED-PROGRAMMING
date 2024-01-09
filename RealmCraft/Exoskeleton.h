#ifndef EXOSKELETON_H
#define EXOSKELETON_H


#include <iostream>
#include <string>

#include "Monster.h"

using namespace std;
class Exoskeleton : public Monster{
	private:
		
	public:
		Exoskeleton();
		Exoskeleton(string n, int l, double hp, double da, double de, double av);
};

#endif
