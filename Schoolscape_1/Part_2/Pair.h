#ifndef PAIR_H
#define PAIR_H


#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Student.h"


class Pair{
	private:
		//THE STUDENTS IN PAIR
		Student *A;
		Student *B;
		Pair *next;
	public :
		//CONSTRUCTORS - DESTRUCTORS
		Pair();
		~Pair();
		Pair(Student *A, Student *B);
		//REPLACE THE CORRESPONDING WITH THE ONE IN THE PARAMETER
		void replaceA(Student *a);
		void replaceB(Student *b);
		//GETTERS - SETTERS
		Student *getA();
		Student *getB();
		Pair *getNext();
		void setNext(Pair *p);
		int getLevel();
		//SWAPS THE PAIR STUDENTS
		void swapMembers();
		//PRINT PAIR STATUS
		void print();
		
		
};

#endif
