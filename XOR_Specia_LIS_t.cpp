#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t-->0)
    {
        int n; cin>>n;
        int a,b;cin>>a;int result = 0;
        if(n%2==0)result = 1;
        for(int i = 1; i<n; i++)
        {cin>>b; if(b>a){a = b;continue;}else result=1;}
        if(result == 1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}