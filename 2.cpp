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
bool check(vector<vector<pair<int,int>>> org, int cap, int n){
    debug(cap);
    vector<vector<int>> graph(n+1),rev(n+1);
    vector<int> id(n+1), sz(n+1,1), idg(n+1);
    iota(id.begin(),id.end(),0);
    function<int(int)> find_par = [&](int u){
        if(u==id[u]) return u;
        return id[u] = find_par(id[u]);
    };
    auto merge = [&](int u, int v){
        u = find_par(u), v = find_par(v);
        if(u!=v){
            if(sz[u]<sz[v]) swap(u,v);
            sz[u] += sz[v], id[v] = u;
        }
    };
    for(int i=1;i<=n;i++){
        for(auto [u,v] : org[i]){
            if(v<=cap) merge(i,u);
        }
    }
    for(int i=1;i<=n;i++) id[i] = find_par(i);
    for(int i=1;i<=n;i++){
        for(auto [u,v] : org[i]){
            if(v>cap && id[u]!=id[i]) graph[id[i]].push_back(id[u]),rev[id[u]].push_back(id[i]), idg[id[u]] = 1;
        }
    }
    debug(id);
    debug(graph);
    fill(sz.begin(),sz.end(),0);
    vector<int> all;
    function<void(int)> find_mother = [&](int node){
        sz[node] = 1;
        for(auto u : rev[node]){
            if(!sz[u]) find_mother(u);
        }
        all.push_back(node);
    };
    find_mother(id[1]);
    int mother = 0;
    for(auto i : all){
        mother = i;
        if(!idg[i]) break;
    }
    debug(mother);
    fill(sz.begin(),sz.end(),0);
    function<void(int)> dfs = [&](int node){
        sz[node] = 1;
        for(auto u : graph[node]){
            if(!sz[u]) dfs(u);
        }
    };
    dfs(mother);
    for(int i=1;i<=n;i++) if(!sz[id[i]]) return false;
    return true;
}


void code(int TC){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    int l = 0, r = 0, ans = -1;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v,w});
        r = max(r,w);
    }
    while(l<=r){
        int mid = (l+r)>>1;
        if(check(graph,mid,n)) r = mid-1, ans = mid;
        else l = mid+1;
    }
    cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}