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
	vector<vector<int>> graph{{1,1,0,0},{1,1,0,1},{0,0,1,0},{0,1,0,1}};
	vector<int> initial({0, 3});
	int n = graph.size(), ans = 1E9, id = 0;
     auto calc = [&](int u){
		vector<int> p(n), sz(n, 1);
		iota(p.begin(), p.end(), 0);
		function<int(int)> getpar = [&](int u){
			if(u == p[u]) return u;
			return p[u] = getpar(p[u]);
		};
		function<void(int, int)> merge = [&](int u, int v){
			u = getpar(u), v = getpar(v);
			if(u != v){
			if(sz[u] < sz[v]) swap(u, v);
			p[v] = u, sz[u] += sz[v];
			}
		};
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
			if(i == u || j == u) continue;
			if(graph[i][j] == 1) merge(i, j);
			}
		}
		int cur = 0;
		vector<int> vis(n);
		debug(p);
		for(auto x : initial){
			if(x == u) continue;
			if(vis[getpar(x)]) continue;
			vis[getpar(x)] = 1;
			cur += sz[getpar(x)];
		}
		debug(n, cur);
		if(ans > cur) ans = cur, id = u;
	};
	for(auto i : initial) calc(i);
	debug(id);
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