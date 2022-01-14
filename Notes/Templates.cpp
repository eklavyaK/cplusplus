#include<iostream>       /*********************************WILL BE UPDATED***********************************/
#include<vector>
#include<cstdlib>
#include<string>
using namespace std;

template <typename t=int> 
//void display(){cout<<"hello world";} ---> if we don't comment this function then print function will not excute because
//it uses the template. This is one of the reason why there is no semicolon at the end of the template.
//Each template is defined for one function or class only, they are not golbal.
t print(t val)
{
    t k = val;
    cout<<val<<endl;
    return k;
}
template <typename t=int>   //template declared directly above a function is used for that function only.
//so declaration of every function must preceeded by a template if function uses a template
t compute_display(t*a, int n)
{
    t v = a[0];cout<<a[0]<<" ";
    for(int i = 1; i<n; i++)  {v = v + a[i]; cout<<a[i]<<" ";}
    cout<<endl<<"The accumulation is: ";
    return v;
}
template <typename t = float, int N = 100> void display(t weight){cout<<"The value of weight is: "<<weight<<endl;cout<<"Total no. is: "<<N;}


int main()
{
    int n = 10;
    cout<<print("string to test the template concept")<<endl;
    cout<<print(23498)<<endl;
    cout<<print('c')<<endl;
    cout<<print(239882.98923)<<endl<<endl;

    int a[n]; string s[n]; float f[n];
    for(int i = 0; i<n; i++) a[i] = rand()%100;
    for(int i = 0; i<n; i++) f[i] = rand()%50 +(float)(rand()%100)/100;
    for(int i = 0; i<n; i++) for(int j = 0; j<5; j++) s[i].push_back(char(65+rand()%26));
    cout<<(compute_display<int>(a,n))<<endl<<endl;
    cout<<(compute_display<string>(s,n))<<endl<<endl;
    cout<<(compute_display<float>(f,n))<<endl<<endl;

    display<int>(23.234);cout<<endl;        //we can also assign values using template
    display(23.234);
    return 0;
}
/*Output:

string to test the template concept
string to test the template concept
23498
23498
c
c
239883
239883

41 67 34 0 69 24 78 58 62 64
The accumulation is: 497

NQDUX WFNFO ZVSRT KJPRE PGGXR PNRVY STMWC YSYYC QPEVI KEFFM
The accumulation is: NQDUXWFNFOZVSRTKJPREPGGXRPNRVYSTMWCYSYYCQPEVIKEFFM

5.45 31.27 11.91 45.42 27.36 41.04 2.53 42.82 21.16 18.95
The accumulation is: 247.91

The value of weight is: 23
Total no. is: 100
The value of weight is: 23.234
Total no. is: 100
*/