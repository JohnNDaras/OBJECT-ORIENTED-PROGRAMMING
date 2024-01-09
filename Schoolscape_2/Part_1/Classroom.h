#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Place.h"
#include "Teacher.h"
#include "Student.h"
#include "JuniorStudent.h"
#include "SeniorStudent.h"

using namespace std;

class Classroom : public Place{
	protected :
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
		//the classroom type (Senior or Junior)
		string classroomtype;
	public :
		//CONSTRUCTORS
		Classroom();
		Classroom(int c);
		virtual ~Classroom();
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
		//classroom operation for x hours
		void operates(int x);
};

#endif
