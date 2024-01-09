package myschool;

public class Teacher extends Human {
    public static final int L = 2;
    public Teacher(){
        super();
        System.out.println("A New Teacher has been created!");
    }
    public Teacher(String fn,int f, int c,int i){
        super(fn,f,c,i);
        System.out.println("A New Teacher has been created!");
    }
    public void print() {
        System.out.println(this.fullName + " (Teacher) Status:" + this.getPhysicalStatus());
    }

    public void computePhysicalStatus() {
        physicalStatus = L * attend;

    }
}
