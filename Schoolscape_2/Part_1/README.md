**Schoolscape 2: C++ Implementation of School Dynamics**


Compilation:

    make all

Run: 

    ./sim2 number1 number2 (i.e. ./sim2 20 1 2 3)
    ./sim2

The purpose of this exercise is to practice in inheritance, virtual functions, and abstract classes. The scenario is a variation of the world described in the First Exercise of Exercise Group A.

Implement in C++ a simulation of students' morning arrival at a school building and their entry into classrooms (the term "classroom" in the statement corresponds to the term "class" in the First Exercise).

The school building consists of three floors, a courtyard, and a staircase. Each floor has six classrooms and a corridor. Each classroom can accommodate up to C class students and one teacher.

The information for a student includes their name, class details (floor number and classroom number), an indication of whether they are in their classroom or not, and a fatigue level counter.

The information for a teacher includes their name, class details, an indication of whether they are in their classroom or not, and a fatigue level counter.

Students are divided into two categories: "junior" and "senior" students. Students attend classes for a certain duration (number of hours). For each hour of attendance, the fatigue level of junior students increases by Lj units, while the fatigue level of senior students increases by Ls units.

Teachers teach for a certain number of hours, and for each teaching hour, their fatigue level increases by Lt units.

Students enter the school building one by one. A student enters the school building (enters) by printing their name accompanied by the message "... enters school!" and entering the courtyard. Then they exit the courtyard and enter the staircase. After that, they exit the staircase and enter the floor of their class.

The entrance of a student into the courtyard (enter) is done by printing their name accompanied by the message "... enters schoolyard!". A student exits the courtyard (exit) by printing their name accompanied by the message "... exits schoolyard!" and becomes available to the environment that triggered the exit.

The entrance of a student into the staircase (enter) is done by printing their name accompanied by the message "... enters stairs!". A student exits the staircase (exit) by printing their name accompanied by the message "... exits stairs!" and becomes available to the environment that triggered the exit.

A student enters a floor (enter) by printing their name accompanied by the message "... enters floor!" and enters the corridor of the floor. Then they exit the corridor and enter the classroom of their class.

A student enters the corridor (enter) by printing their name accompanied by the message "... enters corridor!". A student exits the corridor (exit) by printing their name accompanied by the message "... exits corridor!" and becomes available to the environment that triggered the exit.

A student enters their classroom (enter) by printing their name and the message "...enters classroom!" and is added to the students of that classroom (no check is made if there is already a teacher in the classroom). Now the relevant indication states that they are within their class.

A teacher is considered to be placed in the school building. This is done by placing the teacher on the floor corresponding to their class. The latter is achieved by placing the teacher in their classroom. Now the teacher's relevant indicator indicates that they are within their class.

Both the school building and the floors, as well as the classrooms, are assumed to operate for a certain duration (number of hours). The school building operates for some hours, operating its floors during those hours. A floor operates for some hours, operating its classrooms during those hours. When a classroom operates for some hours, students attend classes during those hours, and their teacher teaches during those hours.

We can print the school building by printing the message "School life consists of: " and printing the floors. Print a floor by printing the message " Floor number " ⟨floor number⟩ " contains: " and printing the classrooms in it. Print a classroom by printing the message "People in class " ⟨class number⟩ are: " and printing the students and the teacher in it. Print a student by printing their name and the value of their fatigue level. The same elements are printed when printing a teacher; it just prints the message "The teacher is:" before.

When a school building is created, the message "A New School has been created!" is printed. Corresponding messages are printed when the courtyard, the staircase, the floors, the corridors, and the classrooms are created. Initially, the classrooms are empty.

When the school building is destroyed, the message "A School to be destroyed!" is printed. Corresponding messages are printed when the courtyard, the staircase, the floors, the corridors, and the classrooms are destroyed.

When a new student is created, they are initialized with their details. Initially, they are outside the classroom, and their fatigue level counter has a value of zero. Also, the message "A New Student has been created!" is printed, along with their name and class details. When a student is destroyed, the message "A Student to be destroyed!" and their details are printed.

When a new teacher is created, they are initialized with their details. Initially, they are outside the classroom, and their fatigue level counter has a value of zero. Also, the message "A New Teacher has been created!" is printed, along with their name and class details. When a teacher is destroyed, the message "A Teacher to be destroyed!" and their details are printed.

From the above description, you will notice that many entities in this world share common characteristics/functionality. For example, there is a more general (and abstract) concept of "space" where students enter and exit. Also, both teachers and different types of students are specializations of "people" with variations in functionality.

Given the above description, we implement the appropriate classes for the described world, leveraging inheritance where necessary. Also, implement a main function where: \
A school building is created. \
Students and teachers are created. \
Students enter, and teachers are placed in the school building in random order. \
The school building operates for N hours. \
The school building is printed. 

The parameters Cclass, Lj, Ls, Lt, and N should be provided in that order from the command line.

Note 1: Consider that on each floor, three classrooms accommodate senior classes, and three accommodate junior classes. The only reason for making this distinction is to establish the appropriate correlation between students and classrooms during student creation. There is no differentiation regarding the classrooms themselves.

Note 2: In this exercise, we use library types we believe they are suitable .
