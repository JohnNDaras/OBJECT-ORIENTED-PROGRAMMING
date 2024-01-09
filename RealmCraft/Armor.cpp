#include "Armor.h"

Armor::Armor(){
	Item();
	damage = 0;
}
Armor::Armor(string s, double p, int l,int d):Item(s,p,l){
	damage = d;
}
int Armor::getDamage(){
	return damage;
}
void Armor::setDamage(int d){
	damage = d;
}
