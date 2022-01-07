#include <bits/stdc++.h>
using namespace std;

//when two or more functions are overloaded then compiler first matches the number of arguments passed
//If there ia default argument in one function then it'll try to match with that function. Compiler tries to find all the possible functions, if all possible functions
//are more than two then it throws error

//then it checks the type of the arguments passed, if two types can be casted into one another like int, float then it throws error because of ambiguity
//order of parameters matter while differentiating between the overloaded functions;
//One thing to note that functions with different return types can be overloaded. Like shown in the exapmple below
/*1st function*/ int sum(int a, int b = 23)
{
    return a + b;
}
/*2nd function*/ //int sum(int a, int b){return<a+b;}        //ambiguous with 1st function when sum(3,4) is excuted
/*3rd function*/ void sum(int a, int b, int c) { cout << a + b + c << endl; }
/*4th function*/ float sum(float a, int b) { return a + b; }
/*5th function*/ //void sum(int a, int b){cout<<a+b<<endl;}        //ambiguous with 1st function even though it has different return type
/*6th function*/ float sum(int k, float l) { return k + l; }
int main()
{
    int n = 10, m = 20;
    float a = 3.4;
    int b = 5;
    cout << sum(4, 5) << endl; //1st function is called because by default integer literals are assumed as int so (int, int) is called
    //cout<<sum(3.4,5)<<endl;  //throws error because by default floating point literals are assumed as double but there is no (double, int) function available
    //so compiler will try to do type casting for which there are three possible candidates 1st, 4rth, 6th so it's ambiguous case
    cout << sum((float)3.4, 5) << endl; //this won't throw error although it's almost same as previous one because we've casted 3.4 to float and there is only one (float,int)
    //function which matches with 4rth function
    sum(n, m, 10);          //there is only function(3rd) with three arguments and (int, int, int) type
    cout << sum(5) << endl; //this won't throw error, because there only one function(1st) with first parameter as int and a default parameter
    //cout<<sum(5,3.4)<<endl;
    cout << sum(a, b) << endl; //4rth function is called because it's only one with type(float, int)
    cout << sum(b, a) << endl; //5th function is called because it's only one with type (int, float)
    return 0;
}
/*Output:
9
8.4
40
28
8.4
8.4
*/