package myschool;

import static myschool.Configuration.MAX_ARRAY_SIZE;
import static myschool.Configuration.locationCorridor;
import static myschool.Configuration.locationStairs;
import static myschool.Configuration.locationYard;


public class Stairs extends Place {
    //ARRAY CONTAINING THE STUDENTS ON STAIRS

    private Student[] studentsIn;
    //THER NUMBER OF STUDENTS ON STAIRS
    private int numberOfStudentsIn;
    //THE STAIRS CAPACITY
    private int capacity;

    public Stairs() {
        int i;
        studentsIn = new Student[MAX_ARRAY_SIZE];
        this.capacity = 0;
        this.numberOfStudentsIn = 0;
        type = "stairs";
        System.out.println("Stairs constructed");
    }

    public Stairs(int c) {
        int i;
        this.numberOfStudentsIn = 0;
        this.capacity = c;
        this.studentsIn = new Student[MAX_ARRAY_SIZE];
        for (i = 0; i < MAX_ARRAY_SIZE; i++) {
            this.studentsIn[i] = null;
        }
        type = "stairs";
        System.out.println("Yard constructed");
    }

    public int addStudent(Student s) {
        if (this.numberOfStudentsIn < this.capacity) {
            System.out.println(s.getFullName() + " exits schoolyard");
            System.out.println(s.getFullName() + " enters stairs");
            s.setLocation(locationStairs);//CHANGING LOCATION
            this.studentsIn[this.numberOfStudentsIn++] = s;
            return 1;
        }
        return 0;
    }
    public int addStudent(Student s, int x) {
        if (this.numberOfStudentsIn < this.capacity) {
            System.out.println(s.getFullName() + " enters stairs");
            s.setLocation(locationStairs);//CHANGING LOCATION
            this.studentsIn[this.numberOfStudentsIn++] = s;
            return 1;
        }
        return 0;
    }

    public int getCapacity() {
        return this.capacity;
    }

    public void setCapacity(int c) {
        this.capacity = c;
    }

    public int addStudentToFloor(Floor f, Student s) {
        int i;
        //IF STUDENT IS NOT ON STAIRS DO NOTHING
        for (i = 0; i < this.numberOfStudentsIn; i++) {
            if (this.studentsIn[i].getId() == s.getId()) {
                break;
            }
        }
        if (i >= this.numberOfStudentsIn) {
            return 0;
        }
        if (f.insertStudent(s) == 1) {

            //EXITS - RAPLACE CUURENT STUDENT WITH THE LAST ONE IN ARRAY
            this.studentsIn[i] = this.studentsIn[this.numberOfStudentsIn - 1];
            this.studentsIn[this.numberOfStudentsIn - 1] = null;
            this.numberOfStudentsIn--;
        } else {
            return 0;
        }
        return 1;
    }

    public void print() {
        System.out.println("People in stairs are:");
        int i;
        for (i = 0; i < this.numberOfStudentsIn; i++) {
            studentsIn[i].print();
        }
    }
    
    public Student exit(){
        if (this.numberOfStudentsIn > 0){
            Student s = studentsIn[--numberOfStudentsIn];
            System.out.println(s.getFullName()+" exits stairs!");
            s.setLocation(locationYard);
            return s;
        }
        return null;
    }
}
