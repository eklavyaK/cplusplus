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
Floyd-Warshall algorithm: can find the shortest distances between the all pairs of the nodes,
It works in O(V^3), where V is the no of nodes
NOTE: It is not applicable for negative cycle in graph
*/
const int N = 505;
vector<vector<int>> D(N,vector<int>(N,1e15));
 
void code(int TC){
    int n,m,q; cin>>n>>m>>q;
    for(int i=1;i<=n;i++) D[i][i] = 0;
    while(m--){
        int u,v,c; cin>>u>>v>>c;
        D[u][v] = min(D[u][v],c);
        D[v][u] = min(D[v][u],c);
    }
    for(int k=1;k<=n;k++){               //The intermediate node is in the outer loop
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
            }
        }
    }
    while(q--){
        int u,v; cin>>u>>v;
        if(D[u][v]>1e13) cout<<-1<<endl;
        else cout<<D[u][v]<<endl;
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