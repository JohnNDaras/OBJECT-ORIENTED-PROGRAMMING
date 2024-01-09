**"Schoolscape: A C++ Simulation of Orderly Movement in Kindergarten Sections and Disorder Handling"**


Compilation:

    make all

Run: 
    ./sim2 number1 number2 (i.e. ./sim2 100 500)

We implement in C++ a simulation of the movement of kindergarten students between sections. We consider that each section has the same number of boys and girls, unless it involves an odd number, in which case there is one more boy or one more girl. In this station, to avoid disorder, when the children of a section are about to move, they form a sequence of pairs. Assuming that girls are quieter than boys, the pairs are boy-girl. Additionally, the boy in the pair, in the corresponding position of the pairs in front and behind, has girls (and one girl, respectively). The sequence is characterized by the section number, e.g., an integer. It is initialized by placing the students of the section in the appropriate position.

When all sections are to be moved, their sequences succeed each other. You can see a depiction of a sequence of two sections in Figure 1. If two sections have an odd number of students but the excess students form boy-girl pairs, they enter as a pair in the sequence of the first section.

However, disorders may arise. If individual students create disorders, they are matched with others of the same gender randomly selected from their section sequence. If it's one or two pairs, the same process is applied to the students who constitute them. If, however, there are more pairs and the pairs are consecutive, the matching occurs between students of different sections, and they are distributed to the other sections. If disorderly pairs are scattered, students are matched with students from the next section. Each section is characterized by a disorder level counter of its students. For each matching of students, the counter of the section to which the student who caused the mismatch belongs increases by one level. If mismatches occur between sections, the increase is double. Initially, each section has a zero disorder level.

Each student is characterized and initialized by their name, section, and gender. The option to print these details is provided.

The option to print the sequence of sections is given by printing their sequences. A section sequence is printed by printing the pairs that constitute it. A pair is printed by printing its position in the sequence and the students in it. When printing the section sequence, if the disorder level is below a percentage of its students, Tquiet, the message "What a quiet class!" is printed. If it is above another (larger) percentage, Tmessy, the message "What a mess!" is printed. In any other case, the message "Please, be quiet!" is printed. The percentages are parameters of the simulation and are provided from the command line.

Implement the above through appropriate classes, where needed, which are related to functions achieving the described procedures.

Also, we implement a main function in which: 

It creates a set of students belonging to K sections. \
It generates sequences for the sections to which they belong. \
It creates the sequence of sections. \
It prints this sequence. \
For L times, randomly select random students to create disorders. For each student, print their details, take the necessary actions, and print the sequences affected by these actions. \
Finally, print the sequence of sections as it has been modified. \
The parameters K and L, as well as the thresholds for the percentages, Tquiet and Tmessy, should be provided from the command line in that order. \

Note: In implementing the exercises of Group A, the only type of library types allowed to be used is the string type."
