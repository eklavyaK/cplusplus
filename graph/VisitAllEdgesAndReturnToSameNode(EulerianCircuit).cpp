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
 
 
/*
Eulerian cicruit is the way of transversing graph where, we begin at a node, go through all the edges exactly once, and finally return to the same starting node.

EXISTENCE: 
    All the nodes must have even indegree,
    graph must have exactly one SCC where edges are present, 
    Other SCC must contain 0 edges and,
    that one SCC must contain the starting node

APPROACH:
    first start at starting node, start transversing the edges
    mark the transversed edges with visited so we don't transverse it again
    It is guaranteed that after one transversal the ending and starting node will be same (because for each incoming edge there will always be a outgoing edge)
    After each transversal we will check if there exist a VISITED node which has edge which still remain unvisited, we again start the transversal from that node

CONSTRUCTION:
    we'd first write the transversal sequence started at starting node
    If there is a node in THAT sequence which has transversal of its own then instead of writing that node, we write it's complete sequence
    we repeat the same process as we a new encounter sequence
*/
 
 
void code(int TC){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> G(n+5);
    vector<int> idg(n+5), E(m), vis(n+5);
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        idg[u]++,idg[v]++;
        G[u].push_back({v,j});
        G[v].push_back({u,j});
    }
    for(int i=1;i<=n;i++){
        if(idg[i] & 1){
            debug(i);
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    vector<queue<int>> C(n+5);
    function<void(int,int)> dfs = [&](int u, int node){
        vis[u] = 1;
        C[node].push(u);
        while(!G[u].empty()){
            auto [v,e] = G[u].back();
            G[u].pop_back();
            if(u==1) debug(v);
            if(!E[e]){
                E[e] = 1, dfs(v,node);
                return;
            }
        }
    };
    vis[1] = 1;
    for(int i=1;i<=n;i++){
        if(!vis[i]) continue;
        while(!G[i].empty()){
            auto [v,e] = G[i].back();
            if(!E[e]) dfs(i,i), debug(C[i]);
            else G[i].pop_back();
        }
    }
    for(int i=0;i<m;i++){
        if(!E[i]){
            debug(i);
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    function<void(int)> construct = [&](int u){
        while(!C[u].empty()){
            int node = C[u].front(); C[u].pop();
            if(u!=node && !C[node].empty()) construct(node);
            else cout<<node<<" ";
        }
    };
    construct(1);
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}