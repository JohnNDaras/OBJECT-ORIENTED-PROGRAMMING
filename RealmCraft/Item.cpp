#include "Item.h"

Item::Item(){
	description = "-";
	price = 0.0;
	level = 0;
	owner = "-";
}
Item::Item(string s, double p, int l){
	description = s;
	price = p;
	level = l;
	owner = "-";
}
void Item::setDescription(string s){
	description = s;
}
void Item::setPrice(double p){
	price = p;
}
void Item::setLevel(int l){
	level = l;
}
string Item::getDescription(){
	return description;
}
double Item::getPrice(){
	return price;
}
int Item::getLevel(){
	return level;
}


Square *Item::getPosition(){
	return position;
}

void Item::setPosition(Square *s){
	position = s;
}

void Item::setOwner(string h){
	owner = h;
}
string Item::getOwner(){
	return owner;
}
void Item::printDetails(){
	cout << "Description:" << this->description << endl;
	cout << "Level:" << this->level << endl;
	cout << "Price:" << this->price << endl;
	if (owner == "-"){
		cout << "Owner:" << this->owner << endl;
	}
}
