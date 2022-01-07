#include<iostream>
using namespace std;
void func(int&, int&);
void func(int*, int*);
int main()
{
    int a = 10;
    int b = 20;
    cout<<"a is: "<<a<<"    "<<"b is: "<<b<<"\n"<<endl;     
    int &c = a;               //Now c and a point to same location
    int *p = &b;              //*p is a pointer which points to the location of b
    cout<<"c is: "<<c<<endl;
    cout<<"*p is: "<<*p<<"  "<<"p is: "<<p<<"\n"<<endl;
    c = c - 1;               //a gets affected
    (*p) = (*p)+2;           //b gets affected
    cout<<"a is: "<<a<<"    "<<"b is: "<<b<<endl;
    cout<<"c is: "<<c<<"    "<<"*p is: "<<*p<<"\n"<<endl;

    func(a,b);                
    cout<<"a is: "<<a<<"    "<<"b is: "<<b<<endl;
    cout<<"c is: "<<c<<"    "<<"*p is: "<<*p<<"\n"<<endl;
    func(&a,&b);
    cout<<"a is: "<<a<<"    "<<"b is: "<<b<<endl;
    cout<<"c is: "<<c<<"    "<<"*p is: "<<*p<<endl;
    return 0;
}
void func(int &n, int &m)     //like happened in line 10, n and m point to the same location as a and b respectively
{
    n--;                   //a gets affected
    m++;                   //b gets affected
}
void func(int *x, int* y)
{
    *x = (*x) - 5;
    *y = (*y) + 20;
}
/*Output:
a is: 10    b is: 20

c is: 10
*p is: 20  p is: 0x61fef0

a is: 9    b is: 22
c is: 9    *p is: 22

a is: 8    b is: 23
c is: 8    *p is: 23

a is: 3    b is: 43
c is: 3    *p is: 43
*/