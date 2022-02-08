#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int a,b; cin>>a>>b;
        if(a%2==b%2)
        {
            int l = (a+b-2*min(a,b))/2;
            int r = l+2*min(a,b); cout<<min(a,b)+1<<endl;
            for(int i = l; i<=r; i+=2) cout<<i<<" ";
        }
        else
        {
            int l = (a+b-(2*min(a,b)+1))/2;
            int r = l+2*min(a,b)+1; cout<<r-l+1<<endl;
            for(int i = l; i<=r; i++) cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}