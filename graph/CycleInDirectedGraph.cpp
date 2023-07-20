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


const int N = 1e5+5;
vector<int> G[N];
int V[N], P[N];



void code(int TC){
    int n,m; cin>>n>>m;
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
    }
    vector<int> ans; bool is = false;
    function<void(int)> dfs = [&](int u){
        V[u] = 2;
        for(auto v : G[u]){
            if(!V[v]) P[v] = u, dfs(v);
            if(!is && V[v]==2){
                int cur = u;
                ans.push_back(v);
                ans.push_back(u);
                while(cur!=v) cur = P[cur], ans.push_back(cur);
                is = true;
            }
        }
        V[u] = 1;
    };
    for(int i=1;i<=n;i++) dfs(i);
    if(!is){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    else cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for(auto i : ans) cout<<i<<" ";cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}