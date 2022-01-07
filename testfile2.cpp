#include <bits/stdc++.h>
using namespace std;
/*In a class when you pass a object as argument then the reference of the object is not passed. The receiving object is created as new 
object of the class and it receives a copy of the variables values of the variables stored in object passed. Any change made to the 
the object which receives the values of the passed object does not affect the original object.*/

int main()
{
    int n = 10;
    for(int i = n; i>=0; i--){cout<<i<<endl;n++;}
    return 0;
}
