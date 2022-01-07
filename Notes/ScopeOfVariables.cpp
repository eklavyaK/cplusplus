/*Local variable takes precedence over the global variables, i.e. if we declare the local variable with same name as global variable
 for every usages of the variable in that function with that name will be taken as the value of the variable declared in local. But 
 only after the compiler has read it's declaration, i.e. if we declare the local variable with the name of the global variable in the function
 such that compiler compiler reads it's usage before reading it's actual declaration then compiler will use the value of the global variable which has been declared
 above it. */

#include<bits/stdc++.h>
using namespace std;
void func()
{
   //cout<<global<<endl; ----> this throws error because global is not declared in the function scope before it's usage and there global variable declared above function with that name
}
int global = 32;
void check()
{
    int a = 9;
    cout<<global<<endl;
    int global = 2324;
    cout<<global<<endl;
    cout<<::global<<endl; //:: is a scope resolution operator which is used to take value of the the global variable instead of local variable
    //this scope resolution operator has the highest prededence of all the operators
    cout<<global<<endl;
    for(int i = 0;i<1;i++){ cout<<::global<<endl;}
}
int main()
{
    int k = 53;
    cout<<k<<endl;     //compiler starts execution from main function. so it first prints the value of k
    check();           //check() is called where at first occurance of global prints 32 because local varablel with that name is declared after it.
    //then global variable is declared in the function with initialization which will be used after that line in the function instead of global "global" variable 32
    cout<<global<<endl;  //this prints the value of global "global" variable which is 32
    func();         
    return 0;
}
/* Output:
53
32
2324
32
2324
32
32
*/
