#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include "School.h"

#define NUMBER_OF_STUDENTS 100
#define MAX_NUMBER_OF_CLASSROOMS 100


int K;
int L;
int T1;
int T2;
Student *students[NUMBER_OF_STUDENTS];
School *school;

//MAKES THE SIMULATION
void init(){
	//EACH CLASS HAS THE SAME POPULATION
	int studentsPerClassroom = (NUMBER_OF_STUDENTS/K)+1;
	int counter = 0;
	srand(time(0));
	int i,j;
	school = new School();
	school->setThreshold1(T1);
	school->setThreshold2(T2);
	Classroom *classroom;
	Student *s1,*s2;
	//CREATING K CLASSROOMS AND ADDING THEN TO SCHOOL LIST
	for (i=0;i<K;i++){
		classroom = new Classroom(i);
		school->addClassroom(classroom);
	}
	//FOR EACH CLASSROOM
	for (i=0;i<K;i++){
		//ADDING STUDENTS IN CLASSROOM (IN PAIRS
		for (j=0;j<studentsPerClassroom/2;j++){
			//CHECKING IF THERE ARE ENOUGH STUDENT TO MAKE A PAIR OR WE HAVE REACHED TO THE END OF STUDENTS' ARRAY
			if (counter<NUMBER_OF_STUDENTS){
				students[counter++] = new Student(counter,'M',1);
				s1 = students[counter-1];
			}	
			else {
				s1 = NULL;
			}
			if (counter<NUMBER_OF_STUDENTS){
				students[counter++] = new Student(counter,'F',1);
				s2 = students[counter-1];
			}
			else {
				s2 = NULL;
			}
			if ((s1==NULL)&&(s2==NULL)){
				break;
			}
			//CREATING PAIR
			Pair *p = new Pair(s1,s2);
			//ADDING PAIR TO CLASSROOM
			classroom = school->getClassroom(i);
			if (classroom != NULL){
				classroom->getSequence()->addPair(p);
			}
			
		}
	}
	cout << "Students added to classrooms.\n"<< endl;
	cout << endl << endl;
	//PRINTIN SCHOOL STATUS
	school->print();
	cout << endl << endl;
	int z;
	//L ITERATIONS
	for (i=0;i<L;i++){
		//MAKE NOT QUIET KIDS (NUMBER Z)
		z = rand()%NUMBER_OF_STUDENTS;
		cout << "z = " << z << endl;
		school->changeStatus(z, students, NUMBER_OF_STUDENTS);
		//MAKING APPROPRIATE SWAPS
		school->fixIt();
		cout << endl << endl;
		//PRINTING THE NEW SCHOOL STATUS
		school->print();
	}
	
}

int main(int argc, char** argv) {
	//READING COMMAND LINE ARGUMENTS
	if (argc==5){
		K = atoi(argv[1]);
		L = atoi(argv[2]);
		T1 = atoi(argv[3]);
		T2 = atoi(argv[4]);
		init();
	}
	else {
		cout << "Parameters K L T1 T2" << endl;
	}
	
	
	return 0;
}
