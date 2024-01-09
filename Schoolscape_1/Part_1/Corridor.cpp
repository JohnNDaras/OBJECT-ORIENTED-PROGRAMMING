#include "Corridor.h"


		Corridor::Corridor(){
			int i;
			this->numberOfStudentsIn = 0;
			cout << "Corridor constructed" << endl;
		}
		Corridor::Corridor(int c){
			int i;
			this->numberOfStudentsIn = 0;
			this->capacity = c;
			for (i=0;i<MAX_ARRAY_SIZE;i++){
				this->studentsIn[i] = NULL;
			}
			cout << "Corridor constructed" << endl;
		}
		Corridor::~Corridor(){
			int i;
			for (i=0;i<MAX_ARRAY_SIZE;i++){
				if (this->studentsIn[i]!=NULL){
					delete(this->studentsIn[i]);
				}
			}
			cout << "Corridor Destroyed" << endl;
		}
		int Corridor::addStudent(Student *s){
			if (this->numberOfStudentsIn<this->capacity){//IF THERE IS ENOUGH SPACE
				cout << s->getFullName() << " enters floor" << endl;
				cout << s->getFullName() << " enters corridor" << endl;
				s->setLocation(locationCorridor);//SET LOCATION
				//ADDING STUDENT
				this->studentsIn[this->numberOfStudentsIn++] = s;
				return 1;
			}
			return 0;
		}
		int Corridor::addStudentToClass(Classroom *c, Student *s){
			int i;
			//IF STUDENT IS NOT IN THE CORRIDOR DO NOTHIN
			for (i=0;i<this->numberOfStudentsIn;i++){
				if (this->studentsIn[i]->getId()==s->getId()){
					break;
				}
			}
			if (i>=this->numberOfStudentsIn){
				return 0;
			}
			
			if (c->insertStudent(s)){
				cout << s->getFullName() << " exits corridor" << endl;
				//EXITS - THE LAST STUDENT IN THE ARRAY TAKES THE PLACE OF THE CURRENT'S
				this->studentsIn[i] = this->studentsIn[this->numberOfStudentsIn-1];
				this->studentsIn[this->numberOfStudentsIn-1] = NULL;
				this->numberOfStudentsIn--;
				 
			}
			else {
				return 0;
			}
			return 1;
		}
		int Corridor::getCapacity(){
			return this->capacity;
		}
		
		void Corridor::setCapacity(int c){
			this->capacity = c;
		}
		
		void Corridor::print(){
			cout << "People in corridor are:" << endl;
			int i;
			for (i=0;i<this->numberOfStudentsIn ;i++){
				studentsIn[i]->print();
			}
		}
		

