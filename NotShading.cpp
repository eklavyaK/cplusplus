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
        int detect = 1, n,m,r,c; cin>>n>>m>>r>>c; string s[n];
        for(int i = 0; i<n; i++) cin>>s[i]; if(s[r-1][c-1]=='B') {cout<<0<<endl;continue;}
        else
        {
            for(int i = 0; i<n; i++) if(s[i][c-1]=='B') {cout<<1<<endl;detect = 0;break;}
            if (detect) for(int j = 0; j<m; j++) if(s[r-1][j]=='B') {cout<<1<<endl;detect=0;break;}
            if (detect) for(int i = 0; i<n; i++) if(s[i].find("B")!=-1) {cout<<2<<endl; detect = 0;break;}
            if(detect) cout<<-1<<endl;
        }
    }
    return 0;
}