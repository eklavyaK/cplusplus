import java.util.*;
class Animal{
	public void print(){
		System.out.println("Animal");
	}
};
class Dog extends Animal{
	public void print(){
		System.out.println("Dog");
	}
};
public class testfile{
    

    public static void main(String[] args) {
		Animal me = new Dog();
		me.print();
     }
}