all: sim2

Classroom.o: Classroom.cpp Classroom.h
	g++ -c -o Classroom.o -Wall -Wextra -pedantic -std=c++11 Classroom.cpp

Pair.o: Pair.cpp Pair.h
	g++ -c -o Pair.o -Wall -Wextra -pedantic -std=c++11 Pair.cpp

School.o: School.cpp School.h
	g++ -c -o School.o -Wall -Wextra -pedantic -std=c++11 School.cpp

Sequence.o: Sequence.cpp Sequence.h
	g++ -c -o Sequence.o -Wall -Wextra -pedantic -std=c++11 Sequence.cpp

Student.o: Student.cpp Student.h
	g++ -c -o Student.o -Wall -Wextra -pedantic -std=c++11 Student.cpp

sim2: Classroom.o Pair.o School.o Sequence.o Student.o main.cpp
	g++ -o sim2 Classroom.o Pair.o School.o Sequence.o Student.o main.cpp -lm

splint:
	splint Classroom.cpp Pair.cpp School.cpp Sequence.cpp Student.cpp main.cpp

run:
	./sim2

clean:
	rm -f sim2 *.o

