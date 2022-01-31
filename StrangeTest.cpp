#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int a,b;cin>>a>>b;int count=0; int res = INT_MAX;
        for(int i = 0; i<=b; i++) 
        {if((i|b)==b) res = min(res,abs(i-a)+(i!=b));}
        cout<<res<<endl;
    }
    return 0;
}