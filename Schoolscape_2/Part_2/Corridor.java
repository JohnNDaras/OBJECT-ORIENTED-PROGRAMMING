package myschool;

import static myschool.Configuration.MAX_ARRAY_SIZE;
import static myschool.Configuration.locationCorridor;

public class Corridor extends Place {
    //ARRAY CONTAINING STUDENTS IN THE CORRIDOR

    private Student[] studentsIn;
    //NUMBER OF STUDENTS IN CORRIDOR
    private int numberOfStudentsIn;
    //THE CORRIDOR CAPACITY
    private int capacity;

    public Corridor() {
        int i;
        this.numberOfStudentsIn = 0;
        this.capacity = 0;
        this.studentsIn = new Student[MAX_ARRAY_SIZE];
        System.out.println("Corridor constructed");
        type = "corridor";
    }

    public Corridor(int c) {
        int i;
        this.numberOfStudentsIn = 0;
        this.capacity = c;
        this.studentsIn = new Student[MAX_ARRAY_SIZE];
        for (i = 0; i < MAX_ARRAY_SIZE; i++) {
            this.studentsIn[i] = null;
        }
        type = "corridor";
        System.out.println("Corridor constructed");
    }

    public int addStudent(Student s) {
        if (this.numberOfStudentsIn < this.capacity) {//IF THERE IS ENOUGH SPACE
            System.out.println(s.getFullName() + " exits stairs");
            System.out.println(s.getFullName() + " enters floor");
            System.out.println(s.getFullName() + " enters corridor");
            s.setLocation(locationCorridor);//SET LOCATION
            //ADDING STUDENT
            this.studentsIn[this.numberOfStudentsIn++] = s;
            return 1;
        }
        return 0;
    }
    public int addStudent(Student s, int x) {
        if (this.numberOfStudentsIn < this.capacity) {//IF THERE IS ENOUGH SPACE
            System.out.println(s.getFullName() + " enters corridor");
            s.setLocation(locationCorridor);//SET LOCATION
            //ADDING STUDENT
            this.studentsIn[this.numberOfStudentsIn++] = s;
            return 1;
        }
        return 0;
    }

    public int addStudentToClass(Classroom c, Student s) {
        int i;
        //IF STUDENT IS NOT IN THE CORRIDOR DO NOTHIN
        for (i = 0; i < this.numberOfStudentsIn; i++) {
            if (this.studentsIn[i].getId() == s.getId()) {
                break;
            }
        }
        if (i >= this.numberOfStudentsIn) {
            return 0;
        }

        if (c.insertStudent(s)==1) {
            //EXITS - THE LAST STUDENT IN THE ARRAY TAKES THE PLACE OF THE CURRENT'S
            this.studentsIn[i] = this.studentsIn[this.numberOfStudentsIn - 1];
            this.studentsIn[this.numberOfStudentsIn - 1] = null;
            this.numberOfStudentsIn--;

        } else {
            return 0;
        }
        return 1;
    }

    public int getCapacity() {
        return this.capacity;
    }

    public void setCapacity(int c) {
        this.capacity = c;
    }

    public void print() {
        System.out.println("People in corridor are:");
        int i;
        for (i = 0; i < this.numberOfStudentsIn; i++) {
            studentsIn[i].print();
        }
    }
    
    public Student exit(){
        if (numberOfStudentsIn > 0){
            Student s = studentsIn[--numberOfStudentsIn];
            System.out.println(s.getFullName()+" exits corridor!");
            s.setLocation(locationCorridor);
            return s;
        }
        return null;
    }

}
