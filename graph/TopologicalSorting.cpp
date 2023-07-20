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


const int N = 1e5+5;
vector<int> G[N];
int indeg[N];

void code(int TC){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i=1;i<=n;i++) if(!indeg[i]) q.push(i);
    while(!q.empty()){
        int node = q.front(); q.pop();
        ans.push_back(node);
        for(auto u : G[node]){
            indeg[u]--;
            if(!indeg[u])q.push(u);
        }
    }
    for(int i=1;i<=n;i++){
        if(indeg[i]){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    for(auto i : ans) cout<<i<<" ";cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}