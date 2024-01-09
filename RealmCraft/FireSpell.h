#ifndef FIRESPELL_H
#define FIRESPELL_H

#include <iostream>
#include <string>
#include "Spell.h"


using namespace std;

class FireSpell : public Spell{
	private:
		double defence;
		int rounds;
	public:
		FireSpell();
		FireSpell(string s, double p, int l, double d, double e, double df, int r);
		double getDefence();
		void setDefence(double df);
		int getRounds();
		void setRounds(int r);
};

#endif
