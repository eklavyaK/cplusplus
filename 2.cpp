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




void code(int TC){
	int n; cin >> n;
	vector<vector<int>> T(n + 5);
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	vector<int> sz(n + 5);
	function<void(int, int)> dfs = [&](int u, int p){
		sz[u] = 0;
		for(auto v : T[u]){
			if(v == p) continue;
			dfs(v, u);
			sz[u] += sz[v];
		}
		if(sz[u] == 0) sz[u] = 1;
	};
	dfs(1, 0);
	int q; cin >> q;
	while(q--){
		int u, v; cin >> u >> v;
		cout << sz[u] * sz[v] << endl;
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