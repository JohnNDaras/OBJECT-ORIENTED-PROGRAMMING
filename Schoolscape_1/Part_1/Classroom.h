#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include "config.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;

class Classroom{
	private :
		//CLASSROOM ID
		int id;
		//THE CLASSROOM TEACHER
		Teacher *teacher;
		//ARRAY CONTAINING CLASSROOM STUDENTS
		Student *students[MAX_ARRAY_SIZE];
		//THE NUMBER OF STUDENTS IN CLASSROOM
		int studentsIn;
		//THE CLASSROOM CAPACITY (STUDENTS)
		int capacity;
	public :
		//CONSTRUCTORS
		Classroom();
		Classroom(int c);
		~Classroom();
		//ID SETTER
		void setId(int i);
		//INSERTS A TEACHER IN THE CLASSROOM
		int insertTeacher(Teacher *t);
		//INSERTS A STUDENT IN THE CLASSROOM
		int insertStudent(Student *s);
		//GETTERS
		int getCapacity();
		void setCapacity(int c);
		int getNumberOfStudentsIn();
		//PRINTS CLASSROOM STATUS
		void print();
};

#endif
