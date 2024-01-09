#ifndef SENIORCLASSROOM_H
#define SENIORCLASSROOM_H

#include "Classroom.h"
//classroom for senior students
class SeniorClassroom : public Classroom {
	private:
		
	public:
		SeniorClassroom():Classroom(){
			classroomtype = "Senior Classroom";
		}
		SeniorClassroom(int c):Classroom(c){
			classroomtype = "Senior Classroom";
		}
};


#endif
