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

const int N = 3E5 + 5;
vector<vector<pair<int, int>>> G(N);
vector<vector<int>> T(N), K(N, vector<int> (20)), L(N, vector<int> (20, 1E9));
vector<int> p(N), sz(N), I(N), parity(N), cyc(N), M(N), dep(N);
int id;

int getpar(int u){
	if(u == p[u]) return u;
	return p[u] = getpar(p[u]);
}

void merge(int u, int v){
	u = getpar(u), v = getpar(v);
	if(u != v){
		if(sz[u] < sz[v]) swap(u, v);
		if(sz[u] == sz[v] && v < u) swap(u, v);
		p[v] = u, sz[u] += sz[v];
	}
}

void dfs(int u, int edge){
	for(auto [v, e] : G[u]){
		if(e == edge) continue;
		if(I[v]){
			I[u] = min(I[u], I[v]);
			merge(u, v);
			if(parity[u] % 2 == parity[v] % 2) cyc[u] = 1;
			continue;
		}
		I[v] = ++id, parity[v] = parity[u] + 1;
		dfs(v, e);
		I[u] = min(I[v], I[u]);
		if(I[u] == I[v]) merge(u, v);
	}
}

void parentise(int u, int p){
	L[u][0] = min(M[u], M[K[u][0]]);
	for(auto v : T[u]){
		if(v == p) continue;
		dep[v] = dep[u] + 1;
		K[v][0] = u;
		parentise(v, u);
	}
}

int lca(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	int d = dep[u] - dep[v];
	for(int j = 0; j < 20; j++){
		if((1 << j) & d) u = K[u][j];
	}
	if(u == v) return u;
	for(int j = 19; j >= 0; j--){
		if(K[u][j] != K[v][j]) u = K[u][j], v = K[v][j];
	}
	return K[u][0];
}

void code(int TC){
	cout << "Case #" << TC << ": ";
	int n, m; cin >> n >> m;
	G.clear(); G.resize(n + 1);
	T.clear(); T.resize(n + 1);
	for(int j = 0; j < m; j++){
		int u, v; cin >> u >> v;
		G[u].push_back({v, j});
		G[v].push_back({u, j});
	}
	id = 0;
	for(int i = 0; i < n + 5; i++) p[i] = i, sz[i] = 1, I[i] = parity[i] = cyc[i] = dep[i] = 0, M[i] = 1E9;
	for(int j = 0; j < 20; j++){
		for(int i = 1; i <= n; i++) K[i][j] = 0, L[i][j] = 1E9;
	}
	parity[1] = 1, I[1] = ++id;
	dfs(1, -1);
	int root = 1E9;
	for(int i = 1; i <= n; i++) cyc[getpar(i)] |= cyc[i], root = min(root, p[i]);
	for(int i = 1; i <= n; i++){
		for(auto [j, e] : G[i]) if(p[j] != p[i]) T[p[i]].push_back(p[j]);
	}
	queue<int> Q;
	fill(I.begin(), I.end(), 0);
	for(int i = 1; i <= n; i++) if(cyc[p[i]] && !I[p[i]]) Q.push(p[i]), I[p[i]] = 1, M[p[i]] = 0;
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		for(auto v : T[u]){
			if(M[v] > M[u] + 1) M[v] = M[u] + 1, Q.push(v);
		}
	}
	parentise(root, 0);
	for(int j = 1; j < 20; j++){
		for(int i = 1; i <= n; i++) K[i][j] = K[K[i][j - 1]][j - 1];
	}
	for(int j = 1; j < 20; j++){
		for(int i = 1; i <= n; i++) L[i][j] = min(L[i][j - 1], L[K[i][j - 1]][j - 1]);
	}
	int q, qsum = 0; cin >> q;
	while(q--){
		int u, v; cin >> u >> v;
		int tu = u, tv = v;
		u = p[u], v = p[v];
		int lc = lca(u, v);
		int ans = min({M[lc], M[u], M[v]});
		int du = dep[u] - dep[lc], dv = dep[v] - dep[lc];
		for(int i = 0; i < 20; i++) if((1 << i) & du) ans = min(ans, L[u][i]), u = K[u][i];
		for(int i = 0; i < 20; i++) if((1 << i) & dv) ans = min(ans, L[v][i]), v = K[v][i];
		qsum += (ans == 1E9 ? -1 : ans);
	}
	cout << qsum << endl;
	if(TC == 45) exit(0);
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	freopen("6.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	freopen("6.txt", "w", stderr);
	cout.precision(30);
	int TT = 1; cin >> TT;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}