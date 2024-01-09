#ifndef STUDENT_H
#define STUDENT_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include "config.h"
using namespace std;

class Student{
	private : 
		//STUDENT'S ID
		int id;
		//STUDENTS'S FULL NAME
		string fullName;
		//STUDENT'S CLASSROOM FLOOR
		int floor;
		//STUDENT'S CLASSROOM NUMBER ON THE FLOOR
		int classNumber;
		//STUDENT'S CURRENT LOCATION
		int location;
	public :
		//CONSTRUCTORS
		Student();
		Student(string fn, int f, int c, int i);
		~Student();
		//SETTERS - GETTERS
		void setFullName(string fn);
		void setLocation(int loc);
		void setFloor(int flo);
		string getFullName();
		int getLocation();
		int getFloor();
		int getClassroom();
		int getId();
		//PRINTS STUDENT'S STATUS
		void print();
};

#endif

