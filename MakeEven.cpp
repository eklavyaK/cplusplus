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
        string s; cin>>s; if(s[s.size()-1]%2==0) {cout<<0<<endl;continue;}
        else if(s[0]%2==0){cout<<1<<endl; continue;}
        else {int detect =1; for(int i = 1; i<s.size()-1; i++) if(s[i]%2==0){detect = 0;break;} if(detect) cout<<-1<<endl; else cout<<2<<endl;}
    }
    return 0;
}