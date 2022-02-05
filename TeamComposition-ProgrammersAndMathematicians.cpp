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
        int a1,b1,count; cin>>a1>>b1; int a = min(a1,b1),b=max(a1,b1);
        count = min(a,(b-a)/2); a-=count;b-=3*count; cout<<min(a,b)/2+count<<endl;
    }
    return 0;
}