#ifndef MONSTER_H
#define MONSTER_H


#include <iostream>
#include <string>

#include "Living.h"

using namespace std;
class Monster : public Living{
	private:
		double damage;
		double defence;
		double avoiding;
	public:
		Monster();
		Monster(string n, int l, double hp, double da, double de, double av);
		double getDamage();
		double getDefence();
		double getAvoiding();
		void setDamage(double x);
		void setDefence(double x);
		void setAvoiding(double x);
		void displayMonsterStats();
};

#endif

