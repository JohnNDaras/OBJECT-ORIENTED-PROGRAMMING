#ifndef SORCERER_H
#define SORCERER_H


#include <iostream>
#include <string>

#include "Hero.h"

using namespace std;

class Sorcerer : public Hero{
	private :
		
	public:
		void levelUp();
		Sorcerer();
		Sorcerer(string n, int l, double hp, double mp, double st, double de, double ag, double mo, double ex);
};


#endif
