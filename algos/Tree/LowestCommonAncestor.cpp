#include <bits/stdc++.h>
#define endl "\n"
#define ii first
#define jj second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a, n) 42
#define debug(...) 42
#endif
 
const int L = 20, N = 2e5 + 5;
vector<vector<int>> T(N);
int p[N][L], dep[N];
 
void dfs(int u){
     for(auto v : T[u]) if(v != p[u][0]) p[v][0] = u, dep[v] = dep[u] + 1, dfs(v);
}
int lca(int u, int v){
     if(dep[u] < dep[v]) swap(u, v);
     int D = dep[u] - dep[v];
     for(int i = 0; i < L; i++) if((1 << i) & D) u = p[u][i];
     if(u == v){
          return u;
     }
     for(int i = L - 1; i >= 0; i--) if(p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
     return p[u][0];
}
void code(int TC){
     int n, m; cin >> n >> m;
     for (int i = 2; i <= n; i++){
          int u; cin >> u;
          T[u].push_back(i);
          T[i].push_back(u);
     }
     dfs(1);
     for(int i = 1; i < L; i++){
          for(int j = 1; j <= n; j++) p[j][i] = p[p[j][i - 1]][i - 1];
     }
     while(m--){
          int u, v; cin >> u >> v;
          cout << lca(u, v) << endl;
     }
}
 
signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1;
     for(int TC = 1; TC <= TT; TC++)
          code(TC);
     return 0;
}