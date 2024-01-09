#include "FireSpell.h"

FireSpell::FireSpell():Spell(){
	
	defence = 0;
	rounds = 0;
}

FireSpell::FireSpell(string s, double p, int l, double d, double e, double df, int r){
	description = s;
	price = p;
	level = l;
	damage = d;
	energy = e;
	defence = df;
	rounds = r;
}

int FireSpell::getRounds(){
	return rounds;
	
}
void FireSpell::setRounds(int r){
	rounds = r;
}

