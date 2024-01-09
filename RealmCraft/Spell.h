#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include <string>


using namespace std;

class Spell {
	protected:
		string description;
		double price;
		int level;
		double damage;
		double energy;
	public:
		Spell();
		Spell(string s, double p, int l, double d, double e);
		void setDescription(string s);
		void setPrice(double p);
		void setLevel(int l);
		void setDamage(double d);
		void setEnergy(double e);
		string getDescription();
		double getPrice();
		int getLevel();
		double getEnergy();
		double getDamage();
		
};

#endif
