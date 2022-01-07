#include<iostream>
using namespace std;
/*======================================================================INLINE FUNCTIONS========================================================================================*/
//read the explanation of need of inline function here https://www.geeksforgeeks.org/inline-functions-cpp/
/*In brief, inline function is used when we want to reduce the time of excution. Where a function peforms a small task which is comparable to time
taken to copy and return the arguments and values passed. This increases the time of excution when same function has to be called multiple times in the program
because each time the function is called it has to be passed to the stack and copy the values of the arguments for just to perform a simple task. Whenever a inline function
is called the whole code is copied to the location it is called so there is no copying of the arguments is done only computation. But for larger function whcih
perform lots of tasks we don't make it inline because time to compy arguments is negligible to the time of excution of the function*/
inline int product(int k,int l)
{
    return k*l;
}
/*======================================================================DEFAULT ARGUMENTS========================================================================================*/
//Default arguments are provided so that function can take that value for that variable if no value is passed to that variable
//void default_arguments(int a = 30,int b) //this throws error because all the default arguments should be in extreme right of the arguments

void default_arguments(int a,int b=30)
{
    cout<<(b-a)<<endl;
}
/*======================================================================FUNCTION PROTOTYPE========================================================================================*/
/*We can also write functions after main() method, but we must declare a prototype of it before the main() method. so that compiler can understand
that there is a function declared with that name*/

int sum(int,int);    //this is the prototype of the function, in prototype we declare the type of parameters passed with return type
//we don't do any kind of computation in prototype
void wish();
/*************************************************************************MAIN METHOD*********************************************************************************************/
int main()
{
    cout<<"function prototypes implementation"<<endl;
    int n = 10,m=20, a = 11, b=20;
    int result = sum(n,m);
    cout<<result<<endl;
    wish();

    cout<<"\ninline function implementation"<<endl;
    cout<<product(n,m)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(23,80)<<endl;
    cout<<product(3,80)<<endl;
    cout<<product(23,8)<<endl;
    cout<<product(230,980)<<endl;
    cout<<product(203,80)<<endl;
    cout<<product(23,810)<<endl;
    cout<<product(23,90)<<endl;
    cout<<product(223,80)<<endl;

    cout<<"\ndefalut arguments implementation"<<endl;
    default_arguments(n);
    default_arguments(n);
    default_arguments(n,m);
}
/*======================================================================ACTUAL FUNCTIONS========================================================================================*/
int sum(int n, int m)
{
    return n+m;
}
void wish()
{
    cout<<"HardWork brings talent."<<endl;
}
/*Output:
function prototypes implementation
30
HardWork brings talent.

inline function implementation
200
220
1840
240
184
225400
16240
18630
2070
17840

defalut arguments implementation
20
20
10
*/