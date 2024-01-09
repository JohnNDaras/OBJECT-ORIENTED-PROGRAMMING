#include "Student.h"


		Student::Student(){
			fullName = "Unknown Unknown";
			location = locationOut;
			floor = -1;
			classNumber -1;
			cout << "Created student:"<<this->fullName<<endl;
		}
		Student::Student(string fn, int f, int c,int i){
			this->id = i;
			this->fullName = fn;
			this->location = locationOut;
			this->floor = f;
			this->classNumber = c;
			cout << "Created student:"<<this->fullName<<" Class:"<<(this->classNumber+1)<<" Floor:"<<(this->floor+1)<<endl;
		}
		Student::~Student(){
			cout << "Student "<<this->fullName<<"Destroyed" << endl;
		}
		void Student::setFullName(string fn){
			fullName = fn;
		}
		void Student::setLocation(int loc){
			location = loc;
		}
		void Student::setFloor(int flo){
			floor = flo;
		}
		string Student::getFullName(){
			return this->fullName;
		}
		int Student::getLocation(){
			return this->location;
		}
		int Student::getFloor(){
			return this->floor;
		}
		int Student::getClassroom(){
			return this->classNumber;
		}
		int Student::getId(){
			return this->id;
		}
		void Student::print(){
			cout << this->fullName << " (Student)"<< endl;
		}
		

