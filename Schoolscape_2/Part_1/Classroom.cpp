#include "Place.h"
#include "Classroom.h"

		Classroom::Classroom(){
			id = -1;
			//int i;
			studentsIn = 0;
			this->capacity = 0;
			teacher = NULL;
			type = "classroom";
			classroomtype = "-";
		}
		Classroom::Classroom(int c){
			id = -1;
			int i;
			this->studentsIn = 0;
			this->teacher = NULL;
			this->capacity = c;
			//THERE IS NOT STUDENTS IN
			for (i=0;i<MAX_ARRAY_SIZE;i++){
				students[i] = NULL;
			}
			type = "classroom";
			classroomtype = "-";
			cout << "Classroom created"<<endl;
		}
		Classroom::~Classroom(){
		
		}
		void Classroom::setId(int i){
			this->id = i;
		}
		int Classroom::insertTeacher(Teacher *t){
			if (this->teacher==NULL){
				teacher = t;
				return 1;
			}
			else {
				cout << "There is a teacher in classroom" << endl;
				return 0;
			}
			
		}
		int Classroom::insertStudent(Student *s){
			//if (teacher == NULL){//TEACHER IS NOT IN
				if (this->studentsIn<this->capacity){//ENOUGH SPACE
					this->students[studentsIn++] = s;
					cout << s->getFullName() << " exits corridor" << endl<< endl;
					cout << s->getFullName() << " enters classroom" << endl<< endl;
					s->setLocation(locationClassroom);
					return 1;
				}
				else {//NOT ENOUGH SPACE
					cout << "Classroom is full" << endl;
					return 0;
				}
			//}
			//else {
			//	cout << "Teacher is in the classroom" << endl;
			//	return 0;
			//}
		}
		
		int Classroom::getCapacity(){
			return this->capacity;
		}
		void Classroom::setCapacity(int c){
			this->capacity = c;
		}
		
		int Classroom::getNumberOfStudentsIn(){
			return this->studentsIn;
		}
		
		void Classroom::print(){
			cout << "People in classroom " << id << "are:" << endl;
			if (this->teacher==NULL){
				cout <<"Teacher lost"<<endl;
			}
			else {
				cout << "The teacher is: ";
				this->teacher->print();
			}
			
			int i;
			cout << "Students("<<this->studentsIn<<"):"<<endl;
			for (i=0;i<this->studentsIn;i++){
				students[i]->print();
			}
		}
		
		void Classroom::operates(int x){
			int i;
			for (i=0;i<this->studentsIn;i++){
				this->students[i]->setAttend(x);
				this->students[i]->computePhysicalStatus();
			}
			this->teacher->setAttend(x);
			this->teacher->computePhysicalStatus();
		}

