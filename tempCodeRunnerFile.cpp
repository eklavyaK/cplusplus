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
#define debugarr(a, n) 42
#define debug(...) 42
#endif

const int N = 1E5 + 5;

map<int,int> m;
vector<int> A(N), dep(N), C(N);
vector<vector<tuple<int,int,int>>> ans(N), R(N);
vector<vector<int>> P(N, vector<int> (25)), T(N);

void lca(int u, int v, int i, int k){
	int d = dep[u] - dep[v];
	int ttu = u, ttv = v;
	for(int i = 0; i < 25; i++){
		if(d & (1 << i)) u = P[u][i];
	}
	if(u == v){
		R[ttv].push_back({ttu, i, k});
		return;
	}
	for(int i = 24; i >= 0; i--){
		if(P[u][i] != P[v][i]) u = P[u][i], v = P[v][i];
	}
	R[P[u][0]].push_back({ttu, i, k});
	R[v].push_back({ttv, i, k});
}

void dfs(int u){
	for(auto v : T[u]){
		if(v == P[u][0]) continue;
		dep[v] = dep[u] + 1;
		P[v][0] = u;
		dfs(v);
	}
}

void calc(int u, int p){
	for(auto [v, i, k] : R[u]) ans[v].push_back({m[k], k, i});
	m[C[u]] += 1;
	for(auto [pre, k, id] : ans[u]) A[id] += (m[k] - pre);
	R[u].clear();
	ans[u].clear();
	for(auto v : T[u]) if(v != p) calc(v, u);
	m[C[u]] -= 1;
	if(m[C[u]] == 0) m.erase(C[u]);
}

void code(int TC){
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> C[i];
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		u++, v++;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	dfs(1);
	for(int j = 1; j < 25; j++){
		for(int i = 1; i <= n; i++){
			P[i][j] = P[P[i][j - 1]][j - 1];
		}
	}
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int u, v, k; cin >> u >> v >> k;
		u++, v++;
		if(dep[u] < dep[v]) swap(u, v);
		lca(u, v, i, k);
	}
	calc(1, 0);
	for(int i = 0; i < q; i++) cout << A[i] << endl;
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	cout.precision(30);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}