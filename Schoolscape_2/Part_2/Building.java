package myschool;

import static myschool.Configuration.locationClassroom;
import static myschool.Configuration.locationCorridor;
import static myschool.Configuration.locationOut;
import static myschool.Configuration.locationStairs;
import static myschool.Configuration.locationYard;

public class Building {

    private Floor[] floors; //BUILDING CONSIST OF 3 FLOORS
    private Yard yard; //CONTAINING ONE YARD
    private Stairs stairs; //CONTAINING STAIRS

    public Building() {
        int i;
        //CREATING FLOORS
        floors = new Floor[3];
        for (i = 0; i < 3; i++) {
            floors[i] = new Floor();
        }
        //CREATING YARD
        yard = new Yard();
        //CREATING STAIRS
        stairs = new Stairs();

        System.out.println("Building created");
    }

    public Building(int yardCapacity, int stairsCapacity, int classCapacity, int corridorCapacity) {
        int i;
        //CREATING FLOORS;
        floors = new Floor[3];
        for (i = 0; i < 3; i++) {
            floors[i] = new Floor(classCapacity, corridorCapacity);
            floors[i].setId(i + 1);
        }
        //CREATING YARD
        yard = new Yard(yardCapacity);
        //CREATING STAIRS
        stairs = new Stairs(stairsCapacity);
        System.out.println("New School has been created!");
    }

    public void place(Teacher s) {
        Classroom c;
        Floor f;
        //GETTING FLOOR - CLASSROOM
        f = this.floors[s.getFloor()];
        c = f.getNClassroom(s.getClassroom());
        c.insertTeacher(s);//INSERTING
        s.setLocation(locationClassroom);//CHANGING LOCATION
    }

    public void print() {
        int i;
        System.out.println("School life consists of:");
        yard.print();
        stairs.print();
        for (i = 0; i < 3; i++) {
            floors[i].print();
        }
    }

    public int addStudent(Student s) {
        return this.yard.addStudent(s);
    }

    Yard getYard() {
        return this.yard;
    }

    Stairs getStairs() {
        return this.stairs;
    }

    Floor getFloor(int i) {
        return this.floors[i];
    }

    void operates(int x) {
        int i, j;
        for (j = 0; j < x; j++) {
            for (i = 0; i < 3; i++) {
                this.floors[i].operates(j + 1);
            }
        }
        System.out.println("Operates End");
    }

    public void empty(Teacher[] T) {
        Student[] s = floors[2].exit();
        while (s != null) {
            for (int i = 0; i < 6; i++) {
                if (s[i] != null) {
                    this.stairs.addStudent(s[i], 0);
                    s[i] = this.stairs.exit();
                    this.yard.addStudent(s[i], 0);
                    this.yard.exit();
                }
                for (int j = 0; j < T.length; j++) {
                    if (T[j].getLocation() == locationCorridor) {
                        System.out.println(T[j].getFullName() + " exits corridor");
                        T[j].setLocation(locationStairs);
                    }
                    if (T[j].getLocation() == locationStairs) {
                        System.out.println(T[j].getFullName() + " exits stairs");
                        T[j].setLocation(locationYard);
                    }
                    if (T[j].getLocation() == locationYard) {
                        System.out.println(T[j].getFullName() + " exits yard");
                        System.out.println(T[j].getFullName() + " exits building");
                        T[j].setLocation(locationOut);
                    }
                }
            }
            s = floors[2].exit();
        }
        s = floors[1].exit();
        while (s != null) {
            for (int i = 0; i < 6; i++) {
                if (s[i] != null) {
                    this.stairs.addStudent(s[i], 0);
                    s[i] = this.stairs.exit();
                    this.yard.addStudent(s[i], 0);
                    this.yard.exit();
                }
            }
            for (int j = 0; j < T.length; j++) {
                if (T[j].getLocation() == locationCorridor) {
                    System.out.println(T[j].getFullName() + " exits corridor");
                    T[j].setLocation(locationStairs);
                }
                if (T[j].getLocation() == locationStairs) {
                    System.out.println(T[j].getFullName() + " exits stairs");
                    T[j].setLocation(locationYard);
                }
                if (T[j].getLocation() == locationYard) {
                    System.out.println(T[j].getFullName() + " exits yard");
                    System.out.println(T[j].getFullName() + " exits building");
                    T[j].setLocation(locationOut);
                }
            }
            s = floors[1].exit();
        }
        s = floors[0].exit();
        while (s != null) {
            for (int i = 0; i < 6; i++) {
                if (s[i] != null) {
                    this.stairs.addStudent(s[i], 0);
                    s[i] = this.stairs.exit();
                    this.yard.addStudent(s[i], 0);
                    this.yard.exit();
                }
            }
            for (int j = 0; j < T.length; j++) {
                if (T[j].getLocation() == locationCorridor) {
                    System.out.println(T[j].getFullName() + " exits corridor");
                    T[j].setLocation(locationStairs);
                }
                if (T[j].getLocation() == locationStairs) {
                    System.out.println(T[j].getFullName() + " exits stairs");
                    T[j].setLocation(locationYard);
                }
                if (T[j].getLocation() == locationYard) {
                    System.out.println(T[j].getFullName() + " exits yard");
                    System.out.println(T[j].getFullName() + " exits building");
                    T[j].setLocation(locationOut);
                }
            }
            s = floors[1].exit();
        }
    }
}
