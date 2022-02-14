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
        int n,q; cin>>n>>q; int a[n]; long long sum=0l; vector<int> v;
        for(int i = 0; i<n; i++) cin>>a[i];
        if(n>1) {if(a[0]>a[1]) v.emplace_back(0);} 
        else {cout<<a[0]<<endl; continue;}
        for(int i = 1; i<n-1; i++) 
        {if(a[i]>a[i-1]&&a[i]>a[i+1]) v.emplace_back(i); if(a[i]<a[i-1]&&a[i]<a[i+1]) v.emplace_back(i);}
        if(a[n-1]>a[n-2]) v.emplace_back(n-1);
        for(int i = 2; i<v.size(); i+=2) sum+=(a[v[i]]-a[v[i-1]]);
        cout<<sum+a[v[0]]<<endl;
    }
    return 0;
}