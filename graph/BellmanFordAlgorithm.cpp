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
Bellman-Ford algorithm is used to find the shortest route between a source and a destination,

It's complexity is O(V*E), which is much more than Dijkstra

ADVANTAGE OVER DIJKSTRA: It can work for negative edge weights, hence it is used to find negative cycle in a graph,

first run the edges for n-1 times (n-1 iteration brings saturation), if in during nth iteration, there is a change observed, then there must be negative cycle in the graph
*/


void code(int TC){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> G(n+5);
    for(int j=0;j<m;j++){
        int u,v,c; cin>>u>>v>>c;
        G[u].push_back({v,c});        
    }
    vector<int> D(n+5,1e18), P(n+5), T(n+5,1e18);   // vector P can used for shortest path construction
    D[1] = 0;
    for(int i=0;i<n;i++){
        for(int u=1;u<=n;u++){
            for(auto [v,c] : G[u]){
                if(D[v]>D[u]+c)D[v] = D[u] + c, P[v] = u;
            }
        }
        if(i==n-2) T = D;
    }
    for(int i=1;i<=n;i++){
        if(T[i]==D[i]) continue;
        cout<<-1<<endl;
        return;
    }
    cout<<D[n]<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}