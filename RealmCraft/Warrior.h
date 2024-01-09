#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include <string>

#include "Hero.h"

using namespace std;

class Warrior : public Hero{
	private :
		
		double pc_warrior[5];
	public:
		void levelUp();
		Warrior();
		Warrior(string n, int l, double hp, double mp, double st, double de, double ag, double mo, double ex);
};


#endif

