#include <iostream>
using namespace std; //In this code I've declared all the user-defined datatypes(union,struct,enum) as global but they can be declared locally but their usage will be local
/*======================================================================ENUMERATION========================================================================================*/
/*Enum is a way of assigning names to integer constants (float pint not allowed). For ex:- if we want to give name to 10 as ten then we can use enum.

If we don't initialize first variable in enum then it takes it's value as 0

If we don't initialize any variable after first variable then by default it's value will be assigned as: value of previous variable + 1

once declared enums are treated as literals. they are not variables. they are literals. you cannot change the value of those enums because literals are constants*/
enum animal
{
    lion,
    tiger,
    elephant,
    wolf
};
enum integers
{
    messi = 1,
    ronaldo,
    neymar,
    lewandowski,
    suarez
}; //one thing to note that variables are separated by commas not semicolon because of they are of same type
enum wishes
{
    goodmorning = 23,
    hello = 89,
    goodafternoon = 89,
    goodevening,
    goodnight = 12
}; //two or more variables can have same value
void enum_implementation()
{
    cout << lion << " " << tiger << " " << elephant << " " << wolf << endl;
    cout << messi << " " << ronaldo << " " << neymar << " " << lewandowski << " " << suarez << endl;
    cout << goodmorning << " " << hello << " " << goodafternoon << " " << goodevening << " " << goodnight << endl;
    //lion = 123;         //this throws error because lion is a literal, it cannot be assigned another value, it's like assigning value to a literal like 1 = 23;
    wishes x = goodmorning; //since wishesh is a datatype we can a declare a variable of it's type which can store a value only present in enum wishes
    //wishes y = 23;         //throws error
    //wishes z = messi;      //throws error
    cout << x << endl;
    //x = 1;             again throws error
    int lion = 9234;
    cout << lion << endl; //this local lion is a variable which overrites enum lion
    cout << ::lion;       //this is used to bring global literal lion;
}
/*======================================================================UNION========================================================================================*/
/* Union has better memory management than struct because struct creates memory space of all the variables for each of it's object, but union creates the
memory space equal to the largest data type in it for each object. And we can use only one variable of the union the previous one will be deleted if we use a new one. 

In union generally it happens that the data is put in the space created by union for it's each object then when a object of union calls the the variable it takes 
out the data and then it's type is assigned to the type of the variable called. So it is necessary that data type of every variable used in a union must be trivial.
because every trivial data type can be converted to another. for ex: int,char,double,float,bool are interconvertible with some loss of data. But string which is 
non trivial cannot be used with trivial data types in union 

If we use non trivial data type union will be deleted at the start of excution cannot be used further. 

Another thing is that we cannot initialize more than one variable in the union bracket.*/

union country
{
    int population;
    int area;
    char firstchar;
    bool exist;
};
typedef union information
{
    bool news;
    int stocks;
    int growth;
} info;
void union_implementation()
{
    union country a;
    a.population = 100000000;     //here object a of the union stores the value 100000000 in raw form without any data type
    cout << a.population << endl; //prints: 100000000              here the value is taken out of the object and it is subjected to datatype of
    //variable pupulation(which is int) and printed

    a.area = 324231287;     //here object a of the union stores the value 324231287
    cout << a.area << endl; //prints: 324231287                here the value is taken out of the object and it is subjected to datatype of
    //variable area(which is int) and printed
    cout << a.firstchar << endl; //prints: w   now I don't how the char value of 324231287 came out to be w      here the value is taken out of the object and it
    //is subjected to datatype of variable firstchar(which is char) and printed
    cout << a.population << endl; //prints: 324231287         here the value is taken out of the object and it is subjected to datatype of variable
    //population(which is int) and printed

    a.firstchar = 'z'; //here object a stores the value 'z' for which it allocates the last 1 byte for char and rest of the 3 bytes are for int value of area
    //now when we print firstchar it prints it correctly but when we print area or population it prints 324231290. This wrong value comes from the mixture of initial
    //3 bytes of int values and final 1 byte of char. It can be proved by giving firstchar another char value which is higher in ascii table which will make the combined
    //value of the int and char values higher which can be noted below that when we give true value to exist it changes the value of the combined value of the 4 bytes
    //to a smaller value.
    cout << a.firstchar << endl;  //prints: r
    cout << a.area << endl;       //prints: 324231282 (not 324231287) because some of the value is lost due to storage of firstchar
    cout << a.population << endl; //prints: 324231282
    cout << a.exist << endl;      //prints: 114            the int value of r as we all know that boolean prints int values only
    a.exist = true;
    cout << a.population << endl; //prints: 324231169    more value from population
    cout << a.area << endl;
    cout << a.firstchar << endl;
    cout << a.exist << endl;
    //so basically conclusion is that we can print the correct value only of the latest modified or assigned variable, values of other variables migght printed wrong.
}
/*======================================================================STRUCTURE========================================================================================*/
/*A struct (short for structure) is a data type available in C programming languages, such as C, C++, and C#. 
It is a user-defined data type that can store multiple related items. A struct variable is similar to a database 
record since it may contain multiple data types related to a single entity.*/

