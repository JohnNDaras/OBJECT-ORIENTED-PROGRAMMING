#include "Student.h"


		
		Student::~Student(){
			cout << "Student "<<this->fullName<<"Destroyed" << endl;
		}
		
		void Student::print(){
			cout << this->fullName << " (Student) Status:"<< this->getPhysicalStatus() <<endl;
		}
		
		
		
