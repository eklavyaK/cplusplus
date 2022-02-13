#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n; cin>>n; cout.precision(20);long long res=1l;int k = n; while(k>n/2) res*=k--; while(k)res/=k--;res/=2;k=n/2;while(k-->2)res*=(k*k);cout<<res<<endl;
    return 0;
}