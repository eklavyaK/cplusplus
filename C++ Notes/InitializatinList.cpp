#include<iostream>
using namespace std;
/*
Syntax for initialization list in constructor:
constructor (argument-list) : initilization-section
{
    assignment + other code;
}
*/
class Test
{
    int a;
    int b;

public:
    //Test(int i, int j) : a(i), b(j+i)               //this will run perfectly
    //Test(int i, int j) : a(i), b(2*j)               //this will run perfectly
    //Test(int i, int j) : a(i), b(a+j)               //this will run perfectly
    //Test(int i, int j) : b(j), a(i+b) ---> Here garbage value will be printed in a because b has been declared after a in the class
                                            //so compiler will initialize it after a, but a requires the value of b which ain't possible
                                            //so there will be a garbage value in a. If we change the order of declaration in lines 12
                                            //and 13 then we could get the desired result
    Test(int i, int j) : a(i), b(j+i)
    {
        cout << "Constructor executed"<<endl;
        cout << "Value of a is "<<a<<endl;
        cout << "Value of b is "<<b<<endl;
    }
};

int main()
{
    Test t(4, 6);
    return 0;
}
/*Output:
Constructor executed
Value of a is 4
Value of b is 10
*/