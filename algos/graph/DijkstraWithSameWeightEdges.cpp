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
    int n,m; cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int> q;
    vector<int> d(n+1,1e9);
    d[n] = 0;
    q.push(n);
    while(!q.empty()){
        auto node = q.front(); q.pop();
        if(node==1) break;
        for(auto u : graph[node]){
            if(d[u]>d[node]+1){
                d[u] = d[node] + 1;
                q.push(u);
            }
        }
    }
    if(d[1]==1e9){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<d[1]+1<<endl;
    function<void(int)> dfs = [&](int node){
        cout<<node<<" ";
        if(node==n) return;
        for(auto i : graph[node]){
            if(d[i]==d[node]-1){
                dfs(i);
                return;
            }
        }
    };
    dfs(1);
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}