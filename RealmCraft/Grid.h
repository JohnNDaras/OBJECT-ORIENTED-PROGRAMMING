#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <string>
#include <time.h>

#include "Square.h"

using namespace std;
class Grid{
	private:
		int size_x;
		int size_y;
		Square ***Matrix;
	public:
		Grid();
		Grid(int x, int y);
		void setX(int c);
		void setY(int c);
		int getX();
		int getY();
		//initiats grid matrix
		void makeMatrix();
		//returns the square on the x,y cell of the grid
		Square *getContent(int x, int y);
};

#endif
