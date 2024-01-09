
#include "Teacher.h"

		Teacher::Teacher(){
			this->fullName = "Unknown Unknown";
			this->classNumber = -1;
			this->location = 0;
			cout << "Created teacher:"<<this->fullName<<endl;
		}
	
		Teacher::Teacher(string fn, int f, int c, int i){
			this->id = i;
			this->fullName = fn;
			this->classNumber = c;
			this->floor = f;
			this->location = locationOut;
			cout << "Created teacher:"<<this->fullName<<" Class:"<<(this->classNumber+1)<<" Floor:"<<(this->floor+1)<<endl;
		}
		Teacher::~Teacher(){
			cout<<"Teacher:"<<this->fullName<<"Destroyed" << endl;
		}
		void Teacher::setFullName(string fn){
			this->fullName = fn;
		}
		void Teacher::setClassNumber(int cn){
			classNumber = cn;
		}
		void Teacher::setLocation(int ii){
			location = ii;
		}
		string Teacher::getFullName(){
			return fullName;
		}
		int Teacher::getClassNumber(){
			return classNumber;
		}
		int Teacher::getLocation(){
			return this->location;
		}
		int Teacher::getClassroom(){
			return this->classNumber;
		}
		int Teacher::getId(){
			return this->id;
		}
		
		int Teacher::getFloor(){
			return this->floor;
		}
		
		void Teacher::print(){
			cout << this->fullName << " (Teacher)"<< endl;
		}
		
