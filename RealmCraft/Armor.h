#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class Armor : public Item{
	private : 
		int damage;
	public :
		Armor();
		Armor(string s, double p, int l,int d);
		int getDamage();
		void setDamage(int d);
};

#endif
