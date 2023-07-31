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
Eulerian path is a way of transversing a graph where, we begin at a node, go through all the edges exactly once and reach a final given node (different from starting node)

EXISTENCE: 
    Starting node must have outdegree one more than indegree
    final node must have indegree onne more than outdegree
    All other nodes must have indegree == outdegree,
    graph must have exactly one SCC where edges are present, 
    Other SCC must contain 0 edges and,
    that one SCC must contain the starting and final nodes

APPROACH:
    first start at starting node, start transversing the edges
    mark the transversed edges with visited so we don't transverse it again
    It is guaranteed that after one transversal the ending node must be equal to final node (because for each incoming edge there will always be a outgoing edge in other)
    After each transversal we will check if there exist a VISITED node which has edge which still remain unvisited, we again start the transversal from that node

CONSTRUCTION:
    we'd first write the first transversal sequence started at starting node (there can be more than one transversal from starting node)
    If there is a node in THAT sequence which has transversal of its own then instead of writing that node, we write it's complete sequence
    we repeat the same process as we a new encounter sequence
*/
 
 
void code(int TC){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> G(n+5);
    vector<int> idg(n+5), E(m), vis(n+5);
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        idg[u]++, idg[v]++;
        G[u].push_back({v,j});
    }
    bool f = false;
    if(idg[1] % 2 == 0 || idg[n] % 2 == 0) f = true;
    for(int i=2;i<n;i++){
        if(idg[i] & 1) f = true;
    }
    if(f){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<queue<int>> C(n+5);
    function<void(int,int)> dfs = [&](int u, int node){
        vis[u] = 1;
        C[node].push(u);
        while(!G[u].empty()){
            auto [v,e] = G[u].back();
            G[u].pop_back();
            if(!E[e]){
                E[e] = 1, dfs(v,node);
                return;
            }
        }
    };
    dfs(1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]) continue;
        while(!G[i].empty()){
            auto [v,e] = G[i].back();
            if(!E[e]) dfs(i,i), debug(i,C[i]);
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
    construct(0);
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}