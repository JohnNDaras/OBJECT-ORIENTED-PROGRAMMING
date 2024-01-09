#ifndef PLACE_H
#define PLACE_H
#include <string>
using namespace std;
//it's the root class for teachers and students
class Place {
	protected : 
		string type;
	public :
		Place(){
			type = "-";
		};
		Place(string s) { 
			type = s;
		};
		//print functin is being defined to the children classes
		virtual void print() = 0;
		//operate function is being defined to children classes
		virtual void operates(int x) = 0;
};

#endif

