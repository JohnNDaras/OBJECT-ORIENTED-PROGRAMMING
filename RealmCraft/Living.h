#ifndef LIVING_H
#define LIVING_H

#include <iostream>
#include <string>
#include "Grid.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3


using namespace std;

class Living{
	protected :
		string name;
		int level;
		double healthPower;
		Square *position;
	public :
		Living();
		Living(string n, int l, double hp);
		string getName();
		int getLevel();
		double getHealthPower();
		void setName(string n);
		void setLevel(int l);
		void setHealthPower(double hp);
		void setPosition(Square *s);
		Square *getPosition();
		int move(int W, Grid *G);
		void displayStats();
		
};

#endif
