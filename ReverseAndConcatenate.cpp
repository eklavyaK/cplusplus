#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    string a[32]; for(int i = 0; i<32; i++) a[i]=to_string(pow(2,i));
    while(tc-->0)
    {
        int n,k; cin>>n>>k; string s; cin>>s; int detect = 1;
        for(int i = 0; i<n/2; i++) if(s[i]!=s[n-1-i]) {detect = 0;break;}
        if(detect) cout<<1<<endl;
        else{k>0?cout<<2<<endl:cout<<1<<endl;}
    }
    return 0;
}