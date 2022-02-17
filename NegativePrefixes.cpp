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
        int n; cin>>n; int a[n],k,sum[n]; vector<int> v,in;
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n; i++) {cin>>k;if(!k){v.emplace_back(a[i]);in.emplace_back(i);}}
        sort(v.begin(),v.end(),greater<int>()); for(int i = 0; i<v.size(); i++) a[in[i]]=v[i];
        for(auto i : a) cout<<i<<" "; cout<<endl;
    }
    return 0;
}