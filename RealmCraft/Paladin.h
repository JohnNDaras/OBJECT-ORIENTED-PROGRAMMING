#ifndef PALADIN_H
#define PALADIN_H


#include <iostream>
#include <string>

#include "Hero.h"

using namespace std;

class Paladin : public Hero{
	private :
		
		double pc_warrior[5];
	public:
		void levelUp();
		Paladin();
		Paladin(string n, int l, double hp, double mp, double st, double de, double ag, double mo, double ex);
};


#endif
