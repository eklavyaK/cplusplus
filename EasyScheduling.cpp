#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int h,p; cin>>h>>p;
        int i = 0;
        while(pow(2,i)<=p) i++;
        if(i>=h) cout<<h<<endl;
        else
        {long double result = (long double)pow(2,i)*(pow(2,h-i)-1)/p;
        if(result == (long long int)result) cout<<(i+(long long)result)<<endl;
        else cout<<(i+1+(long long) result)<<endl;}
    }
    return 0;
}