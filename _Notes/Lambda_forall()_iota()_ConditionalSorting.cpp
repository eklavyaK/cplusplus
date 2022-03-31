#include<iostream>
#include<vector>
#include<algorithm>    /* library for sort() and for_each() loop */
#include<cstdlib>      /* library for random numbers */
#include<numeric>      /* library for iota() method */

using namespace std;     /*Run this code file in testfile because it's name is such that it won't run in coderunner*/

void dothis(int &a) { a = 10;}
bool sorting(string &a, string &b) { if(a.size()>b.size()) return true; else return false;}
int main()
{
    vector<int> v(20);
    int val = 1;
    iota(v.begin(),v.end(),val); //iota() assigns each element a value 1 more than previous, first element takes the value of val.
    //for that we must have the size of the vector defined, here it is 20
    for(int i = 0; i<20; i++) cout<<v[i]<<" ";cout<<endl;
    cout<<val<<endl<<endl; //we can see that value of val remains same

    for_each(v.begin(),v.end(), dothis); //for_each() is a loop not a function. dothis is a function defined above. 
    //each element of vector v is passed to the function dothis one by one
    for(int i = 0; i<20; i++) cout<<v[i]<<" "; cout<<endl<<endl;

    for(int i = 0; i<20; i++) v[i] = rand()%100;
    for(int i = 0; i<20; i++) cout<<v[i]<<" ";cout<<endl<<endl;

    /*lambda expression is a inline function which performs a simple task. 
    
    Syntax: 

    [<---typeof arguement capturing---->](<---parameters--->)<specifications(optional)>{<----function body---->};
    
    ex: [&](int a, int b){ return a-b;}; 

    lambda expression can use variables from surrounding space. so we have to define how it should access the variables from 
    surrounding space.
    [] ----------> means it cannot use the value from outside the lambda body, except passed arguments
    [&] ----------> means it can use all the variables by their reference i.e. if a is variable defined in main(or any other function
                    where lambda is defined) and it's current value is 10, when we use the variable (a) in lambda body then it is 
                    the same variable as (a), any change in a will directly affect variable a outside

    [=] ----------> means all the variables are accessed by value i.e. if a is variable defined in main(or the function in which lambda
                    is defined) a copy of variable is created  in lambda body which is stored in different location than that outside lambda
                    NOTE: in case of [=] outside variables can only be modified if specifier "mutable" has been specified

    [&, r,l]------> means all the variables are captured by reference except r and l

    [=, &r, &l] ---> means all the variables are passed by value except r and l who are captured by reference

    specifiers: specifiers control the working of lambda, mutable specifier allows body to modify the variables and objects captured 
                by copy ([=]), and to call their non-const member functions. But values of variables remain same outside of the lambda body 

    lambda expression has no return type, it may or may not return any value, compiler understands it dependint on how we define it.
    */
    cout<<"Square of 4 is: ";
    auto square = [](int a){cout<< a*a <<" ";}; 
    square(4); cout<<endl;
    auto sq = [](int &a) {return a*a;};
    int s = sq(v[8]); cout<<"Square of 62 is: "<<s<<endl;        //v[8] is 62
    s = 0;
    cout<<"Sum of all the v[i] is: ";
    for_each(v.begin(),v.end(), [&](int &a){ s=s+a; });
    cout<<s<<endl;
    s = 0;
    //for_each(v.begin(),v.end(),[=](int &a){ s=s+a; }); ----> this throws error because s is outside variable and there is no mutable 
    //cout<<s<<endl;                                                                                                          specifier
    cout<<endl<<"Successive sum of numbers is: "<<endl; //we can use endl even before the values to be printed
    for_each(v.begin(),v.end(),[=](int &a) mutable { s = s+a; cout<<s<<" "; });  //we can see that value of s changing in the scope
    cout<<endl<<s<<endl<<endl;  //prints: 0        so value of s doesn't change outside of lambda body
    cout<<"Squares from 1 to 20 is: "<<endl;
    int a[20] = {0}; iota(a,a+20,1);
    for_each(a,a+20, square);cout<<endl<<endl;



    /*************************c***************CONDITIONAL SORTING********************************************************/

    string st[10]{"what","is","the","name","of","the","person","of","the","century"};
    sort(st,st+sizeof(st)/sizeof(st[0]), [](string &s1, string &s2){if(s1.size()<s2.size()) return true; else return false;});
    cout<<"Sorted string array in increasing order of string length is: \n[";
    for(int i = 0; i<9; i++) cout<<st[i]<<", "; cout<<st[9]<<"]"<<endl;  //here we have sorted based on their length
    //another way of doing this without using lambda expression is by writing a separate function
    //for ex: - let's sort in descending order of length
    sort(st,st+10,sorting);
    cout<<endl<<"Sorted string array in decreasing order of string length is: \n[";
    for(int i = 0; i<9; i++) cout<<st[i]<<", "; cout<<st[9]<<"]"<<endl;

    cout<<endl<<"Let's sort the vector elements in descending order: "<<endl;
    sort(v.begin(),v.end(), [](int &a, int &b){return a>b;});
    for(int i = 0; i<20; i++) cout<<v[i]<<" "; cout<<endl<<endl;

    cout<<"Let's sort the array elements based on sum of squares of their digits: "<<endl;
    sort(a, a+20, [](int a, int b)
    {
        auto sosq = [](int &a){int sum = (a%10)*(a%10); a = a/10; sum = sum + a*a; return sum;};
        return sosq(a)<sosq(b);
    });
    for(int i = 0; i<20; i++) cout<<a[i]<<" ";cout<<endl;
    return 0;
}
/*Output:

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 
1

10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10

41 67 34 0 69 24 78 58 62 64 5 45 81 27 61 91 95 42 27 36 

Square of 4 is: 16
Square of 62 is: 3844
Sum of all the v[i] is: 1007

Successive sum of numbers is:
41 108 142 142 211 235 313 371 433 497 502 547 628 655 716 807 902 944 971 1007
0

Squares from 1 to 20 is:
1 4 9 16 25 36 49 64 81 100 121 144 169 196 225 256 289 324 361 400

Sorted string array in increasing order of string length is:
[is, of, of, the, the, the, what, name, person, century]

Sorted string array in decreasing order of string length is:
[century, person, what, name, the, the, the, is, of, of]

Let's sort the vector elements in descending order:
95 91 81 78 69 67 64 62 61 58 45 42 41 36 34 27 27 24 5 0

Let's sort the array elements based on sum of squares of their digits:
1 10 11 20 2 12 3 13 4 14 5 15 6 16 7 17 8 18 9 19
*/