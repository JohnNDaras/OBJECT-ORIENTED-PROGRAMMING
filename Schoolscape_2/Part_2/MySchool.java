/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package myschool;

import java.util.Random;
import static myschool.Configuration.locationOut;

/**
 *
 * @author Admin
 */
public class MySchool {

    /*
There are 3 floors 
There are 3 x 6 = 18 classrooms
There are 18 teachers
Therea are 3 X 6 X Cclass students
     */
    static Random R;
//SIMULATION PARAMETERS GETTING DEFAULT VALUES
    static final int INT_MAX = 1000000;
    static int Cclass;
    static int Ccorridor;
    static int Cstairs;
    static int Cyard;

    static int Lj;
    static int Ls;
    static int Lt;
    static int TotalNumberOfStudents;
    static int TotalNumberOfTeachers;
//NAMES TO BE USED TO CONSTRUCT RANDOM FULLNAMES FOR STUDENTS AND TEACHERS
    static String firstNames[] = {"Jerry", "Manos", "John", "Mary", "Bill", "Zoe", "Ann", "Jim", "Mel", "George", "Georgia", "Philip", "Kostas", "Olga", "Marios"};
    static String lastNames[] = {"Black", "Smith", "White", "Mos", "Bell", "Zeus", "Antams", "Jimer", "Melow", "Georgan", "Georgian", "Philipou", "Kostaras", "Olia", "Mara"};
//CREATES RANDOM FULLNAME

    static String makeRandomFullname(int max, Random r) {
        return firstNames[r.nextInt(max - 1)] + " " + lastNames[r.nextInt(max - 1)];
    }
//IT RETURNS 1 IF THERE ARE STUDENTS HAVING NOT BEEN INSERTED IN THE BUILDING
//RETURNS 0 OTHERWISE

    static int thereAreStudentsOut(Student AllStudents[]) {
        int i;
        for (i = 0; i < TotalNumberOfStudents; i++) {
            if (AllStudents[i].getLocation() == locationOut) {
                return 1;
            }
        }
        return 0;
    }
//IT RETURNS 1 IF THERE ARE STUDENTS HAVING NOT BEEN INSERTED IN THE BUILDING
//RETURNS 0 OTHERWISE

    static int thereAreTeachersOut(Teacher AllTeachers[]) {
        int i;
        for (i = 0; i < TotalNumberOfTeachers; i++) {
            if (AllTeachers[i].getLocation() == locationOut) {
                return 1;
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        int stds;
        int tchs;
        //READING COMMAND LINE ARGUMENTS
        if (args.length == 5) {
            Cclass = Integer.parseInt(args[1]);
            Lj = Integer.parseInt(args[2]);
            Ls = Integer.parseInt(args[3]);
            Lt = Integer.parseInt(args[4]);
        } else {
            Cclass = 25;
            Cstairs = INT_MAX;
            Ccorridor = INT_MAX;
            Cyard = INT_MAX;
            Lj = JuniorStudent.L;
            Ls = SeniorStudent.L;
            Lt = Teacher.L;
            System.out.println("Default values are going to be used!");
        }
        R = new Random();
        //COMPUTING NUMBER OF STUDENTS AND TEACHERS FOR FILLING ALL CLASSROOMS OF THE BUILDING
        TotalNumberOfStudents = 3 * 6 * Cclass;
        TotalNumberOfTeachers = 18;
        //CREATING ARRAYS FOR STORING STUDENTS AND TEACHERS
        Teacher[]  AllTeachers = new Teacher[TotalNumberOfTeachers];
        Student[]  AllStudents = new Student[TotalNumberOfStudents];
        int flr;
        int cls;
        //CREATING STUDETNS COMPUTING THE FLOOR AND THE CLASSROOM TO BE PLACED
        //if class is 0,1,2 it corresponds to junior class
        //if class is 3,4,5 it corresponds to senior class
        for (stds = 0; stds < TotalNumberOfStudents; stds++) {
            flr = stds % 18;
            cls = stds % 18;
            flr = flr / 6;
            cls = cls % 6;
            System.out.println("Class:" + cls);
            if (cls < 3) {
                AllStudents[stds] = new JuniorStudent(makeRandomFullname(15, R), flr, cls, stds);
            } else {
                AllStudents[stds] = new SeniorStudent(makeRandomFullname(15, R), flr, cls, stds);
            }

        }
        //CREATING TEACHERS COMPUTING THE FLOOR AND THE CLASSROOM TO BE PLACED
        for (tchs = 0; tchs < TotalNumberOfTeachers; tchs++) {
            flr = tchs / 6;
            cls = tchs % 6;
            AllTeachers[tchs] = new Teacher(makeRandomFullname(15, R), flr, cls, tchs);
        }
        //creating building
        Building  building = new Building(Cyard, Cstairs, Cclass, Ccorridor);
        do {
            //A STUDENT CHOSEN RANDOMLY INSERTS
            stds = R.nextInt(TotalNumberOfStudents-1);
            while (AllStudents[stds].getLocation() != locationOut) {
                stds = R.nextInt(TotalNumberOfStudents);
            }
            //TEACHERS ARE COMIN IN WITH POSIBILITY OF 20%
            //THEY ARE GOING DIRECTLY TO THEIR CLASSROOM
            if ((thereAreTeachersOut(AllTeachers)==1) && (R.nextInt(100) > 20)) {
                tchs = R.nextInt(TotalNumberOfTeachers);
                System.out.println(tchs);
                building.place(AllTeachers[tchs]);
            }
            //IF STUDENTS INSERTS BUILDING
            if (building.addStudent(AllStudents[stds])==1) {
                //INSERTING THE BUILDING . INSERTS DIRECTLY YARD -. INSERTS DIRECTLY TO STAIRS (IF THERE IS ENAOUGH SPACE)
                if (building.getYard().addStudentToStairs(building.getStairs(), AllStudents[stds])==1) {
                    //IF STUDENTS INSERTS FLOOR (IF THERE IS ENOUGH SPACE)
                    if (building.getStairs().addStudentToFloor(building.getFloor(AllStudents[stds].getFloor()), AllStudents[stds])==1) {
                        //IF STUDENTS INSERTS CLASSROOM (IF THERE IS ENOUGH SPACE)
                        if (building.getFloor(AllStudents[stds].getFloor()).addStudentToClassroom(AllStudents[stds])==1) {
                            
                        }
                    }
                }
            }
            //IF ALL TEACHERS HAVE ENTERED CLASSROOMS , NO STUDENT CAN ENTER . THIS IS THE END OF SIMULATION
            if (thereAreTeachersOut(AllTeachers) == 0) {
                break;
            }
            System.out.println(thereAreTeachersOut(AllTeachers) + " " + thereAreStudentsOut(AllStudents));
        } while ((thereAreTeachersOut(AllTeachers)==1) || (thereAreStudentsOut(AllStudents)==1));//SIMULATION ENDS WHEN ALL STUDENTS ENTERED OR ALL TEACHERS ENTERED
        //PRINTING BUILDING STATUS
        building.operates(10);
        building.print();
        building.empty(AllTeachers);
    }

}
