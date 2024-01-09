#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Sequence.h"

#define noSwap 0
#define inClassroomSwap 1
#define exClassroomSwap 2
#define polyexClassroomSwap 3

using namespace std;

class Classroom{
	private:
		//THE SEQUENCE CORESPONDING TO THE CLASSROOM
		Sequence *sequence;
		//THE CLASSROOM ID
		int name;
		//THE NEXT CLASSROOM TO THE CLASSROOM LIST
		Classroom *next;
		int counter;
		//KIDS SWAPS MADE TO THE CLASSROOM
		int swaps;
	public:
		//CONSTRUCTOR
		Classroom();
		//DESTRUCTOR
		~Classroom();
		//CONSTRUCTOR
		Classroom(int name);
		//GETTERS - SETTERS
		void setName(int name);
		int getName();
		int getCounter();
		void setNext(Classroom *c);
		void setCounter(int x);
		int getSwaps();
		void setSwaps(int x);
		Classroom *getNext();
		Sequence *getSequence();
		//PRINTS SEQUENCE STATUS
		void print();
		//INCREASES THE NUMBER OF SWAPS
		void increaseSwaps();
		//MAKES A MESSAGE ACCORDING TO HOW QUIET ARE THE CHILDREN (DEPENDING ON THRESHOLDS TR1, TR2)
		string message(int tr1, int tr2);
		//UPDATES THE COUNTER
		void updateCounter();
		//MAKING KIDS SWAP IN THE CLASSROOM
		void intraSwap(int x);
		//RETURN THE SWAO TYPE NEEDED FOR PAIR IN X POSITION
		int swapType(int x);
		//RETURN HOW MANY PAIRS ARE NOT QUIET
		int countNoQuietPairs();
};


#endif
