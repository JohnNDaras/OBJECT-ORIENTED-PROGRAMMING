#ifndef STAIRS_H
#define STAIRS_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Student.h"
#include "Stairs.h"
#include "Floor.h"

using namespace std;
class Stairs {
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
		~Stairs();
		//SETTER - GETTER
		void setCapacity(int c);
		int getCapacity();
		//ADSS STUDENT S TO STAIRS
		int addStudent(Student *s);
		//ADDS STUDENT S TO FLOOR F
		int addStudentToFloor(Floor *f,Student *s);
		//PRINTS STAIRS STATUS
		void print();
		
};

#endif
