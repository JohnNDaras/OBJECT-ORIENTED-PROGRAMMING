#ifndef YARD_H
#define YARD_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Stairs.h"
#include "Student.h"

using namespace std;

class Yard{
	private :
		//ARRAY CONTAINING STUDENTS IN THE YARD
		Student *studentsIn[MAX_ARRAY_SIZE];
		//NUMBER OF STUDENT IN THE YARD
		int numberOfStudentsIn;
		//YARD CAPACITY
		int capacity;
	public :
		//CONSTRUCTORS
		Yard();
		Yard(int c);
		~Yard();
		//SETTERS - GETTERS 
		void setCapacity(int c);
		int getCapacity();
		//ADDS STUDENT S TO THE YARD
		int addStudent(Student *s);
		//ADDS STUDENT S TO STAIRS
		int addStudentToStairs(Stairs *st,Student *s);
		//PRINTS YARD STATUS
		void print();
};

#endif


