package myschool;

public class SeniorStudent extends Student {
    public static int L = 2;
    public SeniorStudent(String fn, int f, int c, int i) {
        super(fn, f, c, i);
        System.out.println("Senior Student");
    }

    public SeniorStudent() {
        super();
        System.out.println("Senior Student");
    }
    //senior student physical status computation

    public void computePhysicalStatus() {
        physicalStatus = L * attend;

    }
    
}
