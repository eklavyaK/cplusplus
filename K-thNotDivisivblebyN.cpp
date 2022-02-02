#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,k,t=0; cin>>n>>k;
        int a = k/(n-1), b = k%(n-1);
        if(b) cout<<a*n+b<<endl;
        else cout<<a*n-1<<endl;
    }
    return 0;
}