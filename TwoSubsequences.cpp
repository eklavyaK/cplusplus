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
        string s; cin>>s; char c='z'; int in = 0;
        for(int i = 0; i<s.size(); i++) if(c>s[i]) {c=s[i];in=i;}
        cout<<c<<" "<<s.substr(0,in)<<s.substr(in+1)<<endl;
    }
    return 0;
}