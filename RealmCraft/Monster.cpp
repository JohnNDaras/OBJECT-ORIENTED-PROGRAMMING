#include "Monster.h"

Monster::Monster():Living(){
	
	damage = 0;
	defence = 0;
	avoiding = 0;
}
Monster::Monster(string n, int l, double hp, double da, double de, double av):Living(n,l,hp){
	
	damage = da;
	defence = de;
	avoiding = av;
}
double Monster::getDamage(){
	return damage;
}
double Monster::getDefence(){
	return defence;
}
double Monster::getAvoiding(){
	return avoiding;	
}
void Monster::setDamage(double x){
	damage = x;
}
void Monster::setDefence(double x){
	defence = x;
}
void Monster::setAvoiding(double x){
	avoiding = x;
}


void Monster::displayMonsterStats(){
	displayStats();
	cout << "Damage:" << damage << endl;
	cout << "Defence:" << defence << endl;
	cout << "Avoiding" << avoiding << endl;
	
}
	
