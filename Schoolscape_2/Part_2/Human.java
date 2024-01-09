package myschool;

import static myschool.Configuration.locationOut;

public class Human {

    //Human's ID
    protected int id;
    //Human's FULL NAME
    protected String fullName;
    //Human's CLASSROOM FLOOR
    protected int floor;
    //Human's CLASSROOM NUMBER ON THE FLOOR
    protected int classNumber;
    //Human's CURRENT LOCATION
    protected int location;
    //The humans physical status
    protected int physicalStatus;
    //working hours
    protected int attend;

    public Human() {
        fullName = "Unknown Unknown";
        location = locationOut;
        floor = -1;
        classNumber = -1;
        this.physicalStatus = 0;
        this.attend = 0;
        System.out.println("Created student:" + this.fullName);
    }

    public Human(String fn, int f, int c, int i) {
        this.id = i;
        this.fullName = fn;
        this.location = locationOut;
        this.floor = f;
        this.classNumber = c;
        this.physicalStatus = 0;
        this.attend = 0;
        System.out.println("Created student:" + this.fullName + " Class:" + (this.classNumber + 1) + " Floor:" + (this.floor + 1));
    }

    public void setFullName(String fn) {
        fullName = fn;
    }

    public void setLocation(int loc) {
        location = loc;
    }

    public void setFloor(int flo) {
        floor = flo;
    }

    public String getFullName() {
        return this.fullName;
    }

    public int getLocation() {
        return this.location;
    }

    public int getFloor() {
        return this.floor;
    }

    public int getClassroom() {
        return this.classNumber;
    }

    public int getId() {
        return this.id;
    }

    public void print() {
        System.out.println(this.fullName + " (Human)");
    }

    public int getPhysicalStatus() {
        return physicalStatus;
    }

    public void setPhysicalStatus(int x) {
        physicalStatus = x;
    }

    public int getAttend() {
        return this.attend;
    }

    public void setAttend(int x) {
        this.attend = x;
    }

}
