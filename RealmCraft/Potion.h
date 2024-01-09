#ifndef POTION_H
#define POTION_H

#include <iostream>
#include <string>
#include "Item.h"


using namespace std;

class Potion : public Item{
	private :
		string statistic;
		double amount;
	public:
		Potion();
		Potion(string s, double p, int l, string statistic, double amount);
		void setStatistic(string stat);
		void setAmount(double a);
		string getStatistic();
		double getAmount();
};

#endif
