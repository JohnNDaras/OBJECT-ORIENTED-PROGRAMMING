#ifndef TEACHER_H
#define TEACHER_H

#include "Human.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Human.h"

using namespace std;

class Teacher : public Human{
	private : 
		
	public :
		
		//CONSTRUCTORS
		Teacher():Human(){
			cout << "A New Teacher has been created!" << endl;
		};
		~Teacher();
		Teacher(string fn,int f, int c,int i):Human(fn,f,c,i){
			cout << "A New Teacher has been created!" << endl;
		};
		
		//PRINTS TEACHER'S STATUS
		void print();
		//computes physical status fro teacher
		void computePhysicalStatus();
		static int L; 

};

#endif

