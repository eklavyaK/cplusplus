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
        long long n,x,y,k,count=0; cin>>n>>x>>y;
        for(int i = 0; i<n; i++) {cin>>k;if(k%2)count++;}
        if(count%2)
        {
            if((x+1)%2==y%2) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
        else
        {
            if(x%2==y%2) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
    }
    return 0;
}