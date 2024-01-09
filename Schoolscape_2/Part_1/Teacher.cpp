
#include "Teacher.h"

		
		Teacher::~Teacher(){
			
			cout<<"A Teacher to be destroyed!" << endl;
		}
		
		
		void Teacher::print(){
			cout << this->fullName << " (Teacher) Status:"<< this->getPhysicalStatus() <<endl;
		}
		
		void Teacher::computePhysicalStatus(){
			physicalStatus = L * attend;
				
		}
		
