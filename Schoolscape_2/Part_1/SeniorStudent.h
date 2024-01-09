#ifndef SENIORSTUDENT_H
#define SENIORSTUDENT_H

#include "Student.h"

class SeniorStudent : public Student{
		public:
			SeniorStudent(string fn, int f, int c, int i):Student(fn, f, c, i){
				cout << "::Senior Student::" << endl;
			}
			SeniorStudent():Student(){
				cout << "::Senior Student::" << endl;
			}
			//senior student physical status computation
			void computePhysicalStatus(){
				physicalStatus = L * attend;
				
			}
			static int L; 
		private:
			
			
};


#endif
