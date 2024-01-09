#include "Weapon.h"

Weapon::Weapon():Item(){
	damage = 0;
	hands = 0;		
}
Weapon::Weapon(string s, double p, int l, double d, int h):Item(s,p,l){
	damage = d;
	hands = h;
}
void Weapon::setDamage(double d){
	damage = d;
}

double Weapon::getDamage(){
	return damage;
}
void Weapon::setHands(int h){
	hands = h;
}

int Weapon::getHands(){
	return hands;
}
