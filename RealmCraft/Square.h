#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <string>

using namespace std;

class Square{
	private:
		int x;
		int y;
		int accessible;
		int market;
	public:
		Square();
		Square(int _x, int _y, int ac, int ma);
		void setX(int c);
		void setY(int c);
		void setAccessible(int c);
		void setMarket(int c);
		int getX();
		int getY();
		int getAccessible();
		int getMarket();
		//showing square contents and status
		void view();
};

#endif
