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

const int N = 2e5+5;
vector<vector<int>> graph(N);
int vis[N], proc[N], mn[N], n, m, id = 0, cnt = 1;
vector<int> ans[N];
bool inStack[N];
stack<int> comps;
void dfs(int node){
    vis[node] = 1;
    comps.push(node);
    inStack[node]=true;
    proc[node]=mn[node]=++id;
    for(auto i : graph[node]){
        if(!vis[i]) dfs(i);
        if(inStack[i]) mn[node] = min(mn[i],mn[node]);
    }
    if(mn[node]!=proc[node])return;
    while(true){
        int c = comps.top();
        mn[c] = proc[node];
        inStack[c] = false;
        comps.pop();
        ans[cnt].push_back(c);
        debug(cnt,c);
        if(c==node)break;
    }
    cnt++;
}
void SCC(){
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
}



void code(int TC){
    cin>>n>>m;
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }
    int c[n];
    SCC();
    int t = 0;
    for(int i=1;i<N;i++){
        for(auto j : ans[i]) c[j-1] = i, t = i;
    }
    cout<<t<<endl;
    for(auto i : c) cout<<i<<' ';
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}