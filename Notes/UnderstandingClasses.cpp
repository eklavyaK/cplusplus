#include <iostream>
using namespace std;

class Employee //if we don't write public as access specifier of  member methods or variables then by default they are assumed as private
{
private: //everything below this private is assumed as private till a next access specifier is encountered or class ends
    int a, b, c;

public: //everything under this public is assumed as public till a next access specifier is encountered or class ends
    int d, e;
    void setData(int a1, int b1, int c1); // Declaration of a prototype function which may or may not used to perform any function;
    void getData()
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
        cout << "The value of c is " << c << endl;
        cout << "The value of d is " << d << endl;
        cout << "The value of e is " << e << endl;
    }
};

void Employee ::setData(int a1, int b1, int c1) //here we are using a public method of the class Employee to set the values of private variables because
//methods of classes can modify the private variables
{
    a = a1;
    b = b1;
    c = c1;
}

int main()
{
    Employee harry; //An object has block scope if its declaration is located inside a block.
    //An object with block scope is visible from the point where it is declared to the closing brace (}) that terminates the block.

    //harry.a = 134; -->This will throw error as a is private so we can't access it directly from outside of class but we can use a function of the
    //class to access it like we did above

    harry.d = 34; //d and e are accessible as they are both public
    harry.e = 89;
    harry.setData(1, 2, 4);
    harry.getData();
    return 0;
}
