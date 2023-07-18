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
    vector<pair<int,int>> G(n+5);
    for(int j=0;j<m;j++){
        int u,v,c; cin>>u>>v>>c;
        G[u].push_back({v,c});
        G[v].push_back({u,c});        
    }
    vector<int> D(n+5,1e18);
    D[1] = 0;
    for(int i=0;i<n;i++){
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++)
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}