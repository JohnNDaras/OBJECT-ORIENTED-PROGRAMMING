#include "Spell.h"

Spell::Spell(){
	description = "-";
	price = 0.0;
	level = 0;
	damage = 0;
	energy = 0;
}
Spell::Spell(string s, double p, int l, double d, double e){
	description = s;
	price = p;
	level = l;
	damage = d;
	energy = e;
}
void Spell::setDescription(string s){
	description = s;
}
void Spell::setPrice(double p){
	price = p;
}
void Spell::setLevel(int l){
	level = l;
}
string Spell::getDescription(){
	return description;
}
double Spell::getPrice(){
	return price;
}
int Spell::getLevel(){
	return level;
}

void Spell::setDamage(double d){
	damage = d;
}

double Spell::getDamage(){
	return damage;
}

void Spell::setEnergy(double d){
	energy = d;
}

double Spell::getEnergy(){
	return energy;
}


