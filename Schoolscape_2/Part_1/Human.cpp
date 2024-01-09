#include "Human.h"


		Human::Human(){
			fullName = "Unknown Unknown";
			location = locationOut;
			floor = -1;
			classNumber = -1;
			this->physicalStatus = 0;
			this->attend = 0;
			cout << "Created student:"<<this->fullName<<endl;
		}
		Human::Human(string fn, int f, int c,int i){
			this->id = i;
			this->fullName = fn;
			this->location = locationOut;
			this->floor = f;
			this->classNumber = c;
			this->physicalStatus = 0;
			this->attend = 0;
			cout << "Created student:"<<this->fullName<<" Class:"<<(this->classNumber+1)<<" Floor:"<<(this->floor+1)<<endl;
		}
		Human::~Human(){
			cout << "Human "<<this->fullName<<"Destroyed" << endl;
		}
		void Human::setFullName(string fn){
			fullName = fn;
		}
		void Human::setLocation(int loc){
			location = loc;
		}
		void Human::setFloor(int flo){
			floor = flo;
		}
		string Human::getFullName(){
			return this->fullName;
		}
		int Human::getLocation(){
			return this->location;
		}
		int Human::getFloor(){
			return this->floor;
		}
		int Human::getClassroom(){
			return this->classNumber;
		}
		int Human::getId(){
			return this->id;
		}
		void Human::print(){
			cout << this->fullName << " (Human)"<< endl;
		}
		
		int Human::getPhysicalStatus(){
			return physicalStatus;
		}
		void Human::setPhysicalStatus(int x){
			physicalStatus = x;
		}
		
		int Human::getAttend(){
			return this->attend;
		}
		
		void Human::setAttend(int x){
			this->attend = x;
		}
		
		
