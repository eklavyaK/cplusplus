#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n; cin>>n; int a[n]; vector<int> res; bool check[n+1]={false};
        for(int i = 0; i<n; i++) cin>>a[i];int track = 1; res.emplace_back(a[0]); check[a[0]] = 1;
        for(int i = 1; i<n; i++){
            if(a[i]==a[i-1]){while(check[track])track++; if(track<a[i]){res.emplace_back(track);check[track]=1;}}
            else {res.emplace_back(a[i]); check[a[i]]=1;}}
        if(res.size()<n) cout<<-1;
        else for(auto i : res) cout<<i<<" ";cout<<endl;
    }
    return 0;
}