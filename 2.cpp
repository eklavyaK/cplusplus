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

vector<vector<int>> Kosaraju(vector<vector<int>> G, int n){
    stack<int> comp;
    vector<int> V(n+5);
    vector<vector<int>> R(n+5), C(n+5);
    for(int u=1;u<=n;u++) for(auto v : G[u]) R[v].push_back(u);
    function<void(int)> dfs = [&](int u){
        V[u] = 1;
        for(auto v : G[u]) if(!V[v]) dfs(v);
        comp.push(u);
    };
    function<void(int,int)> scc = [&](int u, int c){
        V[u] = 0; C[c].push_back(u);
        for(auto v : R[u]) if(V[v]) scc(v,c);
    };
    int c = 0;
    for(int i=1;i<=n;i++) if(!V[i]) dfs(i);
    while(!comp.empty()){
        int node = comp.top(); comp.pop();
        if(V[node]) scc(node,c++);
    }
    return C;
}

void code(int TC){
    int n,m; cin>>n>>m;
    vector<vector<int>> G(n+5);
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
    }
    int ans[n];
    auto C = Kosaraju(G,n);
    for(int i=0;i<n;i++){
        for(auto j : C[i]) ans[j-1] = i+1;
    }
    cout<<*max_element(ans,ans+n)<<endl;
    for(auto i : ans) cout<<i<<' ';
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}