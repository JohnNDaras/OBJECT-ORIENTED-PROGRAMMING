#ifndef SCHOOL_H
#define SCHOOL_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Classroom.h"


using namespace std;

class School {
	private:
		//THE SCHOOL FIRST CLASSROOM
		Classroom *head;
		//THE SIZE OF THE SCHOOL LIST
		int size;
		//LOWER LIMIT
		int threshold1;
		//UPPER LIMIT
		int threshold2;
	public:
		//CONSTRUCTOR - DESTRUCTOR
		School();
		~School();
		//SETTERS - GETTERS 
		Classroom *getClassroom(int x);
		int getThreshold1();
		int getThreshold2();
		void setThreshold1(int t1);
		void setThreshold2(int t2);
		//CHANGIG THE SCHOOL STAUS
		void changeStatus(int z, Student *S[], int size);
		//PRINTS THE QUIET LEVELS TO EACH CLASSROOM
		void printQuietLevels();
		//MAKE THE APPROPRIATE SWAPS DEPENDING ON STUDENTS BEHAVIOUR
		void fixIt();
		//ADDS THE CLASSROOM P TO SCHOOL
		void addClassroom(Classroom *p);
		//MAKES A SWAP BETWEEN PAIRS FROM FROMCLASS AND TOCLASSA (ELEMENT <-> ELEMENTA)
		void exSwap(int fromClass, int element, int toClassA, int elementA);
		//PRINTS SCHOOL STATUS
		void print();
		//RETURNS THE N-TH CLASSROOM
		Classroom *getN(int n);
};

#endif

