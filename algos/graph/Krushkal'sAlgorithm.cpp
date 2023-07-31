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
Krushkal's algorithm sorts and edges and then adds all the edges which do not form cycle. Cycle is checked using DSU
*/

const int N = 1e5+5;
vector<tuple<int,int,int>> E;
int V[N], p[N], sz[N];

int find(int u){
    if(u==p[u]) return u;
    return p[u] = find(p[u]);
}
void merge(int u, int v){
    u = find(u), v = find(v);
    if(u!=v){
        if(sz[u]<sz[v]) swap(u,v);
        sz[u] += sz[v], p[v] = u;
    }
}


void code(int TC){
    int n,m; cin>>n>>m;
    for(int j=0;j<m;j++){
        int u,v,c; cin>>u>>v>>c;
        E.push_back({c,u,v});
    }
    for(int i=1;i<=n;i++) p[i] = i, sz[i] = 1;
    sort(E.begin(),E.end());
    int ans = 0, cnt = 0;
    for(int j=0;j<m;j++){
        auto [c,u,v] = E[j];
        if(find(u)==find(v)) continue;
        ans += c;
        cnt++;
        merge(u,v);
    }
    if(cnt==n-1) cout<<ans<<endl;
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