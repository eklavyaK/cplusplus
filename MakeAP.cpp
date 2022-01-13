#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t-->0)
    {
        int a,b,c; cin>>a>>b>>c;
        if(((long double)a +c)/(2*b)==(a+c)/(2*b)) cout<<"yes"<<endl;
        else if(((long double)b*2 - c)/a==(2*b-c)/a && 2*b>c) cout<<"yes"<<endl;
        else if(((long double)b*2 - a)/c==(2*b-a)/c && 2*b>a) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}