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
	vector<int> h(n + 5), I(n + 5), O(n + 5);
	vector<pair<int,int>> ranges, T(n + 5), S(n + 5);
	for(int i = 1; i <= n; i++) cin >> h[i], T[i] = {0, h[i]};
	for(int j = 0; j < m; j++){
		int u, v; cin >> u >> v;
		G[v].push_back(u);
		I[v] += 1, O[u] += 1;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++) if(O[i] == 0) q.push(i), S[i] = T[i];
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto v : G[u]){
			if(h[v] > h[u] && (S[u].ff + 1 > S[v].ff || (S[u].ff + 1 == S[v].ff && S[u].ss > S[v].ss))) S[v] = {S[u].ff + 1, S[u].ss};
			else if(S[u].ff > S[v].ff || (S[u].ff == S[v].ff && S[u].ss > S[v].ss)) S[v] = S[u];
			O[v]--;
			if(O[v] == 0) q.push(v);
		}
	}
	debug(S), debug(T);
	for(int i = 1; i <= n; i++) if(I[i] == 0) ranges.push_back({T[i].ff * k + T[i].ss, S[i].ff * k + S[i].ss});
	sort(ranges.begin(), ranges.end());
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