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
Remember we can't use dijkstra for negative edges, or in such cases where value of the shortest can decrease infinitely
*/
const int N = 1e5+5;
vector<pair<int,int>> graph[N];
vector<int> D(N,1e18), P(N);


void code(int TC){
    int n,m; cin>>n>>m;
    for(int j=0;j<m;j++){
        int u,v,c; cin>>u>>v>>c;
        graph[u].push_back({v,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,1});
    D[1] = 0;
    while(!q.empty()){
        auto [d,node] = q.top(); q.pop();
        if(P[node]) continue;
        else P[node] = 1;
        for(auto [U,C] : graph[node]){
            if(D[U]>D[node]+C){
                D[U] = D[node] + C;
                q.push({D[U],U});
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<D[i]<<" ";cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}