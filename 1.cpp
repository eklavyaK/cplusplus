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
    vector<vector<bool>> I(n+5,vector<bool>(n+5));
    vector<vector<ll>> p(n+5,vector<ll>(n+5,-1));
    vector<vector<pair<ll,ll>>> G(n+5);
    vector<ll> L(n+5), id(n+5);
    for(ll u=1;u<=n;u++){
        for(ll j=0;j<(ll)T[u].size();j++){
            auto [v,cap] = T[u][j];
            if(p[u][v] == -1) p[u][v] = (ll) G[u].size(), p[v][u] = (ll) G[v].size(), G[u].push_back({v,0}), G[v].push_back({u,0});
            G[u][p[u][v]].second += cap, I[u][v] = G[u][p[u][v]].second > 0;
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
    ll maxflo = 0;
    if(snk == src) return -1ll;
    while(bfs()) id.assign(n+5,0), maxflo += dfs(src,8e18);
    
    "To find MIN CUT EDGES we vist all the nodes from the source such that these nodes are connected to source with a sequence of positive flow in RESIDUAL graph (obtained after the last bfs), visited and unvisited nodes will form two subgraphs, nodes connecting the subgraphs must be saturated, so their residual cap is 0, after this we just check if a edge connects a visited node and an unvisited node and it EXISTED in the initial graph with positive cap, then it will be a min cut edge";
    // id.assign(n+5,0); vector<pair<int,int>> edges;
    // function<void(int)> add = [&](int u){
    //     id[u] = 1;
    //     for(auto [v,c] : G[u]) if(!id[v] && c>0) add(v);
    // };
    // add(src);
    // for(int u=1;u<=n;u++) if(id[u]) for(auto [v,c] : G[u]) if(!id[v] && I[u][v]) edges.push_back({u,v});
    
    "To find maximum number of DISJOINT PATHS we just simply begin from source and go along the path which EXISTED in original graph with a positive cap and got vanished (cap is reduced to 0) after pushing the flow, we'are sure to find a distinct path (no edges are common) along it because if two paths have a common edge one of them shuouldn't exist";
    // id.assign(n+5,0); vector<int> path;
    // function<void(int)> go = [&](int u){
    //     path.push_back(u);
    //     if(u == snk){
    //         cout<< endl << (int) path.size() << endl;
    //         for(auto i : path) cout<< i << " ";
    //         return;
    //     }
    //     for(;id[u] < (int)G[u].size();id[u]++){
    //         auto [v,c] = G[u][id[u]];
    //         if(I[u][v] && c<=0){
    //             I[u][v] = 0, go(v);
    //             path.pop_back();
    //             if(u != src) return;
    //         }
    //     }
    // };
    // go(src);
    
    return maxflo;
}


void code(int TC){
    

}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}