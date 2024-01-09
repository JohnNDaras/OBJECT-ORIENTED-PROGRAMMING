#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;


class Student{
	private :
		//STUDENT'S ID
		int id;
		//STUDENT'S GENDER (M MALE - F FEMALE)
		char gender;
		//1 QUAIET - 0 NOT QUAIET
		int quiet;
	public :
		//CONSTRUCTORS - DESTRUCTORS
		Student();
		~Student();
		Student(int i, char g, int q);
		//GETTERS - SETTERS 
		void setQuiet(int q);
		int getQuiet();
		void setGender(char g);
		char getGender();
		//PRINTS STUDENT STATUS
		void print();
};


#endif
