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
        int n; cin>>n; string s; cin>>s; int detect = 1;
        for(int i = 0; i<n-1; i++) if(s[i]!=s[i+1]){detect = 0;cout<<i+1<<" "<<i+2<<endl;break;}
        if(detect)cout<<-1<<" "<<-1<<endl;
    }
    return 0;
}