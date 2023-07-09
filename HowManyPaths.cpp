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
        int u, v; cin>>u>>v;
        graph[u].push_back(v);
    }
    set<int> st;
    vector<int> vis(n+1), is(n+1), indeg(n+1);
    function<void(int)> mark_cycles = [&](int node){
        vis[node] = 1;
        st.insert(node);
        for(auto i : graph[node]){
            indeg[i]++;
            if(vis[i]){
                if(st.count(i)) is[i] = 1;
                continue;
            }
            mark_cycles(i);
        }
        st.erase(node);
    };
    mark_cycles(1);
    int ans[n+1]{};
    fill(vis.begin(),vis.end(),0);
    function<void(int)> dfs_inf = [&](int node){
        ans[node] = -1;
        vis[node] = 1;
        for(auto i : graph[node]){
            if(!vis[i]) dfs_inf(i);
        }
    };
    for(int i=1;i<=n;i++) if(is[i] && !vis[i]) dfs_inf(i);
    if(vis[1]){
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
        return;
    }
    queue<int> q;
    q.push(1);
    ans[1] = 1;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto i : graph[node]){
            if(vis[i]) continue;
            ans[i] += ans[node];
            ans[i] = min(ans[i],10ll);
            indeg[i]--;
            if(!indeg[i]) q.push(i);
        }
    }
    for(int i=1;i<=n;i++) cout<<min(ans[i],2ll)<<' ';cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}