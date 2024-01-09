#ifndef JUNIORCLASSROOM_H
#define JUNIORCLASSROOM_H

#include "Classroom.h"
//Classroom for junior students
class JuniorClassroom : public Classroom {
	private:
		
	public:
		JuniorClassroom():Classroom(){
			classroomtype = "Junior Classroom";
		}
		JuniorClassroom(int c):Classroom(c){
			classroomtype = "Junior Classroom";
		}
};


#endif
