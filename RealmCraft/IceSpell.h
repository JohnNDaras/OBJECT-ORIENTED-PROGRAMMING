#ifndef ICESPELL_H
#define ICESPELL_H

#include <iostream>
#include <string>

#include "Spell.h"

using namespace std;

class IceSpell : public Spell{
	private:
		double damageRange;
		int rounds;
	public:
		IceSpell();
		IceSpell(string s, double p, int l, double d, double e, double df, int r);
		void setDamageRange(double df);
		double getDamageRange();
		void setRounds(int r);
		int getRounds();
};

#endif
