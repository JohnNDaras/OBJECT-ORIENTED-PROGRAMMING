#include "Building.h"

		Building::Building(){
			int i;
			//CREATING FLOORS
			for (i=0;i<3;i++){
				floors[i] = new Floor();
			}
			//CREATING YARD
			yard = new Yard();
			//CREATING STAIRS
			stairs = new Stairs();
			cout << "Building created" << endl;
		}
		Building::Building(int yardCapacity, int stairsCapacity, int classCapacity, int corridorCapacity){
			int i;
			cout << "Going to create floors"<<endl;
			//CREATING FLOORS;
			for (i=0;i<3;i++){
				floors[i] = new Floor(classCapacity, corridorCapacity);
				floors[i]->setId(i+1);
			}
			//CREATING YARD
			yard = new Yard(yardCapacity);
			//CREATING STAIRS
			stairs = new Stairs(stairsCapacity);
			cout << "New School has been created!" << endl;
		}
		Building::~Building(){
			int i;
			cout << "A School to be destroyed!" << endl;
			//DESTROYING STAIRS
			for (i=0;i<3;i++){
				delete(floors[i]);
			}
			//DESTROYING YARD
			delete(yard);
			//DESTROYING STAIRS
			delete(stairs);
			
		}
		void Building::place(Teacher *s){
			Classroom *c;
			Floor *f;
			//GETTING FLOOR - CLASSROOM
			f = this->floors[s->getFloor()];
			c = f->getNClassroom(s->getClassNumber());
			c->insertTeacher(s);//INSERTING
			s->setLocation(locationClassroom);//CHANGING LOCATION
		}
		
		void Building::print(){
			int i;
			yard->print();
			stairs->print();
			for (i=0;i<3;i++){
				floors[i]->print();
			}
		}
		
		int Building::addStudent(Student *s){
			return this->yard->addStudent(s);
		}
		
		Yard *Building::getYard(){
			return this->yard;
		}
		Stairs *Building::getStairs(){
			return this->stairs;
		}
		
		Floor *Building::getFloor(int i){
			return this->floors[i];
		}
