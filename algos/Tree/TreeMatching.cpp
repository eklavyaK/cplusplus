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


/**
 * To find the maximum matching we should start pairing the leaves to their parents first
 */



void code(){
	int n; cin >> n;
	vector<vector<int>> T(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	int ans = 0;
	vector<int> color(n + 1);
	function<void(int, int)> dfs = [&](int node, int par) {
		for (auto v : T[node]) {
			if (v == par) continue;
			dfs(v, node);
			if (color[v] == 0 && color[node] == 0) {
				color[v] = color[node] = 1;
				ans += 1;
			}
		}
	};
	dfs(1, 0);
	cout << ans << endl;

}


signed main(){
	cin.tie(0)->sync_with_stdio(0);
	code();
	return 0;
}