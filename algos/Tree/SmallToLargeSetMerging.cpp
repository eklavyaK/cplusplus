#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a,n) 42
#define debug(...) 42
#endif




void code(int TC){
     int n; cin>>n;
     vector<vector<int>> T(n+5);
     vector<int> c(n+5), ans(n+5);
     for(int i=1;i<=n;i++) cin>>c[i];
     for(int i=0;i<n-1;i++){
          int u,v; cin>>u>>v;
          T[u].push_back(v);
          T[v].push_back(u);
     }
     vector<set<int>> st(n+5);
     function<void(int,int)> dfs = [&](int u, int par){
          for(auto v : T[u]){
               if(v == par) continue;
               dfs(v, u);
               if(st[u].size()<st[v].size()) swap(st[u], st[v]);
               st[u].insert(st[v].begin(),st[v].end());
               st[v].clear();
          }
          st[u].insert(c[u]);
          ans[u] = (int)st[u].size();
     };
     dfs(1,0);
     for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}


signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}