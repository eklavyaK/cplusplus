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
        string s; cin>>s; int counta=0, countb=0, countc=0;
        for(int i = 0; i<s.length(); i++) {if(s[i]=='A') counta++; else if(s[i]=='B') countb++; else countc++;}
        if(counta+countc==countb) cout<<"yes"<<endl; else cout<<"no"<<endl;
    }
    return 0;
}