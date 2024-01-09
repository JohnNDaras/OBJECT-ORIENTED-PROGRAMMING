#ifndef DRAGON_H
#define DRAGON_H


#include <iostream>
#include <string>

#include "Monster.h"

using namespace std;
class Dragon : public Monster{
	private:
		
	public:
		Dragon();
		Dragon(string n, int l, double hp, double da, double de, double av);
};

#endif
