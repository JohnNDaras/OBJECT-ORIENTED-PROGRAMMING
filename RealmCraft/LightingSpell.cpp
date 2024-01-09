#include "LightingSpell.h"

LightingSpell::LightingSpell():Spell(){
	
	avoid = 0;
	rounds = 0;
}

LightingSpell::LightingSpell(string s, double p, int l, double d, double e, double df, int r):Spell(s,p,l,d,e){
	
	avoid = df;
	rounds = r;
}


void LightingSpell::setAvoiding(double a){
	avoid = a;
}
double LightingSpell::getAvoiding(){
	return avoid;
}
void LightingSpell::setRounds(int r){
	rounds = r;
}
int LightingSpell::getRounds(){
	return rounds;
}
