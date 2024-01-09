#ifndef CORRIDOR_H
#define CORRIDOR_H

#define Ccorr 10
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Place.h"
#include "Classroom.h"
#include "Student.h"


using namespace std;
class Corridor : public Place{
	private :
		//ARRAY CONTAINING STUDENTS IN THE CORRIDOR
		Student *studentsIn[MAX_ARRAY_SIZE];
		//NUMBER OF STUDENTS IN CORRIDOR
		int numberOfStudentsIn;
		//THE CORRIDOR CAPACITY
		int capacity;
	public :
		//CONSTRUCTORS
		Corridor();
		Corridor(int c);
		virtual ~Corridor();
		//ADDS STUDENT S IN CORRIDOR
		int addStudent(Student *s);
		//ADDS STUDENT S IN THE CLASSROOR C
		int addStudentToClass(Classroom *c, Student *s);
		//SETTERS - GETTERS
		void setCapacity(int c);
		int getCapacity();
		//PRINTS CORRIDOR STATUS
		void print();
		void operates(int x){};
};

#endif
