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
        int n,detect=0; cin>>n; string s1,s2; cin>>s1>>s2;
        for(int i = 1; i<n-1; i++) if(s1[i]=='1'&& s2[i]=='1') {detect = 1;break;}
        if(detect) cout<<"NO"<<endl; else cout<<"YES"<<endl;
    }
    return 0;
}