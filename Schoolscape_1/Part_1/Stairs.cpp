#include "Stairs.h"

		Stairs::Stairs(){
			int i;
			this->numberOfStudentsIn = 0;
			
			cout << "Stairs constructed" << endl;
		}
		Stairs::Stairs(int c){
			int i;
			this->numberOfStudentsIn = 0;
			this->capacity = c;
			for (i=0;i<MAX_ARRAY_SIZE;i++){
				this->studentsIn[i] = NULL;
			}
			cout << "Yard constructed" << endl;
		}
		Stairs::~Stairs(){
			int i;
			for (i=0;i<MAX_ARRAY_SIZE;i++){
				if (this->studentsIn[i]!=NULL){
					delete(this->studentsIn[i]);
				}
			}
			cout << "Corridor Destroyed" << endl;
		}
		int Stairs::addStudent(Student *s){
			if (this->numberOfStudentsIn<this->capacity){
				cout << s->getFullName() << " enters stairs" << endl;
				s->setLocation(locationStairs);//CHANGING LOCATION
				this->studentsIn[this->numberOfStudentsIn++] = s;
				return 1;
			}
			return 0;
		} 
		
		int Stairs::getCapacity(){
			return this->capacity;
		}
		
		void Stairs::setCapacity(int c){
			this->capacity = c;
		}
		
		int Stairs::addStudentToFloor(Floor *f,Student *s){
			int i;
			//IF STUDENT IS NOT ON STAIRS DO NOTHING
			for (i=0;i<this->numberOfStudentsIn;i++){
				if (this->studentsIn[i]->getId()==s->getId()){
					break;
				}
			}
			if (i>=this->numberOfStudentsIn){
				return 0;
			}
			if (f->insertStudent(s)){
				cout << s->getFullName() << " exits stairs" << endl;
				//EXITS - RAPLACE CUURENT STUDENT WITH THE LAST ONE IN ARRAY
				this->studentsIn[i] = this->studentsIn[this->numberOfStudentsIn-1];
				this->studentsIn[this->numberOfStudentsIn-1] = NULL;
				this->numberOfStudentsIn--;
			}
			else {
				return 0;
			}
			return 1;
		}
		
		void Stairs::print(){
			cout << "People in stairs are:" << endl;
			int i;
			for (i=0;i<this->numberOfStudentsIn ;i++){
				studentsIn[i]->print();
			}
		}
	
