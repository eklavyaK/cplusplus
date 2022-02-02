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
        int n,m; cin>>n>>m; int res[n*m];
        for(int i = 0; i<n*m; i++) res[i]=max(i/m,n-1-i/m)+max(i%m,m-1-i%m);
        sort(res,res+n*m);for(int i = 0; i<n*m; i++) cout<<res[i]<<" ";cout<<endl;
    }
    return 0;
}