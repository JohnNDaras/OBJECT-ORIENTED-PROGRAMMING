#include "Square.h"

Square::Square(){
	x = -1;
	y = -1;
	accessible = 0;
	market = 0;
}

Square::Square(int _x, int _y, int ac, int ma){
	x = _x;
	y = _y;
	accessible = ac;
	market = ma;
}

void Square::setX(int c){
	x = c;
}
void Square::setY(int c){
	y = c;
}
void Square::setAccessible(int c){
	accessible = c;
}
void Square::setMarket(int c){
	market = c;
}

int Square::getX(){
	return x;
}
int Square::getY(){
	return y;
}
int Square::getAccessible(){
	return accessible;
}
int Square::getMarket(){
	return market;
}


void Square::view(){
	cout << "[" << x << "," << y << "]";
	if (accessible == 1){
		cout << " ACCESSIBLE ";
	}
	else {
		cout << " NOT ACCESSIBLE ";
	}
	if (market == 1){
		cout << " MARKET ";
	}
	cout << endl;
	
}




