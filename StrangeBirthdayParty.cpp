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
        int n,m; cin>>n>>m; int f[n], g[m+1], track = 1; long long sum = 0l;
        for(int i = 0; i<n; i++) cin>>f[i];for(int i = 1; i<=m; i++) cin>>g[i]; sort(f,f+n);
        int i = n-1;for(; i>=0; i--)
        {
            if(f[i]<=track) break;
            else sum+=g[track++];
        }
        for(int j = 0; j<=i; j++) sum+=g[f[j]]; cout<<sum<<endl;
    }
    return 0;
}