#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

#include "Square.h"


using namespace std;

class Item{
	protected:
		string description; 
		double price;
		int level;
		Square *position;
		string owner;
	public:
		Item();
		Item(string s, double p, int l);
		void setDescription(string s);
		void setPrice(double p);
		void setLevel(int l);
		string getDescription();
		double getPrice();
		int getLevel();
		void setPosition(Square *s);
		Square *getPosition();
		void setOwner(string h);
		string getOwner();
		void printDetails();
};

#endif
