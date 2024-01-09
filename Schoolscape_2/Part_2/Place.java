package myschool;

public class Place {

    protected String type;

    public Place() {
        type = "-";
    }

    
    public Place(String s) {
        type = s;
    }
    public void print(){}
    //operate function is being defined to children classes
    public void operates(int x){}
}
