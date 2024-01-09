CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: sim3

Building.o: Building.cpp Building.h
	$(CXX) $(CXXFLAGS) -c Building.cpp

Human.o: Human.cpp Human.h
	$(CXX) $(CXXFLAGS) -c Human.cpp

Classroom.o: Classroom.cpp Classroom.h
	$(CXX) $(CXXFLAGS) -c Classroom.cpp
	
Corridor.o: Corridor.cpp Corridor.h
	$(CXX) $(CXXFLAGS) -c Corridor.cpp
	
Floor.o: Floor.cpp Floor.h
	$(CXX) $(CXXFLAGS) -c Floor.cpp
	
Student.o: Student.cpp Student.h
	$(CXX) $(CXXFLAGS) -c Student.cpp
	
Teacher.o: Teacher.cpp Teacher.h
	$(CXX) $(CXXFLAGS) -c Teacher.cpp

Yard.o: Yard.cpp Yard.h
	$(CXX) $(CXXFLAGS) -c Yard.cpp
	
Stairs.o: Stairs.cpp Stairs.h
	$(CXX) $(CXXFLAGS) -c Stairs.cpp

sim3: Human.o Building.o Classroom.o Corridor.o Floor.o Student.o Teacher.o Yard.o Stairs.o main.cpp
	$(CXX) $(CXXFLAGS) -o sim3 Human.o Building.o Classroom.o Corridor.o Floor.o Student.o Teacher.o Yard.o Stairs.o main.cpp -lm 
	
splint:
	splint Building.cpp Human.cpp Classroom.cpp Corridor.cpp Floor.cpp Student.cpp Teacher.cpp Yard.cpp Stairs.cpp main.cpp
	
run:
	./sim3
	
clean:
	rm -f sim3 *.o
	
