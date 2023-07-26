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


ll dinic(vector<vector<pair<ll,ll>>> T, ll n, ll src, ll snk){
    if(src > n || snk > n || src <=0 || snk <= 0) return 0ll;
    vector<vector<ll>> p(n+5,vector<ll>(n+5,-1));
    vector<vector<pair<ll,ll>>> G(n+5);
    vector<ll> L(n+5), id(n+5);
    ll max_flo = 0;
    for(ll u=1;u<=n;u++){
        for(ll j=0;j<(ll)T[u].size();j++){
            auto [v,cap] = T[u][j];
            if(p[u][v] == -1) p[u][v] = (ll) G[u].size(), p[v][u] = (ll) G[v].size(), G[u].push_back({v,cap}), G[v].push_back({u,0});
            else G[u][p[u][v]].second += cap;
        }
    }
    auto bfs = [&](){
        L.assign(n+5,-1), L[src] = 0;
        queue<ll> q; q.push(src);
        while(!q.empty()){
            ll u = q.front(); q.pop();
            for(auto [v,c] : G[u]) if(c > 0 && L[v] == -1) L[v] = L[u] + 1, q.push(v);
        }
        return L[snk] != -1;
    };
    function<ll(ll,ll)> dfs = [&](ll u, ll pushed){
        if(u == snk) return pushed;
        for(;id[u] < (ll) G[u].size();id[u]++){
            auto [v, c] = G[u][id[u]];
            if(L[v] != L[u] + 1 || c <= 0) continue;
            if(ll flo = dfs(v, min(pushed, c))){
                G[u][id[u]].second -= flo, G[v][p[v][u]].second += flo;
                return flo;
            }
        }
        return 0ll;
    };
    if(snk == src) return -1ll;
    while(bfs()) id.assign(n+5,0), max_flo += dfs(src,8e18);

    // id.assign(n+5,0);
    // vector<pair<int,int>> cut_edges;                   //finding the min cut edges
    // function<void(int)> construct = [&](int u){
    // 	for(;id[u] < (ll) G[u].size();id[u]++){
    // 		auto [v, c] = G[u][id[u]];
    // 		if(L[v] == L[u] + 1) construct(v);
    // 		else if(L[v] == -1 && c<=0) cut_edges.push_back({u,v});
    // 	}
    // };
    // construct(src);

    return max_flo;
}


void code(int TC){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> G(n+5);
    for(int i=0;i<m;i++){
        int u,v,c; cin>>u>>v>>c;
        G[u].push_back({v,c});
    }
    cout<<dinic(G,n,1,n);
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}