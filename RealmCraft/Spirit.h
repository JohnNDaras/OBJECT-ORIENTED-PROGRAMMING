#ifndef SPIRIT_H
#define SPIRIT_H


#include <iostream>
#include <string>

#include "Monster.h"

using namespace std;
class Spirit : public Monster{
	private:
		
	public:
		Spirit();
		Spirit(string n, int l, double hp, double da, double de, double av);
};

#endif
