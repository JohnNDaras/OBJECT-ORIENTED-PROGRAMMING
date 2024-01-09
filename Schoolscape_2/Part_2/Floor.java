package myschool;

public class Floor extends Place {

    //FLOOR ID
    private int id;
    //ARRAY CONTAINING CLASSROOMS
    private Classroom[] classrooms;
    //THE FLOOR CORRIDOR
    private Corridor corridor;

    public Floor() {
        int i;
        this.classrooms = new Classroom[6];
        for (i = 0; i < 3; i++) {
            this.classrooms[i] = new SeniorClassroom();
            this.classrooms[i].setId(this.id * 6 + i + i);
        }
        for (i = 3; i < 6; i++) {
            this.classrooms[i] = new JuniorClassroom();
            this.classrooms[i].setId(this.id * 6 + i + i);
        }
        this.corridor = new Corridor();
        type = "floor";
        System.out.println("Floor Created");
    }

    public Floor(int classCapacity, int corridorCapacity) {
        int i;
        //CREATING CLASSROOMS
        this.classrooms = new Classroom[6];
        for (i = 0; i < 3; i++) {
            this.classrooms[i] = new SeniorClassroom(classCapacity);
        }
        for (i = 3; i < 6; i++) {
            this.classrooms[i] = new JuniorClassroom(classCapacity);
        }
        this.corridor = new Corridor(corridorCapacity);
        type = "floor";
        System.out.println("Floor Created");
    }

    public void setId(int i) {
        this.id = i;
    }

    public int getId() {
        return this.id;
    }

    public Corridor getCorridor() {
        return this.corridor;
    }

    public void addClassroom(Classroom cl, int i) {
        this.classrooms[i] = cl;
    }

    public Classroom getNClassroom(int n) {
        return this.classrooms[n];
    }

    public int insertStudent(Student s) {
        //WHEN STUDENT ARRIVES MOVES DIRECTLY TO CORRIDOR
        if (this.corridor != null) {
            return corridor.addStudent(s);
        }
        return 0;
    }

    public int addStudentToClassroom(Student s) {
        //MOVING STUDENT FROM CORRIDOR TO CLASS
        return this.corridor.addStudentToClass(this.classrooms[s.getClassroom()], s);
    }

    public void print() {
        int i;
        System.out.println("Floor number " + this.id + " contains:");
        corridor.print();
        for (i = 0; i < 6; i++) {
            this.classrooms[i].print();
        }
    }

    public void operates(int x) {
        int i;
        for (i = 0; i < 6; i++) {
            this.classrooms[i].operates(x);
        }
    }

    public Student[] exit() {
        Student c1, c2, c3, c4, c5, c6;

        c1 = this.classrooms[0].exit();
        if (c1 != null) {
            this.corridor.addStudent(c1);
            c1 = this.corridor.exit();
        }
        c2 = this.classrooms[1].exit();
        if (c2 != null) {
            this.corridor.addStudent(c2);
            c2 = this.corridor.exit();
        }
        c3 = this.classrooms[2].exit();
        if (c3 != null) {
            this.corridor.addStudent(c3);
            c3 = this.corridor.exit();
        }
        c4 = this.classrooms[3].exit();
        if (c4 != null) {
            this.corridor.addStudent(c4);
            c4 = this.corridor.exit();
        }
        c5 = this.classrooms[4].exit();
        if (c5 != null) {
            this.corridor.addStudent(c5);
            c5 = this.corridor.exit();
        }
        c6 = this.classrooms[5].exit();
        if (c6 != null) {
            this.corridor.addStudent(c6);
            c6 = this.corridor.exit();
        }
        if ((c1 == null) && (c2 == null) && (c3 == null) && (c4 == null) && (c5 == null) && (c6 == null)) {
            return null;
        }
        else {
            Student[] stds = new Student[6];
            stds[0] = c1;
            stds[1] = c2;
            stds[2] = c3;
            stds[3] = c4;
            stds[4] = c5;
            stds[5] = c6;
            return stds;
        }
    }
}
