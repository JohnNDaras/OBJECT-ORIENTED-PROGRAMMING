#include "Living.h"

Living::Living(){
	name = "-";
	level = 0;
	healthPower = 0;
}
Living::Living(string n, int l, double hp){
	name = n;
	level = l;
	healthPower = hp;
}
string Living::getName(){
	return name;
}
int Living::getLevel(){
	return level;
}
double Living::getHealthPower(){
	return healthPower;
}
void Living::setName(string n){
	name = n;
}
void Living::setLevel(int l){
	level = l;
}
void Living::setHealthPower(double hp){
	healthPower = hp;
}

Square *Living::getPosition(){
	return position;
}

void Living::setPosition(Square *s){
	position = s;
}


int Living::move(int W, Grid *G){
	cout << "Moving:" << W << endl;
	if (W == RIGHT){
		//Hero is allready to the RIGHT edge
		if ((G->getX()-1)==this->getPosition()->getX()){
			cout << "Right move rejected (RIGHT EDGE)" << endl;
			return 0;
		}
		else if (G->getContent(this->getPosition()->getX()+1, this->getPosition()->getY())->getAccessible()==0){
			cout << "Right move rejected (RESTRICTED LOCATION)" << endl;
			return 0;
		}
		else {
			this->setPosition(G->getContent(this->getPosition()->getX()+1, this->getPosition()->getY()));
			cout << "Moved Right" << endl;
			return 1;
		}
	}
	else if (W == LEFT){
		//Hero is allready to the LEFT edge
		if (this->getPosition()->getX()==0){
			cout << "Left move rejected (LEFT EDGE)" << endl;
			return 0;
		}
		//The down location is not accessible
		else if (G->getContent(this->getPosition()->getX()-1, this->getPosition()->getY())->getAccessible()==0){
			cout << "Left move rejected (RESTRICTED LOCATION)" << endl;
			return 0;
		}
		//move completed
		else {
			this->setPosition(G->getContent(this->getPosition()->getX()-1, this->getPosition()->getY()));
			cout << "Moved Left" << endl;
			return 1;
		}
	}
	else if (W == DOWN){
		//Hero is allready to the DOWN edge
		if (this->getPosition()->getY()==0){
			cout << "Down move rejected (DOWN EDGE)" << endl;
			return 0;
		}
		//The down location is not accessible
		else if (G->getContent(this->getPosition()->getX(), this->getPosition()->getY()-1)->getAccessible()==0){
			cout << "Down move rejected (RESTRICTED LOCATION)" << endl;
			return 0;
		}
		//move completed
		else {
			this->setPosition(G->getContent(this->getPosition()->getX(), this->getPosition()->getY()-1));
			cout << "Moved Down" << endl;
			return 1;
		}
	}
	else if (W == UP){
		//Hero is allready to the UP edge
		if (this->getPosition()->getY()==(G->getY()-1)){
			cout << "Up move rejected (DOWN EDGE)" << endl;
			return 0;
		}
		//The down location is not accessible
		else if (G->getContent(this->getPosition()->getX(), this->getPosition()->getY()+1)->getAccessible()==0){
			cout << "Up move rejected (RESTRICTED LOCATION)" << endl;
			return 0;
		}
		//move completed
		else {
			this->setPosition(G->getContent(this->getPosition()->getX(), this->getPosition()->getY()+1));
			cout << "Moved Up" << endl;
			return 1;
		}
	}
	return 1;
}

void Living::displayStats(){
	cout << name << " [Level: "<< level << " Health:" << healthPower << "]" << endl;
}

