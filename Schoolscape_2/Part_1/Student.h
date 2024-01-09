#ifndef STUDENT_H
#define STUDENT_H

#include "Human.h"
#include <stdlib.h>
#include <iostream>
#include <string>


using namespace std;

class Student : public Human{
	protected : 
		
	public :
		//CONSTRUCTORS
		Student():Human(){
		};
		Student(string fn, int f, int c, int i):Human(fn,f,c,i){
		};
		virtual ~Student();
		//PRINTS STUDENT'S STATUS
		void print();

};

#endif

