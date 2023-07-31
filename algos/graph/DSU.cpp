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
DSU - Disjoint Set Union
*/
 
const int N = 1e5+5;
vector<int> G[N];
int p[N], sz[N];

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
    for(int i=1;i<=n;i++) sz[i] = 1, p[i] = i;
    for(int j=0;j<m;j++){
        int u,v; 
        cin>>u>>v;
        merge(u,v);
    }
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}