#include "Sequence.h"

Sequence::Sequence(){
	this->head = NULL;
	this->size = 0;
	this->quietLevel = 0;
}
Sequence::~Sequence(){
	
}
void Sequence::addPair(Pair *p){
	Pair *temp = this->head;
	if (temp == NULL){
		this->head = p;
		this->head->setNext(NULL);
		this->quietLevel=p->getLevel();
		this->size++;
	}
	else {
		p->setNext(head);
		head = p;
		this->size++;
		if (p->getA()->getGender()==p->getNext()->getA()->getGender()){
			cout << "Need to swap"<< endl;
			p->swapMembers();
		}
		this->quietLevel+=p->getLevel();
	}
	
}
string Sequence::message(int tr1, int tr2){
	//MESSAGE TO BE RETURN DEPENDS ON THRESHOLDS
	if (this->quietLevel>tr1){
		return "What a quiet class";
	}
	else if (this->quietLevel<tr2){
		return "Monsters";
	}
	else {
		return " \b";
	}
}
Pair *Sequence::getHead(){
	return this->head;
}
void Sequence::print(){
	Pair *p = this->head;
	while (p!=NULL){
		p->print();
		p = p->getNext();
	}
}

int Sequence::getQuietLevel(){
	Pair *p = this->head;
	this->quietLevel = 0;
	while (p!=NULL){
		this->quietLevel+=p->getLevel();
		p = p->getNext();
	}
	return this->quietLevel;
}
int Sequence::getSize(){
	return this->size;
}
Pair *Sequence::getN(int n){
	Pair *p = this->head;
	while ((p!=NULL) && (n>0)){
		n--;
		p = p->getNext();
	}
	return p;
}

