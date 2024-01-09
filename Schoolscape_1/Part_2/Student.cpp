#include "Student.h"

Student::Student(){
	this->id = 0;
	this->gender = '-';
	this->quiet = 0;
}
Student::~Student(){
	
}
Student::Student(int i, char g, int q){
	this->id = i;
	this->gender = g;
	this->quiet = q;
	cout << "Student " << i << " created" << endl;
}
void Student::setQuiet(int q){
	this->quiet = q;
}
int Student::getQuiet(){
	return this->quiet;
}
void Student::setGender(char g){
	this->gender = g;
}
char Student::getGender(){
	return this->gender;
}
void Student::print(){
	cout << id << " - " << gender << " - " << quiet << endl;
}

