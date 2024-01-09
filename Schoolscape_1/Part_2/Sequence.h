#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Pair.h"

using namespace std;

class Sequence{
	private:
		//THE FIRST PAIR IN LIST
		Pair *head;
		//THE SEQUENCE SIZE
		int size;
		//THE NUMBER SHOWS HOW THE CHILDREN ARE
		int quietLevel;
	public:
		//CONSTRUCTOR - DESTRUCTOR
		Sequence();
		~Sequence();
		//ADDING A PAIR TO THE LIST
		void addPair(Pair *p);
		//PRINTS SEQUENCE STATUS
		void print();
		//GENERATES MESSAGES DEPENDING ON CHILDRENS BEAHVOUR AND THRESHOLDS T1 AND T2
		string message(int tr1, int tr2);
		//GETTERS
		int getQuietLevel();
		Pair *getHead();
		//GETS THE N-TH PAIR IN THW SEQUENCE
		Pair *getN(int n);
		int getSize();
};

#endif
