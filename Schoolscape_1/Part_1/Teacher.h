#ifndef TEACHER_H
#define TEACHER_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include "config.h"


using namespace std;

class Teacher{
	private : 
		//TECHER'S ID
		int id;
		//TEACHER'S FULLNAME
		string fullName;
		//TEACHER'S CLASSROOM NUMBER
		int classNumber;
		//TEACHER'S CLASSROOM FLOOR
		int floor;
		//TEACHER' CURRENT LOCATION
		int location;
	public :
		//CONSTRUCTORS
		Teacher();
		~Teacher();
		Teacher(string fn,int f, int c,int i);
		//SETTERS - GETTERS
		void setFullName(string fn);
		void setClassNumber(int cn);
		void setLocation(int ii);
		string getFullName();
		int getClassNumber();
		int getLocation();
		int getClassroom();
		int getFloor();
		int getId();
		//PRINTS TEACHER'S STATUS
		void print();
		
		
};

#endif

