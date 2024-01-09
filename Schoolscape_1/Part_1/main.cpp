#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>


#include "config.h"
#include "Building.h"


using namespace std;
/*
There are 3 floors 
There are 3 x 6 = 18 classrooms
There are 18 teachers
Therea are 3 X 6 X Cclass students
*/
//SIMULATION PARAMETERS GETTING DEFAULT VALUES
int Cclass = 25;
int Cstairs = 10;
int Ccorridor = 10;
int Cyard = 150;
int TotalNumberOfStudents;
int TotalNumberOfTeachers;
//NAMES TO BE USED TO CONSTRUCT RANDOM FULLNAMES FOR STUDENTS AND TEACHERS
string firstNames[] = {"Jerry","Manos","John","Mary","Bill","Zoe","Ann","Jim","Mel","George","Georgia","Philip","Kostas","Olga","Marios"};
string lastNames[] = {"Black","Smith","White","Mos","Bell","Zeus","Antams","Jimer","Melow","Georgan","Georgian","Philipou","Kostaras","Olia","Mara"};
//CREATES RANDOM FULLNAME
string makeRandomFullname(int max){
	return firstNames[rand()%max]+" "+lastNames[rand()%max];
}
//IT RETURNS 1 IF THERE ARE STUDENTS HAVING NOT BEEN INSERTED IN THE BUILDING
//RETURNS 0 OTHERWISE
int thereAreStudentsOut(Student *AllStudents[]){
	int i;
	for (i=0;i<TotalNumberOfStudents;i++){
		if (AllStudents[i]->getLocation() == locationOut){
			return 1;
		}
	}
	return 0;
}
//IT RETURNS 1 IF THERE ARE STUDENTS HAVING NOT BEEN INSERTED IN THE BUILDING
//RETURNS 0 OTHERWISE
int thereAreTeachersOut(Teacher *AllTeachers[]){
	int i;
	for (i=0;i<TotalNumberOfTeachers;i++){
		if (AllTeachers[i]->getLocation() == locationOut){
			return 1;
		}
	}
	return 0;
}
int main(int argc, char** argv) {
	int stds;
	int tchs;
	//READING COMMAND LINE ARGUMENTS
	if (argc==5){
		Cclass = atoi(argv[1]);
		Cyard = atoi(argv[2]);
		Cstairs = atoi(argv[3]);
		Ccorridor = atoi(argv[4]);
	}
	else {
		cout << "Default values are going to be used!" << endl;
	}
	srand(time(0));
	//COMPUTING NUMBER OF STUDENTS AND TEACHERS FOR FILLING ALL CLASSROOMS OF THE BUILDING
	TotalNumberOfStudents = 3*6*Cclass;
	TotalNumberOfTeachers = 18;
	//CREATING ARRAYS FOR STORING STUDENTS AND TEACHERS
	Teacher *AllTeachers[TotalNumberOfTeachers];
	Student *AllStudents[TotalNumberOfStudents];
	int flr;
	int cls;
	//CREATING STUDETNS COMPUTING THE FLOOR AND THE CLASSROOM TO BE PLACED
	for (stds=0;stds<TotalNumberOfStudents;stds++){
		flr = stds % 18;
		cls = stds % 18;
		flr = flr / 6;
		cls = cls%6; 
		cout << "Class:" << cls << endl;
		AllStudents[stds] = new Student(makeRandomFullname(15),flr,cls,stds);
	}
	//CREATING TEACHERS COMPUTING THE FLOOR AND THE CLASSROOM TO BE PLACED
	for (tchs=0;tchs<TotalNumberOfTeachers;tchs++){
		flr = tchs / 6;
		cls = tchs%6; 
		AllTeachers[tchs] = new Teacher(makeRandomFullname(15),flr,cls,tchs);
	}
	//creating building
	Building *building = new Building(Cyard,Cstairs,Cclass,Ccorridor);
	do{
		//A STUDENT CHOSEN RANDOMLY INSERTS
		stds = rand() % TotalNumberOfStudents;
		while (AllStudents[stds]->getLocation()!=locationOut){
			stds = rand() % TotalNumberOfStudents;
		}
		//TEACHERS ARE COMIN IN WITH POSIBILITY OF 20%
		//THEY ARE GOING DIRECTLY TO THEIR CLASSROOM
		if ((thereAreTeachersOut(AllTeachers))&&(rand()%100<20)){
			tchs = rand()%TotalNumberOfTeachers;
			cout << tchs << endl;
			building->place(AllTeachers[tchs]);
		}
		//IF STUDENTS INSERTS BUILDING
		if (building->addStudent(AllStudents[stds])){
			//INSERTING THE BUILDING -> INSERTS DIRECTLY YARD --> INSERTS DIRECTLY TO STAIRS (IF THERE IS ENAOUGH SPACE)
			if (building->getYard()->addStudentToStairs(building->getStairs(),AllStudents[stds])){
				//IF STUDENTS INSERTS FLOOR (IF THERE IS ENAOUGH SPACE)
				if (building->getStairs()->addStudentToFloor(building->getFloor(AllStudents[stds]->getFloor()),AllStudents[stds])){
					//IF STUDENTS INSERTS CLASSROOM (IF THERE IS ENOUGH SPACE)
					if (building->getFloor(AllStudents[stds]->getFloor())->addStudentToClassroom(AllStudents[stds])){

					}	
				}
			}
		}
		//IF ALL TEACHERS HAVE ENTERED CLASSROOMS , NO STUDENT CAN ENTER . THIS IS THE END OF SIMULATION
		if (thereAreTeachersOut(AllTeachers)==0){
			break;
		}
	} while ((thereAreTeachersOut(AllTeachers)) || (thereAreStudentsOut(AllStudents)));//SIMULATION ENDS WHEN ALL STUDENTS ENTERED OR ALL TEACHERS ENTERED
	//PRINTING BUILDING STATUS
	building->print();
	delete(building);
	return 0;
}
