#include "Yard.h"

		Yard::Yard(){
			//int i;
			this->numberOfStudentsIn = 0;
			this->capacity = 0;
			this->type = "yard";
			cout << "Yard constructed" << endl;
		}
		Yard::Yard(int c){
			int i;
			this->numberOfStudentsIn = 0;
			this->capacity = c;
			this->type = "yard";
			for (i=0;i<MAX_ARRAY_SIZE;i++){
				this->studentsIn[i] = NULL;
			}
			cout << "Yard constructed" << endl;
		}
		Yard::~Yard(){
			int i;
			for (i=0;i<MAX_ARRAY_SIZE;i++){
				if (this->studentsIn[i]!=NULL){
					delete(this->studentsIn[i]);
				}
			}
			cout << "Corridor Destroyed" << endl;
		}
		int Yard::addStudent(Student *s){
			if (this->numberOfStudentsIn<this->capacity){//IF THERE IS ENOUGH SPACE
				//Entering school
				cout <<  s->getFullName() << " enters school."<<endl<<endl;
				//Entering yard
				cout << s->getFullName() << " enters schoolyard." << endl<<endl;
				s->setLocation(locationYard);
				this->studentsIn[this->numberOfStudentsIn++] = s;
				return 1;
			}
			return 0;
		} 
		
		void Yard::print(){
			cout << "People in yard are:" << endl;
			int i;
			for (i=0;i<this->numberOfStudentsIn;i++){
				studentsIn[i]->print();
			}
		}
		
		int Yard::getCapacity(){
			return this->capacity;
		}
		
		void Yard::setCapacity(int c){
			this->capacity = c;
		}
		
		int Yard::addStudentToStairs(Stairs *st,Student *s){
			int i;
			//IF STUDENT IS NOT IN THE YARD DO NOTHING
			for (i=0;i<this->numberOfStudentsIn;i++){
				if (this->studentsIn[i]->getId()==s->getId()){
					break;
				}
			}
			if (i>=this->numberOfStudentsIn){
				return 0;
			}
			//ADDS TO STAIRS
			if (st->addStudent(s)){
				
				//EXITS - REPLACE CURRENT STUDENT WITH THE LAST IN THE ARRAY
				this->studentsIn[i] = this->studentsIn[this->numberOfStudentsIn-1];
				this->studentsIn[this->numberOfStudentsIn-1] = NULL;
				this->numberOfStudentsIn--;
			}
			else {
				return 0;
			}
			return 1;
		}
