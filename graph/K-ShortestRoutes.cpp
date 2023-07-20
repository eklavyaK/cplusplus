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
vector<pair<int,int>> G[N];
vector<vector<int>> D(N,vector<int>(10,1e18));
vector<vector<int>> V(N,vector<int>(10));
 
 
void code(int TC){
    int n,m,k; cin>>n>>m>>k;
    for(int j=0;j<m;j++){
        int u,v,c; cin>>u>>v>>c;
        G[u].push_back({v,c});
    }
    D[1][0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,1});
    while(!q.empty()){
        auto [d,u] = q.top(); q.pop();
        if(V[u][k-1]) continue;
        else{
            V[u][k-1] = 1;
            sort(V[u].begin(),V[u].end(),greater<int>());
        }
        for(auto [v,c] : G[u]){
            if(D[v][k-1]>d+c){
                D[v][k-1] = d+c;
                sort(D[v].begin(),D[v].end());
                q.push({d+c,v});
            }
        }
    }
    for(int i=0;i<k;i++) cout<<D[n][i]<<" ";cout<<endl;
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}