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
Prims Algorithm for minimum spanning tree
*/

const int N = 1e5+5;
vector<pair<int,int>> G[N];
int V[N];

void code(int TC){
    int n,m; cin>>n>>m;
    for(int j=0;j<m;j++){
        int u,v,c; cin>>u>>v>>c;
        G[u].push_back({v,c});
        G[v].push_back({u,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,1});
    int cnt = 0, ans = 0;
    while(!q.empty()){
        auto [e,node] = q.top(); q.pop();
        if(V[node]) continue;
        else V[node] = 1, ans += e, cnt++;
        for(auto [u,e] : G[node]){
            if(!V[u]) q.push({e,u});
        }
    }
    if(cnt==n) cout<<ans<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}