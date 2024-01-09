#include "Floor.h"

		Floor::Floor(){
			int i;
			for (i=0;i<3;i++){
				this->classrooms[i] = new SeniorClassroom();
				this->classrooms[i]->setId(this->id*6 + i + i);
			}
			for (i=3;i<6;i++){
				this->classrooms[i] = new JuniorClassroom();
				this->classrooms[i]->setId(this->id*6 + i + i);
			}
			this->corridor = new Corridor();
			type = "floor";
			cout << "Floor Created" << endl;
		}
		Floor::Floor(int classCapacity, int corridorCapacity){
			int i;
			//CREATING CLASSROOMS
			for (i=0;i<3;i++){
				this->classrooms[i] = new SeniorClassroom(classCapacity);
			}
			for (i=3;i<6;i++){
				this->classrooms[i] = new JuniorClassroom(classCapacity);
			}
			this->corridor = new Corridor(corridorCapacity);
			type = "floor";
			cout << "Floor Created" << endl;
		}
		Floor::~Floor(){
			int i;
			//DESTROYING CLASSROOMS
			for (i=0;i<6;i++){
				delete(this->classrooms[i]);
			}
			delete(this->corridor);
			cout << "Floor Destroyed" << endl;
		}
		void Floor::setId(int i){
			this->id = i;
		}
		int Floor::getId(){
			return this->id;
		}
		
		Corridor *Floor::getCorridor(){
			return this->corridor;
		}
		void Floor::addClassroom(Classroom *cl, int i){
			this->classrooms[i] = cl;
		}
		Classroom *Floor::getNClassroom(int n){
			return this->classrooms[n];
		}
		
		int Floor::insertStudent(Student *s){
			//WHEN STUDENT ARRIVES MOVES DIRECTLY TO CORRIDOR
			if (this->corridor!=NULL){
				return corridor->addStudent(s);
			}
			return 0;
		} 
		int Floor::addStudentToClassroom(Student *s){
			//MOVING STUDENT FROM CORRIDOR TO CLASS
			return this->corridor->addStudentToClass(this->classrooms[s->getClassroom()],s);
		}
		
		void Floor::print(){
			int i;
			cout<< "Floor number "<<this->id<<" contains:"<< endl;
			corridor->print();
			for (i=0;i<6;i++){
				this->classrooms[i]->print();
			}
		}
		
		void Floor::operates(int x){
			int i;
			for (i=0;i<6;i++){
				this->classrooms[i]->operates(x);
			}
		}
