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
        int a,b,c; cin>>a>>b>>c;
        int t = max(max(a,b),c);
        if(t>a) cout<<t-a+1<<" "; else if(t==a && (a==b||a==c)) cout<<1<<" "; else cout<<0<<" ";
        if(t>b) cout<<t-b+1<<" "; else if(t==b && (b==a||b==c)) cout<<1<<" "; else cout<<0<<" ";
        if(t>c) cout<<t-c+1<<" "; else if(t==c && (c==b||a==c)) cout<<1<<" "; else cout<<0<<" ";
        cout<<endl;
    }
    return 0;
}