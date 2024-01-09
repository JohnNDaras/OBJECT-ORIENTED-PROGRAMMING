all: Building.o Classroom.o Corridor.o Floor.o Student.o Teacher.o Yard.o Stairs.o sim1

Building.o: Building.cpp
	g++ -c Building.cpp

Classroom.o: Classroom.cpp
	g++ -c Classroom.cpp

Corridor.o: Corridor.cpp
	g++ -c Corridor.cpp

Floor.o: Floor.cpp
	g++ -c Floor.cpp

Student.o: Student.cpp
	g++ -c Student.cpp

Teacher.o: Teacher.cpp
	g++ -c Teacher.cpp

Yard.o: Yard.cpp
	g++ -c Yard.cpp

Stairs.o: Stairs.cpp
	g++ -c Stairs.cpp

sim1: Building.o Classroom.o Corridor.o Floor.o Student.o Teacher.o Yard.o Stairs.o main.cpp
	g++ -o sim1 Building.o Classroom.o Corridor.o Floor.o Student.o Teacher.o Yard.o Stairs.o main.cpp -lm

splint:
	splint Building.cpp Classroom.cpp Corridor.cpp Floor.cpp Student.cpp Teacher.cpp Yard.cpp Stairs.cpp main.cpp

run:
	./sim1

clean:
	rm -f sim1 *.o
