package myschool;

public class Student extends Human {

    public static final int L = 1;

    //CONSTRUCTORS
    public Student() {
        super();
    }

    public Student(String fn, int f, int c, int i) {
        super(fn, f, c, i);
    }

    public void print() {
        System.out.println(this.fullName + " (Student) Status:" + this.getPhysicalStatus());
        System.out.println(this.fullName + " (Student) Status:" + this.getPhysicalStatus());
    }

    public void computePhysicalStatus() {
        physicalStatus = L * attend;

    }
    
    
}
