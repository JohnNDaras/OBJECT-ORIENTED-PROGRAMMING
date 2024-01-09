/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package myschool;

import static myschool.Configuration.MAX_ARRAY_SIZE;
import static myschool.Configuration.locationClassroom;
import static myschool.Configuration.locationCorridor;

/**
 *
 * @author Admin
 */
public class Classroom extends Place {

    //CLASSROOM ID
    protected int id;
    //THE CLASSROOM TEACHER
    protected Teacher teacher;
    //ARRAY CONTAINING CLASSROOM STUDENTS
    protected Student[] students;
    //THE NUMBER OF STUDENTS IN CLASSROOM
    protected int studentsIn;
    //THE CLASSROOM CAPACITY (STUDENTS)
    protected int capacity;
    //the classroom type (Senior or Junior)
    protected String classroomtype;

    public Classroom() {
        id = -1;
        int i;
        students = new Student[MAX_ARRAY_SIZE];
        studentsIn = 0;
        this.capacity = 0;
        teacher = null;
        type = "classroom";
        classroomtype = "-";
    }

    public Classroom(int c) {
        id = -1;
        int i;
        this.studentsIn = 0;
        this.teacher = null;
        this.capacity = c;
        //THERE IS NOT STUDENTS IN
        students = new Student[MAX_ARRAY_SIZE];
        for (i = 0; i < MAX_ARRAY_SIZE; i++) {
            students[i] = null;
        }
        type = "classroom";
        classroomtype = "-";
        System.out.println("Classroom created");
    }

    public void setId(int i) {
        this.id = i;
    }

    public int insertTeacher(Teacher t) {
        if (this.teacher == null) {
            teacher = t;
            return 1;
        } else {
            System.out.println("There is a teacher in classroom");
            return 0;
        }

    }

    public int insertStudent(Student s) {
        //if (teacher == NULL){//TEACHER IS NOT IN
        if (this.studentsIn < this.capacity) {//ENOUGH SPACE
            this.students[studentsIn++] = s;
            System.out.println(s.getFullName() + " exits corridor");
            System.out.println(s.getFullName() + " enters classroom");
            s.setLocation(locationClassroom);
            return 1;
        } else {//NOT ENOUGH SPACE
            System.out.println("Classroom is full");
            return 0;

        }
    }    
    
    public int getCapacity() {
        return this.capacity;
    }

    public void setCapacity(int c
    ) {
        this.capacity = c;
    }

    public int getNumberOfStudentsIn() {
        return this.studentsIn;
    }

    public void print() {
        System.out.println("People in classroom " + id + "are:");
        if (this.teacher == null) {
            System.out.println("Teacher lost");
        } else {
            System.out.println("The teacher is: ");
            this.teacher.print();
        }

        int i;
        System.out.println("Students(" + this.studentsIn + "):");
        for (i = 0; i < this.studentsIn; i++) {
            students[i].print();
        }
    }

    public void operates(int x
    ) {
        int i;
        for (i = 0; i < this.studentsIn; i++) {
            this.students[i].setAttend(x);
            this.students[i].computePhysicalStatus();
        }
        this.teacher.setAttend(x);
        this.teacher.computePhysicalStatus();
    }
    
    public Student exit(){
        if (studentsIn > 0){
            Student s = students[--studentsIn];
            System.out.println(s.getFullName()+" exits classroom!");
            s.setLocation(locationCorridor);
            return s;
        }
        else {
            if (this.teacher != null){
                this.teacher.setLocation(locationCorridor);
            }
            return null;
        }
        
    }
}
