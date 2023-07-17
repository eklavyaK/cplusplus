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
Bipartite matching is simply coloring the nodes of a graph in such a way that no two adjacent nodes have same color

We can color any graph in bipartite way if it doesn't have a ODD cycle

NOTE: This can be used as a criteria to check if the graph has any ODD cycle
*/


void code(int TC){
    int n,m; cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool possible = true;
    vector<int> color(n+1);
    function<void(int,int)> go = [&](int node, int col){
        color[node] = col;
        for(auto i : graph[node]){
            if(color[i] && color[i]==color[node]) possible = false;
            if(!color[i]) go(i,3^color[node]);
        }
    };
    for(int i=1;i<=n;i++) if(!color[i]) go(i,1);
    if(!possible){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    for(int i=1;i<=n;i++) cout<<color[i]<<" ";cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}