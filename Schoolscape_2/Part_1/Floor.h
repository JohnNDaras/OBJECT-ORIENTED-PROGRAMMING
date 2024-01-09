#ifndef FLOOR_H
#define FLOOR_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Place.h"
#include "SeniorClassroom.h"
#include "JuniorClassroom.h"
#include "Corridor.h"

using namespace std;

class Floor : public Place {
private:
    //FLOOR ID
    int id;
    //ARRAY CONTAINING CLASSROOMS
    Classroom *classrooms[6];
    //THE FLOOR CORRIDOR
    Corridor *corridor;

public:
    //CONSTRUCTORS
    Floor();
    Floor(int classCapacity, int corridorCapacity);
    virtual ~Floor(); // Declare the destructor as virtual
    //SETTERS - GETTERS
    void setId(int i);
    int getId();
    Corridor *getCorridor();
    //INSERTS STUDENT S TO THE FLOOR
    int insertStudent(Student *s);
    //ADDS CLASSROOM C ON THE FLOOR (IT IS THE I-TH CLASSROOM)
    void addClassroom(Classroom *cl, int i);
    //ADDS STUDENT S ON THE FLOOR
    int addStudentToClassroom(Student *s);
    //RETURNS THE N-TH CLASSROOM
    Classroom *getNClassroom(int n);
    //PRINTS THE FLOOR STATUS
    void print();
    //floor operation for x hours
    void operates(int x);
};

#endif

