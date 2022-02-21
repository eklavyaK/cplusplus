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
        int n; cin>>n; int a[n]; vector<int> b(n); vector<int> c;
        int g, k=0;
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n; i++) if(a[i]>k) {k=a[i];g=i;}
        b[g]=1;c.emplace_back(k); g = k;
        while(g!=1 && find(b.begin(),b.end(),0)!=b.end()) {
            int in, temp;k=0;
            for(int i = 0; i<n; i++) {
                if(!b[i]){
                    temp=gcd(a[i],g);
                    if(temp>k){k=temp;in=i;}
                }
            }
            g=k;b[in]=1;
            c.emplace_back(a[in]);
        }
        for(int i = 0; i<n; i++) if(!b[i])c.emplace_back(a[i]);
        for(auto i : c) cout<<i<<" ";cout<<endl;   
    }
    return 0;
}