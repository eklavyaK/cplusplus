#include <bits/stdc++.h>
#define endl "\n"
#define ii first
#define jj second
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a, n) 42
#define debug(...) 42
#endif

/*
Heavy-Light decomposition of a tree is basically decomposing the tree into various chains where each node is present in exactly one chain

METHOD:
     first run a dfs and calculate the sizes of each subtree and depth of each node
     start 1st chain at root and move towards heavyiest child (child subtree with biggest number of nodes in it)
     if two or more children have the maximum size then any of them can be selected at random
     extend the chain until a leaf is reached
     for other children we start a new chain from them
     we repeat these steps till we break the complete tree into chains

COMPLEXITY: O(n)

FACT: 
     We can reach from a node to a other node just by shifting chains which is just near to current chain in just O(logn) steps
     We can use exploit fact to solve tree related problems

APPLICATIONS:
     we can use this technique to handle tree path related queries where update is also done,
     Update can be performed easily in O(logn) time
     Path query like max, min, sum can be perfromed in O(log^2(n)) time, there will be atmost log(n) chains on path from u to v, for
     every chain we have to make a query which will take another log(n) time, so overall log^2(n)
*/

const int N = 2e5 + 5;
int pos, n;
vector<int> id(N), dep(N), sC(N), bigc(N), up(N), par(N), Seg(N*4);
vector<vector<int>> T;
void dfssz(int u, int p){
     sC[u] = 1;
     for(auto v : T[u]){
          if(v == p) continue;
          par[v] = u, dep[v] = dep[u] + 1;
          dfssz(v, u);
          sC[u] += sC[v];
          bigc[u] = sC[bigc[u]] < sC[v] ? v : bigc[u];
     }
}
void dfsid(int u, int p){
     id[u] = pos++;
     if(bigc[u]) up[bigc[u]] = up[u], dfsid(bigc[u], u);
     for(auto v : T[u]) if(v != p && v != bigc[u]) dfsid(v, u);
}
int lca(int u, int v){
     while(up[u] != up[v]) dep[up[u]] > dep[up[v]] ? u = par[up[u]] : v = par[up[v]];
     return dep[u] < dep[v] ? u : v;
}
void upd(int node, int l, int r, int pos, int c){
     if(l == r){
          Seg[node] = c;
          return;
     }
     int mid = (l + r) >> 1;
     pos <= mid ? upd(2 * node, l, mid, pos, c) : upd(2 * node + 1, mid + 1, r, pos, c);
     Seg[node] = max(Seg[2 * node], Seg[2 * node + 1]);
}
int qry(int node, int l, int r, int st, int en){
     if(l > en || r < st || st > en) return 0;
     if(st <= l && r <= en) return Seg[node];
     int mid = (l + r) >> 1;
     return max(qry(2 * node, l, mid, st, en), qry(2 * node + 1, mid + 1, r, st, en));
}
void update(int u, int val){
     upd(1, 0, n - 1, id[u], val);
}
int query(int u, int v){
     int mx = 0;
     while (up[u] != up[v]){
          if(dep[up[u]] > dep[up[v]]) mx = max(mx, qry(1, 0, n - 1, id[up[u]], id[u])), u = par[up[u]];
          else mx = max(mx, qry(1, 0, n - 1, id[up[v]], id[v])), v = par[up[v]];
     }
     if(dep[u] > dep[v]) swap(u, v);
     return max(mx, qry(1, 0, n - 1, id[u], id[v]));
}
void HLD(vector<vector<int>> Tree, int N){
     for(int i = 0; i <= N*4; i++) Seg[i] = 0;
     for(int i = 0; i <= N; i++) id[i] = dep[i] = sC[i] = bigc[i] = par[i] = 0, up[i] = i;
     dep[0] = -1, n = N, T = Tree;
     dfssz(1, 0), dfsid(1, 0);
}

void code(int TC){
     int n, q;
     cin >> n >> q;
     vector<int> c(n + 5);
     vector<vector<int>> Tree(n + 5); 
     for(int i = 1; i <= n; i++) cin >> c[i];
     for(int i = 1; i < n; i++){
          int u, v;
          cin >> u >> v;
          Tree[u].push_back(v);
          Tree[v].push_back(u);
     }
     HLD(Tree, n);
     for(int i = 1; i <= n; i++) update(i, c[i]);
     while(q--){
          int qrt;
          cin >> qrt;
          if(qrt == 1){
               int u, val;
               cin >> u >> val;
               update(u, val);
          }
          else{
               int u, v;
               cin >> u >> v;
               cout << query(u, v) << endl;
          }
     }
}

signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0); cout.tie(0); cerr.tie(0);
     int TT = 1;
     for(int TC = 1; TC <= TT; TC++)
          code(TC);
     return 0;
}