#ifndef HUMAN_H
#define HUMAN_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include "config.h"


using namespace std;

class Human{
	protected : 
		//Human's ID
		int id;
		//Human's FULL NAME
		string fullName;
		//Human's CLASSROOM FLOOR
		int floor;
		//Human's CLASSROOM NUMBER ON THE FLOOR
		int classNumber;
		//Human's CURRENT LOCATION
		int location;
		//The humans physical status
		int physicalStatus;
		//working hours
		int attend;
	public :
		//CONSTRUCTORS
		Human();
		Human(string fn, int f, int c, int i);
		~Human();
		//SETTERS - GETTERS
		void setFullName(string fn);
		void setLocation(int loc);
		void setFloor(int flo);
		string getFullName();
		int getLocation();
		int getFloor();
		int getClassroom();
		int getId();
		int getPhysicalStatus();
		void setPhysicalStatus(int x);
		int getAttend();
		void setAttend(int x);
		//PRINTS STUDENT'S STATUS
		void print();
		//physical status computation is differenrt for each type of human (depending in L value)
		virtual void computePhysicalStatus() = 0;
		
		
};

#endif

