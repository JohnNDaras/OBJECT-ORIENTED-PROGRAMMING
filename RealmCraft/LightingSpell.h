#ifndef LIGHTINGSPELL_H
#define LIGHTINGSPELL_H

#include <iostream>
#include <string>

#include "Spell.h"

using namespace std;

class LightingSpell : public Spell {
	private :
		double avoid;
		int rounds;
	public :
		LightingSpell();
		LightingSpell(string s, double p, int l, double d, double e, double df, int r);
		void setAvoiding(double a);
		double getAvoiding();
		void setRounds(int r);
		int getRounds();
};

#endif