struct student
{
    int rollno;
    string name;
    bool present;
}; //after defining every struct we must put semicolor after it
struct fixed
{
    string post = "commander";
    int salary = 1000000;
    int els = 30;
};
struct sports
{
    int k;
}; //even if struct contains just one member variable it must be declared in curly brackets only
typedef struct address
{
    string name;
    string colony;
    string city;
    string country;
} add; //typedef keyworod is used to define the name with
//which we would use the struct address

/****************************************************************MAIN METHOD*****************************************************************/
int main()
{
    struct student akash;
    struct student ramsingh;
    akash.rollno = 1;
    akash.name = "akash";
    akash.present = true;
    ramsingh.rollno = 24;
    ramsingh.name = "ramsingh";
    ramsingh.present = false;
    cout << "RollNo. of Akash is: " << akash.rollno << endl;
    cout << "Name of Akash is: " << akash.name << endl;
    cout << "Status of Akash is: " << akash.present << endl;
    cout << "RollNo. of Ramsingh is: " << ramsingh.rollno << endl;
    cout << "Name of Ramsingh is: " << ramsingh.name << endl;
    cout << "Status of Ramsingh is: " << ramsingh.present << endl;
    cout << endl;
    struct fixed hariram;
    struct fixed sitaram;
    cout << "Post of Hariram is: " << hariram.post << endl;
    cout << "Salary of Hariram is: " << hariram.salary << endl;
    cout << "NoOfleaves of Hariram is: " << hariram.els << endl;
    cout << "Post of Sitaram is: " << sitaram.post << endl;
    cout << "Salary of Sitaram is: " << sitaram.salary << endl;
    cout << "NoOfleaves of Sitaram is: " << sitaram.els << endl;
    cout << endl;
    //Let's overrite the fixed struct
    hariram.post = "general";
    hariram.salary = 2000000;
    hariram.els = 40;
    cout << "Post of Hariram is: " << hariram.post << endl;
    cout << "Salary of Hariram is: " << hariram.salary << endl;
    cout << "NoOfleaves of Hariram is: " << hariram.els << endl;
    cout << "\n";

    add eklavya;
    eklavya.name = "EKLAVYA";
    eklavya.colony = "Gamhariya";
    eklavya.city = "Sasaram";
    eklavya.country = "India";
    cout << "Name of eklavya is: " << eklavya.name << endl;
    cout << "Colony Address of eklavya is: " << eklavya.colony << endl;
    cout << "City Address of eklavya is: " << eklavya.city << endl;
    cout << "Country of eklavya is: " << eklavya.country << endl;

    //We can also create array of structure instead of creating multiple variables
    cout << "\nImplementation of structure array starts" << endl;
    struct student st[5];
    for (int i = 0; i < 5; i++)
    {
        st[i].name = "student" + to_string(i + 1);
        st[i].rollno = i + 1;
        st[i].present = i % 2;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << st[i].rollno << " " << st[i].name << " "
             << " " << (st[i].present == 1 ? "present" : "absent") << endl;
        ;
    }

    cout << "\nunion_implementation starts\n";
    union_implementation();

    cout << "\nenums_implementation starts\n";
    enum_implementation();
    return 0;
}
/*Output:
RollNo. of Akash is: 1
Name of Akash is: akash
Status of Akash is: 1
RollNo. of Ramsingh is: 24
Name of Ramsingh is: ramsingh
Status of Ramsingh is: 0

Post of Hariram is: commander
Salary of Hariram is: 1000000
NoOfleaves of Hariram is: 30
Post of Sitaram is: commander
Salary of Sitaram is: 1000000
NoOfleaves of Sitaram is: 30

Post of Hariram is: general
Salary of Hariram is: 2000000
NoOfleaves of Hariram is: 40

Name of eklavya is: EKLAVYA
Colony Address of eklavya is: Gamhariya
City Address of eklavya is: Sasaram
Country of eklavya is: India

Implementation of structure array starts
1 student1  absent
2 student2  present
3 student3  absent
4 student4  present
5 student5  absent

union_implementation starts
100000000
324231287
w
324231287
z
324231290
324231290
122
324231169
324231169
☺
1

enums_implementation starts
0 1 2 3
1 2 3 4 5
23 89 89 90 12
23
9234
0
*/