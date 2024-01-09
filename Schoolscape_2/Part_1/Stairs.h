#ifndef STAIRS_H
#define STAIRS_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Place.h"
#include "Student.h"
#include "Floor.h"

using namespace std;
class Stairs : public Place{
	private :
		//ARRAY CONTAINING THE STUDENTS ON STAIRS
		Student *studentsIn[MAX_ARRAY_SIZE];
		//THER NUMBER OF STUDENTS ON STAIRS
		int numberOfStudentsIn;
		//THE STAIRS CAPACITY
		int capacity;
	public :
		//CONSTRUCTORS
		Stairs();
		Stairs(int s);
		virtual ~Stairs();
		//SETTER - GETTER
		void setCapacity(int c);
		int getCapacity();
		//ADSS STUDENT S TO STAIRS
		int addStudent(Student *s);
		//ADDS STUDENT S TO FLOOR F
		int addStudentToFloor(Floor *f,Student *s);
		//PRINTS STAIRS STATUS
		void print();
		//stairs operation for x hours
		void operates(int x){};
		
};

#endif
