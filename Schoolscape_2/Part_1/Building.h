#ifndef BUILDING_H
#define BUILDING_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Place.h"
#include "Floor.h"
#include "Stairs.h"
#include "Yard.h"

using namespace std;

class Building{
	private :
		Floor *floors[3]; //BUILDING CONSIST OF 3 FLOORS
		Yard *yard; //CONTAINING ONE YARD
		Stairs *stairs; //CONTAINING STAIRS
	public :
		//CONSTRUCTORS
		Building();
		Building(int yardCapacity, int stairsCapacity, int classCapacity, int corridorCapacity);
		//DESTRUCTOR
		~Building();
		//ADDS STUDENT TO BUILDING
		int addStudent(Student *s);
		//GETTERS		
		Yard *getYard();
		Stairs *getStairs();
		Floor *getFloor(int i);
		//ADD THE TEACHER TO HIS CLASSROOM
		void place(Teacher *s);
		//PRINTS BUIDING STATUS
		void print();
		
		void operates(int x);
		
};

#endif

