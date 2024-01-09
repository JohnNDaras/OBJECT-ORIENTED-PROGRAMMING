#ifndef YARD_H
#define YARD_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Place.h"
#include "Stairs.h"
#include "Student.h"

using namespace std;

class Yard : public Place {
private:
    //ARRAY CONTAINING STUDENTS IN THE YARD
    Student *studentsIn[MAX_ARRAY_SIZE];
    //NUMBER OF STUDENT IN THE YARD
    int numberOfStudentsIn;
    //YARD CAPACITY
    int capacity;

public:
    //CONSTRUCTORS
    Yard();
    Yard(int c);
    virtual ~Yard(); // Declare the destructor as virtual
    //SETTERS - GETTERS 
    void setCapacity(int c);
    int getCapacity();
    //ADDS STUDENT S TO THE YARD
    int addStudent(Student *s);
    //ADDS STUDENT S TO STAIRS
    int addStudentToStairs(Stairs *st, Student *s);
    //PRINTS YARD STATUS
    void print();
    //yard operatin for x hours
    void operates(int x) {};
};

#endif
