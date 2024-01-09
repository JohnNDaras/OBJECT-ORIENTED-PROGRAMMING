package myschool;


public class JuniorStudent extends Student {
    public static int L = 1;
    public JuniorStudent(String fn, int f, int c, int i) {
        super(fn, f, c, i);
        System.out.println("Junior Student");
    }

    public JuniorStudent() {
        super();
        System.out.println("Junior Student");
    }
    //junior student physical status computation

    public void computePhysicalStatus() {
        physicalStatus = L * attend;
    }
    

}
