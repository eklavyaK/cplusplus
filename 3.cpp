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

const int M = 1E9 + 7;
int exp(int a, int n){
	int res = 1;
	while(n > 0){
		if(n & 1) res = res * a % M;
		a = a * a % M; n >>= 1;
	}
	return res;
}


void code(int TC){
	int n; cin >> n;
	vector<int> a(n + 5);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<vector<int>> T(n + 5);
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	vector<int> sum(n + 5), odd(n + 5), even(n + 5), sz(n + 5), ans(n + 5);
	vector<int> centroids;
	function<void (int, int)> dfs1 = [&](int u, int p) {
		sz[u] = 1;
		bool is_centroid = true;
		for(auto v : T[u]){
			if (v == p) continue;
			dfs1(v, u);
			sz[u] += sz[v];
			if(sz[v] > n / 2) is_centroid = false;
		}
		if(n - sz[u] > n / 2) is_centroid = false;
		if(is_centroid) centroids.push_back(u);
	};
	dfs1(1, 0);
	fill(sz.begin(), sz.end(), 0);
	sort(centroids.begin(), centroids.end());
	function<void(int, int)> dfs = [&](int u, int p){
		sz[u] = (sz[u] + a[u]) % M;
		even[u] = (even[u] + a[u]) % M;
		for(auto v : T[u]){
			if(v == p) continue;
			dfs(v, u);
			even[u] = (even[u] + odd[v]) % M;
			odd[u] = (odd[u] + even[v]) % M;
			sz[u] = (sz[u] + sz[v]) % M;
			sum[u] = (sum[u] + sum[v] + sz[v]) % M;
		}
	};
	dfs(centroids[0], 0);
	cout << (sum[centroids[0]] + odd[centroids[0]]) % M * exp(2, M - 2) % M << endl;
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