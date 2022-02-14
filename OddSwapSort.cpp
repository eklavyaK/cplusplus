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
        int n; cin>>n; int k,detect=0; vector<int> o,e;
        for(int i = 0; i<n; i++) {cin>>k;if(k%2)o.emplace_back(k); else e.emplace_back(k);}
        for(int i = 1; i<o.size(); i++) if(o[i]<o[i-1]){detect=1;break;}
        if(detect){cout<<"no"<<endl;continue;}
        for(int i = 1; i<e.size(); i++) if(e[i]<e[i-1]){detect=1;break;}
        if(detect){cout<<"no"<<endl;} else cout<<"yes"<<endl;
    }
    return 0;
}