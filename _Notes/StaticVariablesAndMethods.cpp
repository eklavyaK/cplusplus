#include <iostream>
using namespace std;
/* static variables are those variables which belongs to the program, not to a particular object. Only one copy of the static variable is created in class, not like 
multiple copies being created for each object. But every object can access the staticd variable location and use it's data. And for this reason static variables are not
declared using constuctors.

Static methods are those methods who can access only static variables. Other variables cannot be accessed by static method. So for this reason we cannot a static function
with a object of class.*/

class Employee
{
    int id;
    static int count;    //default value of a static variable is 0
    //static int counter = 100;---------> throws error because we cannot initialize a static variable here

public:
    void setData(void)
    {
        cout << "Enter the id" << endl;
        cin >> id;
        count++;
    }
    void getData(void)
    {
        cout << "The id of this employee is " << id << " and this is employee number " << count << endl;
    }

    static void getCount(void){
        // cout<<id; // throws an error because id is non-static
        cout<<"The value of count is "<<count<<endl;
    }
};

// Count is the static data member of class Employee
int Employee::count=1000; //we can initialize the static varibles only outside of class not inside it, because classes are almost same as constructors which can initialize
//non static variables. Point to note is we cannot initialize a static variable inside a class, it can be initalized only outside of class.

int main()
{
    Employee harry, rohan, lovish;     //we can create multiple objects in one line;
    // harry.id = 1;
    // harry.count=1; // cannot do this as id and count are private

    harry.setData();
    harry.getData();
    Employee::getCount(); //note that we are not calling the static method using object, it can be called with class mane outside the class and with just signature inside it

    rohan.setData();
    rohan.getData();
    Employee::getCount();

    lovish.setData();
    lovish.getData();
    Employee::getCount();

    return 0;
}
