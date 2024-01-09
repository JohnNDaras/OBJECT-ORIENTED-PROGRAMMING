#include "IceSpell.h"

IceSpell::IceSpell():Spell(){
	
	damageRange = 0;
	rounds = 0;
}
IceSpell::IceSpell(string s, double p, int l, double d, double e, double df, int r){
	description = s;
	price = p;
	level = l;
	damage = d;
	energy = e;
	damageRange = df;
	rounds = r;
}
void IceSpell::setDamageRange(double df){
	damageRange = df;
}
double IceSpell::getDamageRange(){
	return damageRange;
}

void IceSpell::setRounds(int r){
	rounds = r;
}
int IceSpell::getRounds(){
	return rounds;
}

