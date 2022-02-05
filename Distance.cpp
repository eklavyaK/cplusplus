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
        int x,y; cin>>x>>y;
        if((x%2 && y%2==0)||(x%2==0 && y%2)) cout<<"-1 -1"<<endl;
        else cout<<(x+x%2)/2<<' '<<(y-y%2)/2<<endl;
    }
    return 0;
}