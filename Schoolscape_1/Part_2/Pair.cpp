#include "Pair.h"

Pair::Pair(){
	this->A = NULL;
	this->B = NULL;
	this->next = NULL;
}
Pair::~Pair(){
	
}
Pair::Pair(Student *a, Student *b){
	this->A = a;
	this->B = b;
	this->next = NULL;
	cout << "Pair  created" << endl;
}
void Pair::replaceA(Student *a){
	this->A = a;
}
void Pair::replaceB(Student *b){
	this->B = b;
}
Student *Pair::getA(){
	return this->A;
}
Student *Pair::getB(){
	return this->B;
}
void Pair::print(){
	cout << "Pair:" << endl;
	if (this->A==NULL){
		
	}
	else {
		this->A->print();
	}
	if (this->B==NULL){
		
	}
	else {
		this->B->print();
	}
	cout << "--" << endl;
}

void Pair::swapMembers(){
	Student *temp = this->A;
	this->A = this->B;
	this->B = temp;
}

Pair *Pair::getNext(){
	return this->next;
}

void Pair::setNext(Pair *p){
	this->next = p;
}

int Pair::getLevel(){
	int a,b;
	a = (this->A==NULL?0:this->A->getQuiet());
	b = (this->B==NULL?0:this->B->getQuiet());
	return a+b;
}

