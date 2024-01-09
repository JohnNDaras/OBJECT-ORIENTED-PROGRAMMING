                                                Schoolscape: Modeling Student Arrival and Classroom Allocation in C++


Compilation:

    make all

Run: 

    ./sim1 20 10 10 10

    ./sim1

The purpose of this exercise is to practice in construction-destruction functions and class composition. This is an implementation in C++ of a simulation of the morning arrival of students in a school building and their entry into classrooms.

The school building consists of three floors, a courtyard, and a staircase. Each floor has six classrooms and a corridor. Each classroom can accommodate up to C class students and one teacher. If the teacher is in the classroom, no other student can enter. Each student is characterized by their name, class details (floor number and class number), and an indication of their location (courtyard, staircase, corridor, classroom, outside the school building). The teacher's details include their name, class details, and an indication of whether they are inside the classroom.

The courtyard, staircase, and the corridors of the floors have a maximum capacity of Cyard, Cstair, and Ccorr, respectively. At any given moment, there may be students in these areas. All corridors have the same capacity.

Students enter the school building (enter) one by one as many as can fit. Then, students exit the courtyard and enter the staircase, as many as can fit in it. After that, students exit the staircase and enter the floors of their classrooms, as many as can fit on each floor.

A student enters the school building (enter) by printing their name accompanied by the message "... enters school!" and entering the courtyard if there is space. The entrance of a student to the courtyard (enter) is printed by their name accompanied by the message "... enters schoolyard!" and is included in the students of the courtyard. The first student who can exit the courtyard (exit) prints their name accompanied by the message "... exits schoolyard!", is removed from the students in the courtyard, and becomes available to the environment that caused the exit.

The entrance of a student to the staircase (enter) is printed by their name accompanied by the message "... enters stairs!" and is included in the students of the staircase. A student exits the staircase (exit) by printing their name accompanied by the message "... exits stairs!", is removed from the students in the staircase, and becomes available to the environment that caused the exit.

A student enters a floor (enter) by printing their name accompanied by the message "... enters floor!" and entering the corridor of the floor if there is space. A student enters the corridor (enter) by printing their name accompanied by the message "... enters corridor!" and is added to the students of that corridor. A student exits the corridor (exit) by printing their name accompanied by the message "... exits corridor!", is removed from the students in the corridor, and becomes available to the environment that caused the exit.

A student enters their classroom (enter) if their teacher is not already in it. Upon entering the classroom, their name is printed, and the message "...enters classroom!" is printed, and they are added to the students of that classroom.

A teacher is considered to be placed instantly in their classroom (place) in the school building—individual entrance steps to the building do not precede them. This is done through their placement (place) on the floor to which their class belongs. The latter is accomplished by placing them in the class (place).

We can print the school building (print) by printing the message "School life consists of: " and then printing the courtyard, the staircase, and the floors. Print the courtyard (print) by printing the message "People in schoolyard are: " and printing the students in it. Print the staircase (print) by printing the message "People in stairs are: " and printing the students in it. Print a floor (print) by printing the message "Floor number " ⟨floor number⟩ " contains: " and printing the corridor and the classrooms in it. Print the corridor (print) by printing the message "People in corridor are: " and printing the students in it. Print a class (print) by printing the message "People in class " ⟨class number⟩ " are: " and printing the students and the teacher in it. We print a student (print) by printing their name. The same elements are printed when printing a teacher (print), just preceded by the message "The teacher is:".

When a school building is created, the message "A New School has been created!" is printed, and the capacities of the classrooms, the courtyard, the staircase, and the corridors are defined. Corresponding messages are printed when the courtyard, the staircase, the floors, the corridors, and the classrooms are created. Initially, the courtyard, the staircase, and the classrooms are empty.

When the school building is destroyed, the message "A School to be destroyed!" is printed. Corresponding messages are printed when the courtyard, the staircase, the floors, the corridors, and the classrooms are destroyed.

When a new student is created, they are initialized with their details and an indication that they are outside the school building. Also, the message "A New Student has been created!" is printed along with their name and class details. When a student is destroyed, the message "A Student to be destroyed!" is printed, along with their details and location.

When a new teacher is created, they are initialized with their details and an indication that they are outside the class. Also, the message "A New Teacher has been created!" is printed along with their name and class details. When a teacher is destroyed, the message "A Teacher to be destroyed!" is printed, along with their details.

Implement the above through the appropriate classes, defining the data members needed and the functions/methods that implement the described behavior. Also, implement a main function in which:

  A school building is created.
  Students and teachers are created.
  The following process is repeated until either all students are in their classrooms or no other student can enter:
  (a) Students enter the school building in random order.
  (b) Randomly decide whether teachers are placed in their classrooms—if positive, the selection of teachers for placement is random again.
  Print the school building.

The values of Cclass, Cyard, Cstair, and Ccorr should be provided from the command line in that order.

(Note: The only type of library types we use is the string type.)
