#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
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
 
 
const int N = 2e5 + 5;
vector<int> T[N];
int M[N][2];
 
void dfs(int u, int p){
     for(auto v : T[u]){
          if(v == p) continue;
          dfs(v, u);
          if(M[u][0] < M[v][1] + 1) M[u][0] = M[v][1] + 1;
          sort(M[u], M[u] + 2);
     }
}
 
void code(int TC){
     int n, D = 0; cin >> n;
     for(int i = 1; i < n; i++){
          int u, v; cin >> u >> v;
          T[u].push_back(v);
          T[v].push_back(u);
     }
     dfs(1, 0);
     for(int i = 1; i <= n; i++) D = max(D, M[i][0] + M[i][1]);
     cout << D;
}
 
 
signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}