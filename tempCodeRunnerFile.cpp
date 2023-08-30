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
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> G(n + 5);
	vector<pair<int,int>> ranges, T(n + 5);
	vector<int> h(n + 5), I(n + 5), O(n + 5);
	for(int i = 1; i <= n; i++) cin >> h[i], T[i] = {0, h[i]};
	vector<int> p(n + 5);
	iota(p.begin(), p.end(), 0);
	for(int j = 0; j < m; j++){
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		p[v] = u;
		I[v] += 1, O[u] += 1;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++) if(I[i] == 0) q.push(i);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto v : G[u]){
			if(T[u].ss > T[v].ss) T[v].ff = max(T[u].ff + 1, T[v].ff), p[v] = p[u];
			else if(T[u].ff > T[v].ff) T[v].ff = T[u].ff, p[v] = p[u];
			I[v]--;
			if(I[v] == 0) q.push(v);
		}
	}
	debug(p);
	for(int i = 1; i <= n; i++) if(O[i] == 0) ranges.push_back({T[p[i]].ff * k + T[p[i]].ss, T[i].ff * k + T[i].ss});
	sort(ranges.begin(), ranges.end());
	debug(ranges);
	n = ranges.size();
	int mx = -1e18, ans = 1e18;
	vector<int> M(n);
	for(int i = n - 1; i >= 0; i--) mx = max(mx, ranges[i].ss), M[i] = mx;
	mx = -1e18;
	for(int i = 0; i < n; i++){ 
		ans = min(ans, max(M[i], mx + k) - ranges[i].ff);
		mx = max(ranges[i].ss, mx);
	}
	cout << ans << endl;
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	cout.precision(30);
	int TT = 1; cin >> TT;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}