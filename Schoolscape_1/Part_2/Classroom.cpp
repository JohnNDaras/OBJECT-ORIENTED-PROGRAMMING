#include "Classroom.h"

Classroom::Classroom(){
	this->sequence = new Sequence();
	this->name = -1;
	this->counter = 0;
	this->swaps = 0;
}
Classroom::~Classroom(){
	
}
Classroom::Classroom(int n){
	this->sequence = new Sequence();
	this->name = n;
	this->counter = n;
	this->swaps = 0;
	cout << "Classroom created" << endl;
}
void Classroom::setName(int n){
	this->name = n;
}
int Classroom::getName(){
	return this->name;
}

Sequence *Classroom::getSequence(){
	return this->sequence;
}

void Classroom::print(){
	cout << "Classroom:"<<this->name<<endl;
	this->sequence->print();
	cout << endl;
}

string Classroom::message(int tr1, int tr2){
	return this->sequence->message(tr1,tr2);
}


Classroom *Classroom::getNext(){
	return this->next;
}

void Classroom::setNext(Classroom *p){
	this->next = p;
}

void Classroom::increaseSwaps(){
	this->swaps++;
}
int Classroom::getCounter(){
	return this->counter;
}
void Classroom::setCounter(int x){
	this->counter = x;
}

void Classroom::updateCounter(){
	this->counter = this->sequence->getQuietLevel();
}

void Classroom::setSwaps(int x){
	this->swaps = x;
}
int Classroom::getSwaps(){
	return this->swaps;
}
int Classroom::swapType(int x){
	int noQuiet = this->countNoQuietPairs();
	Pair *p = this->sequence->getN(x);
	//int c;
	if (p == NULL){
		return noSwap;
	}
	if ((p->getLevel()==0) && (noQuiet>=3)){
		if (p->getNext()!=NULL){
			if ((p->getNext()->getLevel()==0)&& (noQuiet>=3)){
				if (p->getNext()->getNext()!=NULL){
					if (p->getNext()->getNext()->getLevel()==0){
						return polyexClassroomSwap;
					}
					else if (noQuiet<3){
						return inClassroomSwap;
					}
					else {
						return exClassroomSwap;
					}
				}
				else if (noQuiet<3){
					return inClassroomSwap;
				}
				else {
					return exClassroomSwap;
				}
			}
			else if (noQuiet<3){
				return inClassroomSwap;
			}
			else {
				return exClassroomSwap;
			}
		}
		else if (noQuiet<3){
			return inClassroomSwap;
		}
		else {
			return exClassroomSwap;
		}
	}
	else if (p->getLevel()==1){
		return inClassroomSwap;
	}
	else {
		return noSwap;
	}
}
void Classroom::intraSwap(int x){
	Pair *toMove = this->sequence->getN(x);
	Student *s;
	int y = rand()%this->sequence->getSize();
	while (y==x){
		y = rand()%this->sequence->getSize();
	}
	Pair *toBePlaced = this->sequence->getN(y); 
	if (toMove->getA()->getQuiet()==0){
		if (toMove->getA()->getGender()==toBePlaced->getA()->getGender()){
			s = toMove->getA();
			toMove->replaceA(toBePlaced->getA());
			toBePlaced->replaceA(s);
		}
		else {
			s = toMove->getA();
			toMove->replaceA(toBePlaced->getB());
			toBePlaced->replaceB(s);
		}
	}
	else if (toMove->getB()->getQuiet()==0){
		if (toMove->getB()->getGender()==toBePlaced->getA()->getGender()){
			s = toMove->getB();
			toMove->replaceA(toBePlaced->getA());
			toBePlaced->replaceA(s);
		}
		else {
			s = toMove->getB();
			toMove->replaceB(toBePlaced->getB());
			toBePlaced->replaceB(s);
		}
	}
	this->increaseSwaps();
}

int Classroom::countNoQuietPairs(){
	//int i;
	//int c = 0;
	return this->getSequence()->getQuietLevel();
}

