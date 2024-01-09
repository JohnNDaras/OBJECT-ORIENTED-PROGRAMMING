#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
#include "Item.h"


using namespace std;

class Weapon : public Item{
	private :
		double  damage;
		int hands;
	public :
		Weapon();
		Weapon(string s, double p, int l, double d, int h);
		void setDamage(double d);
		void setHands(int h);
		double getDamage();
		int getHands();
};

#endif
