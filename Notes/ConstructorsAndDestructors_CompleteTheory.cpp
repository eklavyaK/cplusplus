#include <iostream>
using namespace std;
/*constructors are special types of member functions of the class which are used to iitialize the member variables of a object 
of a class. 

It has no return type and it doesn't return any values.

We generally define a constructor as public so that we can use it whenever we need to create the object of the class.

We can use constructor overloading to define objects in various ways

If user doesn't define a constructors for a class then compiler uses a default constructors where variables are just declared but not initialised

If we don't define manually copy constructor manually then compiler invokes a default copy constructor too.
*/

/* Destructor is a function which is used to delete a object from the memory. It's name is same as class with negation sign(~) at beginining

It takes no arguments and has no return type.

If not declared manually, compiler invokes it by default but this can be used to perform some operations if we need before destroying a object

Yes, we can call a destructor manually whenever we need to delete an object. But compiler it by default when compilation of the scope of object ends
*/
class student
{
    int marks, rollno;
    static int count;

public:
    string name; //I declared name as public so that I can use it whenever I change the names
    student() {} //This is the default constructor. Similar to what compiler invokes when don't create any constructor
    student(int rn, int m, string n = "eklavya")
    {
        name = n;
        marks = m;
        rollno = rn;
    }
    student(int, float, string); //here we have indicated the compiler that there may be definition of this funciton further

    student(student &x) //Note: If we don't write this constructor then compiler will make it's own copy compiler with same
    {                   //functionality as this but will not print anything like we did
        cout << "Copy constructor is called!!" << endl;
        rollno = x.rollno;
        name = x.name;
        marks = x.marks;
    }
    student(int);
    void display(int k = 0)
    {
        cout << "Object: s" << k << endl;
        cout << "RollNo.: " << rollno << "	  ";
        cout << "Student's name: " << name << "	  ";
        cout << "Student's marks: " << marks << "		 ";
        cout << '\n'
             << endl;
    }
    ~student() //this how to define destructor(no return type no arguments only class name and negation sighh)
    {
        int k = 1;
        k = counter();
        if (k == 0)
            cout << "One Object has been removed from the memory" << endl;
        else
            cout << "Object s" << k << " has been removed from the memory" << endl;
    }
    void check();
    static void setCount(int k = 0)
    {
        count = k;
    }
    static int counter()
    {
        return count;
    }
};
int student::count = 0;
student::student(int rn, float m, string n)
{
    rollno = rn;
    marks = m;
    name = n;
}
student::student(int rn)
{
    rollno = rn;
    marks = 100;
    name = "Abhishek";
}
int main()
{
    student s1(30, 82, "Dipesh"), s2(1, 90, "Aakash"), s3(3, 67);
    student s4(2);
    s1.display(1);
    s2.display(2);
    s3.display(3);
    s4.display(4);
    student s5(s1); //copy constructor will be called
    cout << "We initilized the value of s5 with copy constructor by passing s1" << endl;
    s1.display(1);
    s5.display(5);
    cout << "Let's change the name of the s5 to eklavya" << endl;
    s5.name = "eklavya";
    s1.display(1);
    s5.display(5);
    student::setCount(1);
    s1.~student(); //here we are manually trying to destroy the object from the memory but it doesn't work like that. s1 won't deleted here
    cout << s1.name << endl;
    student::setCount(5);
    s5.~student();
    student s6 = s4; //copy constructor will be called!!
    cout << "We initialized s6 as: student s6 = s4;" << endl;
    s4.display(4);
    s6.display(6);
    cout << "Now let's change the value of s6 to eklavya" << endl;
    s6.name = "eklavya";
    s4.display(4);
    s6.display(6);
    student::setCount(4);
    s4.~student();
    student::setCount(6);
    s6.~student();
    {
        cout << "Here we enter the block" << endl;
        student s7;
        student s8(32, 100, "eklavya");
        student s9(32, float(100), "eklavya");
        s7.display(7);
        s8.display(8);
        s9.display(9);
        cout << "Now here we are exiting the block" << endl;
        student::setCount();
        student::setCount();
        student::setCount();
    }
    student s10;
    s10 = s3; //copy constructor will not be called but variable contents of s3 will be copied to s10, just like assignment
    //now this is different from what happens in java where object point to the same location when we assign.
    //now it seems like it performs almost same function as copy constructor. But it's not true, because assignment performs almost
    //same function like "default" copy constructor. But when we define copy constructor manually then we can costumize it in various ways
    //which can be different than simple assignment which default copy constructor performs.
    cout << "We initlized s10 as: s10 = s3;" << endl;
    s3.display(3);
    s10.display(7);
    cout << "Now we change the name of s10 to Sindhu" << endl;
    s10.name = "Sindhu"; //since it's not java and s10 and s3 are completely different changing contents one doesn't affect another
    s3.name = "Raj";
    s3.display(3);
    s10.display(10);
    return 0;
}
/*Output:

Object: s1
RollNo.: 30       Student's name: Dipesh          Student's marks: 82            

Object: s2
RollNo.: 1        Student's name: Aakash          Student's marks: 90            

Object: s3
RollNo.: 3        Student's name: eklavya         Student's marks: 67            

Object: s4
RollNo.: 2        Student's name: Abhishek        Student's marks: 100           

Copy constructor is called!!
We initilized the value of s5 with copy constructor by passing s1
Object: s1
RollNo.: 30       Student's name: Dipesh          Student's marks: 82            

Object: s5
RollNo.: 30       Student's name: Dipesh          Student's marks: 82            

Let's change the name of the s5 to eklavya
Object: s1
RollNo.: 30       Student's name: Dipesh          Student's marks: 82            

Object: s5
RollNo.: 30       Student's name: eklavya         Student's marks: 82            

Object s1 has been removed from the memory
Dipesh
Object s5 has been removed from the memory
Copy constructor is called!!
We initialized s6 as: student s6 = s4;
Object: s4
RollNo.: 2        Student's name: Abhishek        Student's marks: 100

Object: s6
RollNo.: 2        Student's name: Abhishek        Student's marks: 100

Now let's change the value of s6 to eklavya
Object: s4
RollNo.: 2        Student's name: Abhishek        Student's marks: 100

Object: s6
RollNo.: 2        Student's name: eklavya         Student's marks: 100

Object s4 has been removed from the memory
Object s6 has been removed from the memory
Here we enter the block
Object: s7
RollNo.: 1878001472       Student's name:         Student's marks: 1878000640

Object: s8
RollNo.: 32       Student's name: eklavya         Student's marks: 100

Object: s9
RollNo.: 32       Student's name: eklavya         Student's marks: 100

Now here we are exiting the block
One Object has been removed from the memory
One Object has been removed from the memory
One Object has been removed from the memory
We initlized s10 as: s10 = s3;
Object: s3
RollNo.: 3        Student's name: eklavya         Student's marks: 67

Object: s7
RollNo.: 3        Student's name: eklavya         Student's marks: 67

Now we change the name of s10 to Sindhu
Object: s3
RollNo.: 3        Student's name: Raj     Student's marks: 67

Object: s10
RollNo.: 3        Student's name: Sindhu          Student's marks: 67

One Object has been removed from the memory
One Object has been removed from the memory
One Object has been removed from the memory
One Object has been removed from the memory
One Object has been removed from the memory
One Object has been removed from the memory
One Object has been removed from the memory

*/