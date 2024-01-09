package myschool;

import static myschool.Configuration.MAX_ARRAY_SIZE;
import static myschool.Configuration.locationOut;
import static myschool.Configuration.locationYard;

public class Yard extends Place {

    //ARRAY CONTAINING STUDENTS IN THE YARD
    private Student[] studentsIn;
    //NUMBER OF STUDENT IN THE YARD
    private int numberOfStudentsIn;
    //YARD CAPACITY
    private int capacity;

    public Yard() {
        int i;
        this.numberOfStudentsIn = 0;
        this.capacity = 0;
        this.type = "yard";
        System.out.println("Yard constructed");

    }

    public Yard(int c) {
        int i;
        this.numberOfStudentsIn = 0;
        this.capacity = c;
        this.type = "yard";
        this.studentsIn = new Student[MAX_ARRAY_SIZE];
        for (i = 0; i < MAX_ARRAY_SIZE; i++) {
            this.studentsIn[i] = null;
        }
        System.out.println("Yard constructed");

    }

    public int addStudent(Student s) {
        if (this.numberOfStudentsIn < this.capacity) {//IF THERE IS ENOUGH SPACE
            //Entering school
            System.out.println(s.getFullName() + " enters school.");
            //Entering yard
            System.out.println(s.getFullName() + " enters schoolyard.");
            s.setLocation(locationYard);
            this.studentsIn[this.numberOfStudentsIn++] = s;
            return 1;
        }
        return 0;
    }

    public int addStudent(Student s, int x) {
        if (this.numberOfStudentsIn < this.capacity) {//IF THERE IS ENOUGH SPACE
            //Entering yard
            System.out.println(s.getFullName() + " enters schoolyard.");
            s.setLocation(locationYard);
            this.studentsIn[this.numberOfStudentsIn++] = s;
            return 1;
        }
        return 0;
    }

    public void print() {
        System.out.println("People in yard are:");
        int i;
        for (i = 0; i < this.numberOfStudentsIn; i++) {
            studentsIn[i].print();
        }
    }

    public int getCapacity() {
        return this.capacity;
    }

    public void setCapacity(int c) {
        this.capacity = c;
    }

    public int addStudentToStairs(Stairs st, Student s) {
        int i;
        //IF STUDENT IS NOT IN THE YARD DO NOTHING
        for (i = 0; i < this.numberOfStudentsIn; i++) {
            if (this.studentsIn[i].getId() == s.getId()) {
                break;
            }
        }
        if (i >= this.numberOfStudentsIn) {
            return 0;
        }
        //ADDS TO STAIRS
        if (st.addStudent(s) == 1) {

            //EXITS - REPLACE CURRENT STUDENT WITH THE LAST IN THE ARRAY
            this.studentsIn[i] = this.studentsIn[this.numberOfStudentsIn - 1];
            this.studentsIn[this.numberOfStudentsIn - 1] = null;
            this.numberOfStudentsIn--;
        } else {
            return 0;
        }
        return 1;
    }

    public Student exit() {
        if (this.numberOfStudentsIn > 0) {
            Student s = studentsIn[--numberOfStudentsIn];
            System.out.println(s.getFullName() + " exits yard!");
            System.out.println(s.getFullName() + " exits building!");
            s.setLocation(locationOut);
            return s;
        }
        return null;
    }
}
